class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # anagram (string) contains the exact same chars
        # group all anagram

        # Solution:
        #   init hashmap
        #   'key' to find anagram group
        #   'key' write a function to hash given string

        def hash_anagram(s) -> str:
            # count fre of char
            # encode them as a string, return

            fres = [0] * 26
            for c in s:
                fres[ord(c) - ord('a')] += 1
            
            res = ''
            for f in fres:
                res += str(f) + ','
            return res
        
        map_anagram = defaultdict(list)
        for s in strs:
            encode = hash_anagram(s)
            print(encode)
            map_anagram[encode].append(s)
        
        res = []
        for key, value in map_anagram.items():
            res.append(value)

        return res