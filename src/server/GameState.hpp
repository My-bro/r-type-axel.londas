/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** GameState - A class representing the state of the game, including win/lose conditions and rendering.
*/

#ifndef GAMESTATE_HPP_
    #define GAMESTATE_HPP_

    #include <cstddef>
    #include <SFML/Graphics.hpp>

/**
 * @class GameState
 * @brief Manages the state of the game, including win/lose conditions and the game window.
 *
 * The GameState class tracks whether the player has won or lost the game, and it provides
 * access to the rendering window for managing graphics using SFML.
 */
class GameState {
    public:
        /**
         * @brief Constructs a GameState object.
         *
         * Initializes the game state with default win/lose conditions set to false
         * and creates an SFML render window with a resolution of 1920x1080.
         */
        GameState();

        /**
         * @brief Checks if the game has been won.
         * @return True if the game is in a win state, false otherwise.
         */
        bool getWin() const;

        /**
         * @brief Checks if the game has been lost.
         * @return True if the game is in a lose state, false otherwise.
         */
        bool getLose() const;

        /**
         * @brief Sets the win state of the game.
         * @param win A boolean value indicating whether the game has been won.
         */
        void setWin(bool win);

        /**
         * @brief Sets the lose state of the game.
         * @param lose A boolean value indicating whether the game has been lost.
         */
        void setLose(bool lose);

        /**
         * @brief Gets the current level of the game.
         * @return The current level of the game.
         */
        std::size_t getLevel() const;

        /**
         * @brief Sets the current level of the game.
         * @param level The new level of the game.
         */
        void incrementLevel();

    private:
        bool _win = false; /**< Tracks whether the game has been won. */
        bool _lose = false; /**< Tracks whether the game has been lost. */
        std::size_t _level = 1; /**< Tracks the current level of the game. */
        std::size_t _score = 0; /**< Tracks the player's score. */
};

#endif /* !GAMESTATE_HPP_ */
