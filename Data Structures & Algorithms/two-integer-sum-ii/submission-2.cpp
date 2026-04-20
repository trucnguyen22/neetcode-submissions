class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int strp = 0, endp = numbers.size() - 1;

        while (strp < endp) {
            int sum = numbers[strp] + numbers[endp]; 
            if (sum == target) {
                return {strp+1, endp+1};
            } else if (sum > target) endp--;
            else strp++; 
        }

        return {};
    }
};
