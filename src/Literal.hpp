#pragma once

#include <string>
#include <variant>

#include "types.h"

using Literal = std::variant<i32, u32, f32, std::string>;
