class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> table;
        for (int num : arr) {
            if (table.count(num * 2) || (num % 2 == 0 && table.count(num / 2))) {
                return true;
            }
            table.insert(num);
        }
        return false;
    }
};