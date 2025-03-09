/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     Menu                                                                             *
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

#include "Menu.hpp"

Menu::Menu(sf::Font& font, unsigned int fontSize, sf::Color textColor, sf::Color hoverColor, sf::Vector2f position, sf::Texture *texture) {
    this->font = &font;
    this->fontSize = fontSize;
    this->textColor = textColor;
    this->hoverColor = hoverColor;
    this->position = position;
    this->clock.restart();
    this->arrowSprite.setTexture(*texture);
    this->arrowSprite.setScale(0.5, 0.5);
}

void Menu::addMenuItem(const std::string& label, std::function<void()> action) {
    std::cout << "step 0" << std::endl;
    MenuItem item;
    item.text.setFont(*font);
    item.text.setString(label);
    item.text.setCharacterSize(fontSize);
    item.text.setFillColor(textColor);
    item.text.setPosition(position.x, position.y + items.size() * (fontSize + 30)); // Spacing between items
    item.action = action;
    items.push_back(item);
    itemHovered.push_back(false);
}

void Menu::setPosition(sf::Vector2f position) {
    this->position = position;
    for (size_t i = 0; i < items.size(); i++) {
        items[i].text.setPosition(position.x, position.y + i * (fontSize + 10));
    }
}

sf::Vector2f Menu::getPosition() {
    return position;
}

void Menu::draw(sf::RenderWindow& window) {
    for (auto& item : items) {
        window.draw(item.text);
    }
    if (isHovered) {
        window.draw(arrowSprite);
    }
}

void Menu::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    isHovered = false;
    for (unsigned int i = 0; i < items.size(); i++) {
        MenuItem &item = items[i];
        if (item.text.getGlobalBounds().contains(mousePos)) {
            arrowSprite.setPosition(item.text.getPosition().x - 300, item.text.getPosition().y - 0);
            //item.text.setFillColor(hoverColor); // Change color on hover
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (_music != nullptr) {
                    _music->playSound("selected");
                }
                item.action();
            }
            if (!itemHovered[i]) {
                if (_music != nullptr) {
                    _music->playSound("hover");
                }
            }
            isHovered = true;
            itemHovered[i] = true;
        } else {
            itemHovered[i] = false;
            //item.text.setFillColor(textColor); // Reset color
        }
    }
}

void Menu::moveMenu(ClientGameState state) {
    sf::Time elapsed = this->getClock().getElapsedTime();
    if (state != ClientGameState::MENU) {
        sf::Vector2f position = this->getPosition();
        if (elapsed.asMilliseconds() > 10 && position.y < 1300) {
            this->setPosition({position.x, position.y + 30});
            this->getClock().restart();
        }
    }
    if (state == ClientGameState::MENU && _haveBeenSelected) {
        if (elapsed.asMilliseconds() > 10 && this->getPosition().y > 400) {
            this->setPosition({this->getPosition().x, this->getPosition().y - 30});
            this->getClock().restart();
        }
    }
}

void Menu::setHoverColor(sf::Color hoverColor) {
    this->hoverColor = hoverColor;
}

sf::Clock& Menu::getClock() {
    return clock;
}

void Menu::setMusic(std::shared_ptr<MusicHandler> &music) {
    _music = music;
}