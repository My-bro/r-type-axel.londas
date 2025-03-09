/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** spawn_boss_mob
*/

#include <ecs/Registry.hpp>

#include "../components/BossMob.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../components/Health.hpp"
#include "../components/HitBox.hpp"
#include "../components/Drawable.hpp"
#include "../components/ShootCooldown.hpp"

void spawn_boss_mob_system(Registry &r)
{
    auto boss = r.spawn_entity();
    r.add_component(boss, BossMob());
    r.add_component(boss, Position(1700, 540));
    r.add_component(boss, Health(1000));
    r.add_component(boss, HitBox(300));
    r.add_component(boss, ShootCooldown(5));
    r.add_component(boss, Drawable("src/server/assets/boss_mob.png"));
}
