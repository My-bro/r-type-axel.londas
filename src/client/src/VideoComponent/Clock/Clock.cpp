/*
** EPITECH PROJECT, 2024
** bs_rtype
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock(int frameRate): _frameRate(frameRate), _frameIndex(0) {
    _startTime = std::chrono::steady_clock::now();
}

std::chrono::milliseconds Clock::getElapsedTime() const {
    auto now = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now - _startTime);
}

void Clock::set_up(double serverTime_s) {
    std::lock_guard<std::mutex> lock(_mutex);
    auto now = std::chrono::steady_clock::now();
    auto serverDuration = std::chrono::duration<double>(serverTime_s);
    _startTime = now - std::chrono::duration_cast<std::chrono::steady_clock::duration>(serverDuration);
}

void Clock::update() {
    auto now = std::chrono::steady_clock::now();
    if (_frameIndex >= _frameRate) {
        _frameIndex = 0;
    }
        std::lock_guard<std::mutex> lock(_mutex);
        _elapsedTime_ms = std::chrono::duration_cast<std::chrono::milliseconds>(now - _startTime).count();
        _elapsedTime_s = std::chrono::duration_cast<std::chrono::seconds>(now - _startTime).count();
        _elapsedTime_m = std::chrono::duration_cast<std::chrono::minutes>(now - _startTime).count();
    if (_elapsedTime_ms >= 1000 / _frameRate) {
        _frameIndex++;
    }
}

void Clock::restart() {
    std::lock_guard<std::mutex> lock(_mutex);
    _startTime = std::chrono::steady_clock::now();
    _frameIndex = 0;
    _elapsedTime_ms = 0;
    _elapsedTime_s = 0;
    _elapsedTime_m = 0;
}

double Clock::getElapsedTime_ms() const {
    std::lock_guard<std::mutex> lock(_mutex);
    return _elapsedTime_ms;
}

double Clock::getElapsedTime_s() const {
    std::lock_guard<std::mutex> lock(_mutex);
    return _elapsedTime_s;
}

double Clock::getElapsedTime_m() const {
    std::lock_guard<std::mutex> lock(_mutex);
    return _elapsedTime_m;
}