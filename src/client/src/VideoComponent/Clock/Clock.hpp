/*
** EPITECH PROJECT, 2024
** bs_rtype
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_
#define DEFAULT_FRAME_RATE 60

#include <chrono>
#include <atomic>
#include <mutex>

class Clock {
public:
    Clock(int frameRate = DEFAULT_FRAME_RATE);

    std::chrono::milliseconds getElapsedTime() const;

    void set_up(double serverTime_s);
    void update();
    void restart();

    double getElapsedTime_ms() const;
    double getElapsedTime_s() const;
    double getElapsedTime_m() const;

private:

    std::chrono::steady_clock::time_point _startTime;
    int _frameRate;
    int _frameIndex;
    mutable std::mutex _mutex;
    double _elapsedTime_ms = 0;
    double _elapsedTime_s = 0;
    double _elapsedTime_m = 0;
};

#endif /* !CLOCK_HPP_ */
