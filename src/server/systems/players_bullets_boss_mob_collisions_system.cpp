/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** players_bullets_boss_mob_collisions_system
*/

#include <ecs/Registry.hpp>
#include "../components/PlayerBullet.hpp"
#include "../components/Position.hpp"
#include "../components/HitBox.hpp"
#include "../components/BossMob.hpp"
#include "../components/Health.hpp"
#include "../components/Damage.hpp"
#include "../PacketRepresentation.hpp"
#include "utils.hpp"

void players_bullets_boss_mob_collisions_system(Registry &r, SparseArray<PlayerBullet> &bullets, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<BossMob> &bosses, SparseArray<Health> &healths, SparseArray<Damage> &damages)
{
    for (std::size_t i = 0; i < bullets.size() && i < positions.size() && i < hitboxs.size() && i < damages.size(); i++) {
        auto &bullet = bullets[i];
        auto &pos = positions[i];
        auto &hitbox = hitboxs[i];
        auto &damage = damages[i];
        if (bullet && pos && hitbox && damage) {
            for (std::size_t bi = 0; bi < bosses.size() && bi < positions.size() && bi < hitboxs.size() && bi < healths.size(); bi++) {
                auto &boss = bosses[bi];
                auto &boss_pos = positions[bi];
                auto &boss_hitbox = hitboxs[bi];
                auto &boss_health = healths[bi];

                if (boss && boss_pos && boss_hitbox && boss_health) {
                    if (circle_collision(pos.value(), hitbox.value(), boss_pos.value(), boss_hitbox.value())) {
                        BossAnimation boss_animation;
                        boss_animation.x = boss_pos.value().getX();
                        boss_animation.y = boss_pos.value().getY();
                        boss_animation.take_damage = true;
                        r.get_class_instance<PacketRepresentation>().boss_animations.push_back(boss_animation);
                        if (boss_health.value().getHealth() <= damage.value().getDamage()) {
                            boss_health.value().setHealth(0);
                        } else {
                            boss_health.value().setHealth(boss_health.value().getHealth() - damage.value().getDamage());
                        }
                        r.kill_entity(r.entity_from_index(i));
                        break;
                    }
                }
            }
        }
    }
}
