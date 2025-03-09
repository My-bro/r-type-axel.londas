/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** HitBox
*/

#include "HitBox.hpp"

HitBox::HitBox(float radius) : _radius(radius) {}

float HitBox::getRadius() const
{
    return _radius;
}
