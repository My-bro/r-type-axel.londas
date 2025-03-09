/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** death_boss_mob_bullets_system
*/

#include <ecs/Registry.hpp>
#include "../components/BossMobBullet.hpp"
#include "../components/Health.hpp"
#include "../components/Position.hpp"
#include "../PacketRepresentation.hpp"

void death_boss_mob_bullets_system(Registry &r, SparseArray<BossMobBullet> &bullets, SparseArray<Health> &healths, SparseArray<Position> &positions)
{
    for (std::size_t i = 0; i < bullets.size() && i < healths.size() && i < positions.size(); i++) {
        auto &bullet = bullets[i];
        auto &health = healths[i];
        auto &pos = positions[i];
        if (bullet && health && pos) {
            if (health.value().getHealth() <= 0) {
                BossBulletAnimation boss_bullet_animation;
                boss_bullet_animation.x = pos.value().getX();
                boss_bullet_animation.y = pos.value().getY();
                boss_bullet_animation.died = true;
                r.get_class_instance<PacketRepresentation>().boss_bullets_animations.push_back(boss_bullet_animation);
                r.kill_entity(r.entity_from_index(i));
            }
        }
    }
}
