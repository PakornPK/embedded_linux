#pragma once
#include <mutex>

class TelemetryStore {
private:
    float temperature_{0.0f};
    mutable std::mutex mutex_;

public:
    void update_temperature(float temp) {
        std::lock_guard<std::mutex> lock(mutex_);
        temperature_ = temp;
    }

    float get_temperature() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return temperature_;
    }
};
