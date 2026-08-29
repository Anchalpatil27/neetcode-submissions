class Solution {
public:
long long totalHours(vector<int>&piles,int h){
    long long totalH = 0;
    for(int pile : piles){
        totalH += (pile + h - 1)/h;

    }
    return totalH;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(),piles.end());
        int low = 1;
        int high = maxPile;
        int ans = maxPile;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long totalH = totalHours(piles,mid);
            if(totalH <= h){
                ans = mid;
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
        
    }
};
