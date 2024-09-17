class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes (n);

        for(int i=0;i<n;i++){
            string st =  timePoints[i];

            string hour = st.substr(0,2); //Hours
            string min = st.substr(3); // Minutes

            int Hour = stoi(hour);
            int Min = stoi(min);

            minutes[i] = Hour*60 +Min;
        }

        sort(minutes.begin(),minutes.end());

        int res = INT_MAX;

        for(int i=1;i<n;i++){
            res = min (res, minutes[i]-minutes[i-1]);
        }

        return min(res, (24*60 - minutes[n-1])+minutes[0]);
    }
};
