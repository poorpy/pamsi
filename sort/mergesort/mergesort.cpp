#include "mergesort.hpp"
#include <algorithm>

///////////PUBLIC METHODS///////////
void Mergesort::run(){
  mergesort(sortedData, 0, dataSize);
}

void Mergesort::prepare(int size){
  dataSize = size;
  data = new int[size];
  sortedData = new int[size];
  srand(time(NULL));
  for (int i=0; i< dataSize; ++i){
    data[i] = rand() % dataSize;
  }
  std::copy(data, data+dataSize, sortedData);
}

void Mergesort::prepareInverse(int size){
  dataSize = size;
  data = new int[size];
  sortedData = new int[size];
  for (int i=0; i<(dataSize+1)/2; ++i){
    data[i] = (dataSize+1)/2+i;
    data[(dataSize/2)+i] = i;
  }
  std::copy(data, data+dataSize, sortedData);
}

void Mergesort::resetData(){
  std::copy(data, data+dataSize, sortedData);
}

int* Mergesort::getData(){
  return this->data;
}

int* Mergesort::getSortedData(){
  return this->sortedData;
}

int& Mergesort::getDataSize(){
  return this->dataSize;
}

Mergesort::~Mergesort(){
  delete[] data;
  delete[] sortedData;
}

///////////PRIVATE METHODS///////////
void Mergesort::mergesort(int A[], int start, int end){
  if (start < end){
    int mid = (start + end)/2;
    mergesort(A, start, mid);
    mergesort(A, mid+1, end);
    merge(A, start, mid, end);
  }
}

void Mergesort::merge(int A[], int start, int mid, int end)
{
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 =  end - mid;
 
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[start + i];
    for (j = 0; j < n2; j++)
        R[j] = A[mid + 1+ j];
 
    i = j = 0; // Initial index of first subarray
    k = start; // Initial index of merged subarray
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){A[k++] = L[i++];}
        else{A[k++] = R[j++];}
    }
 
    while (i < n1){A[k++] = L[i++];}
 
    while (j < n2){A[k++] = R[j++];}
}
