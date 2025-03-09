/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** spawn_boulders
*/

#include <ecs/Registry.hpp>
#include "../components/Boulder.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../components/Drawable.hpp"
#include "../components/HitBox.hpp"
#include "../components/Damage.hpp"
#include <random>

void spawn_boulders_system(Registry &r) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> x_dist(0, 760);

    static auto last_spawn_time = std::chrono::steady_clock::now();
    auto current_time = std::chrono::steady_clock::now();

    const int spawn_interval = 5;

    if (std::chrono::duration_cast<std::chrono::seconds>(current_time - last_spawn_time).count() >= spawn_interval) {
        last_spawn_time = current_time;
        int boulder_radius = 200;
        int random_x = x_dist(gen);
        auto boulder = r.spawn_entity();
        r.add_component(boulder, Boulder());
        r.add_component(boulder, Position(random_x, -boulder_radius));
        r.add_component(boulder, Velocity(0, 20));
        r.add_component(boulder, Drawable("src/server/assets/boulder.png"));
        r.add_component(boulder, HitBox(boulder_radius));
        r.add_component(boulder, Damage(5));
    }
}
