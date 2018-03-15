#include <chrono>
#include <thread>
#include <fstream>
#include <iostream>
using namespace std::chrono;

class IRunnable{
  public:
    virtual void run()=0;
};

class IPreparable{
  public:
    virtual void prepare(int size)=0;
};

class Stub : public IRunnable, public IPreparable{
  int dataSize;
  int * data;
  public:
  void run(){
    unsigned int durationTime = 0.01 * this->dataSize;
    std::this_thread::sleep_for(milliseconds(durationTime));
  }
    void prepare(int size){
       dataSize=size;
  }
};

int measureTime(IRunnable &prog){
  int timeSum=0;

  for(int i=0; i<50; ++i){
    high_resolution_clock::time_point begin = high_resolution_clock::now();
    prog.run();
    high_resolution_clock::time_point end = high_resolution_clock::now();
    timeSum += duration_cast<milliseconds>(end - begin).count();
  }
  return (timeSum/50);
}

int main(){
  Stub program;
  std::fstream file;
  file.open("duration.csv", std::fstream::out);
  int sizes[] = { 10, 100, 1000, 10000, 100000, 1000000 };
  file << "Wiekość problemu,Czas trwania [ms]" << std::endl;
  for(int i=0; i<5; i++){
    program.prepare(sizes[i]);
    file << sizes[i] << ',';
    file << measureTime(program) << std::endl; 
  }
  file.close();
  return 0;
}
