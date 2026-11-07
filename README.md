# Dictionary and std::variant visitors

[![CI](https://github.com/Loomwixx/cpp-dictionary-structures/actions/workflows/ci.yml/badge.svg)](https://github.com/Loomwixx/cpp-dictionary-structures/actions/workflows/ci.yml)

A dictionary class written from scratch, holding values of several types through `std::variant`.

## What's inside

- Constructors, destructor and copy/move semantics, plus construction from `std::initializer_list`
- Operators: `operator[]`, concatenation, const-correct access
- `keys()`, `values()`, `pop()`
- A static counter of live instances, used to check that nothing leaks
- Visitors for `std::visit` (`PrintVisitor`, `ToStringVisitor`) and JSON export

## Build and run

Requires CMake 3.24+ and GCC 13 (the code uses C++23). GoogleTest is downloaded automatically.

```bash
cmake -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Context

Written as a lab for the Programming Languages II course at AGH University of Krakow. The task specification and the GoogleTest suite were provided by the course; the implementation is mine. The code builds with `-Wall -Wextra -Werror` and a long list of extra warnings, and is formatted with clang-format.
