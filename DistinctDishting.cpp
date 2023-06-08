#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int main()
{
    int n,q;
    cin >> n >> q;
    int arr[n+5];
    for(int i=0; i<n; ++i)
    {
        cin >> arr[i];
        if(arr[i]%3!=0)
        {
            arr[i] = 0;
        }
    }
    int a = (sqrt(n))+1;
    int sq[a];
    for(int i=0; i<a; ++i)
    {
        sq[i] = 0;
    }
    for(int i=0; i<n; ++i)
    {
        sq[i/a] = sq[i/a]+arr[i];
    }
    while(q--)
    {
        int N,x,y;
        cin >> N >> x >> y;
        if(N==1)
        {
            int l=x-1,r=y-1;
            int ans = 0;
            for(int i=l; i<=r;)
            {
                if(i%(a)==0 && i+(a)-1<=r)
                {
                    ans += sq[i/a];
                    i += a;
                }
                else
                {
                    ans += ans,arr[i];
                    i++;
                }
            }
            cout << ans << "\n";
        }
        else
        {
            if(y%3 == 0)
            {
                x--;
                if(arr[x]==0)
                {
                    arr[x] = y;
                    sq[a/x] += y;
                }
                else
                {
                    sq[a/x]-=arr[x];
                    arr[x] = y;
                    sq[a/x] += arr[y];
                }

            }
        }
        /*   */
    }
}
