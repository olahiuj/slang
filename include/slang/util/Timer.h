#pragma once

#include <chrono>
#include <iostream>
#include <ratio>

namespace qihe {
struct Timer {
    const char *func_name_;
    std::chrono::steady_clock::time_point current_time{};

    Timer() : Timer("") {}

    explicit Timer(const char *func_name) : func_name_(func_name) {
        current_time = std::chrono::steady_clock::now();
    }

    void tick() {
        auto now = std::chrono::steady_clock::now();
        const std::chrono::duration<double, std::milli> duration = now - current_time;
        std::cout << "qihe time tracking:: "
				  << func_name_ << "@@"
                  << duration.count()
				  << " ms" << std::endl;
        current_time = now;
    }

};
};
