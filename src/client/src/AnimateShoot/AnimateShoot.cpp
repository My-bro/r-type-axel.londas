/*
** EPITECH PROJECT, 2025
** B-CPP-500-PAR-5-2-rtype-axel.londas
** File description:
** animate-shoot
*/

#include "AnimateShoot.hpp"

AnimateShoot::AnimateShoot(sf::Texture *texture)
{
    sprite.setTexture(*texture);
}

AnimateShoot::~AnimateShoot()
{
    sprite.setTexture(sf::Texture());
}

void AnimateShoot::animateShoot(sf::RenderWindow& window)
{
    sprite.setTextureRect(sf::IntRect(0, 0, 15, 10));
    static sf::Clock _clock;
    sf::Time elapsed = _clock.getElapsedTime();
    if (elapsed.asSeconds() > 0.1f) {
        if (sprite.getTextureRect().left != 45) {
            sprite.setTextureRect(sf::IntRect(sprite.getTextureRect().left + 15, 0, 15, 10));
        } else {
            sprite.setTextureRect(sf::IntRect(45, 0, 15, 10));
        }
        _clock.restart();     
    }
    window.draw(sprite);
}

void AnimateShoot::draw(sf::RenderWindow& window)
{
    // if (sprite.getTexture() != nullptr) {
    //     window.draw(sprite);
    //     animateShoot();
    // }
}

void AnimateShoot::setRotation(float rotation)
{
    sprite.setRotation(rotation);
}

void AnimateShoot::setPosition(sf::Vector2f position)
{
    sprite.setPosition(position);
}

void AnimateShoot::setScale(float x, float y)
{
    sprite.setScale(x, y);
}
