/*
ROTATE IMAGE (90° CLOCKWISE)

Think, don't memorize.

1. Track one element:
      (i,j) -> (j,n-1-i)

2. Direct movement overwrites elements.

3. Split into simpler operations.

Observation:
- Columns should become rows.
- That's exactly what transpose does.

Transpose:
      (i,j) -> (j,i)

Now only one change remains:
      (j,i) -> (j,n-1-i)

This is simply reversing every row.

Algorithm:
1. Transpose matrix.
2. Reverse every row.

Time : O(n²)
Space: O(1)
*/



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
                reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};
