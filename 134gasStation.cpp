// Greedy Approach
// 1. Compute gain = gas[i] - cost[i] at each station.
// 2. Keep track of:
//    - total: total gain over the entire route.
//    - tank: current gas while travelling.
// 3. If tank becomes negative:
//    - Current start and all stations before i cannot be valid.
//    - Set start = i + 1 and reset tank = 0.
// 4. If total < 0, completing the circuit is impossible.
// 5. Otherwise, return the recorded starting index.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int total = 0;
        int tank = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); i++)
        {
            int gain = gas[i] - cost[i];

            total += gain;
            tank += gain;

            if(tank < 0)
            {
                start = i + 1;
                tank = 0;
            }
        }

        if(total < 0)
            return -1;

        return start;
    }
};
