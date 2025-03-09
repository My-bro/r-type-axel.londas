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
         * @brief Constructs a HitBox object with a specified radius.
         * @param radius The radius of the hitbox.
         */
        HitBox(float radius);

        /**
         * @brief Retrieves the radius of the hitbox.
         * @return The radius as a floating-point value.
         */
        float getRadius() const;

    private:
        float _radius; /**< The radius of the circular hitbox. */
};

#endif /* !HITBOX_HPP_ */
