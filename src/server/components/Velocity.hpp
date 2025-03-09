/*
** EPITECH PROJECT, 2024
** bsrtype
** File description:
** Velocity - A class representing the velocity (directional movement) of an object.
*/

#ifndef VELOCITY_HPP_
    #define VELOCITY_HPP_

    #include <cstddef>

/**
 * @class Velocity
 * @brief Represents the velocity (directional movement) of an object.
 *
 * The Velocity class provides methods to manage and retrieve the horizontal
 * and vertical velocity components of an object in motion. These components
 * are represented as integers (delta X and delta Y).
 */
class Velocity {
    public:
        /**
         * @brief Constructs a Velocity object with specified horizontal and vertical velocities.
         * @param dx The horizontal velocity (delta X).
         * @param dy The vertical velocity (delta Y).
         */
        Velocity(int dx, int dy);

        /**
         * @brief Retrieves the horizontal velocity (delta X).
         * @return The horizontal velocity as an integer.
         */
        int getDX() const;

        /**
         * @brief Retrieves the vertical velocity (delta Y).
         * @return The vertical velocity as an integer.
         */
        int getDY() const;

        /**
         * @brief Updates the horizontal velocity (delta X).
         * @param dx The new horizontal velocity.
         */
        void setDX(int dx);

        /**
         * @brief Updates the vertical velocity (delta Y).
         * @param dy The new vertical velocity.
         */
        void setDY(int dy);

    private:
        int _dx; /**< The horizontal velocity component (delta X). */
        int _dy; /**< The vertical velocity component (delta Y). */
};

#endif /* !VELOCITY_HPP_ */
