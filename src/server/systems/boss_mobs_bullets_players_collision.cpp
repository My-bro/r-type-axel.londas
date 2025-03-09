/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** boss_mobs_bullets_players_collision
*/

#include <ecs/Registry.hpp>
#include "../components/BossMobBullet.hpp"
#include "../components/Position.hpp"
#include "../components/HitBox.hpp"
#include "../components/Player.hpp"
#include "../components/Health.hpp"
#include "../components/Damage.hpp"
#include "../PacketRepresentation.hpp"
#include "utils.hpp"

void boss_mobs_bullets_players_collision_system(Registry &r, SparseArray<BossMobBullet> &bullets, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<Player> &players, SparseArray<Health> &healths, SparseArray<Damage> &damages)
{
    for (std::size_t i = 0; i < bullets.size() && i < positions.size() && i < hitboxs.size() && i < damages.size(); i++) {
        auto &bullet = bullets[i];
        auto &pos = positions[i];
        auto &hitbox = hitboxs[i];
        auto &damage = damages[i];
        if (bullet && pos && hitbox && damage) {
            for (std::size_t j = 0; j < players.size() && j < positions.size() && j < hitboxs.size() && j < healths.size(); j++) {
                auto &player = players[j];
                auto &player_pos = positions[j];
                auto &player_hitbox = hitboxs[j];
                auto &player_health = healths[j];
                if (player && player_pos && player_hitbox && player_health) {
                    if (circle_collision(pos.value(), hitbox.value(), player_pos.value(), player_hitbox.value())) {
                        PlayerAnimation player_animation;
                        player_animation.x = player_pos.value().getX();
                        player_animation.y = player_pos.value().getY();
                        player_animation.take_damage = true;
                        r.get_class_instance<PacketRepresentation>().players_animations.push_back(player_animation);
                        if (player_health.value().getHealth() <= damage.value().getDamage()) {
                            player_health.value().setHealth(0);
                        } else {
                            player_health.value().setHealth(player_health.value().getHealth() - damage.value().getDamage());
                        }
                        r.kill_entity(r.entity_from_index(i));
                        break;
                    }
                }
            }
        }
    }
}
