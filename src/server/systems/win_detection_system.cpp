/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** win_lose_detection_system
*/

#include "../GameState.hpp"
#include <ecs/Registry.hpp>
#include "../components/BossMob.hpp"
void win_detection_system(Registry &r, SparseArray<BossMob> &bosses)  
{
    if (r.get_class_instance<GameState>().getLevel() != 3) {
        return;
    }
    for (std::size_t i = 0; i < bosses.size(); i++) {
        auto &boss = bosses[i];
        if (boss) {
            return;
        }
    }
    r.get_class_instance<GameState>().setWin(true);
}
