/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** mobs_render_system
*/

#include <ecs/Registry.hpp>
#include "../components/Mob.hpp"
#include "../components/Position.hpp"
#include "../components/Drawable.hpp"

void mobs_render_system(Registry &r, SparseArray<Mob> &mobs, SparseArray<Position> &positions, SparseArray<Drawable> &drawables)
{
    sf::RenderWindow &window = r.get_class_instance<sf::RenderWindow>();
    for (size_t i = 0; i < mobs.size() && i < positions.size() && i < drawables.size(); i++) {
        auto &mob = mobs[i];
        auto &pos = positions[i];
        auto &drawable = drawables[i];
        if (mob && pos && drawable) {
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
