/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** mob_turrets_bullets_mouvement_system
*/

#include <ecs/Registry.hpp>
#include "../components/TurretMobBullet.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"

void turrets_mobs_bullets_mouvement_system(Registry &r, SparseArray<TurretMobBullet> &bullets, SparseArray<Position> &positions, SparseArray<Velocity> &velocities)
{
    for (std::size_t i = 0; i < bullets.size() && i < positions.size() && i < velocities.size(); i++) {
        auto &bullet = bullets[i];
        auto &pos = positions[i];
        auto &vel = velocities[i];
        if (bullet && pos && vel) {
            pos.value().setX(pos.value().getX() + vel.value().getDX());
            pos.value().setY(pos.value().getY() + vel.value().getDY());
        }
    }
}
