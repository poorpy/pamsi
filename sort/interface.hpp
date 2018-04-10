#pragma once 

#include <chrono>

class IRunnable{
  public:
  virtual void run() = 0; 
};

class IPreparable{
  public:
    virtual void prepare(int size)=0;
    virtual void prepareInverse(int size)=0;
};

class Algorithm : public IRunnable, public IPreparable{
  public:
    virtual void resetData()=0;
    virtual int* getData()=0;
    virtual int* getSortedData()=0;
    virtual int& getDataSize()=0;
};

int measureTime(Algorithm &prog);
