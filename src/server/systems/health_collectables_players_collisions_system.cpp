/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** health_collectables_players_collisions_system
*/

#include <ecs/Registry.hpp>

#include "../components/HealthCollectable.hpp"
#include "../components/Position.hpp"
#include "../components/HitBox.hpp"
#include "../components/Player.hpp"
#include "../components/Health.hpp"
#include "utils.hpp"

void health_collectables_players_collisions_system(Registry &r, SparseArray<HealthCollectable> &healths_collectables, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<Health> &healths, SparseArray<Player> &players)
{
    for (std::size_t i = 0; i < healths_collectables.size() && i < positions.size() && i < hitboxs.size() && i < healths.size(); i++) {
        auto &health_collectable = healths_collectables[i];
        auto &pos = positions[i];
        auto &hitbox = hitboxs[i];
        auto &health = healths[i];
        if (health_collectable && pos && hitbox && health) {
            for (std::size_t j = 0; j < players.size() && j < positions.size() && j < hitboxs.size() && j < healths.size(); j++) {
                auto &player = players[j];
                auto &player_pos = positions[j];
                auto &player_hitbox = hitboxs[j];
                auto &player_health = healths[j];
                if (player && player_pos && player_hitbox && player_health) {
                    if (circle_collision(pos.value(), hitbox.value(), player_pos.value(), player_hitbox.value())) {
                        player_health.value().setHealth(player_health.value().getHealth() + health.value().getHealth());
                        r.kill_entity(r.entity_from_index(i));
                        break;
                    }
                }
            }
        }
    }
}
