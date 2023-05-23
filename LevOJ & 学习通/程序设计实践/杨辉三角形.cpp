#include<iostream>
using namespace std;
 
typedef long long ll;
 
ll n;
 
ll C(ll q,ll x)   
{
    ll ans=1;
    for(int i=1,j=q-x+1;i<=x;i++,j++) 
    {
        ans=ans*j/i;
        if(ans>n) return ans;
    }
    return ans;
}
 
ll check(ll x)           //¶þ·Ö
{
    ll l=2*x,r=n,q;
    while(l<=r)
    {
        ll mid=l+(r-l)/2; 
        q=C(mid,x);
        if(q>n) r=mid-1;
        else if(q<n) l=mid+1;
        else 
        {
            cout<<(1+mid)*mid/2+x+1<<endl;
            return 1;
        }
    }
    return 0;
}
 
int main()
{
    while (scanf("%lld", &n) != EOF)
    {
        for(int i=14;~i;i--) if(check(i)) break;
    }

    return 0;
}