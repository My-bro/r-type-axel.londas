/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Entity
*/

#include <ecs/Entity.hpp>

Entity::Entity(std::size_t id) : _id(id) {}

Entity::operator std::size_t() const
{
    return _id;
}
