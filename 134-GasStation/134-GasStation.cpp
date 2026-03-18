// Last updated: 3/18/2026, 2:30:08 PM
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totgas = 0;
        int totcost = 0;

        for(int val : gas){
            totgas += val;
        }

        for(int val : cost){
            totcost += val;
        }
        if(totgas < totcost){
            return -1;
        }

        int start = 0, curr = 0;

        for(int i = 0; i < gas.size(); i++){
            curr += (gas[i] - cost[i]);
            if(curr < 0){
                start = i + 1;
                curr = 0;
            }
        }
        return start;

    }
};