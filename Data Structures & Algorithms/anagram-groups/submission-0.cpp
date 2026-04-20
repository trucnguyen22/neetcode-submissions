class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // time exceed < O(10^6)
        // bruteforce O(n^2)
        // step 1: initialize memory
        //
        // step 2: make example
        // ["act", "pots", "tops"]
        // [], act -> [[act]]
        // [act], pots -> [[act], [pots]]
        // [act, pots], tops -> [[act], [pots, tops]]
        //
        // step 3: make a group

        map<map<char, int>, vector<string>> myMap;
        // <<character, frequency>, []>

        for (int i = 0; i < strs.size(); i++) {
            string curr_str = strs[i];
            map<char, int> hashValue = hashValueResult(curr_str);
            myMap[hashValue].push_back(curr_str);
        }

        vector<vector<string>> ans;
        for (const auto& pair : myMap) {
            ans.push_back(pair.second);
        }

        return ans;
    }

    map<char, int> hashValueResult(string anagram) {
        map<char, int> hashValue;
        for (int i = 0; i < anagram.length(); i++) {
            hashValue[anagram[i]]++;
        }
        return hashValue;
    }
};
