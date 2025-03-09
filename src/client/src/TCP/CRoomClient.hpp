/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Thu, Jan, 2025                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     CRoomClient                                                                      *
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

#ifndef CROOMCLIENT_HPP
#define CROOMCLIENT_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>
#include <unordered_map>
#include <optional>
#include "ParsingTcp.hpp"
#include <thread>

#ifdef _WIN32
    #include <winsock2.h>
#else
    #include <unistd.h>
    #include <arpa/inet.h>
#endif

enum message_type {
    ADD,
    DELETE,
    PORT,
    OK,
    KO
};

class CRoomClient {
    private:
        int client_socket;
        struct sockaddr_in server_address;
        std::unordered_map<std::string, std::string> client_info;

    public:
        CRoomClient();
        ~CRoomClient();
        void connectToServer();
        void sendMessage(const std::vector<uint16_t>& message);
        std::vector<uint16_t> receiveMessage();
        std::vector<uint16_t> Refresh();
        std::vector<uint16_t> CreateLobby();
        void chooseMessage(message_type _type, std::optional<int> lobby_);

        message_type _cmd_input = KO;
        bool isConnected;
};

#endif
