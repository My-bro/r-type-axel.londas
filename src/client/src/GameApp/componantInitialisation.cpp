/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     componantInitialisation                                                          *
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

#include <iostream>
#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>
#include "Menu.hpp"
#include "Gameoverlay.hpp"
#include "GameApp.hpp"
#include "TextureHandler.hpp"
#include <sstream>
#include <iomanip>

void initializeOverlayElements(Gameoverlay& overlay, const sf::Vector2f& screenSize, sf::Texture *texturePilot) {

    // for flowerman, doctor, ramboum, kwanga the value is 170, 120, 175
    AnimateSprite pilotSprite(texturePilot, 170, 120, 175);
    overlay.addElement("pilotSprite", pilotSprite, sf::Color::White, 0, {20, 10}, [](AnimateSprite& pilot) {
        pilot.setScale(0.8, 0.8);
    });
    sf::RectangleShape shape1({screenSize.x - (screenSize.x / 3), 5});
    overlay.addElement("shap1", shape1, sf::Color::Yellow, 0, {screenSize.x / 3, 100}, [](sf::RectangleShape& shape) {
        shape.setOutlineColor(sf::Color::Yellow);
    });

    sf::RectangleShape shape2({175, 5});
    overlay.addElement("shape2", shape2, sf::Color::Yellow, 145, {(screenSize.x / 3) + 5, 104}, [](sf::RectangleShape& shape) {
        shape.setOutlineColor(sf::Color::Yellow);
    });

    sf::RectangleShape shape3({501, 5});
    overlay.addElement("shape3", shape3, sf::Color::Yellow, 0, {0, 200}, [](sf::RectangleShape& shape) {
        shape.setOutlineColor(sf::Color::Yellow);
    });

}


void initializeOverlayTexts(Gameoverlay& overlay, const sf::Vector2f& screenSize, const sf::Font& font) {
    
    auto lifeText = sf::Text();
    lifeText.setFont(font);
    lifeText.setCharacterSize(40);
    lifeText.setString("Life\n 200/200");
    overlay.addElement("lifeText", lifeText, sf::Color::Yellow, 0, {300, 0}, [](sf::Text& text) {
    });


    
    auto timeText = sf::Text();
    timeText.setFont(font);
    timeText.setCharacterSize(40);
    timeText.setString("Time\n 0");
    overlay.addElement("timeText" , timeText, sf::Color::Yellow, 0, {1000, 0}, [](sf::Text& text) {
    });

    auto scoreText = sf::Text();
    scoreText.setFont(font);
    scoreText.setCharacterSize(40);
    scoreText.setString("Score\n 0");
    overlay.addElement("scoreText", scoreText, sf::Color::Yellow, 0, {1700 , 0}, [](sf::Text& text) {
    });

    auto scoreKills = sf::Text();
    scoreKills.setFont(font);
    scoreKills.setCharacterSize(40);
    scoreKills.setString("Kills\n 00");
    overlay.addElement("scoreKills", scoreKills, sf::Color::Yellow, 0, {650 , 0}, [](sf::Text& text) {
    });

    auto worldtexte = sf::Text();
    worldtexte.setFont(font);
    worldtexte.setCharacterSize(40);
    worldtexte.setString("World\n  0-1");
    overlay.addElement("worldText", worldtexte, sf::Color::Yellow, 0, {1350 , 0}, [](sf::Text& text) {
    });
}

