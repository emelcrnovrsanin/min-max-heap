#include "minmaxheap.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main () {

    MinMaxHeap<int> h;
    h.push(32);
    h.push(9);
    h.push(3);
    h.push(94);
    h.write();
    cout<<endl;

    vector<int> v{39,9,3,1,8,10};
    MinMaxHeap<int> h1(v);
    h1.write();

    vector<int> v2{39,9,3};
    MinMaxHeap<int> h2(v2);
    h2.write();

    vector<int> v3{38,94,12,132,85,74,9,7,4,55,21,24,23,1,99};
    MinMaxHeap<int> h3(v3);
    h3.push(180);
    h3.write();

}
