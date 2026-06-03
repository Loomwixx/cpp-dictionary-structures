#pragma once

#include <iostream>
#include <sstream>
#include <variant>

namespace variantVisitors
{
using PrintVariant = std::variant<bool, int, float>;
using ToStringVariant = std::variant<bool, int, double, float>;

struct ToStringVisitor {
    std::string operator()(const bool& b){ return (b ? "true" : "false"); }
    std::string operator()(const int& i){ 
        std::stringstream ss;
        ss << std::hex << i;
        return ss.str();
    }
    std::string operator()(const double& d){ 
        std::stringstream ss;
        ss << d;
        return ss.str();
    }
    std::string operator()(const float& f){ 
        std::stringstream ss;
        ss << f;
        return ss.str();
    }
};

struct PrintVisitor {
    void operator()(const bool& )       { std::cout << "bool"; }
    void operator()(const int& )        { std::cout << "int"; }
    void operator()(const float& )      { std::cout << "float"; }
};

}  // namespace variantVisitors
