/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_

    #include <ecs/Registry.hpp>
    #include <random>
    #include <iostream>
    #include <unordered_map>
    #include <thread>
    #include <vector>
    #include <atomic>
    #include "systems/systems.hpp"
    #include "GameState.hpp"
    #include "network/NetworkServer.hpp"
    #include "PacketRepresentation.hpp"

class Server {
    public:
        Server(bool windows = false);
        ~Server();
        void createLobby(unsigned short port);
        std::vector<unsigned short> getLobbiesPorts() const;
        bool isRunning() const;
    private:
        void startGame(unsigned short port, bool window_flag);
        std::unordered_map<unsigned short, std::thread> _threads;
        std::atomic<bool> _running = true;
        bool _windows;
};

#endif /* !SERVER_HPP_ */
