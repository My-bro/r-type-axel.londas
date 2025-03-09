/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Mon, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     Lobby                                                                            *
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

#ifndef INCLUDED_LOBBY_HPP
    #define INCLUDED_LOBBY_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Lobby
{
    private:
        std::string id;
        std::vector<std::string> clients;
        std::size_t max_players;
        friend class NetworkServer;
        
    protected:
    public:
        Lobby(const std::string& lobby_id, std::size_t max_players_ = 4);
        ~Lobby() = default;

        bool addClient(const std::string& client_id);
        void removeClient(const std::string& client_id);
        bool isEmpty() const;
};

#endif
