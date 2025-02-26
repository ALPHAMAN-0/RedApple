#include<iostream>
#include<vector>

using namespace std;
void SubsetSum(vector<int> arr,int M){
    // DP initialization
    vector<int> dp(M+10,0);
    dp[0] = 1;

    // DP computation
    for(int i=0;i<arr.size();i++){
        for(int j=M;j>=arr[i];j--){
            dp[j] |= dp[j-arr[i]];
        }
    }
    PrintSubSetSum(dp,M);
}
void PrintSubSetSum(vector<int> dp,int M){
      //output result
    for(int k=0;k<=M;k++){
        if(dp[k]){
            cout<<"subset sum possible for "<<k<<endl;
        }
    }
}
int main(){
    int n,M;
    cout<<"enter the maximum sum and the array size"<<endl;
    cin>>M>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SubsetSum(arr,M);
    return 0;
}