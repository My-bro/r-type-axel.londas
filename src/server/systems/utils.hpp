/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** utils
*/

#ifndef UTILS_HPP_
    #define UTILS_HPP_

    #include "../components/Position.hpp"
    #include "../components/HitBox.hpp"

bool circle_collision(const Position& pos1, const HitBox& radius1, const Position& pos2, const HitBox& radius2);

#endif /* !UTILS_HPP_ */
