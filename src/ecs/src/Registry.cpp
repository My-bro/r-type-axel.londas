/*
** EPITECH PROJECT, 2024
** bsrtype
** File description:
** Registry
*/

#include <ecs/Registry.hpp>

Registry::Registry() {}

Entity Registry::spawn_entity()
{
    size_t id = this->_next_id;
    if (this->_free_ids.empty()) {
        this->_next_id++;
    } else {
        id = this->_free_ids.back();
        this->_free_ids.pop_back();
    }
    return Entity(id);
}

Entity Registry::entity_from_index(std::size_t idx)
{
    return Entity(idx);
}

void Registry::kill_entity(Entity const& e)
{
    this->_free_ids.push_back(static_cast<std::size_t>(e));
    for (auto &component_eraser : this->_component_erasers) {
        component_eraser.second(*this, e);
    }
}

void Registry::run_systems()
{
    for (auto &system : _systems) {
        system();
    }
}
