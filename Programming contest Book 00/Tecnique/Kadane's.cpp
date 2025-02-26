#include <iostream>
#include <vector>
using namespace std;

int kadane(vector<int>& nums) {
    int currentSum = 0;    // Coins in your hand right now
    int bestSum = nums[0]; // Most coins you've had
    
    for(int num : nums) {
        // Pick up this coin
        currentSum = max(num, currentSum + num);
        
        // Is this the most coins we've had?
        bestSum = max(bestSum, currentSum);
    }
    return bestSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Biggest sum possible is: " << kadane(nums) << endl;
    return 0;
}