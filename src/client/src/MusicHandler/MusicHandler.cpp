/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     MusicHandler                                                                     *
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

#include "MusicHandler.hpp"

bool MusicHandler::loadMusic(const std::string& filePath) {
    if (!backgroundMusic.openFromFile(filePath)) {
        return false;
    }
    backgroundMusic.setLoop(true);
    // backgroundMusic.setVolume(0);
    backgroundMusic.setVolume(_backgroundVolume);
    backgroundMusic.play();
    return true;
}

bool MusicHandler::changeMusic(const std::string& filePath) {
    backgroundMusic.stop();
    return loadMusic(filePath);
}

bool MusicHandler::addSound(const std::string& key, const std::string& filePath) {
    auto buffer = std::make_shared<sf::SoundBuffer>();
    if (!buffer->loadFromFile(filePath)) {
        return false;
    }
    soundBuffers[key] = buffer;
    return true;
}

void MusicHandler::playSound(const std::string& key) {
    auto now = std::chrono::steady_clock::now();
    auto it = lastPlayTime.find(key);
    if (it != lastPlayTime.end()) {
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - it->second).count();
        if (elapsed < 200) { // Cooldown of 0.3 seconds
            return;
        }
    }
    lastPlayTime[key] = now;

    auto bufferIt = soundBuffers.find(key);
    if (bufferIt != soundBuffers.end()) {
        auto sound = std::make_shared<sf::Sound>();
        sound->setBuffer(*bufferIt->second);
        sound->setVolume(_effectsVolume);
        sound->play();
        sounds.push_back(sound); // Store the sound to keep it alive
    }

    // Delete sound after it's done playing
    for (auto it = sounds.begin(); it != sounds.end();) {
        if ((*it)->getStatus() == sf::Sound::Stopped) {
            it = sounds.erase(it);
        } else {
            ++it;
        }
    }
}