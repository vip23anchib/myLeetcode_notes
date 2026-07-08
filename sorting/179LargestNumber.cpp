/*
---------------------- 179. Largest Number ----------------------

INTUITION:
Brute force (trying all permutations) is impossible.

Think:
Can I decide the order of ONLY TWO numbers?

For two numbers a and b:
Possible arrangements:
1. ab
2. ba

Whichever forms the larger number should come first.

Example:
3,30

330 > 303
=> 3 should come before 30.

TRICK:
Instead of comparing values,
compare concatenated strings.

Rule:
a comes before b if

(a + b) > (b + a)

Once we know how to order ANY two elements,
use SORT with a custom comparator.

ALGORITHM:
1. Convert every integer to string.
2. Sort using comparator:
      return (a+b) > (b+a);
3. Concatenate all strings.
4. Edge Case:
   If first character is '0',
   return "0" instead of "0000".

PATTERN TO REMEMBER:
Whenever the question asks for the "best arrangement/order"
and you can determine which of TWO elements should come first,
think:
        ---> Custom Comparator + Sorting

TIME  : O(n log n)
SPACE : O(n)
*/

class Solution {
public:

    static bool cmp(string a, string b){
                if (a+b>b+a){
                    return true;
                }
                else {
                    return false;
                }
            }
        

    string largestNumber(vector<int>& nums) {
        int n=nums.size();

        vector<string> str;
        for (int i = 0; i < nums.size(); i++) {
            str.push_back(to_string(nums[i])); 
        }
        
        int index=0;
        
        
        sort(str.begin(),str.end(),cmp);
        if (str[0] == "0") {
            return "0";
        }
        string sum;
        for(int i=0;i<n;i++){
            sum+=str[i];
        }
        
    return sum;
        
    }
};
