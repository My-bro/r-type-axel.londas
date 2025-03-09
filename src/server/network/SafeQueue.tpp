/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Mon, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     SafeQueue                                                                        *
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

#include "SafeQueue.hpp"

template <typename T>
void SafeQueue<T>::push(T value) {
    std::lock_guard<std::mutex> lock(_mutex);
    _queue.push(std::move(value));
}

template <typename T>
std::optional<T> SafeQueue<T>::tryPop() {
    std::lock_guard<std::mutex> lock(_mutex);
    if (_queue.empty()) {
        return std::nullopt;
    }
    T value = std::move(_queue.front());
    _queue.pop();
    return value;
}

template <typename T>
bool SafeQueue<T>::empty() const {
    std::lock_guard<std::mutex> lock(_mutex);
    return _queue.empty();
}

template <typename T>
std::size_t SafeQueue<T>::size() const {
    std::lock_guard<std::mutex> lock(_mutex);
    return _queue.size();
}
