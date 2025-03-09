/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** mobs_ai_system
*/

#include <ecs/Registry.hpp>
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../components/Mob.hpp"
#include "../components/ShootCooldown.hpp"
#include "../components/MobBullet.hpp"
#include "../components/HitBox.hpp"
#include "../components/Damage.hpp"
#include "../components/Drawable.hpp"
#include "../PacketRepresentation.hpp"

void mobs_ai_system(Registry &r, SparseArray<Position> &positions, SparseArray<Velocity> &velocities, SparseArray<Mob> &mobs, SparseArray<ShootCooldown> &shoot_cooldowns)
{
    for (std::size_t i = 0; i < mobs.size() && i < positions.size() && i < velocities.size() && i < shoot_cooldowns.size(); i++) {
        auto &mob = mobs[i];
        auto &pos = positions[i];
        auto &vel = velocities[i];
        auto &shoot_cooldown = shoot_cooldowns[i];

        if (mob && pos && vel && shoot_cooldown) {
            if (pos.value().getY() < 0 || pos.value().getY() > 1080) {
                vel.value().setDY(vel.value().getDY() * -1);
            }
            pos.value().setY(pos.value().getY() + vel.value().getDY());
            if (shoot_cooldown.value().canShoot()) {
                MobAnimation mob_animation;
                mob_animation.x = pos.value().getX();
                mob_animation.y = pos.value().getY();
                mob_animation.shooting = true;
                r.get_class_instance<PacketRepresentation>().mobs_animations.push_back(mob_animation);
                auto entity = r.spawn_entity();
                r.add_component(entity, MobBullet());
                r.add_component(entity, Position(pos.value().getX() - 10, pos.value().getY()));
                r.add_component(entity, Velocity(-50, 0));
                r.add_component(entity, HitBox(10));
                r.add_component(entity, Damage(10));
                r.add_component(entity, Drawable("src/server/assets/mob_bullet.png"));
                shoot_cooldown.value().reset();
            }
        }
    }
}
