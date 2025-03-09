/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** pipes_mouvement_system
*/

#include <ecs/Registry.hpp>
#include "../components/Pipe.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"

void pipes_mouvement_system(Registry &r, SparseArray<Pipe> &pipes, SparseArray<Position> &positions, SparseArray<Velocity> &velocities)
{
    for (std::size_t i = 0; i < pipes.size() && i < positions.size() && i < velocities.size(); i++) {
        auto &pipe = pipes[i];
        auto &pos = positions[i];
        auto &vel = velocities[i];

        if (pipe && pos && vel) {
            if (pos.value().getX() < -300) {
                r.kill_entity(r.entity_from_index(i));
                continue;
            }
            pos.value().setX(pos.value().getX() + vel.value().getDX());
        }
    }
}
