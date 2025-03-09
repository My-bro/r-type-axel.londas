/*
** EPITECH PROJECT, 2024
** bsrtype
** File description:
** Velocity
*/

#include "Velocity.hpp"

Velocity::Velocity(int dx, int dy) : _dx{dx}, _dy{dy} {}

int Velocity::getDX() const
{
    return this->_dx;
}

int Velocity::getDY() const
{
    return this->_dy;
}

void Velocity::setDX(int dx)
{
    this->_dx = dx;
}

void Velocity::setDY(int dy)
{
    this->_dy = dy;
}
