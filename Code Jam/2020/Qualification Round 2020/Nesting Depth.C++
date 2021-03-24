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
        string s;
        cin >> s;

        int count = 0;
        string res = "";

        for (auto x : s)
        {
            int change = x - '0' - count;

            if (change > 0)
            {
                while (change)
                {
                    res += '(';
                    count++;
                    change--;
                }

                res += x;
            }
            else
            {
                while (change)
                {
                    res += ')';
                    count--;
                    change++;
                }

                res += x;
            }
        }

        while (count > 0)
        {
            res += ')';
            count--;
        }

        cout << "Case #" << tc++ << ": " << res << endl;
    }

    return 0;
}

// Command Line
//     g++ Problem.cpp -o problem
//     ./problem