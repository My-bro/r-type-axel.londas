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

#include "OverlayElementTemplate.hpp"
#include "Video.hpp"

template <typename T>
OverlayElementTemplate<T>::OverlayElementTemplate(const T& elem, sf::Color color, float rotation, sf::Vector2f relativePosition)
: element(elem) {
    this->color = color;
    this->rotation = rotation;
    this->relativePosition = relativePosition;
}

template <typename T>
void OverlayElementTemplate<T>::draw(sf::RenderWindow& window) {
    if constexpr (std::is_same_v<T, AnimateSprite>) {
        element.setScale(1.5, 1.5);
        element.Animate();
        element.draw(window);
    } else if constexpr (std::is_same_v<T, sf::Sprite>) {
        element.setColor(color);
        element.setRotation(rotation);
        element.setPosition(absolutePosition);
        window.draw(element);
    } else if constexpr (std::is_same_v<T, std::shared_ptr<Video>>) {
        element->setPosition(absolutePosition);
        element->draw(window);
    } else {
        element.setFillColor(color);
        element.setRotation(rotation);
        element.setPosition(absolutePosition);
        window.draw(element);
    }
}

template <typename T>
void OverlayElementTemplate<T>::updatePosition(const sf::Vector2f& overlayPosition) {
    absolutePosition = overlayPosition + relativePosition;
    if constexpr (std::is_same_v<T, std::shared_ptr<Video>>) {
        element->setPosition(absolutePosition);
    } else {
        element.setPosition(absolutePosition);
    }
}

template <typename T>
sf::FloatRect OverlayElementTemplate<T>::getGlobalBounds() const {
    if constexpr (std::is_same_v<T, std::shared_ptr<Video>>) {
        return element->getGlobalBounds();
    } else {
        return element.getGlobalBounds();
    }
}

template <typename T>
void OverlayElementTemplate<T>::setColor(sf::Color color) {
    this->color = color;
}
