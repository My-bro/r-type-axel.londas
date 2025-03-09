/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     MusicHandler                                                                     *
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

#ifndef INCLUDED_MUSIC_HPP
    #define INCLUDED_MUSIC_HPP


#include <iostream>
#include <SFML/Audio.hpp>
#include <map>
#include <string>
#include <memory>
#include <chrono>

class MusicHandler {
public:
    // Load and play background music
    bool loadMusic(const std::string& filePath);
    // Change the main music
    bool changeMusic(const std::string& filePath);
    // Add a sound effect
    bool addSound(const std::string& key, const std::string& filePath);
    // Play a sound effect
    void playSound(const std::string& key);;

    int getBackgroundMusicVolume() const { return backgroundMusic.getVolume(); }
    void setBackgroundMusicVolume(int volume) { backgroundMusic.setVolume(volume);
    _backgroundVolume = volume; }
    int getEffectsVolume() const { return _effectsVolume; }
    void setEffectsVolume(int volume) { _effectsVolume = volume; }

private:
    sf::Music backgroundMusic;
    int _effectsVolume = 1;
    int _backgroundVolume = 5;
    std::map<std::string, std::shared_ptr<sf::SoundBuffer>> soundBuffers;
    std::vector<std::shared_ptr<sf::Sound>> sounds; // Store sounds to keep them alive while playing
    std::map<std::string, std::chrono::steady_clock::time_point> lastPlayTime;
};

#endif
