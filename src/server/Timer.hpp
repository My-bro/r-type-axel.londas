/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Timer
*/

#ifndef TIMER_HPP_
    #define TIMER_HPP_

    #include <chrono>

class Timer {
public:
    Timer();
    void reset();
    double elapsed() const;
private:
    std::chrono::time_point<std::chrono::steady_clock> _start_time_point;
};

#endif /* !TIMER_HPP_ */
