#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+10;
int n;
int arr[N];
int bit[N];
int phi[N];
void generatePhi(int x)
{
    for(int i=1; i<=x; ++i)
    {
        phi[i]=i;
    }
    for(int i=2; i<=x; ++i)
    {
        if(phi[i]==i)
        {
            for(int j=i; j<=x; j+=i)
            {
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }
}
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
    while(idx <= N)
    {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}
int32_t main()
{
    generatePhi(N);
    int q;
    cin >> n >> q;
    for(int i=1; i<=n; ++i)
    {
        cin >> arr[i];
        update(i,phi[arr[i]]);
    }
    while(q--)
    {
        int type;
        cin >> type;
        if(type==1)
        {
            int idx,val;
            cin >> idx >> val;
            //update(idx,-phi[arr[idx]]);
            arr[idx] = val;
            update(idx,phi[arr[idx]]);
        }
        else
        {
            int x,y;
            cin >> x >> y;
            cout << query(x-1)+query(y) << "\n";
        }
    }
}

