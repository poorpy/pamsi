#pragma once 

#include "interface.hpp"

class quicksort : public IRunnable, public IPreparable {
public:
  void run();
  void prepare(int size);
  ~quicksort();
  int * data;
  int dataSize; 
private:
  void sort(int A[], int lo, int hi);
  int split(int A[], int lo, int hi);
}; 


