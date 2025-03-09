/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** player_laser_canon_shooting_system
*/

#include <ecs/Registry.hpp>
#include "../components/Player.hpp"
#include "../components/LaserCanon.hpp"
#include "../components/Controllable.hpp"
#include "../components/Position.hpp"
#include "../components/PlayerLaser.hpp"
#include "../components/Velocity.hpp"
#include "../components/Damage.hpp"
#include "../components/Drawable.hpp"
#include "../components/HitBox.hpp"
#include "../components/ShootCooldown.hpp"
#include "../PacketRepresentation.hpp"

void players_laser_canon_shooting_system(Registry &r, SparseArray<Player> &players, SparseArray<LaserCanon> &canons, SparseArray<Position> &positions, SparseArray<Controllable> &controllables, SparseArray<ShootCooldown> &shoot_cooldowns)
{
    for (std::size_t i = 0; i < players.size() && i < canons.size() && i < positions.size() && i < controllables.size() && i < shoot_cooldowns.size(); i++) {
        auto &player = players[i];
        auto &canon = canons[i];
        auto &pos = positions[i];
        auto &controllable = controllables[i];
        auto &shoot_cooldown = shoot_cooldowns[i];
        if (player && canon && pos && controllable && shoot_cooldown) {
            if (controllable.value().isShooting() && shoot_cooldown.value().canShoot()) {
                PlayerAnimation player_animation;
                player_animation.x = pos.value().getX();
                player_animation.y = pos.value().getY();
                player_animation.laser_shooting = true;
                r.get_class_instance<PacketRepresentation>().players_animations.push_back(player_animation);
                int space = 0;
                for (std::size_t i = 0; i < 5; i++) {
                    auto entity = r.spawn_entity();
                    r.add_component(entity, PlayerLaser());
                    r.add_component(entity, Position(pos.value().getX() + space, pos.value().getY()));
                    r.add_component(entity, Velocity(50, 0));
                    r.add_component(entity, Damage(1));
                    r.add_component(entity, HitBox(10));
                    r.add_component(entity, Drawable("src/server/assets/player_laser.png"));
                    space += 10;
                }
                shoot_cooldown.value().reset();
                controllable.value().setShoot(false);
            }
        }
    }
}
