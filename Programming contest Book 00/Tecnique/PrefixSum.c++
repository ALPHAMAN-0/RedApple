#include<iostream>
#include<vector>

using namespace std;
// Prefix Sum Array of same size
vector<int> PrefixSum(vector<int> &arr){
    int ArraySize(arr.size());
    vector<int> prefixSum(ArraySize);

    prefixSum[0] = arr[0];
    for(int i=1;i<ArraySize;i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
    return prefixSum;
}
// Prefix Sum array of size n+1
vector<int> PrefixSumOffset(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n + 1, 0);
    
    for (int i = 0; i < n; ++i) {
        prefix[i+1] = prefix[i] + arr[i];
    }
    return prefix;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    vector<int> prefixSum = PrefixSum(arr);
    vector<int> prefixSumOffset = PrefixSumOffset(arr);

    
    for(int i=0;i<prefixSumOffset.size();i++){
        cout<<prefixSumOffset[i]<<" ";
    }
    for(int i=0;i<prefixSum.size();i++){
        cout<<prefixSum[i]<<" ";
    }
    return 0;

}