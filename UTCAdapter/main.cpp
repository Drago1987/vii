#include"UTCAdapter.h"
#include <memory>

int main (int argc, char **argv)
{
  std::unique_ptr<UTCAdapter> tmp;
  tmp->print();
  return 0;
}

