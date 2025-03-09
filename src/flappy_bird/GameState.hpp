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
         * @brief Checks if the game has been lost.
         * @return True if the game is in a lose state, false otherwise.
         */
        bool getLose() const;

        /**
         * @brief Sets the lose state of the game.
         * @param lose A boolean value indicating whether the game has been lost.
         */
        void setLose(bool lose);

        /**
         * @brief Gets the player's score.
         * @return The player's score.
         */
        int getScore() const;

        /**
         * @brief Sets the player's score.
         * @param score The player's score.
         */
        void setScore(int score);

    private:
        bool _lose = false; /**< Tracks whether the game has been lost. */
        int _score = 0; /**< The player's score. */
};

#endif /* !GAMESTATE_HPP_ */
