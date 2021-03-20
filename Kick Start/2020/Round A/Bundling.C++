#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef struct data
{
    data *child[26];
    int count = 0;
} trie;

trie *root;
int ans = 0, n, k;

void insert(string &s)
{
    trie *curr = root;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (!curr->child[s[i] - 'A'])
            curr->child[s[i] - 'A'] = new trie();

        curr = curr->child[s[i] - 'A'];
    }

    curr->count++;
}

void dfs(trie *curr, int lvl)
{
    for (int i = 0; i < 26; i++)
        if (curr->child[i])
        {
            dfs(curr->child[i], lvl + 1);
            curr->count += curr->child[i]->count;
        }

    while (curr->count >= k)
    {
        curr->count -= k;
        ans += lvl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, tc = 1;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        root = new trie();
        ans = 0;

        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            insert(s);
        }

        dfs(root, 0);
        cout << "Case #" << tc++ << ": " << ans << endl;
    }

    return 0;
}

// Command Line
//     g++ Problem.cpp -o problem
//     ./problem