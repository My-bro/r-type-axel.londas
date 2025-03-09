/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** collectables_data_packet_system
*/

#include <ecs/Registry.hpp>
#include "../components/HealthCollectable.hpp"
#include "../components/LaserCanonCollectable.hpp"
#include "../components/Position.hpp"
#include "../PacketRepresentation.hpp"

void collectables_data_packet_system(Registry &r,  SparseArray<HealthCollectable> &health_collectables, SparseArray<LaserCanonCollectable> &laser_canon_collectables, SparseArray<Position> &positions)
{
    for (std::size_t i = 0; i < health_collectables.size() && i < positions.size(); i++) {
        auto &health_collectable = health_collectables[i];
        auto &pos = positions[i];
        if (health_collectable && pos) {
            HealthCollectableData health_collectable_data;
            health_collectable_data.x = pos.value().getX();
            health_collectable_data.y = pos.value().getY();
            r.get_class_instance<PacketRepresentation>().health_collectables_data.push_back(health_collectable_data);
        }
    }

    for (std::size_t i = 0; i < laser_canon_collectables.size() && i < positions.size(); i++) {
        auto &laser_canon_collectable = laser_canon_collectables[i];
        auto &pos = positions[i];
        if (laser_canon_collectable && pos) {
            LaserCollectableData laser_canon_collectable_data;
            laser_canon_collectable_data.x = pos.value().getX();
            laser_canon_collectable_data.y = pos.value().getY();
            r.get_class_instance<PacketRepresentation>().laser_collectables_data.push_back(laser_canon_collectable_data);
        }
    }
}
