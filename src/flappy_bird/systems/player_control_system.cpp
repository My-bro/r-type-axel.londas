/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** player_control_system
*/

#include <ecs/Registry.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "../components/Player.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"

void player_control_system(Registry &r, SparseArray<Player> &players, SparseArray<Position> &positions, SparseArray<Velocity> &velocities)
{
    for (std::size_t i = 0; i < players.size() && i < positions.size() && i < velocities.size(); i++) {
        auto &player = players[i];
        auto &pos = positions[i];
        auto &vel = velocities[i];

        if (player && pos && vel) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                vel.value().setDY(-15);
            } else {
                vel.value().setDY(10);
            }
        }
    }
}
