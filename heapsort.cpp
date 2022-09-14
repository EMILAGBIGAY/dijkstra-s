#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//heap sort using vectors
class heapsort{
    public:
        vector<pair<int32_t,int32_t>> nums;
        int tSize=0;
        void insert(int,int);
        pair<int,int> min();
        void removeMin();
        int size();
        bool isEmpty();
        void upheap(int,int);
        void downheap();
};

void heapsort::downheap(){
    nums[0]=nums[tSize-1]; //last element as root
    int index=0;
    while((index*2+2) < tSize){    //dont stop till u reach the end
        //set values to compare
        pair<int,int> temp2 =nums[index];
        int temp=nums[index].first;    
        int left=nums[index*2+1].first;
        int right=nums[index*2+2].first;
        if(left<right && left<temp){       //check to switch with left child
            nums[index]=nums[index*2+1];
            nums[index*2+1]=temp2;
            index=index*2+1;  //change to correct index on the vector 
        }
        else if(right<left && right<temp){  //check to switch with right child
            nums[index]=nums[index*2+2];
            nums[index*2+2]=temp2;
            index=index*2+2;    //change to correct index on the vector 
        }
        else{               //stop in right place

            break;
        }
    }
}

void heapsort::upheap(int element,int city){

    //int index=tSize;       //set index as Size of heap because u havent added to size yet
    //cout<<tSize<<endl;
    int index=tSize;
    while(((index-1)/2) >= 0 ){    //check for parents
        //pair<int,int> temp={element,city};
        //pair<int,int> parent=nums[(index-1)/2];   
        int parent = nums[(index-1)/2].first;
        int parentc = nums[(index-1)/2].second;
        //cout<<parent<<" "<<parentc<<endl;
        if(element < parent){        //check to swap 
            nums[(index-1)/2]={element,city};
            //nums[(index-1)/2].first=element;
            //nums[(index-1)/2].second=city;
            //nums[index].first=parent;
            //nums[index].second=parentc;
            nums[index]={parent,parentc};
            //cout<<index<<" "<<nums[index].first<<endl;
        }
        else{                        //if not stop and put the number in place
            //nums[index].first=element;
            //nums[index].second=city;
            nums[index]={element,city};
            
            break;
        }
        index=((index-1)/2);
    }
    
}

void heapsort::insert(int element,int city){
    if(isEmpty()){   //if empty element is the root
        nums.push_back({element,city});
    }
    else{           //else call upheap to inset the element in the correct position
        upheap(element,city);
    }
    tSize++;        //increase size of heap
}

pair<int,int> heapsort::min(){
    return nums[0];   //first element in vector is the root
} 

void heapsort::removeMin(){
    if(tSize<=1){       //if only the root exists clear the vector
        nums.pop_back();
        tSize=0;
    }
    else{             //call downheap to remove the root and fix the heap order
        downheap();
        tSize--;
    }
                          //decrease the size of the heap
}

int heapsort::size(){
    return tSize;    //variable for the size of the heap
}

bool heapsort::isEmpty(){
    if(tSize<=0)        //check size of the heap 
        return true;
    else
        return false;
}


int main(){
    heapsort heap;
    

    int arr[]={5,6,9,7,2};
    int n=5;
    
    for(int i=0;i<n;i++){
        heap.insert(arr[i],i);
    }

    cout<<"min: "<<heap.min().first<<endl;
    cout<<"size: "<<heap.size()<<endl;
    cout<<"empty? "<<heap.isEmpty()<<endl;

    for(int i=0;i<heap.tSize;i++){
        cout<<heap.nums[i].first<<" ";
    }
    cout<<endl;

    heap.removeMin();
    for(int i=0;i<heap.tSize;i++){
        cout<<heap.nums[i].first<<" ";
        
    }
    cout<<endl;

    cout<<"size: "<<heap.size()<<endl;
    cout<<"min: "<<heap.min().first<<endl;
}