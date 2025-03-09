/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Fri, Nov, 2024                                                     *
 * Title           - R-type                                                             *
 * Description     -                                                                    *
 *     NetworkClient                                                                    *
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

#ifndef INCLUDED_NETWORKCLIENT_HPP
    #define INCLUDED_NETWORKCLIENT_HPP
    #define BUFFER_SIZE 7910

#include <iostream>
#include <asio.hpp>
#include "../Error/Error.hpp"
#include <memory>

/**
 * @class NetworkClient
 * @brief A class to handle client-side UDP networking functionalities.
 *
 * This class manages sending and receiving messages over a UDP socket as a client using ASIO.
 */
class NetworkClient {
private:
    /**
     * @brief ASIO I/O context for managing asynchronous operations.
     */
    asio::io_context io_context;

    /**
     * @brief UDP socket used for communication.
     */
    asio::ip::udp::socket socket;

    /**
     * @brief Port number on which the client communicates.
     */
    unsigned short port;

    /**
     * @brief Host address for the destination server.
     */
    const std::string host;

    /**
     * @brief Destination endpoint for sending messages.
     */
    asio::ip::udp::endpoint destination;

protected:

public:
    // = operators
    NetworkClient& operator=(const NetworkClient&) {
        return *this;
    };

    NetworkClient()
    : io_context(),
    socket(io_context)
    {
        // Intentionally empty
    }

    /**
     * @brief Constructor that initializes the client with a specified port and host.
     * @param port_ The port number to use for communication.
     * @param host_ The host address of the server.
     */
    NetworkClient(unsigned short port_, const std::string& host_);


    /**
     * @brief Destructor to clean up resources.
     */
    ~NetworkClient();

    /**
     * @brief Sends a message to the destination server.
     * @param message The message to send.
     */
    void sendMessage(std::vector<uint8_t> message);

    /**
     * @brief Receives a message from the server.
     * @return A string containing the received message.
     */
    std::vector<uint8_t> receiveMessage();
};

#endif
