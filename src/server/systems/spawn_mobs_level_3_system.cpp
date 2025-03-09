
#include <ecs/Registry.hpp>
#include "../components/Mob.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../components/Health.hpp"
#include "../components/HitBox.hpp"
#include "../components/ShootCooldown.hpp"
#include "../components/Drawable.hpp"
#include <random>

void spawn_mobs_level_3_system(Registry &reg)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<double> random_cooldown_dist(0.0, 5.0);

    std::vector<std::pair<int, int>> spawn_positions = {
        {1200, 300},
        {1300, 350},
        {1400, 400},
        {1500, 450},
        {1600, 500},
        {1700, 550} 
    };
    int multiplier = 1;
    for (const auto& [x, y] : spawn_positions) {
        double random_cooldown = random_cooldown_dist(gen);
        auto mob = reg.spawn_entity();
        reg.add_component(mob, Mob());
        reg.add_component(mob, Position(x, y));
        reg.add_component(mob, Velocity(10 * multiplier, 10));
        reg.add_component(mob, Health(100));
        reg.add_component(mob, HitBox(50));
        reg.add_component(mob, ShootCooldown(2, random_cooldown));
        reg.add_component(mob, Drawable("src/server/assets/mob.png"));
        multiplier * -1;
    }
}
