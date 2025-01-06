#include <variant>
#include <string>
#include <array>
#include <algorithm>
#include <memory>
#include <vector>
#include "Math.hpp"

enum class VariantType : uint8_t {
    NONE,
    FLOAT,
    STRING,
    VECTOR_2,
    VECTOR_3,
    UNSIGNED_INT,
    INT = 9,
};

class variant {
public:
    using var_type = std::variant<float, std::string, CL_Vec2f, CL_Vec3f, uint32_t, int>;
    variant() : m_object(0) {}
    variant(const var_type& var) : m_object({ var }) {}
    variant(const float& var) : m_object({ var }) {}
    variant(const std::string& var) : m_object({ var }) {}
    variant(const CL_Vec2f& var) : m_object({ var }) {}
    variant(const CL_Vec3f& var) : m_object({ var }) {}
    variant(const uint32_t& var) : m_object({ var }) {}
    variant(const int& var) : m_object({ var }) {}

    template<typename T>
    T Get() const {
        return std::get<T>(m_object);
    }
    std::string Get() const {
        return std::get<std::string>(m_object);
    }
    VariantType GetVarType() const {
        switch (m_object.index())
        {
        case 0:
            return VariantType::FLOAT;
        case 1:
            return VariantType::STRING;
        case 2:
            return VariantType::VECTOR_2;
        case 3:
            return VariantType::VECTOR_3;
        case 4:
            return VariantType::UNSIGNED_INT;
        case 5:
            return VariantType::INT;
        default:
            return VariantType::NONE;
        }
    }
    size_t GetMemAlloc() const {
        size_t alloc{ 0 };
        switch (this->GetVarType()) {
        case VariantType::STRING: {
            alloc = 5 + this->Get().size();
        } break;
        case VariantType::VECTOR_2: {
            alloc = 1 + (2 * sizeof(float));
        } break;
        case VariantType::VECTOR_3: {
            alloc = 1 + (3 * sizeof(float));
        } break;
        case VariantType::FLOAT:
        case VariantType::UNSIGNED_INT:
        case VariantType::INT: {
            alloc = 5;
        } break;
        default:
            break;
        }
        return alloc;
    }

    void Pack(uint8_t*& buffer) const {
        *buffer++ = static_cast<uint8_t>(this->GetVarType());

        switch (this->GetVarType()) {
        case VariantType::FLOAT: {
            float value = this->Get<float>();
            std::copy_n(reinterpret_cast<uint8_t*>(&value), sizeof(float), buffer);
            buffer += sizeof(float);
        } break;
        case VariantType::STRING: {
            const auto& str = this->Get<std::string>();
            uint32_t len = static_cast<uint32_t>(str.size());
            std::copy_n(reinterpret_cast<uint8_t*>(&len), sizeof(len), buffer);
            buffer += sizeof(len);
            std::copy_n(reinterpret_cast<const uint8_t*>(str.data()), len, buffer);
            buffer += len;
        } break;
        case VariantType::VECTOR_2: {
            const auto& var = this->Get<CL_Vec2f>();
            std::copy_n(reinterpret_cast<const uint8_t*>(&var.X), sizeof(float), buffer);
            buffer += sizeof(float);
            std::copy_n(reinterpret_cast<const uint8_t*>(&var.Y), sizeof(float), buffer);
            buffer += sizeof(float);
        } break;
        case VariantType::VECTOR_3: {
            const auto& var = this->Get<CL_Vec3f>();
            std::copy_n(reinterpret_cast<const uint8_t*>(&var.X), sizeof(float), buffer);
            buffer += sizeof(float);
            std::copy_n(reinterpret_cast<const uint8_t*>(&var.Y), sizeof(float), buffer);
            buffer += sizeof(float);
            std::copy_n(reinterpret_cast<const uint8_t*>(&var.Z), sizeof(float), buffer);
            buffer += sizeof(float);
        } break;
        case VariantType::UNSIGNED_INT: {
            uint32_t value = this->Get<uint32_t>();
            std::copy_n(reinterpret_cast<uint8_t*>(&value), sizeof(uint32_t), buffer);
            buffer += sizeof(uint32_t);
        } break;
        case VariantType::INT: {
            int value = this->Get<int>();
            std::copy_n(reinterpret_cast<uint8_t*>(&value), sizeof(int), buffer);
            buffer += sizeof(int);
        } break;
        default:
            break;
        }
    }
private:
    var_type m_object;
};

class variantlist_t {
public:
    variantlist_t(const variant::var_type& v0)
        : m_objects{ variant(v0) } {
    }
    variantlist_t(const variant::var_type& v0, const variant::var_type& v1)
        : m_objects{ variant(v0), variant(v1) } {
    }
    variantlist_t(const variant::var_type& v0, const variant::var_type& v1, const variant::var_type& v2)
        : m_objects{ variant(v0), variant(v1), variant(v2) } {
    }
    variantlist_t(const variant::var_type& v0, const variant::var_type& v1, const variant::var_type& v2, const variant::var_type& v3)
        : m_objects{ variant(v0), variant(v1), variant(v2), variant(v3) } {
    }
    variantlist_t(const variant::var_type& v0, const variant::var_type& v1, const variant::var_type& v2, const variant::var_type& v3, const variant::var_type& v4)
        : m_objects{ variant(v0), variant(v1), variant(v2), variant(v3), variant(v4) } {
    }
    variantlist_t(const variant::var_type& v0, const variant::var_type& v1, const variant::var_type& v2, const variant::var_type& v3, const variant::var_type& v4, const variant::var_type& v5)
        : m_objects{ variant(v0), variant(v1), variant(v2), variant(v3), variant(v4), variant(v5) } {
    }
    variantlist_t(const variant::var_type& v0, const variant::var_type& v1, const variant::var_type& v2, const variant::var_type& v3, const variant::var_type& v4, const variant::var_type& v5, const variant::var_type& v6)
        : m_objects{ variant(v0), variant(v1), variant(v2), variant(v3), variant(v4), variant(v5), variant(v6) } {
    }

    _NODISCARD std::unique_ptr<uint8_t[]> Serialize() const {
        size_t alloc = 1;
        for (const auto& var : m_objects)
            alloc += var.GetMemAlloc() + 1;
        std::unique_ptr<uint8_t[]> buffer = std::make_unique<uint8_t[]>(alloc);
        uint8_t* ptr = buffer.get();
        *ptr++ = static_cast<uint8_t>(m_objects.size());
        for (size_t index = 0; index < m_objects.size(); index++) {
            *ptr++ = static_cast<uint8_t>(index);
            m_objects[index].Pack(ptr);
        }
        return buffer;
    }
    _NODISCARD const std::array<variant, 8>& GetObjects() const { return m_objects; }
private:
    std::array<variant, 8> m_objects{};
};