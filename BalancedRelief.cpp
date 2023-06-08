#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bug(x) cout << #x << "  " << x << '\n';
template <class T>
void _print(vector<T> v1)
{
    cout << "vector = ";
    for (T i : v1)
    {
        cout << i << "   ";
    }
    cout << "\n";
}
const int MOD = 1e9 + 7;
const int MAX = 1e6;
int ar[(int)1e6 + 5], br[(int)1e6 + 5];
int binarySearch(int l, int r, int val, int m, int ar[], int br[]) // m = size of br array
{
    int lowest = -1, highest = -1;
    int left = 0;
    int right = m - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (br[mid] + val >= l)
        {
            lowest = mid;
            right = mid - 1;
        }
        else if (br[mid] + val < l)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    left = 0;
    right = m - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (br[mid] + val <= r)
        {
            highest = mid;
            left = mid + 1;
        }
        else if (br[mid] + val > r)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (highest == -1 || lowest == -1)
    {
        return 0;
    }
    return highest - lowest + 1;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    int ar[n + 5], br[m + 5];
    for (int i = 0; i < n; ++i)
    {
        cin >> ar[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> br[i];
    }
    sort(ar, ar + n);
    sort(br, br + m);
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += binarySearch(l, r, ar[i], m, ar, br);
    }
    cout << ans << '\n';
}
