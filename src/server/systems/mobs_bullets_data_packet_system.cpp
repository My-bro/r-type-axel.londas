/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** mobs_bullets_data_packet_system
*/

#include <ecs/Registry.hpp>
#include "../components/MobBullet.hpp"
#include "../components/Position.hpp"
#include "../PacketRepresentation.hpp"

void mobs_bullets_data_packet_system(Registry &r, SparseArray<MobBullet> &bullets, SparseArray<Position> &positions)
{
    for (std::size_t i = 0; i < bullets.size() && i < positions.size(); i++) {
        auto &bullet = bullets[i];
        auto &pos = positions[i];
        if (bullet && pos) {
            MobBulletData bullet_data;
            bullet_data.x = pos.value().getX();
            bullet_data.y = pos.value().getY();
            r.get_class_instance<PacketRepresentation>().mobs_bullets_data.push_back(bullet_data);
        }
    }
}
