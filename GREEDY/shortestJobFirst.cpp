class Solution {
public:
    long long solve(vector<int>& bt) {

        int n = bt.size();

        sort(bt.begin(), bt.end());

        long long waitingTime = 0;
        long long totalWaitingTime = 0;

        for(int i = 0; i < n; i++) {

            totalWaitingTime += waitingTime;

            waitingTime += bt[i];
        }

        return totalWaitingTime / n;
    }
};
