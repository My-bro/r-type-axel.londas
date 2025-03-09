/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** NetworkPlayer - A class representing a player in a networked game session.
*/

#ifndef NETWORKPLAYER_HPP_
    #define NETWORKPLAYER_HPP_

    #include <iostream>
    #include <string>

/**
 * @class NetworkPlayer
 * @brief Represents a player in a networked game session.
 *
 * The NetworkPlayer class manages information about a player connected to the
 * game via the network. Each player is identified by a unique player ID.
 */
class NetworkPlayer {
    public:
        /**
         * @brief Constructs a NetworkPlayer object with a specified player ID.
         * @param player_id A unique identifier for the player.
         */
        NetworkPlayer(std::string player_id, int mini_id);

        /**
         * @brief Retrieves the player ID.
         * @return The unique identifier of the player as a string.
         */
        std::string getPlayerId() const;

        int getMiniId() const;

    private:
        std::string _player_id; /**< The unique identifier for the player. */
        int _mini_id; /** id transfered to the client */
};

#endif /* !NETWORKPLAYER_HPP_ */
