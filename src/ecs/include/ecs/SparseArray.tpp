/*
** EPITECH PROJECT, 2024
** bsrtype
** File description:
** SparseArray
*/

#ifndef SPARSEARRAY_TPP_
#define SPARSEARRAY_TPP_

#include "SparseArray.hpp"
#include "ECSError.hpp"

template <typename Component>
inline SparseArray<Component>::SparseArray() = default;

template <typename Component>
inline SparseArray<Component>::SparseArray(const SparseArray&) = default;

template <typename Component>
inline SparseArray<Component>::SparseArray(SparseArray&&) noexcept = default;

template <typename Component>
inline SparseArray<Component>::~SparseArray() = default;

template <typename Component>
inline SparseArray<Component>& SparseArray<Component>::operator=(const SparseArray& other) = default;

template <typename Component>
inline SparseArray<Component>& SparseArray<Component>::operator=(SparseArray&& other) noexcept = default;

template <typename Component>
inline typename SparseArray<Component>::reference_type SparseArray<Component>::operator[](size_t idx)
{
    return this->_data[idx];
}

template <typename Component>
inline typename SparseArray<Component>::const_reference_type SparseArray<Component>::operator[](size_t idx) const
{
    return this->_data[idx];
}

template <typename Component>
inline typename SparseArray<Component>::iterator SparseArray<Component>::begin()
{
    return this->_data.begin();
}

template <typename Component>
inline typename SparseArray<Component>::const_iterator SparseArray<Component>::begin() const
{
    return this->_data.begin();
}

template <typename Component>
inline typename SparseArray<Component>::const_iterator SparseArray<Component>::cbegin() const
{
    return this->_data.cbegin();
}

template <typename Component>
inline typename SparseArray<Component>::iterator SparseArray<Component>::end()
{
    return this->_data.end();
}

template <typename Component>
inline typename SparseArray<Component>::const_iterator SparseArray<Component>::end() const
{
    return this->_data.end();
}

template <typename Component>
inline typename SparseArray<Component>::const_iterator SparseArray<Component>::cend() const
{
    return this->_data.cend();
}

template <typename Component>
inline typename SparseArray<Component>::size_type SparseArray<Component>::size() const
{
    return this->_data.size();
}

template <typename Component>
inline typename SparseArray<Component>::reference_type SparseArray<Component>::insert_at(size_type pos, const Component& component)
{
    if (pos >= this->_data.size())
        this->_data.resize(pos + 1);
    this->_data[pos] = component;
    return this->_data[pos];
}

template <typename Component>
inline typename SparseArray<Component>::reference_type SparseArray<Component>::insert_at(size_type pos, Component&& component)
{
    if (pos >= this->_data.size())
        this->_data.resize(pos + 1);
    this->_data[pos] = std::move(component);
    return this->_data[pos];
}

template <typename Component>
inline void SparseArray<Component>::erase(size_type pos)
{
    if (pos < _data.size()) {
        this->_data[pos] = value_type{};
    }
}

template <typename Component>
template <class... Params>
inline typename SparseArray<Component>::reference_type SparseArray<Component>::emplace_at(size_type pos, Params &&...args)
{
    if (pos >= this->_data.size()) {
        return this->insert_at(pos, Component{ std::forward<Params>(args)... });
    }
    auto& slot = this->_data[pos];
    typename container_t::allocator_type allocator = this->_data.get_allocator();
    if (slot.has_value()) {
        std::allocator_traits<decltype(allocator)>::destroy(allocator, std::addressof(slot.value()));
    }
    std::allocator_traits<decltype(allocator)>::construct(allocator, std::addressof(slot.emplace(std::forward<Params>(args)...)));
    return slot;
}

template <typename Component>
inline typename SparseArray<Component>::size_type SparseArray<Component>::get_index(const value_type& value) const
{
    for (size_type i = 0; i < this->_data.size(); ++i) {
        if (std::addressof(this->_data[i]) == std::addressof(value)) {
            return i;
        }
    }
    throw SparseArrayError("Value not found in SparseArray.");
}

#endif /* !SPARSEARRAY_TPP_ */