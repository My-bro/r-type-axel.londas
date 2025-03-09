/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** mobs_bullets_render_system
*/

#include <ecs/Registry.hpp>
#include "../components/MobBullet.hpp"
#include "../components/Position.hpp"
#include "../components/Drawable.hpp"

void mobs_bullets_render_system(Registry &r, SparseArray<MobBullet> &bullets, SparseArray<Position> &positions, SparseArray<Drawable> &drawables)
{
    sf::RenderWindow &window = r.get_class_instance<sf::RenderWindow>();
    for (size_t i = 0; i < bullets.size() && i < positions.size() && i < drawables.size(); i++) {
        auto &bullet = bullets[i];
        auto &pos = positions[i];
        auto &drawable = drawables[i];
        if (bullet && pos && drawable) {
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
