/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Thu, Nov, 2024                                                     *
 * Title           - R-type                                                             *
 * Description     -                                                                    *
 *     Error                                                                            *
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
 * @file Error.cpp
 * @brief Implementation of the Error hierarchy for managing exceptions in the server.
 */

#include "Error.hpp"

/**
 * @brief Default constructor for the base Error class.
 */
Error::Error() = default;

/**
 * @brief Default destructor for the base Error class.
 */
Error::~Error() = default;

/**
 * @brief Constructor for the ServerWrongSocket class.
 * 
 * This exception is thrown when the server cannot connect to a socket.
 */
ServerWrongSocket::ServerWrongSocket() : Error() {}

/**
 * @brief Destructor for the ServerWrongSocket class.
 */
ServerWrongSocket::~ServerWrongSocket() = default;

/**
 * @brief Returns an error message indicating the socket connection failure.
 * 
 * @return A C-string describing the error.
 */
const char* ServerWrongSocket::what() const noexcept {
    return "Couldn't connect to the socket.";
}

/**
 * @brief Constructor for the ServerWrongSend class.
 * 
 * This exception is thrown when the server cannot send a message.
 */
ServerWrongSend::ServerWrongSend() : Error() {}

/**
 * @brief Destructor for the ServerWrongSend class.
 */
ServerWrongSend::~ServerWrongSend() = default;

/**
 * @brief Returns an error message indicating the message send failure.
 * 
 * @return A C-string describing the error.
 */
const char* ServerWrongSend::what() const noexcept {
    return "Couldn't send a message to the client.";
}

/**
 * @brief Constructor for the ServerWrongReceive class.
 * 
 * This exception is thrown when the server cannot receive a message.
 */
ServerWrongReceive::ServerWrongReceive() : Error() {}

/**
 * @brief Destructor for the ServerWrongReceive class.
 */
ServerWrongReceive::~ServerWrongReceive() = default;

/**
 * @brief Returns an error message indicating the message receive failure.
 * 
 * @return A C-string describing the error.
 */
const char* ServerWrongReceive::what() const noexcept {
    return "Couldn't receive a message from the client.";
}

/**
 * @brief Overloaded stream insertion operator for Error objects.
 * 
 * Writes the error message to the provided output stream.
 * 
 * @param os The output stream to write to.
 * @param error The Error object to output.
 * @return A reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const Error& error)
{
    os << error.what();
    return os;
}
