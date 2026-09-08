class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";
        
        vector<int> map(128, 0);
        for (char c : t) map[c]++;
        
        int count = t.length();
        int l = 0, r = 0, start = 0, minLen = INT_MAX;
        
        while (r < s.length()) {
            if (map[s[r]] > 0) count--;
            map[s[r]]--;
            r++;
            
            while (count == 0) {
                if (r - l < minLen) {
                    minLen = r - l;
                    start = l;
                }
                map[s[l]]++;
                if (map[s[l]] > 0) count++;
                l++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};