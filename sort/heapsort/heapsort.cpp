#include "heapsort.hpp"
#include <algorithm>

///////////PUBLIC METHODS///////////
void Heapsort::run(){
  this->heapsort(sortedData, this->dataSize);
}

void Heapsort::prepare(int size){
  dataSize = size;
  data = new int[size];
  sortedData = new int[size];
  srand(time(NULL));
  for (int i=0; i<dataSize; ++i){
    data[i] = rand() % dataSize;
  }
  std::copy(data, data+dataSize, sortedData);
}

void Heapsort::prepareInverse(int size){
  dataSize = size;
  data = new int[size];
  sortedData = new int[size];
  for (int i=0; i<(dataSize+1)/2; ++i){
    data[i] = (dataSize+1)/2+i;
    data[(dataSize/2)+i] = i;
  }
  std::copy(data, data+dataSize, sortedData);
}

void Heapsort::resetData(){
  std::copy(data, data+dataSize, sortedData);
}

int* Heapsort::getData(){
  return this->data;
}

int* Heapsort::getSortedData(){
  return this->sortedData;
}

int& Heapsort::getDataSize(){
  return this->dataSize;
}

Heapsort::~Heapsort(){
  delete[] data;
  delete[] sortedData;
}

///////////PRIVATE METHODS///////////
void Heapsort::heapsort(int A[], int size){
  for (int i=size/2 -1; i>=0; i--){
    heapify(A, size, i);
  }

  for (int i=size-1; i>=0; i--){
    std::swap(A[0], A[i]);
    heapify(A, i, 0);
  }
}

void Heapsort::heapify(int A[], int size, int root){
  int largest = root;
  int l = 2*root + 1;
  int r = 2*root + 2;
  
  if (l < size && A[l] > A[largest]){
    largest = l;
  }

  if (r < size && A[r] > A[largest]){ 
    largest = r;
  }

  if (largest != root) {
    std::swap(A[root], A[largest]);
    heapify(A, size, largest);
  }

}
