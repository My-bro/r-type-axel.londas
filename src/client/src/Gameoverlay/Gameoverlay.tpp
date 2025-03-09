/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     Gameoverlay                                                                      *
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

#include "Gameoverlay.hpp"

template <typename T, typename Func>
void Gameoverlay::addElement(std::string name, const T& element, sf::Color color, float rotation, sf::Vector2f relativePosition, Func adjustFunc) {
    OverlayElementTemplate<T> overlayElement(element, color, rotation, relativePosition);
    adjustFunc(overlayElement.element);
    overlayElement.updatePosition(position);

    // check if element already exists
    if (elements.find(name) != elements.end()) {
        elements.erase(name);
    }
    elements.insert({name, std::make_shared<OverlayElementTemplate<T>>(overlayElement)});
}

template <typename Func, typename... Args>
void Gameoverlay::addHook(const std::string& name, Func&& func, Args&&... args) {
    hooks[name] = [func = std::forward<Func>(func), ...args = std::forward<Args>(args)]() mutable {
        func(args...);
    };
}



