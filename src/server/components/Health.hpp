/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Health - A class that represents the health state of an entity.
*/

#ifndef HEALTH_HPP_
    #define HEALTH_HPP_

    #include <cstddef>

/**
 * @class Health
 * @brief Represents the health state of an entity.
 *
 * The Health class provides methods to manage the health value of an entity.
 * It allows retrieving and updating the current health value.
 */
class Health {
    public:
        /**
         * @brief Constructs a Health object with a specified initial health value.
         * @param health The initial health value.
         */
        Health(int health);

        /**
         * @brief Retrieves the current health value.
         * @return The current health as an integer.
         */
        int getHealth() const;

        /**
         * @brief Updates the health value.
         * @param health The new health value to set.
         */
        void setHealth(int health);

    private:
        int _health; /**< The current health value of the entity. */
};

#endif /* !HEALTH_HPP_ */
