/*
** EPITECH PROJECT, 2024
** bsrtype
** File description:
** Position - A class representing a 2D position with X and Y coordinates.
*/

#ifndef POSITION_HPP_
    #define POSITION_HPP_

    #include <cstddef>

/**
 * @class Position
 * @brief Represents a 2D position with X and Y coordinates.
 *
 * The Position class provides methods to manage and retrieve the X and Y
 * coordinates of an object in a 2D space. It allows updating and accessing
 * these coordinates individually.
 */
class Position {
    public:
        /**
         * @brief Constructs a Position object with specified X and Y coordinates.
         * @param x The X coordinate.
         * @param y The Y coordinate.
         */
        Position(int x, int y);

        /**
         * @brief Retrieves the X coordinate.
         * @return The X coordinate as an integer.
         */
        int getX() const;

        /**
         * @brief Retrieves the Y coordinate.
         * @return The Y coordinate as an integer.
         */
        int getY() const;

        /**
         * @brief Updates the X coordinate.
         * @param x The new X coordinate.
         */
        void setX(int x);

        /**
         * @brief Updates the Y coordinate.
         * @param y The new Y coordinate.
         */
        void setY(int y);

    private:
        int _x; /**< The X coordinate of the position. */
        int _y; /**< The Y coordinate of the position. */
};

#endif /* !POSITION_HPP_ */
