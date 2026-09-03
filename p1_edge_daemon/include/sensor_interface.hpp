#pragma once
#include <cstdint>

class ISensor {
public:
    virtual ~ISensor() = default;
    virtual bool initialize() = 0;
    virtual float read_temperature() = 0;
};
