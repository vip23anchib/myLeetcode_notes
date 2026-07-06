/*
Problem: Can Place Flowers
Goal:
- Check if we can plant 'n' flowers.
- No two adjacent flowers can exist.
------------------------------------------------
Logic:
1. Traverse every position.
2. Plant only if:
   - Current spot is empty (0)
   - Left is empty (or doesn't exist)
   - Right is empty (or doesn't exist)
3. After planting:
   - Mark current position as 1
   - Decrement n
4. If n <= 0, return true immediately.
------------------------------------------------
Edge Cases:
- i == 0       -> No left neighbour (treat as empty)
- i == size-1  -> No right neighbour (treat as empty)
- n == 0       -> Already satisfied
------------------------------------------------
Trick:
- Update flowerbed[i] = 1 after planting.
  Otherwise future positions may incorrectly think
  this spot is still empty.

- Use OR (||) for boundaries:
  leftEmpty  = (i==0 || flowerbed[i-1]==0)
  rightEmpty = (i==size-1 || flowerbed[i+1]==0)
-----------------------------------------------

Complexity:
Time  : O(n)
Space : O(1)
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size=flowerbed.size();
        
        for (int i=0;i<size;i++){
            bool leftEmpty= (i==0 || flowerbed[i-1]==0);
            bool rightEmpty= (i==size-1 || flowerbed[i+1]==0);

            if(flowerbed[i]==0 && leftEmpty && rightEmpty){
                flowerbed[i]=1;
                n--;

                if(n<=0){
                    return true;
                }
            }
        }
        return false;
    }        
    
};
