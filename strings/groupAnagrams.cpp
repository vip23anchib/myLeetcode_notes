// NeetCode:
// Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.
// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

// Example 1:
// Input: strs = ["act","pots","tops","cat","stop","hat"]
// Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]



//Approach 1:
// Approach:
// 1. Every anagram has the same sorted form.
//    Example: "eat", "tea", "ate" -> "aet"
// 2. Use the sorted string as the key in an unordered_map.
// 3. Store the original string in the vector corresponding to that key.
// 4. Finally, collect all the vectors from the map and return them.
//
// Time: O(n * k log k)
//       n = number of strings
//       k = average length of each string (sorting each string)
// Space: O(n * k)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        
        unordered_map <string , vector<string>> grp_anagram;
        for(int i=0;i<strs.size();i++){
            string key=strs[i];
            sort(key.begin(),key.end());
            
            grp_anagram[key].push_back(strs[i]);
        }
        vector<vector< string>> answer;
        for( auto &it : grp_anagram){
            answer.push_back(it.second);
        }
        return answer;
    }
};



// APPROACH 2:
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Count character frequencies to create a unique key for each anagram group.
        // Convert the frequency array into a string because unordered_map
        // cannot directly use vector<int> as a key.
        //
        // Time: O(n * k)
        // Space: O(n * k)

        unordered_map<string, vector<string>> mp;

        for (string word : strs) {

            // Frequency array for 26 lowercase letters
            vector<int> freq(26, 0);

            for (char ch : word) {
                freq[ch - 'a']++;
            }

            // Convert frequency array to a unique string key
            string key = "";

            for (int count : freq) {
                key += to_string(count);
                key += '#';      // Separator to avoid ambiguity
            }

            mp[key].push_back(word);
        }

        vector<vector<string>> ans;

        for (auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};



// | Approach        | Key Used                                 | Time               |
// | --------------- | ---------------------------------------- | ------------------ |
// | Sorting         | Sorted string (`"aet"`)                  | **O(n × k log k)** |
// | Frequency Count | Character frequency string (`"1#0#..."`) | **O(n × k)**       |

