/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     OverlayElementTemplate                                                           *
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

#ifndef INCLUDED_OVERLAYELEMENTTEMPLATE_HPP
    #define INCLUDED_OVERLAYELEMENTTEMPLATE_HPP

#include <iostream>
#include "OverlayElement.hpp"
#include "AnimateSprite.hpp"
#include "AnimateShoot.hpp"

template <typename T>
class OverlayElementTemplate : public OverlayElement {
    public:
    T element;

    OverlayElementTemplate(const T& elem, sf::Color color, float rotation, sf::Vector2f relativePosition);
    void draw(sf::RenderWindow& window) override;
    void updatePosition(const sf::Vector2f& overlayPosition) override;
    sf::FloatRect getGlobalBounds() const override;
    void setColor(sf::Color color) override;
};

#include "OverlayElementTemplate.tpp"

#endif /* !OVERLAYELEMENTTEMPLATE_HPP_ */