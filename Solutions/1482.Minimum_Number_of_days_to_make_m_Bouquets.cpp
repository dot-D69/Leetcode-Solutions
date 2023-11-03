class Solution
{
public:
    int findmax(vector<int> arr)
    {
        int maxi = INT_MIN;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }

    int findmin(vector<int> arr)
    {
        int mini = INT_MAX;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, arr[i]);
        }
        return mini;
    }

    bool ispossible(vector<int> arr, int day, int k, int m)
    {
        int cnt = 0;
        int n = arr.size();
        int Bouquet = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= day)
            {
                cnt++;
            }
            else
            {
                Bouquet += (cnt / k); // To check the no.of bouquets that can be formed (like if the cnt for blossomed flowers is 4/3 =1 so one bouque
                cnt = 0;
            }
        }
        Bouquet += (cnt / k);
        if (Bouquet >= m)
            return true;
        else
            return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        long long val = k * 1LL * m * 1LL;
        if (n < val)
            return -1; // Not possible case

        int low = findmin(bloomDay), high = findmax(bloomDay);
        int ans = INT_MAX;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (ispossible(bloomDay, mid, k, m))
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};