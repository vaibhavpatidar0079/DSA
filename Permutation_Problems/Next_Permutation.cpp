#include <iostream>
#include <vector>
using namespace std;

void sorting(vector<int>& arr, int n, int i){
    for(int j = n-1; j>i; j--){
        if(arr[j]>arr[i]){
            swap(arr[j],arr[i]);
            break;
        }
    }
    int st=i+1;
    int end=n-1;
    while(st<end){
        swap(arr[st], arr[end]);
        end--;
        st++;
    }

    for(int i:arr){
        cout<<i<< " ";
    }
}



void nextP(vector<int>& arr, int n){
    for(int i=n-2; i>=0; i--){
        if(arr[i] < arr[i+1]){
            sorting(arr,n,i);
            break;
        }
    }
}

int main() {
    vector<int> arr = {1,3,2};
    int n = arr.size();

    nextP(arr,n);
}