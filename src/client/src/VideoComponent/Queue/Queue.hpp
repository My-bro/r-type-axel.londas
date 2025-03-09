/*
** EPITECH PROJECT, 2024
** bs_rtype
** File description:
** Queue
*/

#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include <deque>
#include <stdexcept>

template<typename T>
class Queue {
private:
    std::deque<T> elements;

public:
    void enqueue(const T& element) {
        elements.push_back(element);
    }

    void dequeue() {
        if (elements.empty()) {
            throw std::out_of_range("Queue<>::dequeue(): empty queue");
        }
        elements.pop_front();
    }

    T& front() {
        if (elements.empty()) {
            throw std::out_of_range("Queue<>::front(): empty queue");
        }
        return elements.front();
    }

    bool empty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

#endif /* !QUEUE_HPP_ */
