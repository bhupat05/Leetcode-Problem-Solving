// Last updated: 3/18/2026, 2:26:05 PM
class Solution {
public:
    int carFleet(int d, vector<int>& pos, vector<int>& speed) {
        priority_queue<vector<double>>pq;
        for(int i = 0; i < pos.size(); i++){
            double time = (double)(d - pos[i]) / speed[i];
            pq.push({(double)pos[i], (double)speed[i], time});
        } 
        if(pq.size() == 0) return 0;

        int fleet = 0;

        while(true){
            if(pq.size() == 1){
                fleet++;
                break;
            }

            auto ahead = pq.top(); pq.pop();
            auto behind = pq.top(); pq.pop();

            if(ahead[2] >= behind[2]){
                pq.push(ahead);
            }else{
                fleet++;
                pq.push(behind);
            }


        }
        return fleet;
    }
};