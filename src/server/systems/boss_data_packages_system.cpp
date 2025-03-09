/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** boss_data_packages
*/

#include <ecs/Registry.hpp>
#include "../components/BossMob.hpp"
#include "../components/Position.hpp"
#include "../components/Health.hpp"
#include "../PacketRepresentation.hpp"

void boss_data_packages_system(Registry &r, SparseArray<BossMob> &bosses, SparseArray<Position> &positions, SparseArray<Health> &healths)
{
    for (std::size_t i = 0; i < bosses.size() && i < positions.size() && i < healths.size(); i++) {
        auto &boss = bosses[i];
        auto &pos = positions[i];
        auto &health = healths[i];
        if (boss && pos && health) {
            BossData boss_data;
            boss_data.x = pos.value().getX();
            boss_data.y = pos.value().getY();
            boss_data.health = health.value().getHealth();
            r.get_class_instance<PacketRepresentation>().boss_data.push_back(boss_data);
        }
    }
}
