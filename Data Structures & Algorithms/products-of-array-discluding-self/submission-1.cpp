class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        int prod = 1;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                count++;
            }else{
                prod = prod*nums[i];
            }

        }
        if(count > 1){
            return vector<int>(nums.size(),0);

        }
        vector<int>res(nums.size());
        for(size_t i=0;i<nums.size();i++)
        {
            if(count > 0){
                res[i] = (nums[i] == 0) ? prod : 0;
            }else{
                res[i] = prod / nums[i];
            }
        }
        return res;

    }
};
