/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Damage - A class that represents damage dealt in the game.
*/

#ifndef DAMAGE_HPP_
    #define DAMAGE_HPP_

    #include <cstddef>

/**
 * @class Damage
 * @brief Represents damage dealt in the game.
 *
 * The Damage class provides a way to store and retrieve the amount of damage
 * an entity can inflict. It encapsulates the damage value in a private member.
 */
class Damage {
    public:
        /**
         * @brief Constructs a Damage object with a specified amount of damage.
         * @param damage The amount of damage to be dealt.
         */
        Damage(int damage);

        /**
         * @brief Retrieves the damage value.
         * @return The amount of damage.
         */
        int getDamage() const;

    protected:
    private:
        int _damage; /**< The amount of damage this object represents. */
};

#endif /* !DAMAGE_HPP_ */
