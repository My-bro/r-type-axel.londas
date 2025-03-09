/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** score_render_system
*/

#include <ecs/Registry.hpp>
#include <SFML/Graphics.hpp>
#include "../GameState.hpp"

void score_render_system(Registry &r)
{
    sf::RenderWindow &window = r.get_class_instance<sf::RenderWindow>();
    auto &gameState = r.get_class_instance<GameState>();
    sf::Font font;
    font.loadFromFile("src/flappy_bird/assets/font.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString(std::to_string(gameState.getScore()));
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::White);
    text.setPosition(325, 200);
    window.draw(text);
}
