/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Thu, Jan, 2025                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     CRoomClient                                                                      *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "CRoomClient.hpp"
#include <chrono>

CRoomClient::CRoomClient() : isConnected(false)
{
    client_info = ParsingTcp(1, NULL).getClientSettings();
    std::cout << client_info["server_ip"] << std::endl;

    auto server_ip = client_info["server_ip"];
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        throw std::runtime_error("Failed to create socket.");
    }
    uint32_t ip_addr = 0;
    size_t pos = 0;
    int shift = 24;
    for (int i = 0; i < 4; ++i) {
        size_t next_pos = server_ip.find('.', pos);
        if (next_pos == std::string::npos && i < 3) {
            throw std::runtime_error("Invalid server IP address format.");
        }
        std::string octet = server_ip.substr(pos, next_pos - pos);
        ip_addr |= (std::stoi(octet) & 0xFF) << shift;
        pos = next_pos + 1;
        shift -= 8;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(std::stoi(client_info["server_port"]));
    server_address.sin_addr.s_addr = htonl(ip_addr);
}


CRoomClient::~CRoomClient()
{
    #ifdef _WIN32
        closesocket(client_socket);
    #else
        close(client_socket);
    #endif
}


void CRoomClient::connectToServer()
{
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        return;
    }
    isConnected = true;
}

void CRoomClient::chooseMessage(message_type _type, std::optional<int> lobby_)
{
    switch (_type)
    {
        case PORT:
            sendMessage({static_cast<uint16_t>(PORT)});
            break;
        case ADD:
            sendMessage({static_cast<uint16_t>(ADD)});
            break;
        case DELETE:
            sendMessage({static_cast<uint16_t>(DELETE)});
            break;
        default:
            break;
    }
}

void CRoomClient::sendMessage(const std::vector<uint16_t>& message)
{
    ssize_t bytes_sent = send(client_socket, message.data(), message.size() * sizeof(uint16_t), 0);
}

std::vector<uint16_t> CRoomClient::receiveMessage()
{
    std::cout << std::stoi(client_info["buffer_size"]) << std::endl;
    uint16_t buffer[std::stoi(client_info["buffer_size"])];
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received == 0) {
        return {static_cast<uint16_t>(KO)};
    }
    std::vector<uint16_t> message(buffer, buffer + (bytes_received / sizeof(uint16_t)));
    std::cout << "Message received from server: ";
    for (uint16_t value : message) {
        std::cout << value << " ";
    }
    return message;
}

std::vector<uint16_t> CRoomClient::Refresh() {
    chooseMessage(PORT, 1);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return receiveMessage();
}

std::vector<uint16_t> CRoomClient::CreateLobby() {
    chooseMessage(ADD, 1);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return receiveMessage();
}
