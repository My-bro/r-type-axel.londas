/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Damage
*/

#include "Damage.hpp"

Damage::Damage(int damage) : _damage{damage} {}

int Damage::getDamage() const
{
    return this->_damage;
}
