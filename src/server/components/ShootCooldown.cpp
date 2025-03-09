/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** ShootCooldown
*/

#include "ShootCooldown.hpp"

ShootCooldown::ShootCooldown(double cooldown, double initial_cooldown) : _cooldown{cooldown}, _initial_cooldown{initial_cooldown} {}

void ShootCooldown::reset()
{
    this->_timer.reset();
}

bool ShootCooldown::canShoot()
{
    if (!this->_initial_cooldown_passed) {
        this->_initial_cooldown_passed = this->_timer.elapsed() >= this->_initial_cooldown;
        return false;
    }
    return this->_timer.elapsed() >= this->_cooldown;
}
