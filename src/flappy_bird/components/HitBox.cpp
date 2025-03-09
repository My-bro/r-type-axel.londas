/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** HitBox
*/

#include "HitBox.hpp"

HitBox::HitBox(float width, float height) : _width(width), _height(height) {}


float HitBox::getWidth() const
{
    return this->_width;
}

float HitBox::getHeight() const
{
    return this->_height;
}
