/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** players_bullets_mouvement_system
*/

#include <ecs/Registry.hpp>
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../components/PlayerBullet.hpp"

void players_bullets_mouvement_system(Registry &r, SparseArray<Position> &positions, SparseArray<Velocity> &velocities, SparseArray<PlayerBullet> &bullets)
{
    for (std::size_t i = 0; i < bullets.size() && i < positions.size() && i < velocities.size(); i++) {
        auto &bullet = bullets[i];
        auto &pos = positions[i];
        auto &vel = velocities[i];
        if (bullet && pos && vel) {
            pos.value().setX(pos.value().getX() + vel.value().getDX());
            pos.value().setY(pos.value().getY() + vel.value().getDY());
            if (pos.value().getX() > 1920 || pos.value().getX() < 0 || pos.value().getY() > 1080 || pos.value().getY() < 0) {
                r.kill_entity(r.entity_from_index(i));
            }
        }
    }
}
