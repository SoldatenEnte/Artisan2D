#pragma once
#include <string>
#include <fstream>

class Logger {
public:
    static void Init(const std::string& filename);
    static void Log(const std::string& message);
    static void Shutdown();

private:
    static std::ofstream logFile;
};