/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Thu, Nov, 2024                                                     *
 * Title           - R-type                                                             *
 * Description     -                                                                    *
 *     Error                                                                            *
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

#ifndef INCLUDED_ERROR_HPP
    #define INCLUDED_ERROR_HPP
    #include <iostream>
    #include <stdexcept>

/**
 * @class Error
 * @brief Base class for custom exception handling.
 *
 * This class serves as a base for specific error types. It inherits from std::exception
 * and requires derived classes to implement the what() method.
 */
class Error : public std::exception {
public:
    /**
     * @brief Default constructor.
     */
    Error();

    /**
     * @brief Virtual destructor.
     */
    virtual ~Error();

    /**
     * @brief Pure virtual method to return the error message.
     * @return A C-style string describing the error.
     */
    virtual const char* what() const noexcept override = 0;

protected:

private:
};

/**
 * @class ServerWrongSocket
 * @brief Exception for handling socket-related server errors.
 *
 * This class is derived from the Error base class and represents an error
 * occurring when there is a problem with the server socket.
 */
class ServerWrongSocket : public Error {
public:
    /**
     * @brief Default constructor.
     */
    ServerWrongSocket();

    /**
     * @brief Destructor.
     */
    ~ServerWrongSocket();

    /**
     * @brief Returns the error message for the socket error.
     * @return A C-style string describing the socket error.
     */
    const char* what() const noexcept override;

private:

protected:
};

/**
 * @class ServerWrongSend
 * @brief Exception for handling errors during server send operations.
 *
 * This class is derived from the Error base class and represents an error
 * occurring when there is an issue sending data from the server.
 */
class ServerWrongSend : public Error {
public:
    /**
     * @brief Default constructor.
     */
    ServerWrongSend();

    /**
     * @brief Destructor.
     */
    ~ServerWrongSend();

    /**
     * @brief Returns the error message for the send error.
     * @return A C-style string describing the send error.
     */
    const char* what() const noexcept override;

private:

protected:
};

/**
 * @class ServerWrongReceive
 * @brief Exception for handling errors during server receive operations.
 *
 * This class is derived from the Error base class and represents an error
 * occurring when there is an issue receiving data on the server.
 */
class ServerWrongReceive : public Error {
public:
    /**
     * @brief Default constructor.
     */
    ServerWrongReceive();

    /**
     * @brief Destructor.
     */
    ~ServerWrongReceive();

    /**
     * @brief Returns the error message for the receive error.
     * @return A C-style string describing the receive error.
     */
    const char* what() const noexcept override;

private:

protected:
};

/**
 * @brief Overload of the stream insertion operator for Error.
 *
 * Allows printing the error message of an Error or derived class using an output stream.
 * @param os The output stream.
 * @param error The Error object.
 * @return The output stream.
 */
std::ostream& operator<<(std::ostream& os, const Error& error);

#endif
