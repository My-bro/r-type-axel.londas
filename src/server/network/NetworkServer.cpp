/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Fri, Nov, 2024                                                     *
 * Title           - R-type                                                             *
 * Description     -                                                                    *
 *     NetworkServer                                                                    *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "NetworkServer.hpp"

/**
 * @brief Construct a new NetworkServer object.
 * 
 * Opens and binds a UDP socket to the specified port.
 * 
 * @param port_ The port to bind the server to.
 */
NetworkServer::NetworkServer(unsigned short port_)
    : io_context(), socket(io_context), port(port_), running(false) {
    try {
        socket.open(asio::ip::udp::v4());
        socket.bind(asio::ip::udp::endpoint(asio::ip::udp::v4(), port));
        std::cout << "Server started on port " << port << std::endl;
    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to open or bind socket: " + std::string(e.what()));
    }
}

/**
 * @brief Destroy the NetworkServer object.
 * 
 * Closes the socket and stops the receive loop.
 */
NetworkServer::~NetworkServer() {
    stop();
    if (socket.is_open()) {
        socket.close();
    }
    std::cout << "Server closed." << std::endl;
}

/**
 * @brief Start the server's receive loop in a separate thread.
 */
void NetworkServer::start() {
    running = true;
    receiveThread = std::thread(&NetworkServer::receiveLoop, this);
}

/**
 * @brief Stop the server and join the receive thread.
 */
void NetworkServer::stop() {
    running = false;
    if (receiveThread.joinable()) {
        receiveThread.join();
    }
}

/**
 * @brief Infinite loop for receiving messages.
 * 
 * This loop checks for incoming messages and pushes them to the SafeQueue.
 */
void NetworkServer::receiveLoop()
{
    std::vector<uint8_t> buffer(7910);
    asio::ip::udp::endpoint senderEndpoint;

    while (running) {
        try {
            if (socket.available() > 0) {
                size_t length = socket.receive_from(asio::buffer(buffer), senderEndpoint);
                std::string client_id = senderEndpoint.address().to_string() + ":" + std::to_string(senderEndpoint.port());

                if (destinations.find(client_id) == destinations.end()) {
                    destinations[client_id] = senderEndpoint;
                }
                buffer.resize(length);
                messageQueue.push(std::make_pair(client_id, buffer));
                buffer.resize(7910);
            } else {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        } catch (const std::exception& e) {
            if (running) {
                std::cerr << "Receive error: " << e.what() << std::endl;
            }
        }
    }
}

/**
 * @brief Sends a message to all known destinations.
 * 
 * @param message The message to send as a vector of bytes.
 */
void NetworkServer::sendMessage(const std::vector<uint8_t>& message)
{
    try {
        for (const auto& [id, endpoint] : destinations) {
            socket.send_to(asio::buffer(message), endpoint);
        }
    } catch (const std::exception& e) {
        std::cerr << "Send error: " << e.what() << std::endl;
    }
}

/**
 * @brief Get the message queue associated with the server.
 * 
 * @return A reference to the SafeQueue of received messages.
 */
SafeQueue<std::pair<std::string, std::vector<uint8_t>>>& NetworkServer::getMessageQueue()
{
    return messageQueue;
}

/**
 * @brief Get the number of clients connected to the server.
 * 
 * @return The number of clients.
 */
std::size_t NetworkServer::getNumberOfClients()
{
    return destinations.size();
}

/**
 * @brief Get the client IDs of all connected clients.
 * 
 * @return A vector of strings containing the client IDs.
 */

std::vector<std::string> NetworkServer::getClientIds() const
{
    std::vector<std::string> client_ids;
    for (const auto& [id, endpoint] : destinations) {
        client_ids.push_back(id);
    }
    return client_ids;
}

void NetworkServer::createLobby(const std::string& lobby_id)
{
    if (lobbies.find(lobby_id) == lobbies.end()) {
        lobbies.emplace(lobby_id, Lobby(lobby_id));
    }
}

void NetworkServer::deleteLobby(const std::string& lobby_id)
{
    lobbies.erase(lobby_id);
}

bool NetworkServer::joinLobby(const std::string& lobby_id, const std::string& client_id)
{
    auto it = lobbies.find(lobby_id);
    if (it != lobbies.end()) {
        return it->second.addClient(client_id);
    }
    return false;
}

void NetworkServer::leaveLobby(const std::string& lobby_id, const std::string& client_id)
{
    auto it = lobbies.find(lobby_id);
    if (it != lobbies.end()) {
        it->second.removeClient(client_id);
        if (it->second.isEmpty()) {
            lobbies.erase(it);
        }
    }
}

void NetworkServer::broadCastLobby(std::string& lobby_id, const std::vector<uint8_t>& message)
{
    try {
        auto it = lobbies.find(lobby_id);
        if (it != lobbies.end()) {
            for (const auto& client_id : it->second.clients) {
                socket.send_to(asio::buffer(message), destinations[client_id]);
            }
        } else {
            std::cerr << "Lobby not found: " << lobby_id << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Send error: " << e.what() << std::endl;
    }
}
