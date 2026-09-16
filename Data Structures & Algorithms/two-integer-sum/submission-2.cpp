class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //sorting approach : use copy of pair {nums[i] , i}
        vector<pair<int,int>> res;
        for(int i = 0; i < nums.size(); i++){
            res.push_back({nums[i], i});
        }

        sort(res.begin(), res.end());
        int i = 0, j = nums.size() - 1;

        while(i < j){
            int currentSum = res[i].first + res[j].first;
            if(currentSum == target)
             return vector<int>{min(res[i].second, res[j].second),
                                max(res[j].second, res[i].second)};

            else if (currentSum < target){
                i++;
            }
            else{
                j--;
            }
        }
        return vector<int>{};

    }
};
