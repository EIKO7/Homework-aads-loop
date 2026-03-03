#include "BiList.h"
#include <iostream>

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int size = 5;

  BiList<int> list;

  for (int i = 0; i < size; ++i) {
    list.push_back(arr[i]);
  }

  list.print();

  return 0;
}
