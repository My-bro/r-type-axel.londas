/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** deaths_players_system
*/

#include <ecs/Registry.hpp>
#include "../components/Player.hpp"
#include "../components/Health.hpp"
#include "../components/Position.hpp"
#include "../PacketRepresentation.hpp"

void deaths_players_system(Registry &r, SparseArray<Player> &players, SparseArray<Health> &healths, SparseArray<Position> &positions)
{
    for (std::size_t i = 0; i < players.size() && i < healths.size() && i < positions.size(); i++) {
        auto &player = players[i];
        auto &health = healths[i];
        auto &pos = positions[i];
        if (player && health && pos) {
            if (health.value().getHealth() <= 0) {
                PlayerAnimation player_animation;
                player_animation.x = pos.value().getX();
                player_animation.y = pos.value().getY();
                player_animation.died = true;
                r.get_class_instance<PacketRepresentation>().players_animations.push_back(player_animation);
                r.kill_entity(r.entity_from_index(i));
            }
        }
    }
}
