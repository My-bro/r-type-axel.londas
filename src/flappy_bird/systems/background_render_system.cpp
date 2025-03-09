/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** background_render_system
*/

#include <ecs/Registry.hpp>
#include <SFML/Graphics.hpp>

void background_render_system(Registry &r)
{
    sf::RenderWindow &window = r.get_class_instance<sf::RenderWindow>();
    sf::Texture texture;
    texture.loadFromFile("src/flappy_bird/assets/background.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    window.draw(sprite);
}
