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

        vector<vector<int>> arr(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        int row = 0, col = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> s;
            for (int j = 0; j < n; j++)
                if (s.find(arr[i][j]) == s.end())
                    s.insert(arr[i][j]);
                else
                {
                    row++;
                    break;
                }
        }

        for (int j = 0; j < n; j++)
        {
            unordered_set<int> s;
            for (int i = 0; i < n; i++)
                if (s.find(arr[i][j]) == s.end())
                    s.insert(arr[i][j]);
                else
                {
                    col++;
                    break;
                }
        }

        int trace = 0;
        for (int i = 0; i < n; i++)
            trace += arr[i][i];

        cout << "Case #" << tc++ << ": " << trace << " " << row << " " << col << endl;
    }

    return 0;
}

// Command Line
//     g++ Problem.cpp -o problem
//     ./problem