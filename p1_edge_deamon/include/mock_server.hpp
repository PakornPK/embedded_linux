#pragma once
#include "sensor_interface.hpp"
#include <random>

class MockTemperatureSensor : public ISensor {
private:
    std::mt19937 rng{std::random_device{}()};
    std::uniform_real_distribution<float> dist{25.0f, 85.0f};

public:
    bool initialize() override {
        return true;
    }

    float read_temperature() override {
        return dist(rng);
    }
};
