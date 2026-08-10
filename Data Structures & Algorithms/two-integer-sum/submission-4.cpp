class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<int, int>> numsWithIndex;

        for(int i = 0; i < n; i++) {
            numsWithIndex.push_back({nums[i], i});
        }

        sort(numsWithIndex.begin(), numsWithIndex.end());

        int i = 0;
        int j = n - 1;

        while(i < j) {
            int sum = numsWithIndex[i].first + numsWithIndex[j].first;

            if(sum == target) {
           int idx1 = numsWithIndex[i].second;
           int idx2 = numsWithIndex[j].second;

    return {min(idx1, idx2), max(idx1, idx2)};
        }
            else if(sum < target) {
                i++;
            }
            else {
                j--;
            }
        }

        return {-1, -1};
    }
};
