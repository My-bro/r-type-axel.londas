/*
** EPITECH PROJECT, 2024
** bsrtype
** File description:
** Main
*/

#include <ecs/Registry.hpp>
#include "systems/systems.hpp"
#include "GameState.hpp"

int main(int ac, char** av)
{
    Registry reg;
    const float FRAME_DURATION = 1.0f / 30.0f;
    reg.register_class<sf::RenderWindow>(sf::VideoMode(700, 1100), "Flappy Bird");
    reg.register_class<GameState>();
    sf::RenderWindow &window = reg.get_class_instance<sf::RenderWindow>();

    reg.register_component<Pipe>();
    reg.register_component<Player>();
    reg.register_component<Position>();
    reg.register_component<Velocity>();
    reg.register_component<Drawable>();
    reg.register_component<HitBox>();
    reg.register_component<Point>();

    spawn_player_system(reg);
    reg.add_system(clear_render_system);
    reg.add_system(spawn_pipes_system);
    reg.add_system<Pipe, Position, Velocity>(pipes_mouvement_system);
    reg.add_system<Player, Position, Velocity>(player_control_system);
    reg.add_system<Player, Position, Velocity>(player_mouvement_system);
    reg.add_system<Player, Pipe, Position, HitBox>(player_pipes_collision_system);
    reg.add_system<Pipe, Position, Point>(score_system);
    reg.add_system(background_render_system);
    reg.add_system<Pipe, Drawable, Position, HitBox>(pipes_render_system);
    reg.add_system<Player, Position, Drawable>(player_render_system);
    reg.add_system(score_render_system);
    reg.add_system(display_render_system);

    while (window.isOpen()) {
        sf::Clock clock;
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        reg.run_systems();
        if (reg.get_class_instance<GameState>().getLose()) {
            window.close();
        }
        sf::Time elapsed = clock.getElapsedTime();
        sf::Time frameTime = sf::seconds(FRAME_DURATION);
        if (elapsed < frameTime) {
            sf::sleep(frameTime - elapsed);
        }
    }
}
