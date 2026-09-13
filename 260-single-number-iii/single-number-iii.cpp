#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: XOR all elements to get (a ^ b)
        long long xorSum = 0;
        for (int i = 0; i < n; i++) {
            xorSum ^= nums[i];
        }

        // Step 2: Find the rightmost set bit to distinguish a from b
        long long lowestBit = xorSum & (-xorSum);

        // Step 3: Partition and XOR elements into two groups
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] & lowestBit) != 0) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }

        return {a, b};
    }
};