/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** score_system
*/

#include <ecs/Registry.hpp>
#include "../components/Pipe.hpp"
#include "../components/Position.hpp"
#include "../components/Point.hpp"
#include "../GameState.hpp"

void score_system(Registry &r, SparseArray<Pipe> &pipes, SparseArray<Position> &positions, SparseArray<Point> &points)
{
    auto &gameState = r.get_class_instance<GameState>();

    for (std::size_t i = 0; i < pipes.size() && i < positions.size() && i < points.size(); i++) {
        auto &pipe = pipes[i];
        auto &pos = positions[i];
        auto &point = points[i];

        if (pipe && pos && point) {
            if (pos.value().getX() < 252.5) {
                r.remove_component<Point>(r.entity_from_index(i));
                gameState.setScore(gameState.getScore() + 1);
            }
        }
    }
}
