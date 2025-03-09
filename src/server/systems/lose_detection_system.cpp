/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** win_detection_system
*/

#include <ecs/Registry.hpp>
#include "../GameState.hpp"
#include "../components/Player.hpp"


void lose_detection_system(Registry &r, SparseArray<Player> &players)
{
    for (std::size_t i = 0; i < players.size(); i++) {
        auto &player = players[i];
        if (player) {
            return;
        }
    }
    r.get_class_instance<GameState>().setLose(true);
}
