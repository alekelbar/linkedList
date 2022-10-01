#include "../include/LinkedList.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
  LinkedList list;
  list.at(2, 0);
  list.at(3, 1);
  list.at(5, 2);
  list.watch();
  list.removeAt(1);
  list.watch();
  return 0;
}
