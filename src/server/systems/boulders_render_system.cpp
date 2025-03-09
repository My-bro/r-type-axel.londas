/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** boulders_render_system
*/

#include <ecs/Registry.hpp>
#include "../components/Boulder.hpp"
#include "../components/Position.hpp"
#include "../components/Drawable.hpp"

void boulders_render_system(Registry &r, SparseArray<Boulder> &boulders, SparseArray<Position> &positions, SparseArray<Drawable> &drawables)
{
    sf::RenderWindow &window = r.get_class_instance<sf::RenderWindow>();
    for (size_t i = 0; i < boulders.size() && i < positions.size() && i < drawables.size(); i++) {
        auto &boulder = boulders[i];
        auto &pos = positions[i];
        auto &drawable = drawables[i];
        if (boulder && pos && drawable) {
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
