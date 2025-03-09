/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Error - Custom exception classes for handling ECS-related errors.
*/

#ifndef ECSERROR_HPP_
    #define ECSERROR_HPP_

    #include <iostream>
    #include "Export.hpp"

/**
 * @class ECSError
 * @brief Base class for ECS-related exceptions.
 *
 * The ECSError class serves as the base exception class for errors
 * encountered in the Entity Component System (ECS). It provides an error
 * message and overrides the `what` method for descriptive output.
 */
class RTYPE_API ECSError : public std::exception {
    public:
        /**
         * @brief Constructs an ECSError with a given error message.
         * @param message A string describing the error.
         */
        ECSError(std::string message);

        /**
         * @brief Retrieves the error message.
         * @return A const char* containing the error description.
         */
        virtual const char *what() const throw();

    private:
        std::string _message; /**< The error message describing the exception. */
};

/**
 * @class SparseArrayError
 * @brief Exception class for SparseArray-related errors.
 *
 * The SparseArrayError class is derived from ECSError and represents
 * errors specific to SparseArray operations.
 */
class RTYPE_API SparseArrayError : public ECSError {
    public:
        /**
         * @brief Constructs a SparseArrayError with a given error message.
         * @param message A string describing the SparseArray-related error.
         */
        SparseArrayError(std::string message);
};

/**
 * @class RegistryError
 * @brief Exception class for Registry-related errors.
 *
 * The RegistryError class is derived from ECSError and represents errors
 * specific to the ECS Registry operations.
 */
class RTYPE_API RegistryError : public ECSError {
    public:
        /**
         * @brief Constructs a RegistryError with a given error message.
         * @param message A string describing the Registry-related error.
         */
        RegistryError(std::string message);
};

#endif /* !ECSERROR_HPP_ */
