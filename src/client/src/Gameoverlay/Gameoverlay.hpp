/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas [WSL: Ubuntu]                  *
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

#ifndef INCLUDED_GAMEOVERLAY_HPP
    #define INCLUDED_GAMEOVERLAY_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include "OverlayElement.hpp"
#include "OverlayElementTemplate.hpp"
#include "AnimateSprite.hpp"
#include "ClientGameState.hpp" 
#include <memory>

class Gameoverlay {
    public:
        using HookFunction = std::function<void()>;

        Gameoverlay() = default;
        Gameoverlay(sf::Vector2f initialPosition);
        template <typename T, typename Func>
        void addElement(std::string name, const T& element, sf::Color color, float rotation, sf::Vector2f relativePosition, Func adjustFunc);
        bool deleteElement(const std::string& name);
        void draw(sf::RenderWindow& window);
        void setPosition(sf::Vector2f newPosition);
        void move(sf::Vector2f offset);
        sf::Clock& getClock() { return clock; }
        sf::Vector2f& getPosition() { return position; }
        std::shared_ptr<OverlayElement>& at(const std::string& name); // get element by name
        // Define a type for the hook functions

        template <typename Func, typename... Args>
        void addHook(const std::string& name, Func&& func, Args&&... args);

        // Method to use a hook
        void useHook(const std::string& name);

        std::unordered_map<std::string, std::shared_ptr<OverlayElement>> getElements() { return elements; }

        bool _haveBeenSelected = false;
        bool _action_clicked = false;

    private:
        void updateElementsPosition();

        sf::Clock clock;
        sf::Vector2f position;
        std::unordered_map<std::string, std::shared_ptr<OverlayElement>> elements;
        std::unordered_map<std::string, HookFunction> hooks;
};

#include "Gameoverlay.tpp"

#endif
