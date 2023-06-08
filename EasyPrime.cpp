#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1e6 + 10;
int arr[MAX+10];
int tree[MAX*4];
bool prime[MAX+10];

void sieve()
{
    memset(prime, true, sizeof prime);

    prime[1] = false;

    for(int i=2; i*i<=MAX; ++i)
    {
        if(prime[i])
        {
            for(int j=i*i; j<=MAX; j+=i)
            {
                prime[j] = false;
            }
        }
    }
}

void init(int node,int b, int e)
{
    if(b==e)
    {
        tree[node] = prime[arr[b]]==true;
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);

    tree[node] = tree[left]+tree[right];
}
int query(int node,int b,int e,int i,int j)
{
    if(i > e|| j < b)
    {
        return 0;
    }
    if(b >= i && e <=j)
    {
        return tree[node];
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b+e)/2;
    int leftSum = query(left,b,mid,i,j);
    int rightSum = query(right,mid+1,e,i,j);
    return leftSum+rightSum;
}
void update(int node,int b,int e,int target,int val)
{
    if(target > e || target < b)
    {
        return;
    }
    if(b==e && b==target)
    {
        tree[node] = prime[val]==true;
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b+e)/2;

    update(left,b,mid,target,val);
    update(right,mid+1,e,target,val);

    tree[node] = tree[left]+tree[right];
}
int32_t main()
{
    sieve();
    int n;
    cin >> n;
    for(int i=0; i<n; ++i)
    {
        cin >> arr[i];
    }
    init(0,0,n-1);
    int q;
    cin >> q;
    while(q--)
    {
        int x,y,a;
        cin >> a >> x >> y;
        if(a==1)
        {
            cout << query(0,0,n-1,x-1,y-1) << "\n";
        }
        else
        {
            update(0,0,n-1,x-1,y);
        }

    }
}
