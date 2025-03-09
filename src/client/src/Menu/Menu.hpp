/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Thu, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     Menu                                                                             *
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



#ifndef MENU_HPP_
#define MENU_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <functional>
#include "ClientGameState.hpp"
#include "MusicHandler.hpp"
#include <memory>

struct MenuItem {
    sf::Text text;
    std::function<void()> action;
};

class Menu {
public:
    Menu() = default;

    Menu(sf::Font& font, unsigned int fontSize, sf::Color textColor, sf::Color hoverColor, sf::Vector2f position, sf::Texture *texture);
    void addMenuItem(const std::string& label, std::function<void()> action);
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
    void moveMenu(ClientGameState state);
    void setHoverColor(sf::Color hoverColor);
    sf::Clock& getClock();
    void setMusic(std::shared_ptr<MusicHandler> &music);
    bool _haveBeenSelected = false;

private:
    sf::Clock clock;
    std::vector<MenuItem> items;
    sf::Font* font;
    unsigned int fontSize;
    sf::Color textColor;
    sf::Color hoverColor;
    sf::Vector2f position;
    sf::Sprite arrowSprite;
    bool isHovered = false;
    //bool lastHovered = false;
    std::vector<bool> itemHovered;

    std::shared_ptr<MusicHandler> _music;
};

#endif /* !MENU_HPP_ */
