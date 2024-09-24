#include "../../include/Core/Logger.h"
#include <iostream>
#include <chrono>
#include <iomanip>

std::ofstream Logger::logFile;

void Logger::Init(const std::string& filename) {
    logFile.open(filename, std::ios::out | std::ios::app);
}

void Logger::Log(const std::string& message) {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_c);

    if (logFile.is_open()) {
        logFile << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << " - " << message << std::endl;
    }
    std::cout << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << " - " << message << std::endl;
}

void Logger::Shutdown() {
    if (logFile.is_open()) {
        logFile.close();
    }
}