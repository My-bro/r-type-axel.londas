/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     Gameoverlay                                                                      *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *         ░        ░       ░░        ░        ░        ░░      ░░  ░░░░  ░             *
 *         ▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒  ▒▒▒▒  ▒             *
 *         ▓      ▓▓▓       ▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓      ▓▓▓  ▓▓▓▓▓▓▓        ▓             *
 *         █  ███████  ██████████  ███████  ████  ███████  ████  █  ████  █             *
 *         █        █  ███████        ████  ████        ██      ██  ████  █             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "Gameoverlay.hpp"

Gameoverlay::Gameoverlay(sf::Vector2f initialPosition) : position(initialPosition) {
    clock.restart();
}

void Gameoverlay::draw(sf::RenderWindow& window) {
    for (auto& element : elements) {
        element.second->draw(window);
        // element->draw(window);
    }
}

void Gameoverlay::setPosition(sf::Vector2f newPosition) {
    position = newPosition;
    updateElementsPosition();
}

void Gameoverlay::move(sf::Vector2f offset) {
    position += offset;
    updateElementsPosition();
}

std::shared_ptr<OverlayElement>& Gameoverlay::at(const std::string& name) {
    return elements.at(name);
}

void Gameoverlay::updateElementsPosition() {
    for (auto& element : elements) {
        element.second->updatePosition(position);
    }
}


void Gameoverlay::useHook(const std::string& name) {
    if (hooks.find(name) != hooks.end()) {
        hooks[name]();
    }
}

bool Gameoverlay::deleteElement(const std::string& name) {
    if (elements.find(name) != elements.end()) {
        elements.erase(name);
        return true;
    }
    return false;
}