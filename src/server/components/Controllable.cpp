/*
** EPITECH PROJECT, 2024
** bsrtype
** File description:
** Controllable
*/

#include "Controllable.hpp"

Controllable::Controllable() {}

void Controllable::setAllFalse()
{
    this->_up = false;
    this->_down = false;
    this->_left = false;
    this->_right = false;
    this->_shoot = false;
}

void Controllable::setUp(bool state)
{
    this->_up = state;
}

void Controllable::setDown(bool state)
{
    this->_down = state;
}

void Controllable::setLeft(bool state)
{
    this->_left = state;
}

void Controllable::setRight(bool state)
{
    this->_right = state;
}

void Controllable::setShoot(bool state)
{
    this->_shoot = state;
}

bool Controllable::isUp() const
{
    return this->_up;
}

bool Controllable::isDown() const
{
    return this->_down;
}

bool Controllable::isLeft() const
{
    return this->_left;
}

bool Controllable::isRight() const
{
    return this->_right;
}

bool Controllable::isShooting() const
{
    return this->_shoot;
}
