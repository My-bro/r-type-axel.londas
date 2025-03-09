/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** HitBox - A class that represents a circular hitbox for collision detection.
*/

#ifndef HITBOX_HPP_
#define HITBOX_HPP_

/**
 * @class HitBox
 * @brief Represents a circular hitbox for collision detection.
 *
 * The HitBox class is used to define a circular area (hitbox) around an entity,
 * typically for collision detection in games. The radius determines the size
 * of the hitbox.
 */
class HitBox {
    public:
        /**
         * @brief Construct a new HitBox object
         */
        HitBox(float width, float height);

        /**
         * @brief Get the width of the hitbox.
         * @return The width of the hitbox.
         */
        float getWidth() const;

        /**
         * @brief Get the height of the hitbox.
         * @return The height of the hitbox.
         */
        float getHeight() const;

    private:
        float _width;
        float _height;
};

#endif /* !HITBOX_HPP_ */
