/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** mobs_turrets_ai_system
*/

#include <ecs/Registry.hpp>

#include "../components/Player.hpp"
#include "../components/Position.hpp"
#include "../components/TurretMob.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../components/Drawable.hpp"
#include "../components/HitBox.hpp"
#include "../components/Damage.hpp"
#include "../components/ShootCooldown.hpp"
#include "../components/TurretMobBullet.hpp"
#include <cmath>
#include "../PacketRepresentation.hpp"

void turrets_mobs_ai_system(Registry &r, SparseArray<TurretMob> &turrets, SparseArray<Position> &positions, SparseArray<ShootCooldown> &shoot_cooldowns, SparseArray<Player> &players)
{
    for (std::size_t i = 0; i < turrets.size() && i < positions.size() && i < shoot_cooldowns.size(); i++) {
        auto &turret = turrets[i];
        auto &pos = positions[i];
        auto &shoot_cooldown = shoot_cooldowns[i];
        if (turret && pos && shoot_cooldown) {
            if (shoot_cooldown.value().canShoot()) {
                TurretAnimation turret_animation;
                turret_animation.x = pos.value().getX();
                turret_animation.y = pos.value().getY();
                turret_animation.shooting = true;
                r.get_class_instance<PacketRepresentation>().turrets_animations.push_back(turret_animation);
                for (std::size_t j = 0; j < players.size() && j < positions.size(); j++) {
                    auto &player = players[j];
                    auto &player_pos = positions[j];
                    if (player && player_pos) {
                        int bullet_speed = 20;
                        int dx = player_pos.value().getX() - pos.value().getX();
                        int dy = player_pos.value().getY() - pos.value().getY();
                        int length = std::max(1, static_cast<int>(std::sqrt(dx * dx + dy * dy)));
                        int scaled_speed = bullet_speed * 1000;
                        int vx = (dx * scaled_speed) / length / 1000;
                        int vy = (dy * scaled_speed) / length / 1000;
                        auto entity = r.spawn_entity();
                        r.add_component(entity, TurretMobBullet());
                        r.add_component(entity, Position(pos.value().getX(), pos.value().getY()));
                        r.add_component(entity, Velocity(vx, vy));
                        r.add_component(entity, HitBox(10));
                        r.add_component(entity, Damage(10));
                        r.add_component(entity, Drawable("src/server/assets/turret_mob_bullet.png"));
                        shoot_cooldown.value().reset();
                    }
                }
            }
        }
    }
}
