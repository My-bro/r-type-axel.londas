/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** spawn_healths_collectables_system
*/

#include <ecs/Registry.hpp>
#include <random>

#include "../components/HealthCollectable.hpp"
#include "../components/Position.hpp"
#include "../components/Drawable.hpp"
#include "../components/HitBox.hpp"
#include "../components/Health.hpp"

void spawn_health_collectables_system(Registry &r)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> x_dist(50, 710);
    static std::uniform_int_distribution<int> y_dist(50, 1030);

    static auto last_spawn_time = std::chrono::steady_clock::now();
    auto current_time = std::chrono::steady_clock::now();

    static int spawn_interval = 10;

    if (std::chrono::duration_cast<std::chrono::seconds>(current_time - last_spawn_time).count() >= spawn_interval) {
        last_spawn_time = current_time;
        spawn_interval = 120;
        auto entity = r.spawn_entity();
        r.add_component(entity, HealthCollectable());
        r.add_component(entity, Position(x_dist(gen), y_dist(gen)));
        r.add_component(entity, HitBox(25));
        r.add_component(entity, Drawable("src/server/assets/health_collectable.png"));
        r.add_component(entity, Health(100));
    }
}
