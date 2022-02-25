#ifndef MINMAXHEAP_CPP
#define MINMAXHEAP_CPP

#include "minmaxheap.h"

template <typename T>
T& MinMaxHeap<T>::getMax() {
    if(elements.size()==1){
        return elements[0];
    }
    else if(elements.size()==2 || elements[1] >= elements[2] ){
        return elements[1];
    }
    else {
        return elements[2];
    }
}

template <typename T>
int MinMaxHeap<T>::getMaxIndex() {
    if(elements.size()==1){
        return 0;
    }
    else if(elements.size()==2 || elements[1] >= elements[2]){
        return 1;
    }
    else {
        return 2;
    }
}

template <typename T>
int MinMaxHeap<T>::getMinChildOrGrandChild(int index) {
    int minChild = index;
    int leftChild = getLeftChild(index);
    if(leftChild < elements.size() && elements[leftChild] < elements[minChild])
        minChild = leftChild;
    int rightChild = leftChild +1;
    if(rightChild < elements.size() && elements[rightChild] < elements[minChild])
        minChild = rightChild;
    int leftGrandChild = getLeftChild(leftChild);
    for (int i = leftGrandChild; i <= leftGrandChild + 3 && i < elements.size(); i++)
        if (elements[i] < elements[minChild])
            minChild = i;
    return minChild;
}

template <typename T>
int MinMaxHeap<T>::getMaxChildOrGrandChild(int index) {
    int maxChild = index;
    int leftChild = getLeftChild(index);
    if(leftChild < elements.size() && elements[leftChild] > elements[maxChild])
        maxChild = leftChild;
    int rightChild = leftChild +1;
    if(rightChild < elements.size() && elements[rightChild] > elements[maxChild])
        maxChild = rightChild;
    int leftGrandChild = getLeftChild(leftChild);
    for (int i = leftGrandChild; i <= leftGrandChild + 3 && i < elements.size(); i++)
        if (elements[i] > elements[maxChild])
            maxChild = i;
    return maxChild;
}

template <typename T>
void MinMaxHeap<T>::pushDownMin(int index) {
    int indexOfLeftChild = getLeftChild(index);
    if(indexOfLeftChild < elements.size()){
        int indexOfMinChildOrGrandchild = getMinChildOrGrandChild(index);
        if(getGrandParent(indexOfMinChildOrGrandchild) == index &&(index > 2 || elements.size() > 3)){
            if(elements[indexOfMinChildOrGrandchild] < elements[index])
                swap(elements[indexOfMinChildOrGrandchild],elements[index]);
                if(elements[indexOfMinChildOrGrandchild] > elements[getParent(indexOfMinChildOrGrandchild)])
                    swap(elements[indexOfMinChildOrGrandchild],elements[getParent(indexOfMinChildOrGrandchild)]);
                    pushDownMin(indexOfMinChildOrGrandchild);
        }
        else if(elements[indexOfMinChildOrGrandchild] < elements[index])
            swap(elements[indexOfMinChildOrGrandchild],elements[index]);
    }
}


template <typename T>
void MinMaxHeap<T>::pushDownMax(int index) {
    int indexOfLeftChild = getLeftChild(index);
    if(indexOfLeftChild < elements.size()){
        int indexOfMaxChildOrGrandchild = getMaxChildOrGrandChild(index);
        if(getGrandParent(indexOfMaxChildOrGrandchild) == index && (index > 2 || elements.size() > 3)){
            if(elements[indexOfMaxChildOrGrandchild] > elements[index])
                swap(elements[indexOfMaxChildOrGrandchild],elements[index]);
                if(elements[indexOfMaxChildOrGrandchild] < elements[getParent(indexOfMaxChildOrGrandchild)])
                    swap(elements[indexOfMaxChildOrGrandchild],elements[getParent(indexOfMaxChildOrGrandchild)]);
                    pushDownMax(indexOfMaxChildOrGrandchild);
        }
        else if(elements[indexOfMaxChildOrGrandchild] > elements[index])
            swap(elements[indexOfMaxChildOrGrandchild],elements[index]);
    }
}

template <typename T>
void MinMaxHeap<T>::pushDown(int index) {
    if(getHeight(index)%2==0){
        pushDownMin(index);
    }
    else {
        pushDownMax(index);
    }
}

template <typename T>
void MinMaxHeap<T>::pushUpMin(int index) {
  if(index > 2 && elements[index] < elements[getGrandParent(index)]){
    swap(elements[index],elements[getGrandParent(index)]);
    pushUpMin(getGrandParent(index));
  }
}

template <typename T>
void MinMaxHeap<T>::pushUpMax(int index) {
  if(index > 2 && elements[index] > elements[getGrandParent(index)]){
    swap(elements[index],elements[getGrandParent(index)]);
    pushUpMax(getGrandParent(index));
  }
}

template <typename T>
void MinMaxHeap<T>::pushUp(int index) {
    if(index == 0) return;
    if(getHeight(index)%2 == 0){
        if(elements[index] > elements[getParent(index)]){
            swap(elements[index],elements[getParent(index)]);
            pushUpMax(getParent(index));
        }
        else pushUpMin(index);
    }
    else{
        if(elements[index] < elements[getParent(index)]){
            swap(elements[index],elements[getParent(index)]);
            pushUpMin(getParent(index));
        }
        else pushUpMax(index);
    }
}

template <typename T>
void MinMaxHeap<T>::push(const T& element) {
    elements.push_back(element);
    pushUp(elements.size()-1);
}

template <typename T>
void MinMaxHeap<T>::makeHeap() {
    int i = getParent(elements.size()-1);
    for (i;i>=0;i--){
        pushDown(i);
    }
}

template <typename T>
void MinMaxHeap<T>::removeMin() {
    elements[0] = elements[elements.size()-1];
    elements.pop_back();
    pushDown(0);
}

template <typename T>
void MinMaxHeap<T>::removeMax() {
    int maxIndex = getMaxIndex();
    elements[maxIndex] = elements[elements.size()-1];
    elements.pop_back();
    pushDown(maxIndex);
}

#endif
