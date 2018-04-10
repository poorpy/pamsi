#include "quicksort.hpp"
#include <algorithm>

///////////PUBLIC METHODS///////////
void Quicksort::run(){
  sort(sortedData,0,dataSize-1);
}

void Quicksort::prepare(int size){
  dataSize = size;
  data = new int[size];
  sortedData = new int[size];
  srand(time(NULL));
  for (int i=0; i< dataSize; ++i){
    data[i] = rand() % dataSize;
  }
  std::copy(data, data+dataSize, sortedData);
}

void Quicksort::prepareInverse(int size){
  dataSize = size;
  data = new int[size];
  sortedData = new int[size];
  for (int i=0; i<(dataSize+1)/2; ++i){
    data[i] = (dataSize+1)/2+i;
    data[(dataSize/2)+i] = i;
  }
  std::copy(data, data+dataSize, sortedData);
}

void Quicksort::resetData(){
  std::copy(data, data+dataSize, sortedData);
}

int* Quicksort::getData(){
  return this->data;
}

int* Quicksort::getSortedData(){
  return this->sortedData;
}

int& Quicksort::getDataSize(){
  return this->dataSize;
}

Quicksort::~Quicksort(){
  delete[] data;
  delete[] sortedData;
}

///////////PRIVATE METHODS///////////
void Quicksort::sort(int A[], int lo, int hi){
  if(lo < hi){
    int s = split(A,lo,hi);
    this->sort(A, lo, s - 1);
    this->sort(A, s+1, hi);
  }
}

int Quicksort::split(int A[], int lo, int hi){
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


