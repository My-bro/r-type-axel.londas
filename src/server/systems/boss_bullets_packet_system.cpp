/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** boss_bullets_packet_system
*/

#include <ecs/Registry.hpp>
#include "../components/BossMobBullet.hpp"
#include "../components/Position.hpp"
#include "../PacketRepresentation.hpp"

void boss_bullets_packet_system(Registry &r, SparseArray<BossMobBullet> &boss_bullets, SparseArray<Position> &positions)
{
    for (std::size_t i = 0; i < boss_bullets.size() && i < positions.size(); i++) {
        auto &boss_bullet = boss_bullets[i];
        auto &pos = positions[i];
        if (boss_bullet && pos) {
            BossBulletData boss_bullet_data;
            boss_bullet_data.x = pos.value().getX();
            boss_bullet_data.y = pos.value().getY();
            r.get_class_instance<PacketRepresentation>().boss_bullets_data.push_back(boss_bullet_data);
        }
    }
}
