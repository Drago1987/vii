#include "LoggerInfo.hpp"
#include "LoggerError.hpp"

int main(int, char*[])
{
    vii::LoggerInfo() << "Test Me" + std::to_string(__LINE__) + " Test";
    vii::LoggerError() << "Test Me" + std::to_string(__LINE__) + " Test";

    return 0;
}