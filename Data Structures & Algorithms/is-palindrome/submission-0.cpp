class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            // skip the spaces
            while (!isalnum(s[left])) {
                left++;
            }
            while (!isalnum(s[right])) {
                right--;
            }

            // second check
            if (left >= right) {
                return true;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            } 
            left++;
            right--;
        }

        return true;
    }
};
