/*
** EPITECH PROJECT, 2024
** bsrtype
** File description:
** Controllable - A class that represents a controllable entity with directional inputs and a shoot state.
*/

#ifndef CONTROLLABLE_HPP_
    #define CONTROLLABLE_HPP_

    #include <string>

/**
 * @class Controllable
 * @brief Represents a controllable entity with directional movement and shooting capability.
 *
 * The Controllable class provides methods to manage directional inputs (up, down, left, right)
 * and a shoot action. It allows toggling these states and checking their current status.
 */
class Controllable {
    public:
        /**
         * @brief Default constructor.
         * Initializes all control states to false.
         */
        Controllable();

        /**
         * @brief Resets all control states to false.
         */
        void setAllFalse();

        /**
         * @brief Sets the state of the "up" input.
         * @param state True to enable, false to disable.
         */
        void setUp(bool state);

        /**
         * @brief Sets the state of the "down" input.
         * @param state True to enable, false to disable.
         */
        void setDown(bool state);

        /**
         * @brief Sets the state of the "left" input.
         * @param state True to enable, false to disable.
         */
        void setLeft(bool state);

        /**
         * @brief Sets the state of the "right" input.
         * @param state True to enable, false to disable.
         */
        void setRight(bool state);

        /**
         * @brief Sets the state of the "shoot" input.
         * @param state True to enable shooting, false to disable.
         */
        void setShoot(bool state);

        /**
         * @brief Checks if the "up" input is active.
         * @return True if "up" is active, false otherwise.
         */
        bool isUp() const;

        /**
         * @brief Checks if the "down" input is active.
         * @return True if "down" is active, false otherwise.
         */
        bool isDown() const;

        /**
         * @brief Checks if the "left" input is active.
         * @return True if "left" is active, false otherwise.
         */
        bool isLeft() const;

        /**
         * @brief Checks if the "right" input is active.
         * @return True if "right" is active, false otherwise.
         */
        bool isRight() const;

        /**
         * @brief Checks if the shooting state is active.
         * @return True if shooting is active, false otherwise.
         */
        bool isShooting() const;

    protected:
    private:
        bool _up = false;    /**< State of the "up" input. */
        bool _down = false;  /**< State of the "down" input. */
        bool _left = false;  /**< State of the "left" input. */
        bool _right = false; /**< State of the "right" input. */
        bool _shoot = false; /**< State of the "shoot" input. */
};

#endif /* !CONTROLLABLE_HPP_ */
