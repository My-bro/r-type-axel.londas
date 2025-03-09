/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Mon, Jan, 2025                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     Video                                                                            *
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

#include "Video.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <future>
#include <thread>
#include <condition_variable>

bool Video::IsDirectory(const std::string &path)
{
    return std::filesystem::is_directory(path);
}

bool Video::OpenAudio(const std::string &path)
{
    std::ifstream file(path);
    if (file.is_open()) {
        _music->openFromFile(path);
        return true;
    } else {
        return false;
    }
}

bool Video::OpenYml(const std::string &path)
{
    std::ifstream file(path);
    std::string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string key;
            std::string value;
            if (std::getline(iss, key, ':') && std::getline(iss, value)) {
                key.erase(0, key.find_first_not_of(" \t"));
                key.erase(key.find_last_not_of(" \t") + 1);
                value.erase(0, value.find_first_not_of(" \t"));
                value.erase(value.find_last_not_of(" \t") + 1);
                if (key == "fps") {
                    std::cout << "fps: <" << value << ">" << std::endl;
                    _frames._frameRate = std::stoi(value);
                }
                if (key == "frame_count") {
                    _frames._framenumber = std::stoi(value);
                    std::cout << "frame_count: <" << value << ">" << std::endl;
                }
                if (key == "video_file") {
                    _frames._name = value;
                    std::cout << "video_file: <" << value << ">" << std::endl;
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

bool Video::OpenFrames(const std::string &path)
{
    std::vector<std::string> fileNames;
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            fileNames.push_back(entry.path().filename().string());
        }
    }

    std::sort(fileNames.begin(), fileNames.end());
    for (auto& fileName : fileNames) {
        fileName = path + fileName;
    }
    _frames._framePaths = fileNames;
    return true;
}


std::string Video::Findbase_name(const std::string &path)
{
    std::string base_name = path;
    size_t pos = base_name.find_last_of("/\\");
    if (pos != std::string::npos) {
        base_name.erase(0, pos + 1);
    }
    base_name.erase(base_name.size() - 7);
    return base_name;
}

Video::Video(const std::string &path, SOUNDSTATUS sound_arg, VIDEOSTATUS loop_arg, SPAWNSTATUS spawn,int nbThreads, int frameBatch)
{
    _clock.restart();
    _animationClock.restart();

    _soundStatus = sound_arg;
    _videoStatus = loop_arg;
    _spawnStatus = spawn;


    // store of each element of the parsing
    std::string base_name = Findbase_name(path);
    std::string copy_path = path;
    std::string mp3_path = path + "/" + base_name + ".mp3";
    std::string yml_path = path + "/info.yml";
    std::string frame_path = path + "/frames/";

    std::cout << mp3_path << std::endl;
    std::cout << yml_path << std::endl;
    std::cout << frame_path << std::endl;

    // Check if the paths are correct
    try {
        if (!IsDirectory(path)) {
            throw std::runtime_error("Error: path is not a directory");
        }
        if (!OpenAudio(mp3_path)) {
            throw std::runtime_error("Error: audio file not found");
        }
        if (!OpenYml(yml_path)) {
            throw std::runtime_error("Error: yml file not found");
        }
        if (!OpenFrames(frame_path)) {
            throw std::runtime_error("Error: frames not found");
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // set Frame hyperparameters
    _frames._nbThreads = nbThreads;
    _frames._frameBatch = frameBatch;

    // Set the homemade condition variable to false
    _frames._restartResponse.resize(_frames._nbThreads, false);

    //starting a thread
    _frames._frameLoaded.resize(_frames._framenumber, false);

    // Function who launche the thread
    _frames.startFrameLoader();

    // we wait until the amount of frame in the batch is loaded
    // while (_frames.getNubberofFrameLoaded() < _frames._frameBatch) {}

    // load spawn texture
    _spawn_texture->loadFromFile(_frames._framePaths[0]);
}

void Video::ControlUpdate()
{


    if (_frames._frameIndex >= _frames._framenumber || _first_launch) {
        _first_launch = false;
        if (_videoStatus == VIDEOSTATUS::WITHOUT_LOOP && _frames._frameIndex >= _frames._framenumber) {
            _end_of_video = true;
            _music->setVolume(0);
            _on_working = false;
        }
        if (_music->getStatus() == sf::SoundSource::Stopped) {
        } else {
            //_music->stop();
        }
        //_music->play();
        if (_soundStatus == SOUNDSTATUS::SOUND_OFF) {
            _music->setVolume(0);
        }
    }
}


void Video::RestartVideo()
{
    // Reset frame index if it exceeds the number of frames
    _frames._frameIndex = 0;

    // Reset all frames free the memory !!! execpt the first "_startFrame" frames
    std::unique_lock<std::mutex> lock(_frames._mutex);

    // Setup status bools for worker threads execpt starter frames

    for (int i = 0; i < _frames._textureMap.size(); ++i) {
        auto& texture = _frames._textureMap[i];
        if (texture && i > _frames._startFrame) {
            texture.reset(); // Free the memory
            texture = nullptr;
            _frames._frameLoaded[i] = false;
        }
    }

    _frames._restart = true;

    lock.unlock();

    // while everyone has restarted
    while (true) {
        bool allRestarted = false;
        int respcout = 0;
        for (bool restart : _frames._restartResponse) {
            if (!restart) {
                respcout = 0;
            }
            if (restart) {
                respcout++;
            }
            if (respcout == _frames._nbThreads) {
                allRestarted = true;
            }
        }
        // std::cout << "respcout: " << respcout << std::endl;
        // std::cout << "allRestarted: " << allRestarted << std::endl;
        // std::cout << "nbThreads: " << _frames._nbThreads << std::endl;
        if (allRestarted) {
            _frames._restart = false;
            std::fill(_frames._restartResponse.begin(), _frames._restartResponse.end(), false);
            break;
        }
    }

    // while (_frames.getNubberofFrameLoaded() < _frames._frameBatch) {

    // }

    _clock.restart();
    _music->stop();
    _music->play();
}

void Video::ActualiseFrame()
{
    // Handle the time between each frame
    sf::Time elapsed = _clock.getElapsedTime();
    float frameTime = 1000.0f / _frames._frameRate;

    // Control the video
    ControlUpdate();

    //std::cout << "frame index: " << _frames._frameIndex << std::endl;

    if (!_on_working) {
        return;
    }


    // Change the frame
    if (elapsed.asMilliseconds() > frameTime) {
        _clock.restart();

    //std::cout << "aaaaaa" << std::endl;
        // Handle the case when the frame is at the end
        if (_frames._frameIndex >= _frames._framenumber) {
            RestartVideo();
        }

        // Change the frame
        if (_frames._frameLoaded[_frames._frameIndex]) {
    
            auto textureOpt = _frames._textureMap[_frames._frameIndex];

            // Check if the texture is loaded
            if (textureOpt.has_value()) {
                _current_texture = textureOpt.value();
            }


            // Set the texture to the sprite
            if (_current_texture) {
                _sprite->setTexture(*_current_texture);
                _sprite->setScale(_scale);
                _sprite->setPosition(_position);

                    if (_frames._frameLoaded[_frames._frameIndex - 1] && _frames._frameIndex - 1 > _frames._startFrame) {
                        std::unique_lock<std::mutex> lock(_frames._mutex);
                        _frames._textureMap[_frames._frameIndex - 1].reset(); // Free the memory
                        _frames._textureMap[_frames._frameIndex - 1] = nullptr;
                        _frames._frameLoaded[_frames._frameIndex - 1] = false;
                        lock.unlock();
                }
            }

        } else {
            std::unique_lock<std::mutex> lock(_frames._mutex);
            _frames._frameIndex++;
            lock.unlock();
            return;
        }
        std::unique_lock<std::mutex> lock(_frames._mutex);
        _frames._frameIndex++;
        lock.unlock();
    }
}

void Video::Play()
{
    _on_working = true;
    _on_pause = false;
    _music->play();
}

void Video::Stop()
{
    this->RestartVideo();
    this->_on_working = false;
    this->_frames._on_working_ptr = false;
    this->_on_pause = false;
    _first_launch = true;
    _end_of_video = false;
    this->_music->setVolume(0);
    std::unique_lock<std::mutex> lock(_frames._mutex);
    _frames._frameIndex = 0;
    lock.unlock();
}

void Video::Close()
{
    // close threads
    for (auto &t : _frames._frameLoaderThreads) {
        _frames._close = true;
        t.join();
    }

    // free memory
    for (int i = 0; i < _frames._textureMap.size(); ++i) {
        auto& texture = _frames._textureMap[i];
        if (texture) {
            texture.reset(); // Free the memory
            texture = nullptr;
        }
    }

    // free music
    _music->stop();
    _music->setVolume(0);
}

void Video::LaunchOnce()
{
    if (_videoStatus == VIDEOSTATUS::WITHOUT_LOOP) {
        this->RestartVideo();
        this->_on_working = true;
        this->_frames._on_working_ptr = true;
        this->_on_pause = false;
        _first_launch = true;
        _end_of_video = false;
        this->_music->setVolume(30);
    }
}


void Video::draw(sf::RenderWindow &window)
{
    if (_spawnStatus == SPAWNSTATUS::DISPLAY && !_on_working) {
        _sprite->setTexture(*_spawn_texture);
        _sprite->setScale(_scale);
        _sprite->setPosition(_position);
        window.draw(*_sprite);
    }
    if (_on_working) {
        ActualiseFrame();
        if (_end_of_video) {
            return;
        }
        window.draw(*_sprite);
    }
}

sf::FloatRect Video::getGlobalBounds() const
{
    return this->_sprite->getGlobalBounds();
}

void Video::setColor(sf::Color color)
{
    return this->_sprite->setColor(color);
}
