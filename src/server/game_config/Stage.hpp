/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     Stage                                                                            *
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

#ifndef INCLUDED_STAGE_HPP
    #define INCLUDED_STAGE_HPP

#include <iostream>
#include "Mobs.hpp"
#include "Boss.hpp"
#include <vector>
#include <optional>

class Stage
{
    private:
        std::size_t number;
        std::optional<Boss> boss;
        std::vector<Mobs> mobs;
        friend class GameParsing;
    protected:
    public:
        Stage(std::size_t number_, std::optional<Boss> boss_, std::vector<Mobs> mobs_);
        ~Stage() = default;
};

#endif
