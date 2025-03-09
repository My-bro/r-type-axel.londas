/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Entity - A class representing an entity in the ECS (Entity Component System).
*/

#ifndef ENTITY_HPP_
    #define ENTITY_HPP_

    #include <cstddef>
    #include "Export.hpp"

/**
 * @class Entity
 * @brief Represents a unique entity in the ECS.
 *
 * The Entity class encapsulates a unique identifier (ID) for an entity. It allows
 * implicit conversion to its underlying ID type, enabling seamless use in ECS
 * operations.
 */
class RTYPE_API Entity {
    public:
        /**
         * @brief Allows implicit conversion of an Entity object to its ID.
         * @return The unique identifier of the entity as a std::size_t.
         */
        operator std::size_t() const;

    private:
        /**
         * @brief Constructs an Entity with a unique identifier.
         * @param id The unique identifier for the entity.
         */
        explicit Entity(std::size_t id);

        std::size_t _id; /**< The unique identifier for the entity. */

        friend class Registry; /**< Grants the Registry class access to private members. */
};

#endif /* !ENTITY_HPP_ */
