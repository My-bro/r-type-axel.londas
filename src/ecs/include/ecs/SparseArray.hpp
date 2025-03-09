/*
** EPITECH PROJECT, 2024
** bsrtype
** File description:
** SparseArray
*/


#ifndef SPARSEARRAY_HPP_
    #define SPARSEARRAY_HPP_

    #include <vector>
    #include <optional>
    #include <cstddef>
    #include <utility>
    #include <memory>
    #include "Export.hpp"

template <typename Component>
class RTYPE_API SparseArray {
    public:
        using value_type = std::optional<Component>;
        using reference_type = value_type &;
        using const_reference_type = const value_type &;
        using container_t = std::vector<value_type>;
        using size_type = typename container_t::size_type;
        using iterator = typename container_t::iterator;
        using const_iterator = typename container_t::const_iterator;

    public:
        SparseArray();
        SparseArray(const SparseArray &);
        SparseArray(SparseArray &&) noexcept;
        ~SparseArray();

        SparseArray &operator=(const SparseArray &);
        SparseArray &operator=(SparseArray &&) noexcept;

        reference_type operator[](size_t idx);
        const_reference_type operator[](size_t idx) const;

        iterator begin();
        const_iterator begin() const;
        const_iterator cbegin() const;

        iterator end();
        const_iterator end() const;
        const_iterator cend() const;

        size_type size() const;

        reference_type insert_at(size_type pos, const Component &);
        reference_type insert_at(size_type pos, Component &&);

        template <class... Params>
        reference_type emplace_at(size_type pos, Params &&...);

        void erase(size_type pos);
        size_type get_index(const value_type &) const;

    private:
        container_t _data;
};

#include "SparseArray.tpp"

#endif /* !SPARSEARRAY_HPP_ */
