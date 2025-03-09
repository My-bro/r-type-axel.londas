/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Jan, 2025                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     CRooms                                                                           *
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

// CRoomServer.hpp
#ifndef CROOMSERVER_HPP
    #define CROOMSERVER_HPP

#include <vector>
#include <cstdint>
#include <stdexcept>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "ParsingTcp.hpp"
#include <sstream>
#include "../Server.hpp"

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

class CRoomServer {
public:
    CRoomServer(bool windows);
    ~CRoomServer();
    int acceptConnection();
    void deleteClient(int socket);
    std::vector<u_int16_t> receiveMessage();
    void sendMessage(int socket, std::vector<uint16_t> msg);
    void handleClientMessage(int client_socket, const std::vector<uint16_t>& message);

private:
    int server_socket;
    std::unordered_map<std::string, std::string> serv_info;
    std::vector<std::size_t> socketClients;
    std::vector<u_int16_t> getListPort();
    std::vector<unsigned short> _ports;
    void createServer();
    Server _game_manager;
};

#endif // CROOMSERVER_HPP
