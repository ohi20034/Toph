#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int n;
int arr[N];
int bit[N];

int query(int idx)
{
    int ans = 0;
    while(idx)
    {
        ans += bit[idx];
        idx -= (idx & -idx);
    }
    return ans;
}
void update(int idx,int val)
{
    //while(idx <= n)
    {
        //cout << idx <<" ";
        bit[idx] = val;
        //idx += (idx & -idx);
    }
}
int main()
{
    cin >> n;
    //update(9,1);
    //for(int i=1; i<=n; ++i)
    // {
    //  cout << bit[i] <<" ";
    //}
    for(int i=1; i<=n; ++i)
    {
        cin >> arr[i];
        update(i,1);
    }
    int ans = 0;
    for(int i=1; i<=n; ++i)
    {
        int MaxSum = query(n);
        int isum = query(i);
        ans+=MaxSum-iSum;
    }
    cout << ans << "\n";
    // cout << query(4) << endl;
}
