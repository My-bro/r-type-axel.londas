/*
** EPITECH PROJECT, 2024
** bsrtype
** File description:
** Registry
*/

#ifndef REGISTRY_HPP_
    #define REGISTRY_HPP_

    #include <memory>
    #include <unordered_map>
    #include <typeindex>
    #include <any>
    #include <functional>
    #include <iostream>
    #include <thread>
    #include <vector>
    #include "Export.hpp"
    #include "ECSError.hpp"
    #include "Entity.hpp"
    #include "SparseArray.hpp"

class RTYPE_API Registry {
    public:
        Registry();

        template <class Component>
        SparseArray<Component> &register_component();

        template <class Component>
        SparseArray<Component> &get_components();

        template <class Component>
        SparseArray<Component> const &get_components() const;

        template <typename T, typename... Args>
        void register_class(Args&&... args);

        template <typename T>
        T& get_class_instance();

        Entity spawn_entity();

        Entity entity_from_index(std::size_t idx);

        void kill_entity(Entity const& e);

        template <typename Component>
        typename SparseArray<Component>::reference_type add_component(Entity const& to, Component&& c);

        template <typename Component, typename... Params>
        typename SparseArray<Component>::reference_type emplace_component(Entity const& to, Params&&... p);

        template <typename Component>
        void remove_component(Entity const& from);

        template <class... Components, typename Function>
        void add_system(Function &&f);

        void run_systems();

    private:
        std::size_t _next_id = 0;
        std::vector<std::size_t> _free_ids;
        std::unordered_map<std::type_index, std::any> _components_arrays;
        std::unordered_map<std::type_index, std::function<void(Registry &, const Entity &)>> _component_erasers;
        std::unordered_map<std::type_index, std::shared_ptr<void>> _class_instances;
        std::vector<std::function<void()>> _systems;
};

#include "Registry.tpp"

#endif /* !REGISTRY_HPP_ */
