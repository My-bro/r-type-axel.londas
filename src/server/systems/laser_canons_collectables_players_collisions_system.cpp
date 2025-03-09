/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** laser_canon_collectables_player_collision_system
*/

#include <ecs/Registry.hpp>
#include "../components/LaserCanonCollectable.hpp"
#include "../components/Position.hpp"
#include "../components/HitBox.hpp"
#include "../components/Player.hpp"
#include "../components/BasicCanon.hpp"
#include "../components/LaserCanon.hpp"
#include "../components/LaserCanon.hpp"
#include "../components/ShootCooldown.hpp"
#include "utils.hpp"

void laser_canons_collectables_players_collisions_system(Registry &r, SparseArray<LaserCanonCollectable> &laser_canons, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<Player> &players)
{
    for (std::size_t i = 0; i < laser_canons.size() && i < positions.size() && i < hitboxs.size(); i++) {
        auto &laser_canon = laser_canons[i];
        auto &pos = positions[i];
        auto &hitbox = hitboxs[i];
        if (laser_canon && pos && hitbox) {
            for (std::size_t j = 0; j < players.size() && j < positions.size() && j < hitboxs.size(); j++) {
                auto &player = players[j];
                auto &player_pos = positions[j];
                auto &player_hitbox = hitboxs[j];
                if (player && player_pos && player_hitbox) {
                    if (circle_collision(pos.value(), hitbox.value(), player_pos.value(), player_hitbox.value())) {
                        auto player = r.entity_from_index(j);
                        r.remove_component<BasicCanon>(player);
                        r.add_component(player, LaserCanon());
                        r.remove_component<ShootCooldown>(player);
                        r.add_component(player, LaserCanon());
                        r.add_component(player, ShootCooldown(0.5));
                        r.kill_entity(r.entity_from_index(i));
                        break;
                    }
                }
            }
        }
    }
}
