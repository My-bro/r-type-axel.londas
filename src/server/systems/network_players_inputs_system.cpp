/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** networked_players_mouvement_system
*/

#include <ecs/Registry.hpp>
#include "../network/NetworkServer.hpp"
#include "../components/NetworkPlayer.hpp"
#include "../components/Controllable.hpp"
#include "../protocol/ProtocolServer.hpp"

void network_players_inputs_system(Registry &r, SparseArray<NetworkPlayer> &network_players, SparseArray<Controllable> &controllables)
{
    auto &messages = r.get_class_instance<NetworkServer>().getMessageQueue();

    while (true) {
        auto mb_message = messages.tryPop();
        if (mb_message.has_value()) {
            auto message = mb_message.value();
            for (std::size_t i = 0; i < network_players.size() && i < controllables.size(); i++) {
                auto &network_player = network_players[i];
                auto &controllable = controllables[i];
                if (network_player && controllable) {
                    auto player_id = network_player.value().getPlayerId();
                    if (player_id == message.first) {
                        controllable.value().setAllFalse();
                        auto input =  ProtocolServer::deserializePacket(message.second);
                        if (input == server_protocol::Input::LEFT) {
                            controllable.value().setLeft(true);
                        } else if (input == server_protocol::Input::RIGHT) {
                            controllable.value().setRight(true);
                        } else if (input == server_protocol::Input::UP) {
                            controllable.value().setUp(true);
                        } else if (input == server_protocol::Input::DOWN) {
                            controllable.value().setDown(true);
                        } else if (input == server_protocol::Input::SHOOT) {
                            controllable.value().setShoot(true);
                        }
                        break;
                    }
                }
            }
        } else {
            break;
        }
    }
}
