class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n=a.size();

        int lsum=0,rsum=0;
        int sum=0;
        for(int i=0;i<k;i++){
            lsum=lsum+a[i];
        }
        sum=lsum;
        int rindex=n-1;
        for(int i=k-1;i>=0;i--){
            lsum=lsum-a[i];
            rsum=rsum+a[rindex];
            rindex--;
            sum=max(sum,rsum+lsum);
        }
        return sum;
    }
};