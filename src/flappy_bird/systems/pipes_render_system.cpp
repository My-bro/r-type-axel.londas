/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** render_system
*/

#include <ecs/Registry.hpp>
#include <SFML/Graphics.hpp>
#include "../components/Pipe.hpp"
#include "../components/Drawable.hpp"
#include "../components/Position.hpp"
#include "../components/HitBox.hpp"

void pipes_render_system(Registry &r, SparseArray<Pipe> &pipes, SparseArray<Drawable> &drawables, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxes)
{
    sf::RenderWindow &window = r.get_class_instance<sf::RenderWindow>();
    for (std::size_t i = 0; i < pipes.size() && i < drawables.size() && i < positions.size() && i < hitboxes.size(); i++) {
        auto &pipe = pipes[i];
        auto &drawable = drawables[i];
        auto &pos = positions[i];
        auto &hitbox = hitboxes[i];

        if (pipe && drawable && pos && hitbox) {
            auto path = drawable.value().getPath();
            sf::Texture texture;
            sf::Sprite sprite;
            texture.loadFromFile(path);
            sprite.setTexture(texture);
            if (pipe.value().getType() == Pipe::Type::TOP) {
                sprite.setTextureRect(sf::IntRect(0, 800 - hitbox.value().getHeight(), 195, hitbox.value().getHeight()));
            } else {
                sprite.setTextureRect(sf::IntRect(0, 0, 195, hitbox.value().getHeight()));
            }
            sprite.setOrigin(0, 0);
            sprite.setPosition(pos.value().getX(), pos.value().getY());
            window.draw(sprite);
        }
    }
}
