// Last updated: 3/18/2026, 2:27:41 PM
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {

                int totalOn = __builtin_popcount(hour) + __builtin_popcount(minute);

                if (totalOn == turnedOn) {

                    string time = to_string(hour) + ":";

                    if (minute < 10)
                        time += "0"; 

                    time += to_string(minute);

                    result.push_back(time);
                }
            }
        }

        return result;
    }
};
