#pragma once

#include <chrono>
#include <iostream>
#include <ratio>

namespace qihe {
struct Timer {
    std::chrono::steady_clock::time_point current_time{};

    Timer() {
        current_time = std::chrono::steady_clock::now();
    }

    void tick() {
        auto now = std::chrono::steady_clock::now();
        const std::chrono::duration<double, std::milli> duration = now - current_time;
        std::cout << duration << std::endl;
        current_time = now;
    }

};
};
