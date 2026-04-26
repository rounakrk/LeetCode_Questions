class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;
        for(int i : nums){
            if(i%2 == 0) result.push_back(i);
        }
        for(int i : nums){
            if(i%2 == 1) result.push_back(i);
        }
        return result;
    }
};