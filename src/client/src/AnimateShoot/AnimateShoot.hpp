/*
** EPITECH PROJECT, 2025
** B-CPP-500-PAR-5-2-rtype-axel.londas
** File description:
** animate-shoot
*/

#ifndef ANIMATE_SHOOT_HPP_
#define ANIMATE_SHOOT_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

class AnimateShoot {
    public:
        AnimateShoot(sf::Texture *texture);
        ~AnimateShoot();
        void animateShoot(sf::RenderWindow& window);
        void draw(sf::RenderWindow& window);
        void setRotation(float rotation);
        void setPosition(sf::Vector2f position);
        void setFillColor(sf::Color color) { sprite.setColor(color); }
        void setScale(float x, float y);
        sf::Sprite getSprite() { return sprite; }
    protected:
    private:
        sf::Texture texture;
        sf::Sprite sprite;
};


#endif /* !ANIMATE_SHOOT_HPP_ */
