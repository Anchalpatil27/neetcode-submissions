class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int temp = target - numbers[i];
            if(mpp.find(temp) != mpp.end()){
                return{mpp[temp],i+1};
            }
            mpp[numbers[i]] = i+1;
        }
        return {};
        
    }
};
