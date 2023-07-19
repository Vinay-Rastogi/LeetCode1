class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end());

        int prev = 0;
        int ans = 0;

        for (int curr = 1; curr < intervals.size(); curr++)
        {

            if (intervals[curr][0] < intervals[prev][1])
            {
                ans++;

                if (intervals[curr][1] <= intervals[prev][1])
                    prev = curr;
            }

            else
                prev = curr;
        }

        return ans;
    }
};