/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     Displayable                                                                      *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef INCLUDED_DISPLAYABLE_HPP
    #define INCLUDED_DISPLAYABLE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "AnimateShoot.hpp"
#include "ProtocolClient.hpp"

class Displayable
{
    private:
        std::vector<sf::Sprite> sprites;
        sf::Texture* texture;
        sf::RectangleShape lifeBar;

    protected:
    public:
        Displayable();
        Displayable(const Displayable& other);
        Displayable& operator=(const Displayable& other);
        ~Displayable() = default;

        void setTexture(sf::Texture* texture);
        void setPosition(size_t index, sf::Vector2f position);
        void addSprite();
        void draw(sf::RenderWindow& window);

        template <typename T>
        void MoveSprite(const std::vector<T>& data, int count);
        template <typename T>
        void setLife(const std::vector<T>& data);
        std::vector<sf::Sprite> getSprites() { return sprites; }
        sf::Sprite& operator[](size_t index);
};


#endif