#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100000+10;

int n;
int arr[N];
int bit[26][N];

int query(int idx, int x)
{
    int ans = 0;
    while (idx)
    {
        ans += bit[x][idx];
        idx -= (idx & -idx);
    }
    return ans;
}
void update(int idx, int val, int x)
{
    while (idx < N)
    {
        bit[x][idx] += val;
        idx += (idx & -idx);
    }
}
int32_t main()
{
    int q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i)
    {
        int x = s[i] - 'a';
        update(i + 1, 1, x);
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int idx;
            char ch;
            cin >> idx >> ch;
            int x = s[idx - 1] - 'a';
            update(idx, -1, x);
            update(idx, 1, ch - 'a');
            s[idx - 1] = ch;
        }
        else
        {
            int x, y;
            char ch;
            cin >> x >> y >> ch;
            int X = ch - 'a';
            cout << query(y, X) - query(x - 1, X) << "\n";
        }
    }
}
