/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** healths_collectables_render_system
*/

#include <ecs/Registry.hpp>
#include "../components/HealthCollectable.hpp"
#include "../components/Position.hpp"
#include "../components/Drawable.hpp"
#include <SFML/Graphics.hpp>

void health_collectables_render_system(Registry &r, SparseArray<HealthCollectable> &healths_collectables, SparseArray<Position> &positions, SparseArray<Drawable> &drawables)
{
    sf::RenderWindow &window = r.get_class_instance<sf::RenderWindow>();
    for (std::size_t i = 0; i < healths_collectables.size() && i < positions.size() && i < drawables.size(); i++) {
        auto &health_collectable = healths_collectables[i];
        auto &pos = positions[i];
        auto &drawable = drawables[i];
        if (health_collectable && pos && drawable) {
            auto path = drawable.value().getPath();
            sf::Texture texture;
            sf::Sprite sprite;
            texture.loadFromFile(path);
            sprite.setTexture(texture);
            sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
            sprite.setPosition(pos.value().getX(), pos.value().getY());
            window.draw(sprite);
        }
    }
}