void GameApp::initializeResources(int ac, char** av) {

    // Load textures
    if (!initialiseTexture(_textureHandler)) {
        exit(-1);
    }

    // Load font
    static sf::Font font;
    if (!font.loadFromFile("asset/font/Retro_Gaming.ttf")) {
        exit(-1);
    }

    // Setup displayables
    _PlayerData.setTexture(_textureHandler.getTexture("player"));
    _PlayerBulletData.setTexture(_textureHandler.getTexture("bullet_allied"));
    _PlayerLaserData.setTexture(_textureHandler.getTexture("laser_allied"));

    _LaserCollectableData.setTexture(_textureHandler.getTexture("laser_collectable"));
    _HealthCollectableData.setTexture(_textureHandler.getTexture("health_collectable"));

    _MobData.setTexture(_textureHandler.getTexture("mob"));
    _MobBulletData.setTexture(_textureHandler.getTexture("bullet_enemy"));

    _TurretData.setTexture(_textureHandler.getTexture("turret"));
    _TurretBulletData.setTexture(_textureHandler.getTexture("turret_bullet"));

    _BoulderData.setTexture(_textureHandler.getTexture("bulder"));

    _BossData.setTexture(_textureHandler.getTexture("boss"));
    _BossBulletData.setTexture(_textureHandler.getTexture("boss_bullet"));



    // Load music
    if (!_music->loadMusic("asset/sound/menu_music.wav")) {
        exit(-1);
    }
    if (!_music->addSound("hover", "asset/sound/effect/over.wav")) {
        exit(-1);
    }
    if (!_music->addSound("selected", "asset/sound/effect/selected.wav")) {
        exit(-1);
    }
    if (!_music->addSound("shoot", "asset/sound/effect/sci_fi_shoot.wav")) {
        exit(-1);
    }
    if (!_music->addSound("gunshoot", "asset/sound/effect/shootgun.wav")) {
        exit(-1);
    }


    // MAIN MENU
    sf::Color darkenYellow(255, 255, 0, 150);
    _menu = Menu(font, 120, sf::Color::Yellow, darkenYellow , {600, 400}, _textureHandler.getTexture("arrow"));
    _menu.addMenuItem("Start Game", [this]() { _state = ClientGameState::SELECT_LOBBY; });
    _menu.addMenuItem("Options", [this]() { _state = ClientGameState::OPTIONS; });
    _menu.addMenuItem("Exit", [this]() { _window.close(); });
    _menu.setMusic(_music); // Take the instance of the music handler

    // GAME OVERLAY
    _overlay = Gameoverlay(sf::Vector2f(0, -510));
    initializeOverlayTexts(_overlay, _screenSize, font);
    _overlay.addHook("ActualiseLife", [this]() {
        auto lifeText = std::dynamic_pointer_cast<OverlayElementTemplate<sf::Text>>(_overlay.at("lifeText"));
        lifeText->element.setString("Life\n " + std::to_string(_hp) + "/200");
    });
    _timeText_ = std::dynamic_pointer_cast<OverlayElementTemplate<sf::Text>>(_overlay.at("timeText"));
    _scoreText_ = std::dynamic_pointer_cast<OverlayElementTemplate<sf::Text>>(_overlay.at("scoreText"));
    _scoreKills_ = std::dynamic_pointer_cast<OverlayElementTemplate<sf::Text>>(_overlay.at("scoreKills"));
    _worldText_ = std::dynamic_pointer_cast<OverlayElementTemplate<sf::Text>>(_overlay.at("worldText"));
    initializeOverlayElements(_overlay, _virtualSize, &_selectedPlayerTexture);
    _overlay.addHook("DropDown", [this]() {
            sf::Time elapsed = _overlay.getClock().getElapsedTime();
            if (_state == ClientGameState::GAME) {
                if (elapsed.asMilliseconds() > 10 && _overlay.getPosition().y < 0) {
                    _overlay.move({0, 30});
                    _overlay.getClock().restart();
                }
            }
    });

    _choosePlayer = Gameoverlay(sf::Vector2f(0, -1010));

    // Initialize lobby
    initializeOverlayLobby();

    // Initialize video
    initializeOverlaySelecPlayer();
    initializaOverlayOptions();
}


