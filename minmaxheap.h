#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>

using namespace std;


template <typename T>
class MinMaxHeap {

  vector<T> elements;

  int getHeight(int index) {return int(log2(index+1));}
  int getRightChild(int index) { return 2*index + 2; }
  int getLeftChild(int index) { return 2*index + 1; }
  int getParent(int index) { return (index-1)/2; }
  int getGrandParent(int index) { return (index-3)/4; }

  void pushUp(int index);
  void pushUpMax(int index);
  void pushUpMin(int index);
  void pushDown(int index);
  void pushDownMax(int index);
  void pushDownMin(int index);
  void makeHeap();
  int getMinChildOrGrandChild(int index);
  int getMaxChildOrGrandChild(int index);

  public:
  MinMaxHeap() {}
  MinMaxHeap(const vector<T> &elements):elements(elements) { makeHeap(); }
  T& getMin() { return elements[0]; }
  T& getMax();
  int getMaxIndex();
  void push(const T& element);
  void removeMin();
  void removeMax();
  void write() { for(int i=0;i<elements.size();i++) cout<<elements[i]<<" "; cout<<endl;}
};

#endif
