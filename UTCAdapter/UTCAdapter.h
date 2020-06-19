#ifndef UTC_ADAPTER_H
#define UTC_ADAPTER_H

#include <ctime>

class UTCAdapter{

public:
UTCAdapter();
virtual ~UTCAdapter();

std::time_t get_time();
void print();

};//class UTCAdapter
#endif//UTC_ADAPTER_H
