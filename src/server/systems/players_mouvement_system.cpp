/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** players_mouvement_system
*/

#include <ecs/Registry.hpp>
#include "../components/Player.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../components/Controllable.hpp"

void players_mouvement_system(Registry &/*r*/, SparseArray<Player> &players, SparseArray<Position> &positions, SparseArray<Velocity> &velocities, SparseArray<Controllable> &controllables)
{
    const float screenWidth = 1920.0f;
    const float screenHeight = 1080.0f;
    const float rightBoundary = screenWidth / 2.0f;

    for (std::size_t i = 0; i < players.size() && i < positions.size() && i < velocities.size() && i < controllables.size(); i++) {
        auto &player = players[i];
        auto &pos = positions[i];
        auto &vel = velocities[i];
        auto &controllable = controllables[i];

        if (player && pos && vel && controllable) {
            if (controllable.value().isUp()) {
                controllable.value().setUp(false);
                if (pos.value().getY() - vel.value().getDY() >= 0.0f) {
                    pos.value().setY(pos.value().getY() - vel.value().getDY());
                }
            }
            if (controllable.value().isDown()) {
                controllable.value().setDown(false);
                if (pos.value().getY() + vel.value().getDY() <= screenHeight) {
                    pos.value().setY(pos.value().getY() + vel.value().getDY());
                }
            }
            if (controllable.value().isLeft()) {
                controllable.value().setLeft(false);
                if (pos.value().getX() - vel.value().getDX() >= 0.0f) {
                    pos.value().setX(pos.value().getX() - vel.value().getDX());
                }
            }
            if (controllable.value().isRight()) {
                controllable.value().setRight(false);
                if (pos.value().getX() + vel.value().getDX() <= rightBoundary) {
                    pos.value().setX(pos.value().getX() + vel.value().getDX());
                }
            }
        }
    }
}
