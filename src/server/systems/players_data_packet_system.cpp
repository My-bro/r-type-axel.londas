/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** players_data_packet_system
*/

#include <ecs/Registry.hpp>
#include "../components/NetworkPlayer.hpp"
#include "../components/Position.hpp"
#include "../components/Health.hpp"
#include "../components/BasicCanon.hpp"
#include "../components/LaserCanon.hpp"
#include "../PacketRepresentation.hpp"

void players_data_packet_system(Registry &r, SparseArray<NetworkPlayer> &players, SparseArray<Position> &positions, SparseArray<Health> &healths, SparseArray<BasicCanon> &basic_canons, SparseArray<LaserCanon> &laser_canons)
{
    for (std::size_t i = 0; i < players.size() && i < positions.size() && i < healths.size() && i < basic_canons.size(); i++) {
        auto &player = players[i];
        auto &pos = positions[i];
        auto &health = healths[i];
        auto &basic_canon = basic_canons[i];
        if (player && pos && health && basic_canon) {
            PlayerData player_data;
            player_data.id = player.value().getMiniId();
            player_data.x = pos.value().getX();
            player_data.y = pos.value().getY();
            player_data.health = health.value().getHealth();
            player_data.basic_canon = true;
            r.get_class_instance<PacketRepresentation>().players_data.push_back(player_data);
        }
    }

    for (std::size_t i = 0; i < players.size() && i < positions.size() && i < healths.size() && i < laser_canons.size(); i++) {
        auto &player = players[i];
        auto &pos = positions[i];
        auto &health = healths[i];
        auto &laser_canon = laser_canons[i];
        if (player && pos && health && laser_canon) {
            PlayerData player_data;
            player_data.id = player.value().getMiniId();
            player_data.x = pos.value().getX();
            player_data.y = pos.value().getY();
            player_data.health = health.value().getHealth();
            player_data.laser_canon = true;
            r.get_class_instance<PacketRepresentation>().players_data.push_back(player_data);
        }
    }
}
