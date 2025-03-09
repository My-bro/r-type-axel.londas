/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** wait_spawn_players_system
*/

#include <ecs/Registry.hpp>
#include "../network/NetworkServer.hpp"
#include "../components/Player.hpp"
#include "../components/NetworkPlayer.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../components/Controllable.hpp"
#include "../components/Health.hpp"
#include "../components/HitBox.hpp"
#include "../components/Drawable.hpp"
#include "../components/ShootCooldown.hpp"
#include "../components/BasicCanon.hpp"

void spawn_players_system(Registry &r)
{
    auto ids = r.get_class_instance<NetworkServer>().getClientIds();
    std::vector<std::pair<int, int>> positions = {
        {300, 135},
        {300, 405}
        // {300, 675},
        // {300, 945}
    };

    for (std::size_t i = 0; i < ids.size() && i < positions.size(); ++i) {
        auto player = r.spawn_entity();
        r.add_component(player, Player());
        r.add_component(player, NetworkPlayer(ids[i], i + 1));
        r.add_component(player, Position(positions[i].first, positions[i].second));
        r.add_component(player, Velocity(20, 20));
        r.add_component(player, Controllable());
        r.add_component(player, Health(200));
        r.add_component(player, HitBox(50));
        r.add_component(player, ShootCooldown(0.2));
        r.add_component(player, BasicCanon());
        r.add_component(player, Drawable("src/server/assets/player.png"));
    }
}
