/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** boss_mob_ai_system
*/

#include <ecs/Registry.hpp>

#include "../components/BossMob.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../components/Drawable.hpp"
#include "../components/HitBox.hpp"
#include "../components/Damage.hpp"
#include "../components/Health.hpp"
#include "../components/ShootCooldown.hpp"
#include "../components/BossMobBullet.hpp"
#include "../PacketRepresentation.hpp"

#include <chrono>
#include <cmath>

void boss_mob_ai_system(Registry &r, SparseArray<BossMob> &bosses, SparseArray<Position> &positions, SparseArray<ShootCooldown> &shoot_cooldowns) {
    const float originX = 1500.0f;
    const float originY = 540.0f;
    const float amplitude = 50.0f;
    const float frequency = 0.2f;
    static auto last_update_time = std::chrono::steady_clock::now();
    static float accumulatedTime = 0.0f;
    auto current_time = std::chrono::steady_clock::now();
    float elapsedTime = std::chrono::duration<float>(current_time - last_update_time).count();
    last_update_time = current_time;
    accumulatedTime += elapsedTime;
    for (std::size_t i = 0; i < bosses.size() && i < positions.size() && i < shoot_cooldowns.size(); i++) {
        auto &boss = bosses[i];
        auto &pos = positions[i];
        auto &shoot_cooldown = shoot_cooldowns[i];
        if (boss && pos && shoot_cooldown) {
            float offsetX = amplitude * std::cos(frequency * accumulatedTime * 2.0f * M_PI);
            float offsetY = amplitude * std::sin(frequency * accumulatedTime * 2.0f * M_PI);
            pos.value().setX(static_cast<int>(originX + offsetX));
            pos.value().setY(static_cast<int>(originY + offsetY));
            if (shoot_cooldown.value().canShoot()) {
                BossAnimation boss_animation;
                boss_animation.x = pos.value().getX();
                boss_animation.y = pos.value().getY();
                boss_animation.shooting = true;
                r.get_class_instance<PacketRepresentation>().boss_animations.push_back(boss_animation);
                std::vector<std::pair<int, int>> bullets_positions = {
                    {pos.value().getX() - 350, pos.value().getY() - 100},
                    {pos.value().getX() - 350, pos.value().getY() + 100},
                    {pos.value().getX() - 350, pos.value().getY() + 200},
                    {pos.value().getX() - 350, pos.value().getY() - 200},
                };
                for (const auto& [bullet_x, bullet_y] : bullets_positions) {
                    auto entity = r.spawn_entity();
                    r.add_component(entity, BossMobBullet());
                    r.add_component(entity, Position(bullet_x, bullet_y));
                    r.add_component(entity, Velocity(0, 0));
                    r.add_component(entity, HitBox(30));
                    r.add_component(entity, Damage(20));
                    r.add_component(entity, Health(30));
                    r.add_component(entity, Drawable("src/server/assets/boss_mob_bullet.png")); // Add visual representation
                }
                shoot_cooldown.value().reset();
            }
        }
    }
}
