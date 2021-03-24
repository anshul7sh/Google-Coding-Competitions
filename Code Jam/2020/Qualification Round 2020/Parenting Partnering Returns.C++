#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, tc = 1;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> arr;

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;

            arr.push_back({a, b, i});
        }

        sort(arr.begin(), arr.end());

        int cEnd = 0, jEnd = 0;

        string res = "";
        for (int i = 0; i < n; i++)
            res += " ";

        bool impossible = false;

        for (auto x : arr)
        {
            if (cEnd <= x[0])
            {
                cEnd = x[1];
                res[x[2]] = 'C';
            }
            else if (jEnd <= x[0])
            {
                jEnd = x[1];
                res[x[2]] = 'J';
            }
            else
            {
                impossible = true;
                break;
            }
        }

        if (impossible)
            cout << "Case #" << tc++ << ": "
                 << "IMPOSSIBLE" << endl;
        else
            cout << "Case #" << tc++ << ": " << res << endl;
    }

    return 0;
}

// Command Line
//     g++ Problem.cpp -o problem
//     ./problem