/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     GameApp                                                                          *
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

#include "GameApp.hpp"
#include <iostream>
#include <functional>
#include "TextureHandler.hpp"
#include "OverlayElementTemplate.hpp"
#include "Parsing.hpp"
#include "ProtocolClient.hpp"
#include "Menu.hpp"
#include "Gameoverlay.hpp"
#include "Displayable.hpp"
#include "ServerCom.hpp"
#include "CRoomClient.hpp"
#include <memory>
#include <thread>
#include <sstream>

void initializeOverlayTexts(Gameoverlay& overlay, const sf::Vector2f& screenSize, const sf::Font& font);
void initializeOverlayElements(Gameoverlay& overlay, const sf::Vector2f& screenSize, sf::Texture *texturePilot);
bool initialiseTexture(TextureHandler& textureHandler);

namespace {
    // Free functions used by the class
    void HelloServer(NetworkClient &client) {
        auto message = ProtocolClient::serializeInput(RIGHT);
        // Send multiple times as an example
        for (int i = 0; i < 5; i++) {
            client.sendMessage(message);
        }
    }
} // end anonymous namespace

void GameApp::getInputs(NetworkClient &client) {
    if (sf::Keyboard::isKeyPressed(keyMap["LEFT"])) {
        auto message = ProtocolClient::serializeInput(LEFT);
        client.sendMessage(message);
    }
    if (sf::Keyboard::isKeyPressed(keyMap["RIGHT"])) {
        auto message = ProtocolClient::serializeInput(RIGHT);
        client.sendMessage(message);
    }
    if (sf::Keyboard::isKeyPressed(keyMap["UP"])) {
        auto message = ProtocolClient::serializeInput(UP);
        client.sendMessage(message);
    }
    if (sf::Keyboard::isKeyPressed(keyMap["DOWN"])) {
        auto message = ProtocolClient::serializeInput(DOWN);
        client.sendMessage(message);
    }
    if (sf::Keyboard::isKeyPressed(keyMap["SHOOT"])) {
        auto message = ProtocolClient::serializeInput(SHOOT);
        client.sendMessage(message);
    }
}

GameApp::GameApp(int ac, char** av)
{
    // Parse arguments to set up network
    Parsing parser(ac, av);
    _clientSettings = parser.getClientSettings();
    unsigned short port = std::stoi(_clientSettings["port"]);

    _roomClient.emplace();
    _roomClient->connectToServer();

    // Parse arguments to set up key bindings
    std::ifstream inputFile("configuration_files/inputs.ini");
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string action, equal, key;
        if (!(iss >> action >> equal >> key)) {
            continue;
        }
        keyMap[action] = mapStringToKey(key);
    }

    // Font
    font.loadFromFile("asset/font/Retro_Gaming.ttf");

    // Window setup
    _virtualSize = {1920, 1080};
    _scaleFactor = 0.5f;
    _screenSize = _virtualSize * _scaleFactor;

    _window.create(sf::VideoMode(_screenSize.x, _screenSize.y), "R-Type Client");
    _window.setFramerateLimit(60);

    // View setup
    _view.setSize(_virtualSize);
    _view.setCenter(_virtualSize / 2.f);
    _window.setView(_view);

    // Initialize game state
    _state = ClientGameState::MENU;
    _gameStartInitialized = false;
    _fakeIterator = 0;

    // Initialize resources
    initializeResources(ac, av);
}

sf::Keyboard::Key GameApp::mapStringToKey(const std::string& key)
{
    if (key == "Z") return sf::Keyboard::Z;
    if (key == "Q") return sf::Keyboard::Q;
    if (key == "S") return sf::Keyboard::S;
    if (key == "D") return sf::Keyboard::D;
    if (key == "Space") return sf::Keyboard::Space;
    return sf::Keyboard::Unknown;
}

void GameApp::processInputs() {
    // Poll events (menu, close window, etc.)
    sf::Event event;
    while (_window.pollEvent(event)) {
        _menu.handleEvent(event, _window);
        if (event.type == sf::Event::Closed) {
            _window.close();
        }

        // Check for hover of the lobbys
        sf::Vector2i mousePosition = sf::Mouse::getPosition(_window);
    }

    // Mouse position
    _mousePosition = sf::Mouse::getPosition(_window);

    // Send keyboard inputs to server
    if (_client) {
        getInputs(_client.value());
    }
}

