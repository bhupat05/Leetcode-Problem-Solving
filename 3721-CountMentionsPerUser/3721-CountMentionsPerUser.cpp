// Last updated: 3/18/2026, 2:20:51 PM
class Solution {
public:
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        
        vector<int> mentions(numberOfUsers, 0);
        vector<int> next_online_time(numberOfUsers, 0);

        sort(events.begin(), events.end(),
             [&](const vector<string>& a, const vector<string>& b) {
                 int ta = stoi(a[1]);
                 int tb = stoi(b[1]);
                 if (ta != tb) return ta < tb;
                 if (a[0] == "OFFLINE" && b[0] == "MESSAGE") return true;
                 if (a[0] == "MESSAGE" && b[0] == "OFFLINE") return false;
                 return true;
             });

        for (auto& ev : events) {
            string type = ev[0];
            int time = stoi(ev[1]);
            string data = ev[2];

            if (type == "MESSAGE") {
                if (data == "ALL") {
                    for (int u = 0; u < numberOfUsers; u++) {
                        mentions[u]++;
                    }
                } 
                else if (data == "HERE") {
                    for (int u = 0; u < numberOfUsers; u++) {
                        if (next_online_time[u] <= time) {
                            mentions[u]++;
                        }
                    }
                } 
                else {
                    int id = 0;
                    bool building = false;

                    for (int i = 0; i < data.size(); i++) {
                        char c = data[i];

                        if (isdigit(c)) {
                            if (!building) {
                                building = true;
                                id = 0;
                            }
                            id = id * 10 + (c - '0');
                        }
                        if (building && (i + 1 == data.size() || data[i + 1] == ' ')) {
                            mentions[id]++;
                            building = false;
                        }
                    }
                }
            } 
            else {
                int user = stoi(data);
                next_online_time[user] = time + 60;
            }
        }

        return mentions;
    }
};
