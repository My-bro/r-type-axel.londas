/*
** EPITECH PROJECT, 2024
** bsrtype
** File description:
** Position
*/

#include "Position.hpp"

Position::Position(int x, int y) : _x{x}, _y{y} {}

int Position::getX() const
{
    return this->_x;
}

int Position::getY() const
{
    return this->_y;
}

void Position::setX(int x)
{
    this->_x = x;
}

void Position::setY(int y)
{
    this->_y = y;
}
