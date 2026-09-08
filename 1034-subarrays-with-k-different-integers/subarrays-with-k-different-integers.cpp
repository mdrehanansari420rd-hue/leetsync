class Solution {
private:
    int Atmost(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, count = 0;
        unordered_map<int, int> mpp;
        
        while (r < n) {
            mpp[nums[r]]++;
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            count += (r - l + 1); // Fixed: calculated dynamically per iteration
            r++;
        }
        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return Atmost(nums, k) - Atmost(nums, k - 1);
    }
};