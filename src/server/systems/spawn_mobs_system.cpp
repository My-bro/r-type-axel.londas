/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** spawn_mobs_system
*/

#include <ecs/Registry.hpp>
#include "../components/Mob.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../components/Health.hpp"
#include "../components/HitBox.hpp"
#include "../components/ShootCooldown.hpp"
#include "../components/Drawable.hpp"
#include <random>

void spawn_mobs_system(Registry &reg)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> y_dist(0, 1079);
    static std::uniform_int_distribution<int> x_dist(960, 1920);
    static std::uniform_real_distribution<double> random_cooldown_dist(0.0, 5.0);

    for (int i = 0; i < 2; i++) {
        int random_y = y_dist(gen);
        int random_x = x_dist(gen);
        double random_cooldown = random_cooldown_dist(gen);
        auto mob = reg.spawn_entity();
        reg.add_component(mob, Mob());
        reg.add_component(mob, Position(random_x, random_y));
        reg.add_component(mob, Velocity(10, 10));
        reg.add_component(mob, Health(100));
        reg.add_component(mob, HitBox(50));
        reg.add_component(mob, ShootCooldown(2, random_cooldown));
        reg.add_component(mob, Drawable("src/server/assets/mob.png"));
    }
}
