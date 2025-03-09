/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** spawn_mob_turrets_level_2
*/

#include <ecs/Registry.hpp>

#include "../components/TurretMob.hpp"
#include "../components/Position.hpp"
#include "../components/ShootCooldown.hpp"
#include "../components/Drawable.hpp"
#include <random>

void spawn_turrets_mobs_level_2_system(Registry &r)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::vector<std::pair<int, int>> spawn_positions = {
        {758, 0},
        {758, 1080},
    };
    for (const auto& [x, y] : spawn_positions) {
        auto entity = r.spawn_entity();
        r.add_component(entity, TurretMob());
        r.add_component(entity, Position(x, y));
        r.add_component(entity, ShootCooldown(5));
        r.add_component(entity, Drawable("src/server/assets/turret_mob.png"));
    }
}
