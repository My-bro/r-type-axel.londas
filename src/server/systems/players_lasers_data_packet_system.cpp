/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** players_lasers_data_packet_system
*/

#include <ecs/Registry.hpp>
#include "../components/PlayerLaser.hpp"
#include "../components/Position.hpp"
#include "../PacketRepresentation.hpp"

void players_lasers_data_packet_system(Registry &r, SparseArray<PlayerLaser> &lasers, SparseArray<Position> &positions)
{
    for (std::size_t i = 0; i < lasers.size() && i < positions.size(); i++) {
        auto &laser = lasers[i];
        auto &pos = positions[i];
        if (laser && pos) {
            PlayerLaserData laser_data;
            laser_data.x = pos.value().getX();
            laser_data.y = pos.value().getY();
            r.get_class_instance<PacketRepresentation>().players_lasers_data.push_back(laser_data);
        }
    }
}
