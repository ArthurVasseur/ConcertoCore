//
// Created by arthur on 18/11/2023.
//

#include "Concerto/Core/Any.hpp"

namespace cct
{
    Any::Any(std::size_t id, std::unique_ptr<void*> data) :
        _id(id), _data(std::move(data))
    {
    }

    Any::Any() : _id(0), _data(nullptr)
    {
    }

    Any::~Any() = default;

    void Any::Reset()
    {
        _data = nullptr;
		_id = 0;
    }

    bool Any::HasValue() const
    {
		return _data != nullptr && _id != 0;
    }
}
