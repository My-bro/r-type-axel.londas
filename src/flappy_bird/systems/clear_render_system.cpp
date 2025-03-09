/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** clear_render_system
*/

#include <ecs/Registry.hpp>
#include <SFML/Graphics.hpp>

void clear_render_system(Registry &r)
{
    sf::RenderWindow &window = r.get_class_instance<sf::RenderWindow>();
    window.clear();
}
