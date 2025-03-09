/*
** EPITECH PROJECT, 2024
** bsrtype
** File description:
** Drawable
*/

#include "Drawable.hpp"

Drawable::Drawable(std::string path) : _path{path} {}

std::string Drawable::getPath() const
{
    return this->_path;
}
