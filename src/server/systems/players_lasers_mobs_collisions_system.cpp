/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** players_lasers_mobs_collisions_system
*/

#include <ecs/Registry.hpp>
#include "../components/PlayerLaser.hpp"
#include "../components/Position.hpp"
#include "../components/HitBox.hpp"
#include "../components/Mob.hpp"
#include "../components/Health.hpp"
#include "../components/Damage.hpp"
#include "../PacketRepresentation.hpp"
#include "utils.hpp"

void players_lasers_mobs_collisions_system(Registry &r, SparseArray<PlayerLaser> &lasers, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<Mob> &mobs, SparseArray<Health> &healths, SparseArray<Damage> &damages)
{
    for (std::size_t i = 0; i < lasers.size() && i < positions.size() && i < hitboxs.size() && i < damages.size(); i++) {
        auto &laser = lasers[i];
        auto &pos = positions[i];
        auto &hitbox = hitboxs[i];
        auto &damage = damages[i];
        if (laser && pos && hitbox && damage) {
            for (std::size_t mi = 0; mi < mobs.size() && mi < positions.size() && mi < hitboxs.size() && mi < healths.size(); mi++) {
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
                    }
                }
            }
        }
    }
}
