/*
** EPITECH PROJECT, 2024
** bsrtype
** File description:
** Main
*/

#include <ecs/Registry.hpp>
#include "network/CRoomServer.hpp"
#include "PacketRepresentation.hpp"

int main(int argc, char **argv)
{
    bool windows = false;
    if (argc > 2) {
        std::cerr << "Usage: ./server [-win]" << std::endl;
        return 1;
    }
    if (argc == 2 && std::string(argv[1]) != "-win") {
        std::cerr << "Usage: ./server [-win]" << std::endl;
        return 1;
    }
    if (argc == 2) {
        windows = true;
    }
    try {
        CRoomServer server(windows);
        while (true) {
            server.receiveMessage();
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
