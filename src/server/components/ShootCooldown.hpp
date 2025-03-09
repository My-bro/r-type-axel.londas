/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** ShootCooldown - A class managing the shooting cooldown for entities.
*/

#ifndef SHOOTCOOLDOWN_HPP_
    #define SHOOTCOOLDOWN_HPP_

    #include <chrono>
    #include "../Timer.hpp"

/**
 * @class ShootCooldown
 * @brief Manages the cooldown period between consecutive shots.
 *
 * The ShootCooldown class provides functionality to handle the delay (cooldown)
 * between consecutive shots fired by an entity. It tracks both the standard
 * cooldown and an optional initial cooldown before shooting becomes available.
 */
class ShootCooldown {
    public:
        /**
         * @brief Constructs a ShootCooldown object.
         * @param cooldown The cooldown duration between shots in seconds.
         * @param initial_cooldown An optional initial cooldown before the first shot.
         */
        ShootCooldown(double cooldown, double initial_cooldown = 0);

        /**
         * @brief Resets the cooldown timer.
         *
         * This method resets the internal timer, indicating that a shot has been fired.
         */
        void reset();

        /**
         * @brief Checks if the entity can shoot.
         * @return True if the cooldown period has passed, false otherwise.
         */
        bool canShoot();

    private:
        Timer _timer = Timer();             /**< Internal timer to track cooldown duration. */
        double _cooldown;                   /**< Standard cooldown duration between shots. */
        double _initial_cooldown;           /**< Initial cooldown duration before shooting starts. */
        bool _initial_cooldown_passed = false; /**< Indicates whether the initial cooldown has passed. */
};

#endif /* !SHOOTCOOLDOWN_HPP_ */
