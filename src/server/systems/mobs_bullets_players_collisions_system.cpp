/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** bullets_players_collisions_system
*/

#include <ecs/Registry.hpp>
#include "../components/Player.hpp"
#include "../components/Damage.hpp"
#include "../components/HitBox.hpp"
#include "../components/Position.hpp"
#include "../components/Health.hpp"
#include "../components/MobBullet.hpp"
#include "../PacketRepresentation.hpp"
#include "utils.hpp"

void mobs_bullets_players_collision_system(Registry &r, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<Damage> &damages, SparseArray<Health> &healths, SparseArray<MobBullet> &bullets, SparseArray<Player> &players)
{
    for (size_t i = 0; i < bullets.size() && i < positions.size() && i < hitboxs.size() && i < damages.size(); i++) {
        auto &bullet = bullets[i];
        auto &pos = positions[i];
        auto &hitbox = hitboxs[i];
        auto &damage = damages[i];
        if (bullet && pos && hitbox && damage) {
            if (pos.value().getX() < 0) {
                r.kill_entity(r.entity_from_index(i));
                continue;
            }
            for (size_t pi = 0; pi < players.size() && pi < positions.size() && pi < hitboxs.size() && pi < healths.size(); pi++) {
                auto &player = players[pi];
                auto &ppos = positions[pi];
                auto &phitbox = hitboxs[pi];
                auto &phealth = healths[pi];
                if (player && ppos && phitbox && phealth) {
                    if (circle_collision(pos.value(), hitbox.value(), ppos.value(), phitbox.value())) {
                        PlayerAnimation player_animation;
                        player_animation.x = ppos.value().getX();
                        player_animation.y = ppos.value().getY();
                        player_animation.take_damage = true;
                        r.get_class_instance<PacketRepresentation>().players_animations.push_back(player_animation);
                        if (phealth.value().getHealth() <= damage.value().getDamage()) {
                            phealth.value().setHealth(0);
                        } else {
                            phealth.value().setHealth(phealth.value().getHealth() - damage.value().getDamage());
                        }
                        r.kill_entity(r.entity_from_index(i));
                        break;
                    }
                }
            }
        }
    }
}
