#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <utility>
#include <variant>
#include <vector>
#include <initializer_list>

namespace dictionary
{
    using CustomVariant = std::variant<int, float, std::string>;
    using DictionaryContainer = std::map<const std::string, CustomVariant>;
    struct Dictionary{
        DictionaryContainer items_;
        static int cnt_;
        static int getObjCounter();
        Dictionary();
        ~Dictionary();
        Dictionary(const Dictionary& other);
        Dictionary& operator=(const Dictionary& other);
        Dictionary(Dictionary&& other) noexcept;
        Dictionary& operator=(Dictionary&& other) noexcept;

        Dictionary(std::initializer_list<std::pair<const std::string, CustomVariant>> list);

        CustomVariant& operator[](const std::string& key);

        const CustomVariant& operator[](const std::string& key) const;

        void pop(const std::string& key);

        std::vector<CustomVariant> values() const;

        std::vector<std::string> keys() const;

        Dictionary& operator+=(const Dictionary&other);

        Dictionary operator+(const Dictionary&other) const;

        std::string toJson() const;
    };

}  // namespace dictionary
