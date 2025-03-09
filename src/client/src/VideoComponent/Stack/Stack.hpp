/*
** EPITECH PROJECT, 2024
** bs_rtype
** File description:
** Stack
*/

#ifndef STACK_HPP_
#define STACK_HPP_

#include <vector>
#include <iostream>
#include <stdexcept>

template<typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T& element);
    void pop();
    T top() const;
    bool empty() const;
    size_t size() const;
};

#endif /* !STACK_HPP_ */