bool GameApp::initialiseTexture(TextureHandler &textureHandler) {
    // Load your textures
    if (!textureHandler.addTexture("player", "asset/sprite/player.png")) return false;
    if (!textureHandler.addTexture("mob", "asset/sprite/mob.png")) return false;

    if (!textureHandler.addTexture("kwanga-sprite", "asset/sprite/kwanga/kwanga_sprite.png")) return false;
    if (!textureHandler.addTexture("flower-sprite", "asset/sprite/flowerman/flower_sprite.png")) return false;
    if (!textureHandler.addTexture("ramboum-sprite", "asset/sprite/ramboum/ramboum_sprite.png")) return false;
    if (!textureHandler.addTexture("doctor-sprite", "asset/sprite/doctor/doctor_sprite.png")) return false;

    if (!textureHandler.addTexture("arrow", "asset/sprite/arrow.png")) return false;
    if (!textureHandler.addTexture("bullet_allied", "asset/sprite/fireBullet.png")) return false;
    if (!textureHandler.addTexture("laser_allied", "asset/sprite/player_laser.png")) return false;
    if (!textureHandler.addTexture("bullet_enemy", "asset/sprite/mob_bullet.png")) return false;

    if (!textureHandler.addTexture("laser_collectable", "asset/sprite/laser_canon_collectable.png")) return false;
    if (!textureHandler.addTexture("health_collectable", "asset/sprite/health_collectable.png")) return false;

    if (!textureHandler.addTexture("turret", "asset/sprite/turret_mob.png")) return false;
    if (!textureHandler.addTexture("turret_bullet", "asset/sprite/turret_mob_bullet.png")) return false;

    if (!textureHandler.addTexture("bulder", "asset/sprite/kwanga/boulder.png")) return false;

    if (!textureHandler.addTexture("boss", "asset/sprite/boss_mob.png")) return false;
    if (!textureHandler.addTexture("boss_bullet", "asset/sprite/boss_mob_bullet.png")) return false;



    if (!textureHandler.addTexture("close", "asset/sprite/Cross.png")) return false;
    if (!textureHandler.addTexture("chevron", "asset/sprite/Chevron.png")) return false;
    std::cout << "Textures loaded" << std::endl;
    return true;
}

