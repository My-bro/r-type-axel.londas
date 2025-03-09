/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-axel.londas
** File description:
** AnimateSprite
*/

#include "AnimateSprite.hpp"

AnimateSprite::AnimateSprite(sf::Texture *texture, int x, int y, int moving_frame)
{
    _sprite.setTexture(*texture);
    this->moving_frame = moving_frame;
    this->leftRect = 0;
    _x = x;
    _y = y;
    _clock.restart();
}

AnimateSprite::~AnimateSprite()
{
    this->moving_frame = 0;
    this->leftRect = 0;
    _x = 0;
    _y = 0;
}

void AnimateSprite::Animate()
{
    sf::Time elapsed = _clock.getElapsedTime();
    if (elapsed.asSeconds() > 0.5f) {
       _sprite.setTextureRect(sf::IntRect(this->leftRect, 0, this->_x, this->_y));
        if (this->leftRect != 350) {
            _sprite.setTextureRect(sf::IntRect(this->leftRect, 0, this->_x, this->_y));
            this->leftRect += this->moving_frame;
        } else {
            _sprite.setTextureRect(sf::IntRect(this->leftRect, 0, this->_x, this->_y));
            this->leftRect = 0;
        }
        _clock.restart();
    }
}

void AnimateSprite::draw(sf::RenderWindow& window)
{
    window.draw(_sprite);
}

void AnimateSprite::setRotation(float rotation)
{
    _sprite.setRotation(rotation);
}

void AnimateSprite::setPosition(sf::Vector2f position)
{
    _sprite.setPosition(position);
}

void AnimateSprite::setScale(float x, float y)
{
    _sprite.setScale(x, y);
}
