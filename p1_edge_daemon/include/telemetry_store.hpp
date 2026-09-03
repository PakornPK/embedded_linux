#pragma once
#include <atomic>

class TelemetryStore {
private:
    std::atomic<float> temperature_{0.0f};

public:
    void update_temperature(float temp) {
        temperature_.store(temp, std::memory_order_relaxed);
    }

    float get_temperature() const {
        return temperature_.load(std::memory_order_relaxed);
    }
};
