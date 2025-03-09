/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-axel.londas
** File description:
** AnimateSprite
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef ANIMATESPRITE_HPP_
#define ANIMATESPRITE_HPP_

class AnimateSprite {
    public:
        AnimateSprite(sf::Texture *texture, int x, int y, int moving_frame);
        ~AnimateSprite();
        void Animate();
        void draw(sf::RenderWindow& window);
        void setRotation(float rotation);
        void setPosition(sf::Vector2f position);
        void setFillColor(sf::Color color) { _sprite.setColor(color); }
        void setScale(float x, float y);
        sf::FloatRect getGlobalBounds() const { return _sprite.getGlobalBounds(); }
        void setColor(sf::Color color) { _sprite.setColor(color); }
    protected:
    private:
        int moving_frame;
        int leftRect;
        int _x;
        int _y;
        sf::Sprite _sprite;
        sf::Clock _clock;
};

#endif /* !ANIMATESPRITE_HPP_ */
