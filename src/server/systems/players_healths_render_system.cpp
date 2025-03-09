/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** players_healths_render
*/

#include <ecs/Registry.hpp>
#include "../components/Player.hpp"
#include "../components/Health.hpp"
#include "../components/Position.hpp"
#include <SFML/Graphics.hpp>

void players_healths_render_system(Registry &r, SparseArray<Player> &players, SparseArray<Health> &healths, SparseArray<Position> &positions)
{
    sf::RenderWindow &window = r.get_class_instance<sf::RenderWindow>();
    for (std::size_t i = 0; i < players.size() && i < healths.size() && i < positions.size(); i++) {
        auto &player = players[i];
        auto &health = healths[i];
        auto &pos = positions[i];
        if (player && health && pos) {
            sf::RectangleShape health_bar(sf::Vector2f(health.value().getHealth(), 10));
            health_bar.setFillColor(sf::Color::Green);
            health_bar.setPosition(pos.value().getX(), pos.value().getY() - 20);
            window.draw(health_bar);
        }
    }
}
