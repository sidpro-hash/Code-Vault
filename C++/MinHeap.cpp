
//============================================================================
// Name        : MinHeap.cpp
// Author      : SidPro
// Version     : 1.0
// Description : 
/*
	MinHeap creation with all operations. 
*/
//============================================================================

#include <climits>
#include <iostream>
using namespace std;


void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

class MinHeap{
    public:
    int capacity; // maximum possible size of min heap
    int heapsize; // Current number of elements in min heap
    int * harr; // pointer to array of elements in heap
    
    MinHeap(int size){
        capacity = size;
        heapsize = 0;
        harr = new int[size];
    }
    
    void insertKey(int k){
        if(heapsize == capacity){
            cout<<"\nOverFlow: cloud not insert Key\n";
            return;
        }
        ++heapsize;
        // first insert new key at the end
        int i = heapsize - 1;
        harr[i] = k;
        
        while(i!=0 && harr[parent(i)]>harr[i]){
            swap(harr[i],harr[parent(i)]);
            i = parent(i);
        }
    }
    
    void printArry(){
        cout<<"PRINT Heap Array:\n";
        for(int i=0;i<heapsize;++i)
            cout<<harr[i]<<" ";
            
        cout<<"\n";
    }
    
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return i*2+1;
    }
    int right(int i){
        return i*2+2;
    }
    
    int getMin() {
        return harr[0];
    }
    
    void MinHeapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < heapsize && harr[l] < harr[i])smallest=l;
        if(r < heapsize && harr[r] < harr[smallest])smallest = r;
        if(smallest != i){
            swap(harr[i],harr[smallest]);
            MinHeapify(smallest);
        }
    }
    
    // Method to remove minimum element (or root) from min heap
    int extractMin(){
        if(heapsize<=0)return INT_MAX;
        if(heapsize==1){
            --heapsize;
            return harr[0];
        }
        // Store the minimum value, and remove it from heap
        
        int root = harr[0];
        harr[0] = harr[heapsize-1];
        --heapsize;
        MinHeapify(0);
        return root;
    }
    
    void decreaseKey(int i,int new_val){
        harr[i] = new_val;
        while(i!=0 && harr[parent(i)] > harr[i]){
            swap(harr[i],harr[parent(i)]);
            i = parent(i);
        }
    }
    
    // This function deletes key at index i. It first reduced value to minus
    // infinite, then calls extractMin()
    void deleteKey(int i){
        decreaseKey(i,INT_MIN);
        extractMin();
    }
    
    int linearSearch(int val) {
        int i=0;
        for (; i < heapsize; i++) {
          if (harr[i] == val) {
            break;
          }
        }
       return i;
    }
};

int main() {
	MinHeap obj(6);
	obj.insertKey(1);
	obj.insertKey(2);

	obj.printArry();
	obj.insertKey(3);
	obj.insertKey(9);
	obj.insertKey(10);
	obj.insertKey(12);
	obj.printArry();
	return 0;
}

