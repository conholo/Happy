#pragma once

#include "Happy/Core/Log.h"

#define BIND_FN(fn) [this](auto&& ... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }
