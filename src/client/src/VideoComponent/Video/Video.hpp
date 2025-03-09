/*
** EPITECH PROJECT, 2024
** bs_rtype
** File description:
** Video
*/

#ifndef VIDEO_HPP_
#define VIDEO_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <memory>
#include <vector>
#include <thread>
#include <mutex>
#include "Frame.hpp"

enum class SOUNDSTATUS {
    SOUND_OFF = 0,
    SOUND_ON = 1,
};
enum class VIDEOSTATUS {
    WITH_LOOP = 0,
    WITHOUT_LOOP = 1,
};
enum class SPAWNSTATUS {
    NO_DISPLAY = 0,
    DISPLAY = 1,
};

class Video {
    public:
        Video() = default;
        Video(const std::string &path, SOUNDSTATUS sound, VIDEOSTATUS loop, SPAWNSTATUS spawn,  int nbThreads, int frameBatch);
        void ActualiseFrame();
        sf::Sprite &getSprite() { return *_sprite; }
        void draw(sf::RenderWindow &window);

        // Setter
        void setScale(sf::Vector2f scale) { _scale = scale; }
        void setScale(float x, float y) { _scale = {x, y}; }
        void setPosition(sf::Vector2f position) { _position = position; }
        void setPosition(float x, float y) { _position = {x, y}; }
        void setRotation(float angle) { _sprite->setRotation(angle); }
        void setFillColor(sf::Color color) { _sprite->setColor(color); }
        sf::Clock _clock;

        sf::FloatRect getGlobalBounds() const;
        void setColor(sf::Color color);

        // Getter
        bool GetWorkingStatus() { return _on_working; }

        // UI Animation Clock
        sf::Clock _animationClock;

        // operator
        Video &operator=(const Video &other) {
            return *this;
        }

        // Control the video Methods
        void Play();
        void Stop();
        void RestartVideo();
        void LaunchOnce();
        void Close();

    protected:
    private:

        Frames _frames;

        void ControlUpdate();


        sf::Vector2f _position = {0, 0};
        sf::Vector2f _scale = {1, 1};
        std::string Findbase_name(const std::string &path);

        bool IsDirectory(const std::string &path);
        bool OpenAudio(const std::string &path);
        bool OpenYml(const std::string &path);
        bool OpenFrames(const std::string &path);
        bool Loadtexture(const std::string &path);
        bool Loadtexture(const std::string &path, size_t index);

        SOUNDSTATUS _soundStatus;
        VIDEOSTATUS _videoStatus;
        SPAWNSTATUS _spawnStatus;
        bool _end_of_video = false;
        bool _first_launch = true;
        bool _on_working = false;
        bool _on_pause = false;

        std::shared_ptr<sf::Sprite> _sprite = std::make_shared<sf::Sprite>();
        std::shared_ptr<sf::Texture> _current_texture = std::make_shared<sf::Texture>();
        std::unique_ptr<sf::Texture> _spawn_texture = std::make_unique<sf::Texture>();
        std::unique_ptr<sf::Sound> _sound = std::make_unique<sf::Sound>();
        std::unique_ptr<sf::SoundBuffer> _soundBuffer;
        std::unique_ptr<sf::Music> _music =  std::make_unique<sf::Music>();
};

#endif /* !VIDEO_HPP_ */
