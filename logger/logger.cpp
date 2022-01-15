#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <iomanip>
#include "logger.hpp"
    bool is_true(const char* x){
        return std::strcmp(x, "true") == 0;
    }
    Logger::Logger(const char* x ,const char* y){
        file_logger = is_true(x);
        console_logger = is_true(y);
    }
    void Logger::log(const char* msg, const char* log_level){
        if(console_logger == true){
            Logger::console_log(msg, log_level);
        }
        if(file_logger == true){
            Logger::file_log(msg, log_level);
        }
    }
    void Logger::console_log(const char* msg, const char* log_level){
            auto t = std::time(nullptr);
            auto tm = *std::localtime(&t);
         std::cout << std::put_time(&tm, "%d-%m-%Y %H-%M-%S") << " [development] " << "[" << log_level << "]" <<" "<< msg<< std::endl;  
    }
    void Logger::file_log(const char* msg, const char* log_level){
// narazie nie ma rozróżnienia na environment więc narazie tylko development
        if(log_file.is_open()){
            auto t = std::time(nullptr);
            auto tm = *std::localtime(&t);
            log_file << "["<< std::put_time(&tm, "%d-%m-%Y %H-%M-%S")<< "]" << " [development] " << "[" << log_level << "]" <<" "<< msg << "\n";  
        }
    }

     void Logger::init_file_log(){
        log_file.open("./log_file.log", std::ios::in | std::ios::out);
        if(log_file.good() != true){
            Logger::console_log("failed_open log file. only console", "warn");
        }
    }
     void Logger::close_file(){
         if(log_file.is_open()){
            log_file.close();
         }
     }