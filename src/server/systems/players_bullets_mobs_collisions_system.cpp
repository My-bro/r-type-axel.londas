/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** bullets_enemies_collision_system
*/

#include <ecs/Registry.hpp>
#include "../components/Mob.hpp"
#include "../components/Damage.hpp"
#include "../components/HitBox.hpp"
#include "../components/Position.hpp"
#include "../components/Health.hpp"
#include "../components/PlayerBullet.hpp"
#include "../PacketRepresentation.hpp"
#include "utils.hpp"

void players_bullets_mobs_collisions_system(Registry &r, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<Damage> &damages, SparseArray<Health> &healths, SparseArray<Mob> &mobs, SparseArray<PlayerBullet> &bullets)
{
    for (size_t i = 0; i < bullets.size() && i < positions.size() && i < hitboxs.size() && i < damages.size(); i++) {
        auto &bullet = bullets[i];
        auto &pos = positions[i];
        auto &hitbox = hitboxs[i];
        auto &damage = damages[i];
        if (bullet && pos && hitbox && damage) {
            for (size_t mi = 0; mi < mobs.size() && mi < positions.size() && mi < hitboxs.size() && mi < healths.size(); mi++) {
                auto &mob = mobs[mi];
                auto &mpos = positions[mi];
                auto &mhitbox = hitboxs[mi];
                auto &mhealth = healths[mi];
                if (mob && mpos && mhitbox && mhealth) {
                    if (circle_collision(pos.value(), hitbox.value(), mpos.value(), mhitbox.value())) {
                        MobAnimation mob_animation;
                        mob_animation.x = mpos.value().getX();
                        mob_animation.y = mpos.value().getY();
                        mob_animation.take_damage = true;
                        r.get_class_instance<PacketRepresentation>().mobs_animations.push_back(mob_animation);
                        if (mhealth.value().getHealth() <= damage.value().getDamage()) {
                            mhealth.value().setHealth(0);
                        } else {
                            mhealth.value().setHealth(mhealth.value().getHealth() - damage.value().getDamage());
                        }
                        r.kill_entity(r.entity_from_index(i));
                        break;
                    }
                }
            }
        }
    }
}
