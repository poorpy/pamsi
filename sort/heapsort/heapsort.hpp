#pragma once

#include "../interface.hpp"

class Heapsort : public Algorithm{
public:
  /**
   * Runs algorithm on *sortedData
   */
  void run() override;
  /**
   * Initializes *data and *sortedData with arrays of random integers
   * @param size number of elements in array
   */
  void prepare(int size) override;
  /**
   * Initializes *data and *sortedData with arrays containing
   * sequence: (size/2)+1, (size/2)+2, ..., size, 1, 2, ..., (size/2)
   * @param size number of elements in array
   */
  void prepareInverse(int size) override;
  /**
   * Copies contents of *data to *sortedData
   */
  void resetData() override;
  ///////////////////////////////////////////////////////
  //Getters - They allow access to members of an object//
  ///////////////////////////////////////////////////////
  int* getData() override;
  int* getSortedData() override;
  int& getDataSize() override;
  //////////////
  //Destructor//
  //////////////
  ~Heapsort();
private:
  /**
   * @param A array
   * @param size number of elements in an array
   */
  void heapsort(int A[], int size);
  /**
   * Places root in correct index in Array
   * @param A array 
   * @param size number of elements in an array
   * @param root index of root element
   */
  void heapify(int A[], int size, int root);
  /**
   * Not mutated copy of data to be sorted
   */
  int* data=nullptr;
  /**
   * Mutated copy of data to be sorted
   */
  int* sortedData=nullptr;
  /**
   * Number of elemnets in an array
   */
  int dataSize=0;

};
