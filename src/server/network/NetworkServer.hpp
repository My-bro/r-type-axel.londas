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



/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** NetworkServer - A class responsible for managing network communication over UDP.
*/

#ifndef NETWORKSERVER_HPP
    #define NETWORKSERVER_HPP

#include <iostream>
#include <unordered_map>
#include <vector>
#include <asio.hpp>
#include <thread>
#include <atomic>
#include "SafeQueue.hpp"
#include "Lobby.hpp"

/**
 * @class NetworkServer
 * @brief Manages UDP-based network communication for the game server.
 *
 * The NetworkServer class handles network operations, such as sending and receiving messages
 * between the server and connected clients. It maintains client endpoints, message queues, and
 * provides thread-safe access to incoming messages using a SafeQueue.
 */
class NetworkServer {
public:
    /**
     * @brief Constructs a NetworkServer object bound to a specific port.
     * @param port The port number the server listens on for incoming connections.
     */
    NetworkServer(unsigned short port);

    /**
     * @brief Destructor to clean up resources.
     * Stops the server and joins the receive thread if running.
     */
    ~NetworkServer();

    /**
     * @brief Starts the server.
     * Begins listening for incoming messages and spawns the receive loop in a separate thread.
     */
    void start();

    /**
     * @brief Stops the server.
     * Terminates the receive loop and closes the socket.
     */
    void stop();

    /**
     * @brief Sends a message to all connected clients.
     * @param message A vector of bytes representing the message to be sent.
     */
    void sendMessage(const std::vector<uint8_t>& message);

    /**
     * @brief Sends a message to all connected clients in a lobby.
     * @param message A vector of bytes representing the message to be sent.
     */
    void broadCastLobby(std::string& lobby_id, const std::vector<uint8_t>& message);

    /**
     * @brief Retrieves the list of connected client IDs.
     * @return A vector of strings representing the client IDs.
     */
    std::vector<std::string> getClientIds() const;

    /**
     * @brief Provides access to the message queue containing received messages.
     * @return A reference to the SafeQueue of received messages.
     */
    SafeQueue<std::pair<std::string, std::vector<uint8_t>>>& getMessageQueue();

    /**
     * @brief Retrieves the number of currently connected clients.
     * @return The number of connected clients as a std::size_t.
     */
    std::size_t getNumberOfClients();

    /**
     * @brief Create a lobby.
     */
    void createLobby(const std::string& lobby_id);

    /**
     * @brief Delete a lobby.
     */
    void deleteLobby(const std::string& lobby_id);

    /**
     * @brief Make a client join a lobby.
     * @return True if success False otherwise.
     */
    bool joinLobby(const std::string& lobby_id, const std::string& client_id);

    /**
     * @brief Make a client leave a lobby.
     * @return True if success False otherwise.
     */
    void leaveLobby(const std::string& lobby_id, const std::string& client_id);

private:
    /**
     * @brief Continuously listens for incoming messages in a separate thread.
     * Processes and adds received messages to the message queue.
     */
    void receiveLoop();

    asio::io_context io_context; /**< The ASIO context used for managing I/O operations. */
    asio::ip::udp::socket socket; /**< The UDP socket for sending and receiving data. */
    unsigned short port; /**< The port number the server is bound to. */
    std::unordered_map<std::string, asio::ip::udp::endpoint> destinations; /**< A map of client IDs to their network endpoints. */
    SafeQueue<std::pair<std::string, std::vector<uint8_t>>> messageQueue; /**< A thread-safe queue for storing received messages. */
    std::thread receiveThread; /**< A separate thread for handling incoming messages. */
    std::atomic<bool> running; /**< A flag indicating whether the server is currently running. */
    std::unordered_map<std::string, Lobby> lobbies; /**< The lobbies created. */
};

#endif // NETWORKSERVER_HPP
