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

#ifndef INCLUDED_GAMEAPP_HPP
    #define INCLUDED_GAMEAPP_HPP

#include <SFML/Graphics.hpp>
#include "NetworkClient.hpp"
#include "ServerCom.hpp"
#include "Displayable.hpp"
#include "Menu.hpp"
#include "Gameoverlay.hpp"
#include "ClientGameState.hpp"
#include "MusicHandler.hpp"
#include "TextureHandler.hpp"
#include "Video.hpp"
#include "CRoomClient.hpp"
#include <memory>

/**
 * @class GameApp
 * @brief A class that encapsulates the entire R-Type client application
 */
class GameApp {
public:
    GameApp(int ac, char** av);
    ~GameApp() = default;

    void run(); // Main loop

private:
    // Window & View
    sf::RenderWindow _window;
    sf::View _view;
    sf::Vector2f _screenSize;
    sf::Vector2f _virtualSize;
    bool mousePressed;
    float _scaleFactor = 0.5f;
    sf::Vector2i _mousePosition;

    // Networking
    std::optional<NetworkClient> _client;
    std::optional<ServerCom> _serverCom;
    std::optional<CRoomClient> _roomClient;

    // Game Logic
    ClientGameState _state;
    bool _gameStartInitialized;
    int _fakeIterator;
    sf::Keyboard::Key mapStringToKey(const std::string& key);
    std::map<std::string, sf::Keyboard::Key> keyMap;

    // Displayables
    Displayable _PlayerData; // done
    Displayable _PlayerAnimation;
    Displayable _PlayerBulletData; // done
    Displayable _PlayerLaserData;
    Displayable _PlayerLifeData;
    Displayable _MobData; // done
    Displayable _MobAnimation;
    Displayable _MobBulletData; // done
    Displayable _TurretData;
    Displayable _TurretAnimation;
    Displayable _TurretBulletData;
    Displayable _BoulderData;
    Displayable _HealthCollectableData; // done
    Displayable _LaserCollectableData; // done
    Displayable _BossData;
    Displayable _BossAnimation;
    Displayable _BossBulletData;
    Displayable _BossBulletAnimation;
    Displayable _mobs;
    Displayable _bullets;

    // Textures handler
    TextureHandler _textureHandler;

    // Menu & Overlay
    Menu _menu;
    Gameoverlay _overlay;
    std::shared_ptr<OverlayElementTemplate<sf::Text>> _timeText_;
    std::shared_ptr<OverlayElementTemplate<sf::Text>> _scoreText_;
    std::shared_ptr<OverlayElementTemplate<sf::Text>> _scoreKills_;
    std::shared_ptr<OverlayElementTemplate<sf::Text>> _worldText_;
    Gameoverlay _choosePlayer;
    Gameoverlay _selectLobby;
    Gameoverlay _options;

    std::unordered_map<std::string, std::string> _clientSettings;

    std::vector<uint16_t> _lobbyList;
    int _biggestNumberLobby = 0;

    std::shared_ptr<OverlayElementTemplate<sf::Text>> _musicVolumeText;
    int _selectedPlayer = 1;

    int _hp = 200;

    std::unordered_map<int, std::string> playerTextures = {
        {1, "ramboum-sprite"},
        {2, "kwanga-sprite"},
        {3, "doctor-sprite"},
        {4, "flower-sprite"}
    };

    sf::Texture _selectedPlayerTexture;
    // Music
    std::shared_ptr<MusicHandler> _music = std::make_shared<MusicHandler>();

    // Font
    sf::Font font;

    // Video
    std::shared_ptr<Video> _ramboumVideo = nullptr;
    std::shared_ptr<Video> _kwangaVideo = nullptr;
    std::shared_ptr<Video> _evilDoctorVideo = nullptr;
    std::shared_ptr<Video> _flowerManVideo = nullptr;
    std::shared_ptr<Video> _backGroundVideo = nullptr;

private:
    bool initialiseTexture(TextureHandler& textureHandler);
    void initializeResources(int ac, char** av);
    void initializeOverlaySelecPlayer(void);
    void initializaOverlayOptions(void);
    void initializeOverlayLobby(void);
    void getInputs(NetworkClient &client);
    void getElements();
    void processInputs();
    void update();
    void render();
};

#endif
