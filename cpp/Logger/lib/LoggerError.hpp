/*
Extracts the players cards from an image
*/
#include <string>
#include <vector>
#include <iostream>

#include <boost/log/trivial.hpp>

#include "LoggerBase.hpp"

#ifndef LOGGER_ERROR_H
#define LOGGER_ERROR_H

/**
    * Extracts the cards from the image
*/
namespace vii {



class LoggerError : LoggerBase
{
    public:
/**
    * [static] class1Name 
    * 
    * @param  {type1} var1                      : 
    * @param  {int*(*)()} f1                    : 
    * @param  {type2** [class2Name:: var]} var2 : 
    * @return {returnType***}                   : 
*/
    LoggerError(){};
    ~LoggerError(){};

    void operator << (const std::string str){
        BOOST_LOG_TRIVIAL(error) << str.c_str();
    };
    void operator << (const char* s){
        BOOST_LOG_TRIVIAL(error) << s;
    };

};

}//namespace vii
#endif //LOGGER_ERROR_H
