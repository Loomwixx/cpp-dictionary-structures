# C++ Advanced Data Structures: Custom Dictionary & Variant Visitors

This repository features a custom implementation of a Dictionary data structure and the application of modern C++17 design patterns, specifically the Visitor pattern with `std::variant`.

## Key Features Demonstrated

### 1. Custom Dictionary Implementation
* **Memory Management & Constructors:** Implemented robust constructors, destructors, and memory handling. Supports modern C++ initialization via `std::initializer_list`.
* **Operator Overloading:** Deeply integrated into the language through overloaded operators for Array access (`operator[]`), Concatenation, and Const-correctness.
* **Data Manipulation:** Developed core dictionary methods for extracting Keys, Values, and popping elements.
* **Instance Tracking:** Includes static object counting mechanisms to track active dictionary instances and prevent memory leaks.

### 2. Modern C++17 Patterns (`std::variant`)
* **Visitor Pattern:** Implemented custom visitors (`PrintVisitor`, `ToStringVisitor`) utilizing `std::visit` to cleanly process and serialize multiple data types stored in `std::variant`.
* **Data Serialization:** Added functionality to convert dictionary states and variant data into JSON format (`ToJson`).

## Comprehensive Unit Testing
The project is thoroughly tested using **GoogleTest (GTest)**, validating all edge cases including:
* Operator logic and const-correctness.
* Memory stability and instance counting.
* Visitor pattern execution and JSON serialization.

## Build Instructions
```bash
mkdir build
cd build
cmake ..
cmake --build .
ctest -V