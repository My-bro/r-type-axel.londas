/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** mobs_turrets_players_collision_system
*/

#include <ecs/Registry.hpp>

#include "../components/TurretMobBullet.hpp"
#include "../components/Position.hpp"
#include "../components/HitBox.hpp"
#include "../components/Player.hpp"
#include "../components/Health.hpp"
#include "../components/Damage.hpp"
#include "../PacketRepresentation.hpp"
#include "utils.hpp"

void turrets_mobs_bullets_players_collisions_system(Registry &r, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<Damage> &damages, SparseArray<Health> &healths, SparseArray<TurretMobBullet> &bullets, SparseArray<Player> &players)
{
    for (std::size_t i = 0; i < bullets.size() && i < positions.size() && i < hitboxs.size() && i < damages.size(); i++) {
        auto &bullet = bullets[i];
        auto &pos = positions[i];
        auto &hitbox = hitboxs[i];
        auto &damage = damages[i];
        if (bullet && pos && hitbox && damage) {
            if (pos.value().getX() < 0 || pos.value().getX() > 1920 || pos.value().getY() < 0 || pos.value().getY() > 1080) {
                r.kill_entity(r.entity_from_index(i));
                continue;
            }
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