void GameApp::initializaOverlayOptions(void)
{
    _options = Gameoverlay(sf::Vector2f(0, -1010));

    _options.addElement("Close", sf::Sprite() , sf::Color::Yellow, 0, {1700, 0}, [this](sf::Sprite& sprite) {
        sprite.setTexture(*_textureHandler.getTexture("close"));
        sprite.setScale(0.3, 0.3);
    });

    _options.addHook("Close", [this]() {
        sf::Vector2f worldPos = _window.mapPixelToCoords(_mousePosition);
        auto& sprite = std::dynamic_pointer_cast<OverlayElementTemplate<sf::Sprite>>(_options.at("Close"))->element;
        if (sprite.getGlobalBounds().contains(worldPos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            _state = ClientGameState::MENU;
            _menu._haveBeenSelected = true;
            if (_music != nullptr) {
                _music->playSound("selected");
            }
        }
    });

    _options.addHook("DropDown", [this]() {
        sf::Time elapsed = _options.getClock().getElapsedTime();
        if (_state == ClientGameState::OPTIONS) {
            _options._haveBeenSelected = true;
            if (elapsed.asMilliseconds() > 10 && _options.getPosition().y < 0) {
                _options.move({0, 30});
                _options.getClock().restart();
            }
        }
        if (_state != ClientGameState::OPTIONS && _options._haveBeenSelected) {
            if (elapsed.asMilliseconds() > 10 && _options.getPosition().y > -1000) {
                _options.move({0, -30});
                _options.getClock().restart();
            }
        }
    });

    _options.addElement("MusicVolume:", sf::Text("Music Volume", font, 80), sf::Color::Yellow, 0, {150, 100}, [](sf::Text& text) {});
    _options.addElement("MusicVolumeValue", sf::Text("30", font, 30), sf::Color::Yellow, 0, {700, 285}, [](sf::Text& text) {});
    _options.addElement("HorizontalSliderMusic", sf::RectangleShape(sf::Vector2f(500, 10)), sf::Color::Yellow, 0, {150, 300}, [](sf::RectangleShape& rect) {
    });

    int initialVolume = _music->getBackgroundMusicVolume();
    _options.addElement("VerticalSliderMusic", sf::RectangleShape(sf::Vector2f(10, 50)), sf::Color::Yellow, 0, {static_cast<float>(150 + 5 * initialVolume) , 280}, [](sf::RectangleShape& rect) {});
    int musicVolume = _music->getBackgroundMusicVolume();
    _options.addHook("HorizontalSliderMusic", [this, musicVolume]() {
        sf::Vector2f worldPos = _window.mapPixelToCoords(_mousePosition);
        auto& rect = std::dynamic_pointer_cast<OverlayElementTemplate<sf::RectangleShape>>(_options.at("HorizontalSliderMusic"))->element;
        if (rect.getGlobalBounds().contains(worldPos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            float x = worldPos.x - rect.getPosition().x;
            float volume = x / rect.getSize().x * 100;
            _music->setBackgroundMusicVolume(static_cast<int>(volume));
            auto verticalElement = std::dynamic_pointer_cast<OverlayElementTemplate<sf::RectangleShape>>(_options.at("VerticalSliderMusic"));
            sf::RectangleShape& vertical = verticalElement->element;
            int initialVolume = 30;

            // Adjust the calculation to account for the initial volume
            float x_pos = (initialVolume / 100.0f * rect.getSize().x) + (volume / 100.0f * rect.getSize().x) - vertical.getSize().x / 2;
            float y_pos = verticalElement->relativePosition.y;

            // Update the relative position of the vertical slider
            verticalElement->relativePosition = {x_pos, y_pos};

            // Optionally, update the absolute position if needed
            verticalElement->updatePosition(_options.getPosition());

            // set the string of the volume
            auto& text = std::dynamic_pointer_cast<OverlayElementTemplate<sf::Text>>(_options.at("MusicVolumeValue"))->element;
            text.setString(std::to_string(static_cast<int>(volume)));
        }
    });

    _options.addElement("EffectVolume:", sf::Text("Effect Volume", font, 80), sf::Color::Yellow, 0, {900, 100}, [](sf::Text& text) {});
    _options.addElement("EffectVolumeValue", sf::Text("30", font, 30), sf::Color::Yellow, 0, {1500, 285}, [](sf::Text& text) {});
    _options.addElement("HorizontalSliderEffect", sf::RectangleShape(sf::Vector2f(500, 10)), sf::Color::Yellow, 0, {900, 300}, [](sf::RectangleShape& rect) {
    });
    int initialEffectVolume = _music->getEffectsVolume();
    _options.addElement("VerticalSliderEffect", sf::RectangleShape(sf::Vector2f(10, 50)), sf::Color::Yellow, 0, {static_cast<float>(900 + 5 * initialEffectVolume) , 280}, [](sf::RectangleShape& rect) {});
    int effectVolume = _music->getEffectsVolume();
    _options.addHook("HorizontalSliderEffect", [this, effectVolume]() {
        sf::Vector2f worldPos = _window.mapPixelToCoords(_mousePosition);
        auto& rect = std::dynamic_pointer_cast<OverlayElementTemplate<sf::RectangleShape>>(_options.at("HorizontalSliderEffect"))->element;
        if (rect.getGlobalBounds().contains(worldPos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            float x = worldPos.x - rect.getPosition().x;
            float volume = x / rect.getSize().x * 100;
            _music->setEffectsVolume(static_cast<int>(volume));
            auto verticalElement = std::dynamic_pointer_cast<OverlayElementTemplate<sf::RectangleShape>>(_options.at("VerticalSliderEffect"));
            sf::RectangleShape& vertical = verticalElement->element;
            int initialVolume = 30;

            // Adjust the calculation to account for the initial volume
            float x_pos = (initialVolume / 100.0f * rect.getSize().x) + (volume / 100.0f * rect.getSize().x) - vertical.getSize().x / 2 + 750;
            float y_pos = verticalElement->relativePosition.y;

            // Update the relative position of the vertical slider
            verticalElement->relativePosition = {x_pos, y_pos};

            // Optionally, update the absolute position if needed
            verticalElement->updatePosition(_options.getPosition());

            // set the string of the volume
            auto& text = std::dynamic_pointer_cast<OverlayElementTemplate<sf::Text>>(_options.at("EffectVolumeValue"))->element;
            text.setString(std::to_string(static_cast<int>(volume)));
            _music.get()->playSound("hover");
        }
    });

    _options.addElement("OptionsText", sf::Text("Screen scale:", font, 80), sf::Color::Yellow, 0, {150, 350}, [](sf::Text& text) {});

    _options.addElement("LeftChevron", sf::Sprite(), sf::Color::Yellow, 180, {250, 600}, [this](sf::Sprite& sprite) {
        sprite.setTexture(*_textureHandler.getTexture("chevron"));
        sprite.setScale(0.2, 0.2);
    });

    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << _scaleFactor;
    _options.addElement("ScaleValue", sf::Text(stream.str(), font, 40), sf::Color::Yellow, 0, {390, 530}, [](sf::Text& text) {});

    _options.addElement("RightChevron", sf::Sprite(), sf::Color::Yellow, 0, {600, 500}, [this](sf::Sprite& sprite) {
        sprite.setTexture(*_textureHandler.getTexture("chevron"));
        sprite.setScale(0.2, 0.2);
    });

    _options.addHook("ScaleValue", [this]() {
        sf::Vector2f worldPos = _window.mapPixelToCoords(_mousePosition);
        auto& sprite = std::dynamic_pointer_cast<OverlayElementTemplate<sf::Sprite>>(_options.at("LeftChevron"))->element;
        auto& sprite2 = std::dynamic_pointer_cast<OverlayElementTemplate<sf::Sprite>>(_options.at("RightChevron"))->element;
        if (sprite.getGlobalBounds().contains(worldPos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            _scaleFactor -= 0.1;
            if (_scaleFactor < 0.1) {
                _scaleFactor = 0.1;
            }
            std::stringstream stream;
            stream << std::fixed << std::setprecision(1) << _scaleFactor;
            auto& text = std::dynamic_pointer_cast<OverlayElementTemplate<sf::Text>>(_options.at("ScaleValue"))->element;
            text.setString(stream.str());

            // Update screen size and recreate window
            _screenSize = _virtualSize * _scaleFactor;
            _window.create(sf::VideoMode(_screenSize.x, _screenSize.y), "R-Type Client");
            _window.setFramerateLimit(60);

            // Update view
            _view.setSize(_virtualSize);
            _view.setCenter(_virtualSize / 2.f);
            _window.setView(_view);
        }
        if (sprite2.getGlobalBounds().contains(worldPos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            _scaleFactor += 0.1;
            if (_scaleFactor > 1) {
                _scaleFactor = 1;
            }
            std::stringstream stream;
            stream << std::fixed << std::setprecision(1) << _scaleFactor;
            auto& text = std::dynamic_pointer_cast<OverlayElementTemplate<sf::Text>>(_options.at("ScaleValue"))->element;
            text.setString(stream.str());

            // Update screen size and recreate window
            _screenSize = _virtualSize * _scaleFactor;
            _window.create(sf::VideoMode(_screenSize.x, _screenSize.y), "R-Type Client");
            _window.setFramerateLimit(60);

            // Update view
            _view.setSize(_virtualSize);
            _view.setCenter(_virtualSize / 2.f);
            _window.setView(_view);
        }
    });

    _options.addElement("CommandMapingText", sf::Text("Command Maping:", font, 80), sf::Color::Yellow, 0, {150, 600}, [](sf::Text& text) {});

    _options.addElement("LeftText", sf::Text("Left:", font, 40), sf::Color::Yellow, 0, {150, 700}, [](sf::Text& text) {});
    _options.addElement("LeftValue", sf::Text("Q", font, 40), sf::Color::Yellow, 0, {400, 700}, [](sf::Text& text) {});

    _options.addElement("RightText", sf::Text("Right:", font, 40), sf::Color::Yellow, 0, {150, 750}, [](sf::Text& text) {});
    _options.addElement("RightValue", sf::Text("D", font, 40), sf::Color::Yellow, 0, {440, 750}, [](sf::Text& text) {});

    _options.addElement("UpText", sf::Text("Up:", font, 40), sf::Color::Yellow, 0, {150, 800}, [](sf::Text& text) {});
    _options.addElement("UpValue", sf::Text("Z", font, 40), sf::Color::Yellow, 0, {310, 800}, [](sf::Text& text) {});

    _options.addElement("DownText", sf::Text("Down:", font, 40), sf::Color::Yellow, 0, {150, 850}, [](sf::Text& text) {});
    _options.addElement("DownValue", sf::Text("S", font, 40), sf::Color::Yellow, 0, {440, 850}, [](sf::Text& text) {});

    _options.addElement("ShootText", sf::Text("Shoot:", font, 40), sf::Color::Yellow, 0, {150, 900}, [](sf::Text& text) {});
    _options.addElement("ShootValue", sf::Text("Space", font, 40), sf::Color::Yellow, 0, {490, 900}, [](sf::Text& text) {});
}

void GameApp::initializeOverlaySelecPlayer(void)
{
    // Initialize video
    _ramboumVideo = std::make_shared<Video>("asset/video/parsed/Ramboum_parsed", SOUNDSTATUS::SOUND_ON, VIDEOSTATUS::WITHOUT_LOOP, SPAWNSTATUS::DISPLAY , 1, 5);
    _ramboumVideo->setScale(0.3, 0.2);
    _choosePlayer.addElement("Ramboum", _ramboumVideo, sf::Color::Yellow, 0, {450, 50}, [](std::shared_ptr<Video> video) {});
    sf::Text RamboumText = sf::Text("Ramboum", font, 40);
    _choosePlayer.addElement("RamboumText", RamboumText, sf::Color::Yellow, 0, {500, 450}, [](sf::Text& text) {});

    _kwangaVideo = std::make_shared<Video>("asset/video/parsed/Kwanga_parsed", SOUNDSTATUS::SOUND_ON, VIDEOSTATUS::WITHOUT_LOOP, SPAWNSTATUS::DISPLAY , 1, 5);
    _kwangaVideo->setScale(0.3, 0.2);
    _choosePlayer.addElement("Kwanga", _kwangaVideo, sf::Color::Yellow, 0, {450, 550}, [](std::shared_ptr<Video> video) {});
    sf::Text KwangaManText = sf::Text("KwangaMan", font, 40);
    _choosePlayer.addElement("KwangaManText", KwangaManText, sf::Color::Yellow, 0, {500, 950}, [](sf::Text& text) {});

    _evilDoctorVideo = std::make_shared<Video>("asset/video/parsed/EvilDoctor_parsed", SOUNDSTATUS::SOUND_ON, VIDEOSTATUS::WITHOUT_LOOP, SPAWNSTATUS::DISPLAY , 1, 5);
    _evilDoctorVideo->setScale(0.4, 0.27);
    _choosePlayer.addElement("EvilDoctor", _evilDoctorVideo, sf::Color::Yellow, 0, {1050, 50}, [](std::shared_ptr<Video> video) {});
    sf::Text EvilDoctorText = sf::Text("EvilDoctor", font, 40);
    _choosePlayer.addElement("EvilDoctorText", EvilDoctorText, sf::Color::Yellow, 0, {1100, 450}, [](sf::Text& text) {});

    _flowerManVideo = std::make_shared<Video>("asset/video/parsed/FlowerMan_parsed", SOUNDSTATUS::SOUND_ON, VIDEOSTATUS::WITHOUT_LOOP, SPAWNSTATUS::DISPLAY , 1, 5);
    _flowerManVideo->setScale(0.4, 0.27);
    _choosePlayer.addElement("FlowerMan", _flowerManVideo, sf::Color::Yellow, 0, {1050, 550}, [](std::shared_ptr<Video> video) {});
    sf::Text FlowerManText = sf::Text("FlowerMan", font, 40);
    _choosePlayer.addElement("FlowerManText", FlowerManText, sf::Color::Yellow, 0, {1100, 950}, [](sf::Text& text) {});

    _backGroundVideo = std::make_shared<Video>("asset/video/parsed/StarBackground_parsed", SOUNDSTATUS::SOUND_OFF, VIDEOSTATUS::WITH_LOOP, SPAWNSTATUS::DISPLAY , 5, 25);
    _backGroundVideo->setScale(3, 3);
    _backGroundVideo->Play();

    _choosePlayer.addHook("DropDown", [this]() {
        sf::Time elapsed = _choosePlayer.getClock().getElapsedTime();
        if (_state == ClientGameState::SELECT_PLAYER) {
            _choosePlayer._haveBeenSelected = true;
            if (elapsed.asMilliseconds() > 10 && _choosePlayer.getPosition().y < 0) {
                _choosePlayer.move({0, 30});
                _choosePlayer.getClock().restart();
            }
        }
        if (_state != ClientGameState::SELECT_PLAYER && _choosePlayer._haveBeenSelected) {
            if (elapsed.asMilliseconds() > 10 && _choosePlayer.getPosition().y < 1500) {
                _choosePlayer.move({0, 30});
                _choosePlayer.getClock().restart();
            }
        }
    });

    // Launch this code only when video are initialized
    _choosePlayer.addHook("VideoPlayerSelection", [this]() {

        // Create the vector of shared_ptr
        std::vector<std::shared_ptr<Video>> videos = {_ramboumVideo, _kwangaVideo, _evilDoctorVideo, _flowerManVideo};
        videos.erase(std::remove(videos.begin(), videos.end(), nullptr), videos.end());

        // clean every null pointer

        // std::vector<std::shared_ptr<Video>> videos = {_ramboumVideo};
        if (_choosePlayer.getPosition().y >= 0) {
            for (auto &video : videos) {
                if (video == nullptr) {
                    continue;
                }
                if (video->getSprite().getGlobalBounds().contains(_mousePosition.x, _mousePosition.y) ) {
                    // if (_music != nullptr) {
                    //     _music->playSound("hover");
                    // }

                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        if (_music != nullptr) {
                            _music->playSound("selected");
                        }
                        if (video == _ramboumVideo) {
                            _selectedPlayer = 1;
                        } else if (video == _kwangaVideo) {
                            _selectedPlayer = 2;
                        } else if (video == _evilDoctorVideo) {
                            _selectedPlayer = 3;
                        } else if (video == _flowerManVideo) {
                            _selectedPlayer = 4;
                        }
                        _selectedPlayerTexture = *_textureHandler.getTexture(playerTextures[_selectedPlayer]);
                        _state = ClientGameState::GAME;
                    }
                    if (video->GetWorkingStatus() == false) {
                        // Stop every other video
                        for (auto &other : videos) {
                            if (other != video) {
                                other->Stop();
                            }
                        }
                        video->LaunchOnce();
                    }
                }
            }
        }
    });
}


void GameApp::initializeOverlayLobby(void)
{
    _selectLobby = Gameoverlay(sf::Vector2f(370, -1000));

    _selectLobby.addElement("CreateLobby", sf::Text("Add", font, 80), sf::Color::Yellow, 0, {100, 50}, [](sf::Text& text) {});
    _selectLobby.addHook("CreateLobby", [this]() {
        sf::Vector2f worldPos = _window.mapPixelToCoords(_mousePosition);
        auto& text = std::dynamic_pointer_cast<OverlayElementTemplate<sf::Text>>(_selectLobby.at("CreateLobby"))->element;
        if (text.getGlobalBounds().contains(worldPos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            std::cout << "Create Lobby clicked" << std::endl;
            if (_roomClient->isConnected) {
                _roomClient->CreateLobby();
            }
            if (_music != nullptr) {
                _music->playSound("selected");
            }
        }
    });

    _selectLobby.addElement("RefreshText", sf::Text("Refresh", font, 80), sf::Color::Yellow, 0, {600, 50}, [](sf::Text& text) {});
    _selectLobby.addHook("RefreshText", [this]() {
        sf::Vector2f worldPos = _window.mapPixelToCoords(_mousePosition);
        auto& text = std::dynamic_pointer_cast<OverlayElementTemplate<sf::Text>>(_selectLobby.at("RefreshText"))->element;
        if (text.getGlobalBounds().contains(worldPos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            std::cout << "Refresh clicked" << std::endl;
            if (_roomClient->isConnected) {
                _lobbyList = _roomClient->Refresh();
            }
            if (_lobbyList.size() > 0 && _lobbyList[0] != static_cast<uint16_t>(KO)) {
                _biggestNumberLobby = 0;
            } else {
                _biggestNumberLobby = _lobbyList.size();
            }
            if (_music != nullptr) {
                _music->playSound("selected");
            }
        }
    });

    _selectLobby.addHook("RefreshLobby", [this]() {
        // delete every lobby
        for (int i = 0; i < _biggestNumberLobby; i++) {
            std::string lobby_name = "Lobby " + std::to_string(i);
            _selectLobby.deleteElement(lobby_name);
        }

        for (int i = 0; i < _lobbyList.size(); i++) {
            if (_lobbyList[i] == static_cast<u_int16_t>(KO)) {
                break;
            }
            std::string lobby_name = "Lobby " + std::to_string(i);
            std::string string_content = lobby_name + " Port: " + std::to_string(_lobbyList[i]);
            sf::Text text(string_content , font, 80);
            _selectLobby.addElement(lobby_name, text, sf::Color::Yellow, 0, {150, static_cast<float>(350 + (i * 150))}, [](sf::Text& text) {});
        }
    });

    _selectLobby.addHook("LobbyInteraction", [this]() {
        sf::Vector2f worldPos = _window.mapPixelToCoords(_mousePosition);
        for (int i = 0; i < _lobbyList.size(); i++) {
            if (_lobbyList[i] == static_cast<u_int16_t>(KO)) {
                break;
            }
            std::string lobby_name = "Lobby " + std::to_string(i);
            auto& text = std::dynamic_pointer_cast<OverlayElementTemplate<sf::Text>>(_selectLobby.at(lobby_name))->element;
            if (text.getGlobalBounds().contains(worldPos)) {
                sf::Color darkenYellow(255, 255, 0, 150);
                _selectLobby.at(lobby_name)->setColor(darkenYellow);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _selectLobby._action_clicked == false) {
                    std::cout << "Lobby chosen by usr: " << lobby_name << "port: " << _lobbyList[i] << std::endl;


                    int port = _lobbyList[i];
                    std::string host = _clientSettings["host"];
                    _client.emplace(port, host);
                    _serverCom.emplace(&_client.value());
                    _selectLobby._action_clicked = true;

                    // Set the state to GAME
                    _state = ClientGameState::SELECT_PLAYER;
                    if (_music != nullptr) {
                        _music->playSound("selected");
                    }
                }
            }
        }
    });


    _selectLobby.addHook("DropDown", [this]() {
        sf::Time elapsed = _selectLobby.getClock().getElapsedTime();
            if (_state == ClientGameState::SELECT_LOBBY) {
                _selectLobby._haveBeenSelected = true;
                if (elapsed.asMilliseconds() > 10 && _selectLobby.getPosition().y < 0) {
                    _selectLobby.move({0, 30});
                    _selectLobby.getClock().restart();
                }
            }
            if (_state != ClientGameState::SELECT_LOBBY && _selectLobby._haveBeenSelected) {
                if (elapsed.asMilliseconds() > 10 && _selectLobby.getPosition().y < 1500) {
                    _selectLobby.move({0, 30});
                    _selectLobby.getClock().restart();
                }
            }
    });
}