void GameApp::update() {
    // Increment a fake iterator for demonstration
    _fakeIterator++;

    // Update overlay text
    if (_timeText_) {
        _timeText_->element.setString("Time\n " + std::to_string(_fakeIterator));
    }
    if (_scoreText_) {
        _scoreText_->element.setString("Score\n " + std::to_string(_fakeIterator));
    }

    // Check for new packets
    if (_serverCom) {
        std::optional<packet> received_pack = _serverCom->getPacket();
        if (received_pack.has_value()) {
            packet Input_pack = received_pack.value();
            // _PlayerLifeData.setLife(Input_pack.players);
            _PlayerData.MoveSprite(Input_pack.players, Input_pack.player_count);
            _PlayerBulletData.MoveSprite(Input_pack.player_bullets, Input_pack.player_bullet_count);
            _PlayerLaserData.MoveSprite(Input_pack.player_lasers, Input_pack.player_laser_count);
            _LaserCollectableData.MoveSprite(Input_pack.laser_collectables, Input_pack.laser_collectable_count);
            _HealthCollectableData.MoveSprite(Input_pack.health_collectables, Input_pack.health_collectable_count);

            _MobData.MoveSprite(Input_pack.enemies, Input_pack.enemy_count);
            _MobBulletData.MoveSprite(Input_pack.enemy_bullets, Input_pack.enemy_bullet_count);

            _TurretData.MoveSprite(Input_pack.turrets, Input_pack.turret_count);
            _TurretBulletData.MoveSprite(Input_pack.turret_bullets, Input_pack.turret_bullet_count);

            _BoulderData.MoveSprite(Input_pack.boulders, Input_pack.boulder_count);

            _BossData.MoveSprite(Input_pack.bosses, Input_pack.boss_count);
            _BossBulletData.MoveSprite(Input_pack.boss_bullets, Input_pack.boss_bullet_count);

            _worldText_->element.setString("World\n " + std::to_string(Input_pack.level));

            _hp = Input_pack.players[0].health;
        }
    }

    // Launch only once on GAME
    if (_state == ClientGameState::GAME && !_gameStartInitialized) {
        _gameStartInitialized = true;
        _music->changeMusic("asset/sound/main_theme.wav");
        if (_client) {
            HelloServer(_client.value());
        }
    }

    // Move menu or overlay if needed
    _menu.moveMenu(_state);

    // Overlay HOOK
    _overlay.useHook("DropDown");
    _overlay.useHook("ActualiseLife");
    _choosePlayer.useHook("DropDown");
    _selectLobby.useHook("DropDown");
    _selectLobby.useHook("RefreshText");
    _selectLobby.useHook("CreateLobby");
    _selectLobby.useHook("RefreshLobby");
    _selectLobby.useHook("LobbyInteraction");
    _choosePlayer.useHook("VideoPlayerSelection");
    _options.useHook("Close");
    _options.useHook("DropDown");
    _options.useHook("HorizontalSliderMusic");
    _options.useHook("HorizontalSliderEffect");
    _options.useHook("ScaleValue");
}

void GameApp::render() {
    _window.clear(sf::Color::Black);

    _backGroundVideo->draw(_window);

    _PlayerLifeData.draw(_window);

    _PlayerData.draw(_window);
    _PlayerBulletData.draw(_window);
    _PlayerLaserData.draw(_window);
    _LaserCollectableData.draw(_window);
    _HealthCollectableData.draw(_window);

    _MobData.draw(_window);
    _MobBulletData.draw(_window);

    _TurretData.draw(_window);
    _TurretBulletData.draw(_window);

    _BoulderData.draw(_window);

    _BossData.draw(_window);
    _BossBulletData.draw(_window);


    _menu.draw(_window);
    _overlay.draw(_window);
    _options.draw(_window);
    _choosePlayer.draw(_window);
    _selectLobby.draw(_window);

    _window.display();
}

void GameApp::run() {
    while (_window.isOpen()) {
        if (!_roomClient->isConnected) {
            _roomClient->connectToServer();
        }
        processInputs();
        update();
        render();
    }

    if (_ramboumVideo) {
        std::cout << "Closing video" << std::endl;
        _ramboumVideo->Close();
    }
    if (_kwangaVideo) {
        std::cout << "Closing video" << std::endl;
        _kwangaVideo->Close();
    }
    if (_evilDoctorVideo) {
        std::cout << "Closing video" << std::endl;
        _evilDoctorVideo->Close();
    }
    if (_flowerManVideo) {
        std::cout << "Closing video" << std::endl;
        _flowerManVideo->Close();
    }
    if (_backGroundVideo) {
        std::cout << "Closing video" << std::endl;
        _backGroundVideo->Close();
    }

    std::cout << "Closing client 1" << std::endl;
    //this->_serverCom.value().Close();
    std::cout << "Closing client 1.1" << std::endl;

}
