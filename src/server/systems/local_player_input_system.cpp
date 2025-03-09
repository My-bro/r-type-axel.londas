/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** local_player_input_system
*/

#include <ecs/Registry.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "../components/LocalPlayer.hpp"
#include "../components/Controllable.hpp"

void local_player_input_system(Registry &/*r*/, SparseArray<LocalPlayer> &local_players, SparseArray<Controllable> &controllables)
{
    for (std::size_t i = 0; i < local_players.size() && i < controllables.size(); i++) {
        auto &local_player = local_players[i];
        auto &controllable = controllables[i];
        if (local_player && controllable) {
            controllable.value().setAllFalse();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                controllable.value().setUp(true);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                controllable.value().setDown(true);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                controllable.value().setLeft(true);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                controllable.value().setRight(true);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                controllable.value().setShoot(true);
            }
        }
    }
}
