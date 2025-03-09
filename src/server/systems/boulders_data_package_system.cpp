/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** boulders_data_package_system
*/

#include <ecs/Registry.hpp>
#include "../components/Boulder.hpp"
#include "../components/Position.hpp"
#include "../PacketRepresentation.hpp"

void boulders_data_package_system(Registry &r, SparseArray<Boulder> &boulders, SparseArray<Position> &positions)
{
    for (std::size_t i = 0; i < boulders.size() && i < positions.size(); i++) {
        auto &boulder = boulders[i];
        auto &pos = positions[i];
        if (boulder && pos) {
            BoulderData boulder_data;
            boulder_data.x = pos.value().getX();
            boulder_data.y = pos.value().getY();
            r.get_class_instance<PacketRepresentation>().boulders_data.push_back(boulder_data);
        }
    }
}
