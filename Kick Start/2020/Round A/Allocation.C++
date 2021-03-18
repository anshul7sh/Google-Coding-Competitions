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
    int count = 1;

    while (t--)
    {
        int n, b;
        cin >> n >> b;

        vector<int> arr(n);

        for (auto &x : arr)
            cin >> x;

        sort(arr.begin(), arr.end());

        int i = 0;
        while (i < n && b >= arr[i])
        {
            b -= arr[i];
            i++;
        }

        cout << "Case #" << count << ": " << i << endl;
        count++;
    }

    return 0;
}

// Command Line
//     g++ Problem.cpp -o problem
//     ./problem