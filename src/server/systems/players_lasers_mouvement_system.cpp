/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** players_lasers_mouvement_system
*/

#include <ecs/Registry.hpp>
#include "../components/PlayerLaser.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"

void players_lasers_mouvement_system(Registry &r, SparseArray<PlayerLaser> &lasers, SparseArray<Position> &positions, SparseArray<Velocity> &velocities)
{
    for (std::size_t i = 0; i < lasers.size() && i < positions.size() && i < velocities.size(); i++) {
        auto &laser = lasers[i];
        auto &pos = positions[i];
        auto &vel = velocities[i];
        if (laser && pos && vel) {
            pos.value().setX(pos.value().getX() + vel.value().getDX());
            pos.value().setY(pos.value().getY() + vel.value().getDY());
            if (pos.value().getX() > 1920) {
                r.kill_entity(r.entity_from_index(i));
            }
        }
    }
}
