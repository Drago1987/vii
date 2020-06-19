/*
Extracts the players cards from an image
*/
#include <string>
#include <vector>
#include <iostream>

#include <boost/log/trivial.hpp>

#ifndef LOGGER_BASE_H
#define LOGGER_BASE_H

/**
    * Extracts the cards from the image
*/
namespace vii {



class LoggerBase
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
    LoggerBase(){};
    ~LoggerBase(){};

    virtual void operator << (const std::string str)=0;
    virtual void operator << (const char* s)=0;
    std::string operator + (const char* s){
        return s;
    };
    std::string operator + (const std::string str){
        return str;
    };

};

}//namespace vii
#endif //LOGGER_BASE_H
