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

#ifndef SAFEQUEUE_HPP_
    #define SAFEQUEUE_HPP_

#include <queue>
#include <mutex>
#include <optional>

/**
 * @class SafeQueue
 * @brief A thread-safe queue implementation with non-blocking operations.
 *
 * The SafeQueue class provides a thread-safe wrapper around a standard queue.
 * It ensures safe concurrent access by multiple threads using a mutex.
 * It offers non-blocking methods for pushing and popping elements, and utility
 * functions to check the queue's state.
 *
 * @tparam T The type of elements stored in the queue.
 */
template <typename T>
class SafeQueue {
public:
    /**
     * @brief Default constructor for SafeQueue.
     */
    SafeQueue() = default;

    /**
     * @brief Pushes a value into the queue in a thread-safe manner.
     * @param value The value to be added to the queue.
     */
    void push(T value);

    /**
     * @brief Attempts to pop a value from the queue in a non-blocking manner.
     * @return An optional containing the value if the queue is not empty,
     *         or std::nullopt otherwise.
     */
    std::optional<T> tryPop();

    /**
     * @brief Checks whether the queue is empty in a thread-safe manner.
     * @return True if the queue is empty, false otherwise.
     */
    bool empty() const;

    /**
     * @brief Retrieves the size of the queue in a thread-safe manner.
     * @return The number of elements in the queue.
     */
    std::size_t size() const;

private:
    std::queue<T> _queue;          /**< The underlying queue storing the elements. */
    mutable std::mutex _mutex;     /**< Mutex to ensure thread-safe access. */
};

#include "SafeQueue.tpp"

#endif /* SAFEQUEUE_HPP_ */
