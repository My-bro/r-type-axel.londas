/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     Boss                                                                             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef INCLUDED_BOSS_HPP
    #define INCLUDED_BOSS_HPP

#include <iostream>
#include "Abilities.hpp"

class Boss
{
    private:
        std::string type;
        std::size_t health;
        std::size_t damage;
        Abilities special_ability;
        friend class Stage;
    protected:
    public:
        Boss(std::string type_, std::size_t health_, std::size_t damage_, Abilities special_ability_);
        ~Boss() = default;
};

#endif
