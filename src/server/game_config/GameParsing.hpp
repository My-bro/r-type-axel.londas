/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     GameParsing                                                                      *
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

#ifndef INCLUDED_GAMEPARSING_HPP
    #define INCLUDED_GAMEPARSING_HPP

#include <iostream>
#include "Stage.hpp"
#include <optional>
#include <yaml-cpp/yaml.h>

class GameParsing
{
    private:
        std::vector<Stage> stages;
    protected:
    public:
        GameParsing();
        ~GameParsing() = default;

        std::vector<Stage> parseStages(const std::string& filePath);
        std::optional<Boss> createBoss(YAML::Node boss_node, YAML::detail::iterator_value stage_node);
        std::vector<Mobs> createMobs(YAML::detail::iterator_value stage_node);
};

#endif
