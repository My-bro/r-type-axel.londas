/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** death_boss_mob_system
*/

#include <ecs/Registry.hpp>
#include "../components/BossMob.hpp"
#include "../components/Position.hpp"
#include "../components/Health.hpp"
#include "../PacketRepresentation.hpp"

void death_boss_mob_system(Registry &r, SparseArray<BossMob> &bosses, SparseArray<Health> &healths, SparseArray<Position> &positions)
{
    for (std::size_t i = 0; i < bosses.size() && i < healths.size() && i < positions.size(); i++) {
        auto &boss = bosses[i];
        auto &health = healths[i];
        auto &pos = positions[i];
        if (boss && health && pos) {
            if (health.value().getHealth() <= 0) {
                BossAnimation boss_animation;
                boss_animation.x = pos.value().getX();
                boss_animation.y = pos.value().getY();
                boss_animation.died = true;
                r.get_class_instance<PacketRepresentation>().boss_animations.push_back(boss_animation);
                r.kill_entity(r.entity_from_index(i));
            }
        }
    }
}
