#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool isValid(vector<int> &arr, int n, int k, int mid)
{
    int tempCount = 0;
    for (int i = 1; i < n; i++)
        tempCount += (arr[i] - arr[i - 1] - 1) / mid;

    if (tempCount > k)
        return false;

    return true;
}

int binarySearch(int start, int end, int n, int k, vector<int> &arr)
{
    while (start < end)
    {
        int mid = (start + end) / 2;

        if (isValid(arr, n, k, mid))
            end = mid;
        else
            start = mid + 1;
    }

    return start;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, cnt = 1;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);

        for (auto &x : arr)
            cin >> x;

        int res = binarySearch(1, 1e9, n, k, arr);

        cout << "Case #" << cnt << ": " << res << endl;
        cnt++;
    }

    return 0;
}

// Command Line
//     g++ Problem.cpp -o problem
//     ./problem