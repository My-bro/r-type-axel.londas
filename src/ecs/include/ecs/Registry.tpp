/*
** EPITECH PROJECT, 2024
** bsrtype
** File description:
** Registry
*/

#include "Registry.hpp"

template <class Component>
SparseArray<Component> &Registry::register_component()
{
    std::type_index type = typeid(Component);
    auto &array = this->_components_arrays[type];
    if (array.has_value()) {
        throw RegistryError("Component array already registered for this type.");
    }
    array = SparseArray<Component>{};
    this->_component_erasers[type] = [](Registry &registry, const Entity &entity) {
        registry.get_components<Component>().erase(entity);
    };
    return std::any_cast<SparseArray<Component>&>(array);
}

template <class Component>
SparseArray<Component> &Registry::get_components()
{
    std::type_index type = typeid(Component);
    auto &array = this->_components_arrays[type];
    if (!array.has_value()) {
        throw RegistryError("Component array not registered for this type.");
    }
    return std::any_cast<SparseArray<Component>&>(array);
}

template <class Component>
SparseArray<Component> const &Registry::get_components() const
{
    std::type_index type = typeid(Component);
    auto it = this->_components_arrays.find(type);
    if (it == this->_components_arrays.end()) {
        throw RegistryError("Component array not registered for this type.");
    }
    return std::any_cast<const SparseArray<Component>&>(it->second);
}

template <typename T, typename... Args>
void Registry::register_class(Args&&... args)
{
    std::type_index type = typeid(T);
    if (_class_instances.find(type) != _class_instances.end()) {
        throw RegistryError("Class instance already registered for this type.");
    }
    _class_instances[type] = std::make_shared<T>(std::forward<Args>(args)...);
}

template <typename T>
T& Registry::get_class_instance()
{
    std::type_index type = typeid(T);
    auto it = _class_instances.find(type);
    if (it == _class_instances.end()) {
        throw RegistryError("Class instance not registered for this type.");
    }
    return *std::static_pointer_cast<T>(it->second);
}

template <typename Component>
typename SparseArray<Component>::reference_type Registry::add_component(Entity const& to, Component&& c)
{
    return this->get_components<Component>().insert_at(static_cast<std::size_t>(to), std::forward<Component>(c));
}

template <typename Component, typename... Params>
typename SparseArray<Component>::reference_type Registry::emplace_component(Entity const& to, Params&&... p)
{
    return this->get_components<Component>().emplace_at(static_cast<std::size_t>(to), std::forward<Params>(p)...);
}

template <typename Component>
void Registry::remove_component(Entity const& from)
{
    this->get_components<Component>().erase(static_cast<std::size_t>(from));
}

template <class... Components, typename Function>
void Registry::add_system(Function &&f) {
    _systems.emplace_back([fwd = std::forward<Function>(f), this]() {
        fwd(*this, get_components<Components>()...);
    });
}
