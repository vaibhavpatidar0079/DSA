// Basic C++ template
#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& arr, int st, int end){
    
    if(end-st == 0 || end-st == 1){
        return;
    }

    int mid = st + (end-st)/2;
    vector<int> left;
    vector<int> right;

    for(int i=st;i<end; i++){
        if(i==mid) continue;
        if(arr[i]>= arr[mid]){
            left.push_back(arr[i]);
        }else{
            right.push_back(arr[i]);
        }
        
    }
    arr[left.size() + st]= arr[mid];

    for(int i=0;i<left.size();i++){
        arr[i+st] = left[i];
    }
    
    for(int i=0;i<right.size();i++){
        arr[i+st+left.size()+1] = right[i];
    }
    sort(arr,st,st+left.size());
    sort(arr,st+left.size()+1,end);
}

int main() {
    vector<int> arr ={ 23,53,24,12,34,56,78,90,11,22};
    sort(arr,0,arr.size());
    for(int x: arr){
        cout<<x<<" ";
    }
	return 0;
}
