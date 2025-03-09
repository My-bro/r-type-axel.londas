/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** deaths_mobs_system
*/

#include <ecs/Registry.hpp>
#include "../components/Mob.hpp"
#include "../components/Health.hpp"
#include "../components/Position.hpp"
#include "../PacketRepresentation.hpp"

void deaths_mobs_system(Registry &r, SparseArray<Mob> &mobs, SparseArray<Health> &healths, SparseArray<Position> &positions)
{
    for (std::size_t i = 0; i < mobs.size() && i < healths.size() && i < positions.size(); i++) {
        auto &mob = mobs[i];
        auto &health = healths[i];
        auto &pos = positions[i];
        if (mob && health && pos) {
            if (health.value().getHealth() <= 0) {
                MobAnimation mob_animation;
                mob_animation.x = pos.value().getX();
                mob_animation.y = pos.value().getY();
                mob_animation.died = true;
                r.get_class_instance<PacketRepresentation>().mobs_animations.push_back(mob_animation);
                r.kill_entity(r.entity_from_index(i));
            }
        }
    }
}
