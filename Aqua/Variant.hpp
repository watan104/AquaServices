#include <variant>
#include "Math.hpp"
#include <string>

enum class VariantType : uint8_t {
    NONE,
    FLOAT,
    STRING,
    VECTOR_2,
    VECTOR_3,
    UNSIGNED_INT,
    INT = 9,
};
/*ya watan anani sikerim ugrasamam suan bunla*/