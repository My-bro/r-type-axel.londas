/*
** EPITECH PROJECT, 2024
** bs_rtype
** File description:
** Stack
*/

#include "Stack.hpp"

template<typename T>
void Stack<T>::push(const T& element)
{
    elements.push_back(element);
}

template<typename T>
void Stack<T>::pop()
{
    if (elements.empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    elements.pop_back();
}

template<typename T>
T Stack<T>::top() const
{
    if (elements.empty()) {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elements.back();
}

template<typename T>
bool Stack<T>::empty() const
{
    return elements.empty();
}

template<typename T>
size_t Stack<T>::size() const
{
    return elements.size();
}