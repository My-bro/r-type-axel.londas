/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Timer
*/

#include "Timer.hpp"

Timer::Timer() : _start_time_point(std::chrono::steady_clock::now()) {}

void Timer::reset()
{
    this->_start_time_point = std::chrono::steady_clock::now();
}

double Timer::elapsed() const
{
    auto end_time_point = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end_time_point - this->_start_time_point;
    return elapsed_seconds.count();
}
