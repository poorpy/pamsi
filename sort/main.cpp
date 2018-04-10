#include "quicksort/quicksort.hpp"
#include "heapsort/heapsort.hpp"
#include "mergesort/mergesort.hpp"
#include <fstream> 
#include <string>

int main(){
  Quicksort qprog = Quicksort();
  Heapsort hprog = Heapsort();
  Mergesort mprog = Mergesort();

  std::fstream file;
  std::string files[] = {"qrand.csv", "hrand.csv", "mrand.csv"};
  std::string invFiles[] = {"qrandinv.csv", "hrandinv.csv", "mrandinv.csv"};
  Algorithm* programs[] = { &qprog, &hprog, &mprog };
  //int sizes[] = {10, 20, 30, 100, 200, 300, 1000, 2000, 3000,
    //10000, 20000, 30000, 100000, 200000, 200000, 1000000, 2000000, 3000000};
  int sizes[] = {10,20};

  for (int i=0; i<3; ++i){
    file.open(files[i], std::fstream::out);
    file << "Wiekość problemu,Czas trwania [us]" << std::endl;

    for(auto j : sizes){
      programs[i]->prepare(j);
      file << j << ',' << measureTime(*(programs[i]))  << std::endl;
    }
    file.close();
  }

  for (int i=0; i<3; ++i){
    file.open(invFiles[i], std::fstream::out);
    file << "Wiekość problemu,Czas trwania [us]" << std::endl;

    for(auto j : sizes){
      programs[i]->prepareInverse(j);
      file << j << ',' << measureTime(*(programs[i]))  << std::endl;
    }
    file.close();
  }

  return 0;
}
