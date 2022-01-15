#include <fstream>
#pragma once
class Logger{
    public:
    bool file_logger = false;
    bool console_logger = false;
    std::fstream log_file;
    Logger(const char* x, const char* y);
    void log(const char* msg, const char* log_level);
    void file_log(const char* msg, const char* log_level);
    void console_log(const char* msg, const char* log_level);
    void init_file_log();
    void close_file();
};