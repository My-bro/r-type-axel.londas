/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** players_bullets_boss_mob_bullets_collisions_system
*/

#include <ecs/Registry.hpp>

#include "../components/PlayerBullet.hpp"
#include "../components/Position.hpp"
#include "../components/HitBox.hpp"
#include "../components/Damage.hpp"
#include "../components/BossMobBullet.hpp"
#include "../components/Health.hpp"
#include "../components/Player.hpp"
#include "../PacketRepresentation.hpp"
#include "utils.hpp"

void players_bullets_boss_mob_bullets_collisions_system(Registry &r, SparseArray<PlayerBullet> &player_bullets, SparseArray<Position> &player_positions, SparseArray<HitBox> &player_hitboxes, SparseArray<Damage> &player_damages, SparseArray<BossMobBullet> &boss_mob_bullets, SparseArray<Position> &boss_mob_positions, SparseArray<HitBox> &boss_mob_hitboxes, SparseArray<Health> &boss_mob_healths, SparseArray<Player> &players)
{
    for (std::size_t i = 0; i < player_bullets.size() && i < player_positions.size() && i < player_hitboxes.size() && i < player_damages.size(); i++) {
        auto &player_bullet = player_bullets[i];
        auto &player_pos = player_positions[i];
        auto &player_hitbox = player_hitboxes[i];
        auto &player_damage = player_damages[i];
        if (player_bullet && player_pos && player_hitbox && player_damage) {
            for (std::size_t j = 0; j < boss_mob_bullets.size() && j < boss_mob_positions.size() && j < boss_mob_hitboxes.size() && j < boss_mob_healths.size(); j++) {
                auto &boss_mob_bullet = boss_mob_bullets[j];
                auto &boss_mob_pos = boss_mob_positions[j];
                auto &boss_mob_hitbox = boss_mob_hitboxes[j];
                auto &boss_mob_health = boss_mob_healths[j];
                if (boss_mob_bullet && boss_mob_pos && boss_mob_hitbox && boss_mob_health) {
                    if (circle_collision(player_pos.value(), player_hitbox.value(), boss_mob_pos.value(), boss_mob_hitbox.value())) {
                        BossBulletAnimation boss_bullet_animation;
                        boss_bullet_animation.x = boss_mob_pos.value().getX();
                        boss_bullet_animation.y = boss_mob_pos.value().getY();
                        boss_bullet_animation.take_damage = true;
                        r.get_class_instance<PacketRepresentation>().boss_bullets_animations.push_back(boss_bullet_animation);
                        if (boss_mob_health.value().getHealth() <= player_damage.value().getDamage()) {
                            boss_mob_health.value().setHealth(0);
                        } else {
                            boss_mob_health.value().setHealth(boss_mob_health.value().getHealth() - player_damage.value().getDamage());
                        }
                        r.kill_entity(r.entity_from_index(i));
                        break;
                    }
                }
            }
        }
    }
}
