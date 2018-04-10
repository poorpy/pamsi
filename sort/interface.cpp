#include  "interface.hpp"

using namespace std::chrono;

int measureTime(Algorithm &prog){
  int timeSum=0;
  for(int i=0; i<50; ++i){
    high_resolution_clock::time_point begin = high_resolution_clock::now();
    prog.run();
    high_resolution_clock::time_point end = high_resolution_clock::now();
    timeSum += duration_cast<microseconds>(end - begin).count();
    prog.resetData();
  }
  return (timeSum/50);
}
