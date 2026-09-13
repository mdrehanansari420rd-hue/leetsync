class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int totalSubsets = 1 << n; // 2^n
        vector<vector<int>> result;
        
        for (int i = 0; i < totalSubsets; ++i) {
            vector<int> current;
            for (int j = 0; j < n; ++j) {
                // Check if the j-th bit is set in the binary representation of i
                if ((i >> j) & 1) {
                    current.push_back(nums[j]);
                }
            }
            result.push_back(current);
        }
        
        return result;
    }
};