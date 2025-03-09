/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** spawn_turrets_mobs_system
*/

#include <ecs/Registry.hpp>

#include "../components/TurretMob.hpp"
#include "../components/Position.hpp"
#include "../components/ShootCooldown.hpp"
#include "../components/Drawable.hpp"
#include <random>

void spawn_turrets_mobs_system(Registry &r)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> x_dist(50, 710);

    auto entity = r.spawn_entity();
    r.add_component(entity, TurretMob());
    r.add_component(entity, Position(x_dist(gen), 0));
    r.add_component(entity, ShootCooldown(3));
    r.add_component(entity, Drawable("src/server/assets/turret_mob.png"));
}
