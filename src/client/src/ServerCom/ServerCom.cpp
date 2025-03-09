/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Mon, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     ServerCom                                                                        *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "ServerCom.hpp"

// start the thread
ServerCom::ServerCom(NetworkClient *client)
{
    listenerThread = std::thread(&ServerCom::packetListener, this, client);
}

// Destructor joins the thread
ServerCom::~ServerCom()
{
    close = true;
    if (listenerThread.joinable()) {
        listenerThread.join();
        std::cout << "ServerCom closed !!!" << std::endl;
    }
}

void ServerCom::packetListener(NetworkClient *client)
{
    while (true) {
        std::vector<uint8_t> messages = client->receiveMessage();
        packet packet = ProtocolClient::deserializePacket(messages);
        this->queue.push(packet);
        if (close) {
            break;
        }
    }
}

packet empty_packet()
{
    packet packet;
    return packet;
}

std::optional<packet> ServerCom::getPacket()
{
    std::optional<packet> packet = queue.tryPop();
    return packet;
}