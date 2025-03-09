/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** mobs_data_packet_system
*/

#include <ecs/Registry.hpp>
#include "../components/Mob.hpp"
#include "../components/Position.hpp"
#include "../components/Health.hpp"
#include "../PacketRepresentation.hpp"

void mobs_data_packet_system(Registry &r, SparseArray<Mob> &mobs, SparseArray<Position> &positions, SparseArray<Health> &healths)
{
    for (std::size_t i = 0; i < mobs.size() && i < positions.size() && i < healths.size(); i++) {
        auto &mob = mobs[i];
        auto &pos = positions[i];
        auto &health = healths[i];
        if (mob && pos && health) {
            MobData mob_data;
            mob_data.x = pos.value().getX();
            mob_data.y = pos.value().getY();
            mob_data.health = health.value().getHealth();
            r.get_class_instance<PacketRepresentation>().mobs_data.push_back(mob_data);
        }
    }
}
