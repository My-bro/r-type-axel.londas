/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** spawn_pipes_system
*/

#include <ecs/Registry.hpp>
#include "../components/Pipe.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../components/Drawable.hpp"
#include "../components/HitBox.hpp"
#include "../components/Point.hpp"
#include <random>
#include <chrono>

void spawn_pipes_system(Registry &r)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> gap_dist(200, 600);
    static std::uniform_int_distribution<int> gap_height_dist(450, 650);

    static auto last_spawn_time = std::chrono::steady_clock::now();
    auto current_time = std::chrono::steady_clock::now();

    if (std::chrono::duration_cast<std::chrono::seconds>(current_time - last_spawn_time).count() >= 2) {
        last_spawn_time = current_time;
        int gap = gap_dist(gen);
        int gap_height = gap_height_dist(gen);
        auto top_pipe = r.spawn_entity();
        int top_pipe_height = gap_height - gap / 2;
        r.add_component(top_pipe, Pipe(Pipe::Type::TOP));
        r.add_component(top_pipe, Position(1295, 0));
        r.add_component(top_pipe, Velocity(-10, 0));
        r.add_component(top_pipe, HitBox(195, top_pipe_height));
        r.add_component(top_pipe, Point());
        r.add_component(top_pipe, Drawable("src/flappy_bird/assets/top_pipe.png"));

        auto bottom_pipe = r.spawn_entity();
        int bottom_pipe_height = 1100 - gap_height - gap / 2;
        r.add_component(bottom_pipe, Pipe(Pipe::Type::BOTTOM));
        r.add_component(bottom_pipe, Position(1295, gap_height + gap / 2));
        r.add_component(bottom_pipe, Velocity(-10, 0));
        r.add_component(bottom_pipe, HitBox(195, bottom_pipe_height));
        r.add_component(bottom_pipe, Point());
        r.add_component(bottom_pipe, Drawable("src/flappy_bird/assets/bottom_pipe.png"));
    }
}
