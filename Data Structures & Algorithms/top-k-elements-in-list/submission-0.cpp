class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;

        }
        //max heap
        priority_queue<pair<int,int>>pq;

        //push{freq,ele}
        for(auto it : mpp){
            pq.push({it.second,it.first});
        }
       
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};
