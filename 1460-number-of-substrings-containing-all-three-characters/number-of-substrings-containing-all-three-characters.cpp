class Solution {
public:
    int numberOfSubstrings(string s) {
         int n=s.size();
    int count=0;
    vector<int>v(3,-1);
    for(int i=0;i<n;i++){
        v[s[i]-'a']=i;
        if(v[0]!=-1 && v[1]!=-1 && v[2]!=-1){
            count+=min({v[0],v[1],v[2]})+1;
        }
    }
    return count;
    }
};