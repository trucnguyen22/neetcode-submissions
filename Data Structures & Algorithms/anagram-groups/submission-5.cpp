class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) { 
        // data structure: hashmap
        // idea: using tag to check anagram, value is a vector
        unordered_map<string, vector<string>> group_anagrams;

        for (int i = 0; i < strs.size(); i++) {
            string new_anagram = create_anagram(strs[i]);
            group_anagrams[new_anagram].push_back(strs[i]);
        }

        vector<vector<string>> groups;
        for (const auto& pair : group_anagrams) {
            groups.push_back(pair.second);
        }

        return groups;
    }

    string create_anagram(string s) {
        vector<int> anagram(26, 0);
        string hash_anagram = "";
        for (char c : s) {
            anagram[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            hash_anagram += "," + to_string(anagram[i]);
        }
        return hash_anagram;
    }

    bool checking_anagram(unordered_map<unordered_map<char, int>, vector<string>>& group_anagrams, string s) {
        
    }
};
