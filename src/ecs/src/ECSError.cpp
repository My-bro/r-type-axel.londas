/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Error
*/

#include <ecs/ECSError.hpp>

ECSError::ECSError(std::string message)
{
    this->_message = message;
}

const char *ECSError::what() const throw()
{
    return this->_message.c_str();
}

SparseArrayError::SparseArrayError(std::string message) : ECSError(message) {}

RegistryError::RegistryError(std::string message) : ECSError(message) {}
