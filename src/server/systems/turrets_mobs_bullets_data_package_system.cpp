/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** turrets_mobs_bullets_data_package_system
*/

#include <ecs/Registry.hpp>
#include "../components/TurretMobBullet.hpp"
#include "../components/Position.hpp"
#include "../PacketRepresentation.hpp"

void turrets_mobs_bullets_data_package_system(Registry &r, SparseArray<TurretMobBullet> &bullets, SparseArray<Position> &positions)
{
    for (std::size_t i = 0; i < bullets.size() && i < positions.size(); i++) {
        auto &bullet = bullets[i];
        auto &pos = positions[i];
        if (bullet && pos) {
            TurretBulletData bullet_data;
            bullet_data.x = pos.value().getX();
            bullet_data.y = pos.value().getY();
            r.get_class_instance<PacketRepresentation>().turrets_bullets_data.push_back(bullet_data);
        }
    }
}
