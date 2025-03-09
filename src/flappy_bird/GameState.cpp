/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** GameState
*/

#include "GameState.hpp"

GameState::GameState() {}

bool GameState::getLose() const
{
    return _lose;
}

void GameState::setLose(bool lose)
{
    this->_lose = lose;
}

int GameState::getScore() const
{
    return _score;
}

void GameState::setScore(int score)
{
    if (score < 0)
        score = 0;
    _score = score;
}
