/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** laster_canons_collectables_render
*/

#include <ecs/Registry.hpp>
#include "../components/LaserCanonCollectable.hpp"
#include "../components/Position.hpp"
#include "../components/Drawable.hpp"
#include "../components/HitBox.hpp"
#include <SFML/Graphics.hpp>

void laser_canons_collectables_render_system(Registry &r, SparseArray<LaserCanonCollectable> &laser_canons, SparseArray<Position> &positions, SparseArray<Drawable> &drawables)
{
    sf::RenderWindow &window = r.get_class_instance<sf::RenderWindow>();
    for (std::size_t i = 0; i < laser_canons.size() && i < positions.size() && i < drawables.size(); i++) {
        auto &laser_canon = laser_canons[i];
        auto &pos = positions[i];
        auto &drawable = drawables[i];
        if (laser_canon && pos && drawable) {
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
