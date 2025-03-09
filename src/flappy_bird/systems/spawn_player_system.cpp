/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** spawn_player_system
*/

#include <ecs/Registry.hpp>
#include "../components/Player.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../components/HitBox.hpp"
#include "../components/Drawable.hpp"

void spawn_player_system(Registry &r)
{
    auto player = r.spawn_entity();
    int width = 167;
    int height = 100;
    r.add_component(player, Player());
    r.add_component(player, Position(350 - width / 2, 550 - height / 2));
    r.add_component(player, Velocity(0, 10));
    r.add_component(player, HitBox(width, height));
    r.add_component(player, Drawable("src/flappy_bird/assets/bird.png"));
}
