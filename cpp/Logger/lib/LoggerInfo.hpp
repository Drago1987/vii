/*
Extracts the players cards from an image
*/
#include <string>
#include <vector>
#include <iostream>

#include <boost/log/trivial.hpp>

#include "LoggerBase.hpp"

#ifndef LOGGER_INFO_H
#define LOGGER_INFO_H

/**
    * Extracts the cards from the image
*/
namespace vii {



class LoggerInfo : LoggerBase
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
    LoggerInfo(){};
    ~LoggerInfo(){};

    void operator << (const std::string str){
        BOOST_LOG_TRIVIAL(info) << str.c_str();
    };
    void operator << (const char* s){
        BOOST_LOG_TRIVIAL(info) << s;
    };

};

}//namespace vii
#endif //LOGGER_INFO_H
