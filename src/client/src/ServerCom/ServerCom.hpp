/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Mon, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     ServerCom                                                                        *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄  ▄▀▀█▀▄    ▄▀▀▀█▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄ ▄▄             *
 *      ▐  ▄▀   ▐ █   █   █ █   █  █  █    █  ▐ ▐  ▄▀   ▐ █ █    ▌ █  █   ▄▀            *
 *        █▄▄▄▄▄  ▐  █▀▀▀▀  ▐   █  ▐  ▐   █       █▄▄▄▄▄  ▐ █      ▐  █▄▄▄█             *
 *        █    ▌     █          █        █        █    ▌    █         █   █             *
 *       ▄▀▄▄▄▄    ▄▀        ▄▀▀▀▀▀▄   ▄▀        ▄▀▄▄▄▄    ▄▀▄▄▄▄▀   ▄▀  ▄▀             *
 *       █    ▐   █         █       █ █          █    ▐   █     ▐   █   █               *
 *       ▐        ▐         ▐       ▐ ▐          ▐        ▐         ▐   ▐               *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef INCLUDED_SERVERCOM_HPP
#define INCLUDED_SERVERCOM_HPP

#include <iostream>
#include <thread>
#include "SafeQueue.hpp"
#include "ProtocolClient.hpp"
#include "NetworkClient.hpp"
#include <atomic>

class ServerCom
{
private:
    SafeQueue<packet> queue;
    std::thread listenerThread;
    void packetListener(NetworkClient *client);
    std::atomic<bool> close = false;

public:
    ServerCom() = default;
    explicit ServerCom(NetworkClient *client);
    ~ServerCom();

    // Delete all copying and moving
    ServerCom(const ServerCom&) = delete;            // no copy constructor
    ServerCom& operator=(const ServerCom&) {
        return *this;
    } // no copy assignment
    ServerCom(ServerCom&&) = delete;                 // no move constructor
    ServerCom& operator=(ServerCom&&) {
        return *this;
    };      // no move assignment

    void Close() {
        close = true;
        listenerThread.join();

    }

    std::optional<packet> getPacket();
};

#endif
