#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



bool isMidAns(int ans, vector<int> stalls, int C,int N){
    int cowsPlaced = 1; //stalls[0]
    int inx = 1;
    int placedAt = stalls[0];

    while(inx < N){
        if(stalls[inx] - placedAt >= ans){
            cowsPlaced++;
            placedAt = stalls[inx];
        }
        inx++;
        if(cowsPlaced == C) return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int N;
        int C;
        cin>>N>>C;
        cout<<endl;

        vector<int> stalls(N);
        for(int i = 0; i < N; i++){
            cin >> stalls[i];
        }
        sort(stalls.begin(),stalls.end());
        //ans between 1 and (stalls[n-1] - stalls[0])/cows-1

        int maxAns = (stalls[N-1] - stalls[0])/(C-1);

        int st = 1;
        int end = maxAns;
        int ans = -1;
        while(st<=end){
            int mid = st + (end-st)/2;
            if(isMidAns(mid,stalls,C,N)){
                ans = mid;
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        cout <<"ans for N: " << N << ", C: " << C<< " is = " << ans<<endl;
    }
    return 0;
}
    