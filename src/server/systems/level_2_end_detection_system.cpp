/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** level_2_end_detection_system
*/

#include <ecs/Registry.hpp>

#include "../components/Mob.hpp"
#include "../GameState.hpp"
#include "../PacketRepresentation.hpp"

void level_2_end_detection_system(Registry &r, SparseArray<Mob> &mobs)
{
    if (r.get_class_instance<GameState>().getLevel() != 2) {
        return;
    }
    for (std::size_t i = 0; i < mobs.size(); i++) {
        auto &mob = mobs[i];
        if (mob) {
            return;
        }
    }
    r.get_class_instance<GameState>().incrementLevel();
    r.get_class_instance<PacketRepresentation>().level = 3;   
}
