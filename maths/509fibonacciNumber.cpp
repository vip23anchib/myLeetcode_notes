class Solution {
public:
    int fib(int n) {
        vector<int> arr ;

        if (n == 0) return 0;
        if (n == 1) return 1;

        arr.push_back(0);
        arr.push_back(1);

        int element;
        for(int i=2;i<=n;i++){
            element=arr[i-1]+arr[i-2];
            arr.push_back(element);
        
        }
        
        return(arr[n]);
        
    }
};
