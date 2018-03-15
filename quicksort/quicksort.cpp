#include "quicksort.hpp"
#include <algorithm>

quicksort::~quicksort(){
  delete data;
}

int quicksort::split(int A[], int lo, int hi){
  int pivot = A[hi];
  int i = lo - 1;
  for(int j=lo; j<hi; ++j){
    if (A[j] < pivot){
      ++i;
      std::swap(A[i], A[j]);
    }
  }
  std::swap(A[i+1], A[hi]);
  return i+1;
}

void quicksort::sort(int A[], int lo, int hi){
  if(lo < hi){
    int s = split(A,lo,hi);
    sort(A, lo, s - 1);
    sort(A, s+1, hi);
  }
}

void quicksort::run(){
  sort(data,*data,data[dataSize-1]);
}

void quicksort::prepare(int size){
  data = new int[size];
  for (int i=0; i<dataSize; ++i){
    data[i] = rand() % dataSize;
  }
}
