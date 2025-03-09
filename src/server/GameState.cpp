/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** GameState
*/

#include "GameState.hpp"

GameState::GameState() {}

bool GameState::getWin() const
{
    return _win;
}

bool GameState::getLose() const
{
    return _lose;
}

void GameState::setWin(bool win)
{
    this->_win = win;
}

void GameState::setLose(bool lose)
{
    this->_lose = lose;
}

std::size_t GameState::getLevel() const
{
    return _level;
}

void GameState::incrementLevel()
{
    this->_level++;
}
