// NEETCODE:
// Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.
// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()){
            return false;
        }
        
        vector<int> check(26,0);

        for (int i=0;i<s.length();i++){
            check[s[i]-'a']++;
            check[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if (check[i]!=0){
                return false;
            }
        }
        return true;
    }
};
