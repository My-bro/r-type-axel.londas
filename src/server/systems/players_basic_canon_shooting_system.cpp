/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** players_shooting_system
*/

#include <ecs/Registry.hpp>
#include "../components/Player.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../components/Controllable.hpp"
#include "../components/PlayerBullet.hpp"
#include "../components/HitBox.hpp"
#include "../components/Damage.hpp"
#include "../components/ShootCooldown.hpp"
#include "../components/Drawable.hpp"
#include "../components/BasicCanon.hpp"
#include "../PacketRepresentation.hpp"

void players_basic_canon_shooting_system(Registry &r, SparseArray<Player> &players, SparseArray<BasicCanon> &canons, SparseArray<Position> &positions, SparseArray<Controllable> &controllables, SparseArray<ShootCooldown> &shoot_cooldowns)
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
                player_animation.basic_shooting = true;
                r.get_class_instance<PacketRepresentation>().players_animations.push_back(player_animation);
                auto entity = r.spawn_entity();
                r.add_component(entity, PlayerBullet());
                r.add_component(entity, Position(pos.value().getX() + 10, pos.value().getY()));
                r.add_component(entity, Velocity(100, 0));
                r.add_component(entity, HitBox(10));
                r.add_component(entity, Damage(20));
                r.add_component(entity, Drawable("src/server/assets/player_bullet.png"));
                shoot_cooldown.value().reset();
                controllable.value().setShoot(false);
            }
        }
    }
}
