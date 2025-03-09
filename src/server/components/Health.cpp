/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Health
*/

#include "Health.hpp"

Health::Health(int health) : _health(health) {}

int Health::getHealth() const
{
    return this->_health;
}

void Health::setHealth(int health)
{
    this->_health = health;
}
