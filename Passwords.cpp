#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin >> s)
    {
        int low=0,up=0,digit=0,ans=0;
        for(int i=0; i<s.size(); ++i)
        {
            if(s[i]>='a' && s[i] <= 'z') low++;
            if(s[i]>='A' && s[i] <= 'Z') up++;
            if(s[i]>='0' && s[i] <= '9') digit++;
            if(low>=1 && up >=1 && digit>=1) low=0,up=0,digit=0,ans++;;
        }
        cout << ans << "\n";
    }
}
