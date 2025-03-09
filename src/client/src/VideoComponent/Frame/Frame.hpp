/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, Jan, 2025                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     Frame                                                                            *
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

#ifndef INCLUDED_FRAME_HPP
    #define INCLUDED_FRAME_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <memory>
#include <vector>
#include <thread>
#include <mutex>
#include <optional>
#include <map>

class Frames {
    public:
            Frames() = default;
            void FrameLoaderThread(int indexThread, std::vector<int> frameIndex);
            void startFrameLoader();
            int getNubberofFrameLoaded();
            bool starterFrameLoaded();
            int numberStarterFrameLoaded();
            int getFirstFrameAfterStartFrame(std::vector<int> ThreadFrameIndex);

            std::string _name;
            int _frameRate = 0;
            int _framenumber = 0;
            int _frameIndex = 0;

            int _nbThreads = 4;
            std::map<int, std::vector<int>> _frameIndexMap;
            std::map<int , std::optional<std::shared_ptr<sf::Texture>>> _textureMap;

            std::vector<bool> _frameLoaded;
            int _textureQueueIndex = 0;
            int _frameBatch = 10;
            int _startFrame = 50; // Start loading frame 10

            std::vector<std::thread> _frameLoaderThreads;
            bool _is_frame_loading = false;
            std::vector<std::string> _framePaths;
            bool _restart = false;
            bool _close = false;
            std::mutex _mutex;
            std::vector<bool> _restartResponse;
            bool _on_working_ptr;
    private:
        void RestartCondvar(int *i, int indexThread);
};

#endif
