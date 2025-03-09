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
 * @brief Implementation of the Error hierarchy for managing client-side exceptions.
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
 * @brief Constructor for the ClientWrongSocket class.
 * 
 * This exception is thrown when the client cannot connect to a socket.
 */
ClientWrongSocket::ClientWrongSocket() : Error() {}

/**
 * @brief Destructor for the ClientWrongSocket class.
 */
ClientWrongSocket::~ClientWrongSocket() = default;

/**
 * @brief Returns an error message indicating the socket connection failure.
 * 
 * @return A C-string describing the error.
 */
const char* ClientWrongSocket::what() const noexcept {
    return "Couldn't connect to the socket.";
}

/**
 * @brief Constructor for the ClientWrongSend class.
 * 
 * This exception is thrown when the client cannot send a message.
 */
ClientWrongSend::ClientWrongSend() : Error() {}

/**
 * @brief Destructor for the ClientWrongSend class.
 */
ClientWrongSend::~ClientWrongSend() = default;

/**
 * @brief Returns an error message indicating the message send failure.
 * 
 * @return A C-string describing the error.
 */
const char* ClientWrongSend::what() const noexcept {
    return "Couldn't send a message to the Server.";
}

/**
 * @brief Constructor for the ClientWrongReceive class.
 * 
 * This exception is thrown when the client cannot receive a message.
 */
ClientWrongReceive::ClientWrongReceive() : Error() {}

/**
 * @brief Destructor for the ClientWrongReceive class.
 */
ClientWrongReceive::~ClientWrongReceive() = default;

/**
 * @brief Returns an error message indicating the message receive failure.
 * 
 * @return A C-string describing the error.
 */
const char* ClientWrongReceive::what() const noexcept {
    return "Couldn't receive a message from the Server.";
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