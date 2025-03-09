/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Jan, 2025                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     CRoomServer                                                                           *
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

// CRoomServer.cpp
#include "CRoomServer.hpp"

CRoomServer::CRoomServer(bool windows) : _game_manager(windows)
{
    serv_info = ParsingTcp(1, NULL).getServerSettings();
    std::string room_ports = serv_info["room_ports"];
    std::stringstream ss(room_ports);
    std::string port;
    while (std::getline(ss, port, ',')) {
        try {
            this->_ports.push_back(static_cast<unsigned short>(std::stoi(port)));
        } catch (const std::exception& e) {
            throw std::runtime_error("Invalid port value: " + port);
        }
    }
    createServer();
}

void CRoomServer::createServer()
{
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        throw std::runtime_error("Failed to create socket.");
    }
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(std::stoi(serv_info["listening_port"]));

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        close(server_socket);
        throw std::runtime_error("Failed to bind socket.");
    }
    if (listen(server_socket, 5) == -1) {
        close(server_socket);
        throw std::runtime_error("Failed to listen on socket.");
    }
}

CRoomServer::~CRoomServer()
{
    #ifdef _WIN32
        closesocket(server_socket);
    #else
        close(server_socket);
    #endif
}

int CRoomServer::acceptConnection()
{
    if (socketClients.size() >= std::stoi(serv_info["max_players"])) {
        return -1;
    }

    sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len);

    if (client_socket != -1) {
        socketClients.push_back(client_socket);
        return client_socket;
    }
    return -1;
}

void CRoomServer::deleteClient(int socket)
{
    auto it = std::find(socketClients.begin(), socketClients.end(), socket);
    
    if (it != socketClients.end()) {
        socketClients.erase(it);
    }
}

void CRoomServer::sendMessage(int socket, std::vector<uint16_t> msg)
{
    ssize_t bytes_sent = send(socket, msg.data(), msg.size() * sizeof(uint16_t), 0);
}

std::vector<uint16_t> CRoomServer::receiveMessage()
{
    uint16_t buffer[std::stoi(serv_info["buffer_size"])];
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(server_socket, &read_fds);

    int max_fd = server_socket;
    for (int client_socket : socketClients) {
        FD_SET(client_socket, &read_fds);
        if (client_socket > max_fd) {
            max_fd = client_socket;
        }
    }

    int activity = select(max_fd + 1, &read_fds, nullptr, nullptr, nullptr);
    if (activity < 0 && errno != EINTR) {
        throw std::runtime_error("Select error.");
    }
    if (FD_ISSET(server_socket, &read_fds)) {
        acceptConnection();
    }
    std::vector<uint16_t> received_data;
    for (auto it = socketClients.begin(); it != socketClients.end();) {
        int client_socket = *it;
        if (FD_ISSET(client_socket, &read_fds)) {
            ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
            if (bytes_received <= 0) {
                std::cout << "Client disconnected: " << client_socket << std::endl;
                close(client_socket);
                deleteClient(client_socket);
                continue;
            }
            size_t elements_received = bytes_received / sizeof(uint16_t);
            std::vector<uint16_t> received_data(buffer, buffer + elements_received);
            handleClientMessage(client_socket, received_data);
        }
        it += 1;
    }
    return received_data;
}

void CRoomServer::handleClientMessage(int client_socket, const std::vector<uint16_t>& message)
{
    if (message.empty()) {
        return;
    }
    if (message[0] == static_cast<uint16_t>(PORT)) {
        if (getListPort().empty()) {
            std::vector<uint16_t> response = {KO};
            sendMessage(client_socket, response);
        } else {
            sendMessage(client_socket, getListPort());
        }
    } else if (message[0] == static_cast<uint16_t>(ADD)) {
        _game_manager.createLobby(_ports.back());
        _ports.pop_back();
        std::vector<uint16_t> response = {OK};
        sendMessage(client_socket, response);
    } else if (message[0] == static_cast<uint16_t>(DELETE)) {
        std::cout << "DELETE" << std::endl;
        std::vector<uint16_t> response = {OK};
        sendMessage(client_socket, response);
    }
}

std::vector<uint16_t> CRoomServer::getListPort()
{
    auto lobbies_ports = _game_manager.getLobbiesPorts();
    std::vector<uint16_t> response;
    for (auto port : lobbies_ports) {
        response.push_back(static_cast<uint16_t>(port));
    }
    return response;
}
