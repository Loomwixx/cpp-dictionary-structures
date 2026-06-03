#include <Structures/Dictionary.h>

#include <cstdint>
#include <iostream>
#include <sstream>

namespace dictionary
{
    int Dictionary::cnt_ = 0;

    int Dictionary::getObjCounter(){
        return cnt_;
    }

    Dictionary::Dictionary() : items_(){
        std::cout << "default constructor\n";
        cnt_++;
    }
    Dictionary::~Dictionary(){
        std::cout << "destructor\n";
        cnt_--;
    }
    Dictionary::Dictionary(const Dictionary& other) : items_(other.items_){
        std::cout << "copy constructor\n";
        cnt_++;
    }
    Dictionary& Dictionary::operator=(const Dictionary&other ){
        std::cout << "copy assignment\n";
        items_ = other.items_;
        return *this;
    }
    Dictionary::Dictionary(Dictionary&& other) noexcept : items_(std::move(other.items_)){
        std::cout << "move constructor\n";
        cnt_++;
    }
    Dictionary& Dictionary::operator=(Dictionary&& other) noexcept{
        std::cout << "move assignment\n";
        items_ = std::move(other.items_);
        return *this;
    }


    Dictionary::Dictionary(std::initializer_list<std::pair<const std::string, CustomVariant>> list) : items_(list) {
        std::cout << "initializer list constructor\n";
        cnt_++;
    }

    CustomVariant& Dictionary::operator[](const std::string& key) {
        return items_[key];
    }

    const CustomVariant& Dictionary::operator[](const std::string& key) const {
        return items_.at(key); //to only look (not create)
    }

    void Dictionary::pop(const std::string& key){
        items_.erase(key);
    }

    std::vector<CustomVariant>Dictionary::values()const{
        std::vector<CustomVariant> result;
        for(const auto& v : items_){
            result.push_back(v.second);
        }
        return result;
    }

    std::vector<std::string>Dictionary::keys()const{
        std::vector<std::string> result;
        for(const auto& k : items_){
            result.push_back(k.first);
        }
        return result;
    }

    Dictionary& Dictionary::operator+=(const Dictionary& other) {
        for (const auto& [key, value] : other.items_) {
            this->items_[key] = value; 
        }
        return *this;   
    }

    Dictionary Dictionary::operator+(const Dictionary&other) const{
        Dictionary result = *this;
        result += other;
        return result;
    }

    std::string Dictionary::toJson() const {
        std::string result = "{";
        bool isFirst = true;

        for (auto const& [key, val] : items_) {
            if (!isFirst) {
                result += ",";
            }
            isFirst = false;

            result += "\"" + key + "\":";    // \" to cout the "

            if (std::holds_alternative<int>(val)) {
                result += std::to_string(std::get<int>(val));
            } 
            else if (std::holds_alternative<float>(val)) {
                result += std::to_string(std::get<float>(val)); //we need std::get bc val is a variant
            } 
            else if (std::holds_alternative<std::string>(val)) {
                result += "\"" + std::get<std::string>(val) + "\"";
            }
        }

        result += "}";
        return result;
    }

}  // namespace dictionary