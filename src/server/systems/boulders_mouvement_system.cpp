/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** boulders_mouvement_system
*/

#include <ecs/Registry.hpp>
#include "../components/Boulder.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"

void boulders_mouvement_system(Registry &r, SparseArray<Boulder> &boulders, SparseArray<Position> &positions, SparseArray<Velocity> &velocities)
{
    for (size_t i = 0; i < boulders.size() && i < positions.size() && i < velocities.size(); i++) {
        auto &boulder = boulders[i];
        auto &pos = positions[i];
        auto &vel = velocities[i];
        if (boulder && pos && vel) {
            pos.value().setX(pos.value().getX() + vel.value().getDX());
            pos.value().setY(pos.value().getY() + vel.value().getDY());
            if (pos.value().getY() > 1280) {
                r.kill_entity(r.entity_from_index(i));
            }
        }
    }
}
