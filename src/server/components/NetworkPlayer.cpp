/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** NetworkPlayer
*/

#include "NetworkPlayer.hpp"

NetworkPlayer::NetworkPlayer(std::string player_id, int mini_id) : _player_id(player_id), _mini_id(mini_id) {}

std::string NetworkPlayer::getPlayerId() const
{
    return _player_id;
}

int NetworkPlayer::getMiniId() const
{
    return _mini_id;
}
