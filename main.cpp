#include "./logger/logger.hpp"

int main(int argc,  char **argv ){
    Logger logger(argv[1],argv[2]);
    if(logger.file_logger == true){
        logger.init_file_log();
    }
    logger.log("siema", "info");
    logger.log("eniu", "info");
    logger.log("critical_isue", "crit");
    logger.close_file();
    return 0; 
}