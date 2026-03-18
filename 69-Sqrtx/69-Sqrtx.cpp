// Last updated: 3/18/2026, 3:02:03 PM
class Solution {
public:
    int mySqrt(int x) {

        if(x == 1) return 1;
        if(x == 0) return 0;

        int l = 0;
        int r = x;
        int result = 0;

        while(l<=r){
            long long int mid = l+(r-l)/2;

            if(mid*mid <= x){
                result = mid;
                l = mid+1;
            }
            else{
                r = mid -1;
            }
        }
        return result;
        
    }
};