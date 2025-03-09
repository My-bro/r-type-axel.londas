/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** boss_mob_bullets_mouvement_system
*/

#include <ecs/Registry.hpp>
#include "../components/BossMobBullet.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../components/Player.hpp"
#include <cmath>

void boss_mob_bullets_mouvement_system(Registry &r, SparseArray<BossMobBullet> &bullets, SparseArray<Position> &positions, SparseArray<Velocity> &velocities, SparseArray<Player> &players) {
    int speed = 10;

    for (std::size_t i = 0; i < bullets.size() && i < positions.size() && i < velocities.size(); i++) {
        auto &bullet = bullets[i];
        auto &pos = positions[i];
        auto &vel = velocities[i];
        if (bullet && pos && vel) {
            int closestDistance = std::numeric_limits<int>::max();
            int closestPlayerX = 0;
            int closestPlayerY = 0;
            for (std::size_t j = 0; j < players.size() && j < positions.size(); j++) {
                auto &player = players[j];
                auto &player_pos = positions[j];

                if (player && player_pos) {
                    int dx = player_pos.value().getX() - pos.value().getX();
                    int dy = player_pos.value().getY() - pos.value().getY();
                    int distanceSquared = dx * dx + dy * dy; // Use squared distance to avoid floating-point calculations

                    if (distanceSquared < closestDistance) {
                        closestDistance = distanceSquared;
                        closestPlayerX = player_pos.value().getX();
                        closestPlayerY = player_pos.value().getY();
                    }
                }
            }
            if (closestDistance != std::numeric_limits<int>::max()) {
                int dx = closestPlayerX - pos.value().getX();
                int dy = closestPlayerY - pos.value().getY();
                if (dx != 0 || dy != 0) {
                    int magnitude = static_cast<int>(std::sqrt(dx * dx + dy * dy));
                    int directionX = (dx * speed) / magnitude;
                    int directionY = (dy * speed) / magnitude;
                    vel.value().setDX(directionX);
                    vel.value().setDY(directionY);
                    pos.value().setX(pos.value().getX() + vel.value().getDX());
                    pos.value().setY(pos.value().getY() + vel.value().getDY());
                }
            }
        }
    }
}
