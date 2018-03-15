#include "quicksort.hpp"
#include <iostream> 

#define SMALL 10
#define MEDIUM 100
#define LARGE 1000 


int main(){
  quicksort* small = new quicksort;
  small -> prepare(SMALL);
  std::cout << "Unsorted:,";
  for(int i=0; i < small->dataSize; ++i){
    std::cout << small -> data[i] << ',';
  }
  std::cout << std::endl;

  small -> run();

  std::cout << "Sorted:,";
  for(int i=0; i < small->dataSize; ++i){
    std::cout << small -> data[i] << ',';
  }
  std::cout << std::endl;
  return 0;
}
