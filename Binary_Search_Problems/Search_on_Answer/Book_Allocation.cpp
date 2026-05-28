#include <iostream>
#include <vector>
using namespace std;

int sumIs(vector<int>& arr, int m){
    int sum = 0;
    for(int i: arr){
        sum += i;
    }
    return sum;
}

bool isValid(vector<int>& arr, int m, int mid){
    int stu =1; int pages = 0;
    for(int i: arr){
        if((pages + i) <= mid){
            pages += i;
        }else if(i <= mid){
            stu++;
            pages = i;
        }else{
            return false;
        }
    }
    if(stu <= m){
        return true;
    }else{
        return false;
    }
}


int minAns(vector<int>& arr, int m){
    int st = 0;
    int end = sumIs(arr, m);
    int mid = st + (end - st) / 2;
    int ans = 0;

    while(st<=end){
        mid = st + (end - st) / 2;
        if(isValid(arr, m, mid)){
            end = mid -1;
            ans = mid;
        }else{
            st = mid +1;
        }
    }
    if(ans == 0){
        return -1;
    }else{
        return ans;
    }
}

int main(){
    vector<int> arr = {100,1,1};
    int m = 1;

   cout<<minAns(arr, m); 
}