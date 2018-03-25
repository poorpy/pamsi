#pragma once 

#include "interface.hpp"

class quicksort : public Algorithm{
public:
  void run();
  void prepare(int size);
  void resetData();
  ~quicksort();
private:
  void sort(int A[], int lo, int hi);
  int split(int A[], int lo, int hi);
  int *data;
  int *sortedData;
  int dataSize; 
}; 
