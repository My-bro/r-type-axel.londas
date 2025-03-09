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

#include "GameParsing.hpp"

GameParsing::GameParsing()
{
    // Default constructor
}

std::optional<Boss> GameParsing::createBoss(YAML::Node boss_node, YAML::detail::iterator_value stage_node)
{
    if (stage_node["boss"] && !stage_node["boss"].IsNull()) {
        std::string boss_type = boss_node["type"].as<std::string>();
        std::size_t boss_health = boss_node["health"].as<std::size_t>();
        std::size_t boss_damage = boss_node["damage"].as<std::size_t>();
        std::vector<Abilities> boss_abilities;
        for (const auto& ability_node : boss_node["special_abilities"]) {
            std::string ability_name = ability_node["name"].as<std::string>();
            std::string ability_effect = ability_node["effect"].as<std::string>();
            std::size_t ability_cooldown = ability_node["cooldown"].as<std::size_t>();
            boss_abilities.emplace_back(ability_name, ability_effect, ability_cooldown);
        }
        Abilities special_ability = boss_abilities.empty() ? Abilities("", "", 0) : boss_abilities[0];
        Boss boss(boss_type, boss_health, boss_damage, special_ability);
        return boss;
    }
    return std::nullopt;
}

std::vector<Mobs> GameParsing::createMobs(YAML::detail::iterator_value stage_node)
{
    std::vector<Mobs> mobs_list;
    for (const auto& mob_node : stage_node["mobs"]) {
        std::string mob_type = mob_node["type"].as<std::string>();
        std::size_t mob_number = mob_node["number"].as<std::size_t>();
        std::size_t mob_health = mob_node["health"].as<std::size_t>();
        std::size_t mob_damage = mob_node["damage"].as<std::size_t>();
        mobs_list.emplace_back(mob_number, mob_type, mob_health, mob_damage);
    }
    return mobs_list;
}

std::vector<Stage> GameParsing::parseStages(const std::string& filePath) {
    std::vector<Stage> parsedStages;
    try {
        YAML::Node root = YAML::LoadFile(filePath);
        for (const auto& stage_node : root["stages"]) {
            std::size_t number = stage_node["stage"].as<std::size_t>();
            std::optional<Boss> boss = createBoss(stage_node["boss"], stage_node);
            std::vector<Mobs> mobs_list = createMobs(stage_node);
            Stage stage(number, boss, mobs_list);
            parsedStages.push_back(stage);
        }
    } catch (const YAML::Exception& e) {
        std::cerr << "Error parsing YAML: " << e.what() << std::endl;
    }
    return parsedStages;
}
