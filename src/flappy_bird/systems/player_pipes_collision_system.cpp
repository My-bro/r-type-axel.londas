/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** player_pipes_collision_system
*/

#include <ecs/Registry.hpp>
#include "../components/Player.hpp"
#include "../components/Position.hpp"
#include "../components/HitBox.hpp"
#include "../components/Pipe.hpp"
#include "../GameState.hpp"

void player_pipes_collision_system(Registry &r, SparseArray<Player> &players, SparseArray<Pipe> &pipes, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxes)
{
    auto &gameState = r.get_class_instance<GameState>();

    for (std::size_t i = 0; i < pipes.size() && i < positions.size() && i < hitboxes.size(); i++) {
        auto &pipe = pipes[i];
        auto &pipe_pos = positions[i];
        auto &pipe_hitbox = hitboxes[i];
        if (pipe && pipe_pos && pipe_hitbox) {
            for (std::size_t j = 0; j < players.size() && j < positions.size() && j < hitboxes.size(); j++) {
                auto &player = players[j];
                auto &player_pos = positions[j];
                auto &player_hitbox = hitboxes[j];
                if (player && player_pos && player_hitbox) {
                    if (player_pos.value().getX() + player_hitbox.value().getWidth() > pipe_pos.value().getX() && player_pos.value().getX() < pipe_pos.value().getX() + pipe_hitbox.value().getWidth()) {
                        if (player_pos.value().getY() + player_hitbox.value().getHeight() > pipe_pos.value().getY() && player_pos.value().getY() < pipe_pos.value().getY() + pipe_hitbox.value().getHeight()) {
                            gameState.setLose(true);
                        }
                    }
                }
            }
        }
    }
}
