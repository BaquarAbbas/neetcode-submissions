class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(freq.find(nums[i]) != freq.end())
             return vector<int> {freq[nums[i]], i};
            freq.insert({diff, i});
        }
        return vector<int>{};

    }
};
