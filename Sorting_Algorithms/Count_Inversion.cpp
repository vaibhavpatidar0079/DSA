#include <iostream>
#include <vector>
using namespace std;

void countInv(vector<int> &arr, int st, int end, int &count){
    if(st >= end){
        return;
    }

    int cut = st+(end-st)/2;
    countInv(arr,st,cut,count);
    countInv(arr,cut+1,end,count);
    
    int pt1=st;
    int pt2=cut+1;
    vector<int> sorted;

    while(pt1<=cut && pt2<=end){
        if(arr[pt1] > arr[pt2]){
            count= count + cut-pt1+1;
            sorted.push_back(arr[pt2]);
            pt2++;
        }else{
            sorted.push_back(arr[pt1]);
            pt1++;
        }
    }
    while(pt1<=cut){
        sorted.push_back(arr[pt1]);
        pt1++;
    }
    while(pt2<=end){
        sorted.push_back(arr[pt2]);
        pt2++;
    }
    for(int i=0; i<sorted.size(); i++){
        arr[st+i] = sorted[i];
    } 
}

int main(){
    vector<int> arr={1,3,5,9,4,12,6,14};
    int count = 0;
    countInv(arr,0,arr.size()-1,count);

    for(int x: arr){
        cout<< x<<" ";
    }
    cout<<endl;
    cout<<count<<endl;

    return 0;
}