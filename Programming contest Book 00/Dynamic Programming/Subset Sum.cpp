#include<iostream>
#include<vector>

using namespace std;
void PrintSubSetSum(vector<int> dp,int M);
void SubsetSum(vector<int> arr,int M){
    // dp[] is indexed by the sums 0..M, so M and every number must not be negative
    if(M<0){
        cout<<"The maximum sum must not be negative"<<endl;
        return;
    }
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0){
            cout<<"The numbers must not be negative"<<endl;
            return;
        }
    }
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
    // after a failed read n would be uninitialised, and a negative n cannot be a size
    if(!cin || n<0){
        cout<<"Enter two numbers; the array size must not be negative"<<endl;
        return 1;
    }

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SubsetSum(arr,M);
    return 0;
}