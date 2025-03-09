/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     Displayable                                                                      *
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

#include "Displayable.hpp"
#include "AnimateShoot.hpp"

Displayable::Displayable() : texture(nullptr) {}

Displayable::Displayable(const Displayable& other) : sprites(other.sprites), texture(other.texture) {}

Displayable& Displayable::operator=(const Displayable& other) {
    if (this != &other) {
        sprites = other.sprites;
        texture = other.texture;
    }
    return *this;
}

void Displayable::setTexture(sf::Texture* texture) {
    this->texture = texture;
    for (auto& sprite : sprites) {
        sprite.setTexture(*texture);
    }
}

void Displayable::addSprite() {
    if (texture) {
        sf::Sprite sprite;
        sprite.setTexture(*texture);
        sprites.push_back(sprite);
    }
}

void Displayable::setPosition(size_t index, sf::Vector2f position) {
    if (index < sprites.size()) {
        sprites[index].setPosition(position);
    }
}

void Displayable::draw(sf::RenderWindow& window) {
    for (auto& sprite : sprites) {
        window.draw(sprite);
    }
    window.draw(lifeBar);
}

sf::Sprite& Displayable::operator[](size_t index) {
    return sprites.at(index);
}


template <>
void Displayable::setLife<PlayerData>(const std::vector<PlayerData>& data)
{
    for (size_t i = 0; i < data.size() && i < sprites.size(); ++i) {
        this->lifeBar.setSize(sf::Vector2f(data[i].health * 10, 5));
        lifeBar.setFillColor(sf::Color::Green);
        lifeBar.setOutlineColor(sf::Color::White);
        lifeBar.setOutlineThickness(1);
        lifeBar.setPosition(50, 100);
    }
}

template <>
void Displayable::MoveSprite<PlayerData>(const std::vector<PlayerData>& data, int count) {
    // delete every sprite in the vector
    this->sprites.clear();
    // resize the vector to the size of the data
    this->sprites.resize(data.size());

    for (size_t i = 0; i < count && i < sprites.size(); ++i) {
        // Make the sprite at index i have the texture
        sprites[i].setTexture(*texture);
        sprites[i].setPosition(data[i].x, data[i].y);
    }
}


template <>
void Displayable::MoveSprite<MobData>(const std::vector<MobData>& data, int count) {
    // delete every sprite in the vector
    this->sprites.clear();
    // resize the vector to the size of the data
    this->sprites.resize(data.size());

    for (size_t i = 0; i < count && i < sprites.size(); ++i) {
        // Make the sprite at index i have the texture
        sprites[i].setTexture(*texture);
        sprites[i].setPosition(data[i].x, data[i].y);
    }
}

template <>
void Displayable::MoveSprite<PlayerBulletData>(const std::vector<PlayerBulletData>& data, int count) {
    this->sprites.clear();
    this->sprites.resize(data.size());

    for (size_t i = 0; i < count && i < sprites.size(); ++i) {
        sprites[i].setTexture(*texture);
        sprites[i].setPosition(data[i].x, data[i].y);
    }
}

template <>
void Displayable::MoveSprite<PlayerLaserData>(const std::vector<PlayerLaserData>& data, int count) {
    this->sprites.clear();
    this->sprites.resize(data.size());

    for (size_t i = 0; i < count && i < sprites.size(); ++i) {
        sprites[i].setTexture(*texture);
        sprites[i].setPosition(data[i].x, data[i].y);
    }
}

template <>
void Displayable::MoveSprite<LaserCollectableData>(const std::vector<LaserCollectableData>& data, int count) {
    this->sprites.clear();
    this->sprites.resize(data.size());

    for (size_t i = 0; i < count && i < sprites.size(); ++i) {
        sprites[i].setTexture(*texture);
        sprites[i].setPosition(data[i].x, data[i].y);
    }
}

template <>
void Displayable::MoveSprite<HealthCollectableData>(const std::vector<HealthCollectableData>& data, int count) {
    this->sprites.clear();
    this->sprites.resize(data.size());

    for (size_t i = 0; i < count && i < sprites.size(); ++i) {
        sprites[i].setTexture(*texture);
        sprites[i].setPosition(data[i].x, data[i].y);
    }
}

template <>
void Displayable::MoveSprite<MobBulletData>(const std::vector<MobBulletData>& data, int count) {
    this->sprites.clear();
    this->sprites.resize(data.size());

    for (size_t i = 0; i < count && i < sprites.size(); ++i) {
        sprites[i].setTexture(*texture);
        sprites[i].setPosition(data[i].x, data[i].y);
    }
}

template <>
void Displayable::MoveSprite<TurretData>(const std::vector<TurretData>& data, int count) {
    this->sprites.clear();
    this->sprites.resize(data.size());

    for (size_t i = 0; i < count && i < sprites.size(); ++i) {
        sprites[i].setTexture(*texture);
        sprites[i].setPosition(data[i].x, data[i].y);
    }
}

template <>
void Displayable::MoveSprite<TurretBulletData>(const std::vector<TurretBulletData>& data, int count) {
    this->sprites.clear();
    this->sprites.resize(data.size());

    for (size_t i = 0; i < count && i < sprites.size(); ++i) {
        sprites[i].setTexture(*texture);
        sprites[i].setPosition(data[i].x, data[i].y);
    }
}

template <>
void Displayable::MoveSprite<BoulderData>(const std::vector<BoulderData>& data, int count) {
    this->sprites.clear();
    this->sprites.resize(data.size());

    for (size_t i = 0; i < count && i < sprites.size(); ++i) {
        sprites[i].setTexture(*texture);
        sprites[i].setPosition(data[i].x, data[i].y);
    }
}

template <>
void Displayable::MoveSprite<BossData>(const std::vector<BossData>& data, int count) {
    this->sprites.clear();
    this->sprites.resize(data.size());

    for (size_t i = 0; i < count && i < sprites.size(); ++i) {
        sprites[i].setTexture(*texture);
        sprites[i].setPosition(data[i].x, data[i].y);
    }
}

template <>
void Displayable::MoveSprite<BossBulletData>(const std::vector<BossBulletData>& data, int count) {
    this->sprites.clear();
    this->sprites.resize(data.size());

    for (size_t i = 0; i < count && i < sprites.size(); ++i) {
        sprites[i].setTexture(*texture);
        sprites[i].setPosition(data[i].x, data[i].y);
    }
}
