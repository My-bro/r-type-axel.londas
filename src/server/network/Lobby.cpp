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

#include "Lobby.hpp"

Lobby::Lobby(const std::string& lobby_id, std::size_t max_players_) : id(lobby_id), max_players(max_players_)
{
}

bool Lobby::addClient(const std::string& client_id)
{
    if (clients.size() < max_players) {
        clients.push_back(client_id);
        return true;
    }
    return false;
}

void Lobby::removeClient(const std::string& client_id) {
    auto it = std::find(clients.begin(), clients.end(), client_id);
    if (it != clients.end()) {
        clients.erase(it);
    }
}

bool Lobby::isEmpty() const
{
    return clients.empty();
}
