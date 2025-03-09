/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** player_render_system
*/

#include <ecs/Registry.hpp>
#include <SFML/Graphics.hpp>
#include "../components/Player.hpp"
#include "../components/Position.hpp"
#include "../components/Drawable.hpp"

void player_render_system(Registry &r, SparseArray<Player> &players, SparseArray<Position> &positions, SparseArray<Drawable> &drawables)
{
    sf::RenderWindow &window = r.get_class_instance<sf::RenderWindow>();
    for (std::size_t i = 0; i < players.size() && i < positions.size() && i < drawables.size(); i++) {
        auto &player = players[i];
        auto &pos = positions[i];
        auto &drawable = drawables[i];

        if (player && pos && drawable) {
            auto path = drawable.value().getPath();
            sf::Texture texture;
            sf::Sprite sprite;
            texture.loadFromFile(path);
            sprite.setTexture(texture);
            sprite.setPosition(pos.value().getX(), pos.value().getY());
            window.draw(sprite);
        }
    }
}
