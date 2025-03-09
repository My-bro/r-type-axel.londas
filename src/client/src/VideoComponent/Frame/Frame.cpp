/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, Jan, 2025                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     Frame                                                                            *
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

#include "Frame.hpp"


int Frames::getNubberofFrameLoaded() {
    int count = 0;
    bool onloaded = false;
    std::unique_lock<std::mutex> lock(_mutex);
    for (int i = 0; i < _frameLoaded.size(); i++) {
        if (_frameLoaded[i] && i > _startFrame) {
            count++;
            onloaded = true;
        }
        if (!_frameLoaded[i] && i > _startFrame && onloaded) {
            break;
        }
    }
    lock.unlock();
    return count;
}

bool Frames::starterFrameLoaded() {
    bool isStarterFrameLoaded = false;
    for (int i = 0; i < _frameLoaded.size(); i++) {
        if (!_frameLoaded[i]) {
            break;
        }
        if (_frameLoaded[i] && i == _startFrame) {
            isStarterFrameLoaded = true;
            break;
        }

    }
    return isStarterFrameLoaded;
}

int Frames::numberStarterFrameLoaded() {
    int count = 0;
    for (int i = 0; i < _frameLoaded.size(); i++) {
        if (_frameLoaded[i] && i < _startFrame) {
            count++;
        } else {
            break;
        }

    }
    return count;
}


int Frames::getFirstFrameAfterStartFrame(std::vector<int> ThreadFrameIndex) {
    int firstFrameAfterStartFrame = 0;
    for (int i = 0; i < ThreadFrameIndex.size(); i++) {
        if (!_frameLoaded[ThreadFrameIndex[i]] &&ThreadFrameIndex[i] < this->_startFrame) {
            firstFrameAfterStartFrame = ThreadFrameIndex[i];
            return firstFrameAfterStartFrame;
        }
    }
    return 0;
}

void Frames::startFrameLoader()
{
    // distribution of frames to threads each "will have" the same amount of frames to handle
    // for example if we have 100 frames and 4 threads each thread will handle 25 frames one after the other
    _frameIndexMap.clear();
    for (int i = 0; i < _framenumber; ++i) {
        int threadId = i % _nbThreads;
        _frameIndexMap[threadId].push_back(i);
    }

    // start worker threads
    for (int i = 0; i < _nbThreads; i++) {
        _frameLoaderThreads.push_back(std::thread(&Frames::FrameLoaderThread, this, i, _frameIndexMap[i]));
    }
}


void  Frames::RestartCondvar(int *i, int indexThread) {
    if (_restart) {
        //std::cout << "Thread " << indexThread << " waiting for restart" << std::endl;
        _restartResponse[indexThread] = true;

        int  numberStarterFrameLoad = numberStarterFrameLoaded();

        if (starterFrameLoaded()) {
            *i = getFirstFrameAfterStartFrame(_frameIndexMap[indexThread]);
        } else {
            *i = 0;
        }

        //std::cout << "i restart " << *i << std::endl;
    }
}

void Frames::FrameLoaderThread(int indexThread, std::vector<int> ThreadFrameIndex) {
    while (true) {

        for (int i = 0; i < ThreadFrameIndex.size(); i++) {
            //std::cout << "i = " << i << std::endl;
            if (_close) {
                return;
            }

            int frame = ThreadFrameIndex[i];
            int numberFrameLoaded = getNubberofFrameLoaded();
            // bool isStarterFrameLoaded = starterFrameLoaded();
            int  numberStarterFrameLoad = numberStarterFrameLoaded();



            int z = 0;
            // while (numberFrameLoaded >= _frameBatch) {
            //     std::this_thread::sleep_for(std::chrono::milliseconds(5));

            //     // std::cout << "Thread " << indexThread << " waiting for frame to be loaded" << std::endl;
            //     //std::cout << "numberFrameLoaded " << numberFrameLoaded << std::endl;
            //     //std::cout << "wait" << std::endl;
            //     //std::cout << "Number of frame loaded " << numberFrameLoaded << std::endl;
            //     //std::cout << "waiting for frame to be loaded " << z << std::endl;

            //     //isStarterFrameLoaded = starterFrameLoaded();



            //     // put in a function

            //     // Check if we need to restart equivalent of a condition variable
            //     numberFrameLoaded = getNubberofFrameLoaded();
            //     RestartCondvar(&i, indexThread);
            //     z++;
            // }

            // Check if the frame is already loaded
            if (!_frameLoaded[frame]) {
                // Instance a new texture
                // if (frame < _frameIndex) {
                //     std::cout << "Frame " << frame << " already loaded!!!!!!!!!!!!!!!" << std::endl;
                //     //continue;
                // }

                std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
                // std::cout << "Loading frame " << frame << std::endl;
                if (!texture->loadFromFile(_framePaths[frame])) {
                    std::cerr << "Error: could not load texture " << _framePaths[frame] << std::endl;
                    continue;
                }
                // Lock the mutex to other worker threads
                std::unique_lock<std::mutex> lock(_mutex);
                _textureMap[frame] = texture;
                _frameLoaded[frame] = true;
                lock.unlock();
            }

            // Check if we need to restart equivalent of a condition variable
            RestartCondvar(&i, indexThread);
        }
    }
}