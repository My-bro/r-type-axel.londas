/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** utils
*/

#include "utils.hpp"

bool circle_collision(const Position& pos1, const HitBox& radius1, const Position& pos2, const HitBox& radius2)
{
    float dx = pos1.getX() - pos2.getX();
    float dy = pos1.getY() - pos2.getY();
    float distanceSquared = dx * dx + dy * dy;
    float radiusSum = radius1.getRadius() + radius2.getRadius();
    return distanceSquared <= radiusSum * radiusSum;
}
