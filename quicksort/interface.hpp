#pragma once 

#include <chrono>

//enum ProblemCase { BEST, AVERAGE, WORST };

class IRunnable{
  public:
  virtual void run() = 0;
};

class IPreparable{
  public:
    virtual void prepare(int size)=0;
};

int mesureTime(IRunnable &prog);
