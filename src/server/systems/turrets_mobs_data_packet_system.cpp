/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** turrets_mobs_data_packet_system
*/

#include <ecs/Registry.hpp>
#include "../components/TurretMob.hpp"
#include "../components/Position.hpp"
#include "../PacketRepresentation.hpp"

void turrets_mobs_data_packet_system(Registry &r, SparseArray<TurretMob> &turrets, SparseArray<Position> &positions)
{
    for (std::size_t i = 0; i < turrets.size() && i < positions.size(); i++) {
        auto &turret = turrets[i];
        auto &pos = positions[i];
        if (turret && pos) {
            TurretData turret_data;
            turret_data.x = pos.value().getX();
            turret_data.y = pos.value().getY();
            r.get_class_instance<PacketRepresentation>().turrets_data.push_back(turret_data);
        }
    }
}
