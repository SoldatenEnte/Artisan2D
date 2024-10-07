#pragma once

#include <string>
#include <functional>

class Block {
public:
    virtual ~Block() = default;
    virtual void Update() = 0;
};