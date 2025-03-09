/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** player_mouvement_system
*/

#include <ecs/Registry.hpp>
#include "../components/Player.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../GameState.hpp"

void player_mouvement_system(Registry &r, SparseArray<Player> &players, SparseArray<Position> &positions, SparseArray<Velocity> &velocities)
{
    for (std::size_t i = 0; i < players.size() && i < positions.size() && i < velocities.size(); i++) {
        auto &player = players[i];
        auto &pos = positions[i];
        auto &vel = velocities[i];

        if (player && pos && vel) {
            pos.value().setX(pos.value().getX() + vel.value().getDX());
            pos.value().setY(pos.value().getY() + vel.value().getDY());
            if ((pos.value().getY() < 0) || (pos.value().getY() > 1000)) {
                r.get_class_instance<GameState>().setLose(true);
            }
        }
    }
}
