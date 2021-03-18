#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    vector<int> res;

    while (t--)
    {
        int n, k, p;
        cin >> n >> k >> p;

        vector<vector<int>> arr(n, vector<int>(k));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];

                if (j > 0)
                    arr[i][j] += arr[i][j - 1];
            }

        vector<vector<int>> dp(n + 1, vector<int>(p + 1, 0));

        for (int i = 1; i < n + 1; i++)
            for (int j = 1; j < p + 1; j++)
            {
                dp[i][j] = dp[i - 1][j];
                for (int z = 0; z < min(k, j); z++)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - z - 1] + arr[i - 1][z]);
            }

        res.push_back(dp[n][p]);
    }

    int len = res.size();

    for (int i = 0; i < len; i++)
        cout << "Case #" << i + 1 << ": " << res[i] << endl;

    return 0;
}

// Command Line
//     g++ Problem.cpp -o problem
//     ./problem