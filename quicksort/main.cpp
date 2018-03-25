#include "quicksort.hpp"
#include <fstream> 

int main(){
  quicksort prog = quicksort();

  std::fstream file;
  file.open("duration.csv", std::fstream::out);

  file << "Wiekość problemu,Czas trwania [us]" << std::endl;
  int sizes[] = {10, 100, 1000, 10000, 100000, 1000000};
  for(auto i : sizes){
    prog.prepare(i);
    file << i << ',' << measureTime(prog)  << std::endl;
  }
  file.close();
  return 0;
}
