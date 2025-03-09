/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     OverlayElement                                                                   *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef INCLUDED_OVERLAYELEMENT_HPP
    #define INCLUDED_OVERLAYELEMENT_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

class OverlayElement {
public:
    sf::Color color;
    float rotation;
    sf::Vector2f relativePosition;
    sf::Vector2f absolutePosition;

    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void updateRelativePosition(const sf::Vector2f& newRelativePosition) {
        relativePosition = newRelativePosition;
    }
    virtual void updatePosition(const sf::Vector2f& overlayPosition) {
        absolutePosition = overlayPosition + relativePosition;
    }
    virtual sf::FloatRect getGlobalBounds() const = 0;
    virtual void setColor(sf::Color color) = 0;
    virtual ~OverlayElement() = default;
};

#endif
