/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Fri, Nov, 2024                                                     *
 * Title           - R-type                                                             *
 * Description     -                                                                    *
 *     NetworkClient                                                                    *
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

/**
 * @file NetworkClient.cpp
 * @brief Implementation of the NetworkClient class for managing a UDP network client.
 */

#include "NetworkClient.hpp"

/**
 * @brief Constructs a new NetworkClient object.
 *
 * Opens a UDP socket, binds it, and initializes the destination endpoint.
 *
 * @param port_ The port to connect to on the server.
 * @param host_ The server's IP address or hostname.
 * @throw ClientWrongSocket Thrown if the socket cannot be opened or bound.
 */
NetworkClient::NetworkClient(unsigned short port_, const std::string& host_) : io_context(), socket(io_context), port(port_), host(host_)
{
    try {
        socket.open(asio::ip::udp::v4());
        socket.bind(asio::ip::udp::endpoint(asio::ip::udp::v4(), 0));
        destination = asio::ip::udp::endpoint(asio::ip::make_address(host), port);
    } catch (const std::exception& e) {
        throw ClientWrongSocket();
    }
}

/**
 * @brief Destroys the NetworkClient object.
 *
 * Closes the socket if it is open and outputs a shutdown message.
 */
NetworkClient::~NetworkClient()
{
    try
    {
        if (socket.is_open()) {
            socket.close();
        }
        std::cout << "NetworkClient détruit, socket fermé." << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << ClientWrongSocket() << std::endl;
        std::cerr << "Fermeture du Client" << std::endl;
    }
}

/**
 * @brief Sends a message to the server.
 *
 * @param message The message to send as a string.
 * @throw ClientWrongSend Thrown if the message cannot be sent.
 */
void NetworkClient::sendMessage(std::vector<uint8_t> message)
{
    try
    {
        socket.send_to(asio::buffer(message), destination);
    }
    catch(const std::exception& e)
    {
        std::cerr << ClientWrongSend() << '\n';
    }
}

/**
 * @brief Receives a message from the server.
 *
 * @return A string containing the received message.
 * @throw ClientWrongReceive Thrown if the message cannot be received.
 */
std::vector<uint8_t> NetworkClient::receiveMessage()
{
    try
    {
        std::vector<uint8_t> buffer(BUFFER_SIZE);
        size_t bytes_received = socket.receive_from(asio::buffer(buffer), destination);
        if (bytes_received > 0) {
            buffer.resize(bytes_received);
            return buffer;
        } else {
            throw ClientWrongReceive();
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << ClientWrongReceive() << '\n';
        return std::vector<uint8_t>();
    }
}
