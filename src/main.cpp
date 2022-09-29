#include "../include/dobleList.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
  LinkedList list(1);
  list.append(2);
  list.append(3);
  list.watch();
  return 0;
}
