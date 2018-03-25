#pragma once 

#include <chrono>

class IRunnable{
  public:
  virtual void run() = 0;
};

class IPreparable{
  public:
    virtual void prepare(int size)=0;
};

class Algorithm : public IRunnable, public IPreparable{
  public:
    virtual void resetData()=0;
};

int measureTime(Algorithm &prog);
