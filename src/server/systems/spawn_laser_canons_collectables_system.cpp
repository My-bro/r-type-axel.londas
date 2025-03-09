/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** spawn_laser_canons_collectables
*/

#include <ecs/Registry.hpp>
#include <random>
#include "../components/LaserCanonCollectable.hpp"
#include "../components/Position.hpp"
#include "../components/Drawable.hpp"
#include "../components/HitBox.hpp"

void spawn_laser_canons_collectables_system(Registry &r)
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
        r.add_component(entity, LaserCanonCollectable());
        r.add_component(entity, Position(x_dist(gen), y_dist(gen)));
        r.add_component(entity, HitBox(25));
        r.add_component(entity, Drawable("src/server/assets/laser_canon_collectable.png"));
    }
}
