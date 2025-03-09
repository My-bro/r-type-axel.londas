/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** Pipe
*/

#include "Pipe.hpp"

Pipe::Pipe(Type type) : _type{type} {}


Pipe::Type Pipe::getType() const
{
    return this->_type;
}
