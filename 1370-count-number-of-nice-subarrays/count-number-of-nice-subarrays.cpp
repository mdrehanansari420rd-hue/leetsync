class Solution {
private:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int n = nums.size();
        int count = 0;
        int l = 0, r = 0;
        int sum = 0;
        
        while (r < n) {
            sum += (nums[r]%2);
            while (sum > goal) {
                sum -= (nums[l]%2);
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k){
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};