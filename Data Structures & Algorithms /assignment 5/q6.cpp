#include <iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;   //ioi2014Fsol6
#define ll long long int
ll mx(ll a, ll b, ll c)
{
    if(b>a) a = b;
    if(c>a) a = c;
    return a;
}
int main()
{
    ll n; cin >> n; 
    ll A[n], V[n - 1][2], P[n], el = n - 1;
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
        P[i] = 0;
    } 
    for(int i = 0; i < n - 1; i++)
    {
        cin >> V[i][0];  
        cin >> V[i][1];
    } 
    for (ll i = n-2; i >= 0; i--)
    {
        ll c = V[i][1], p = V[i][0];
        if(c == 0)
        {
            A[p] = A[p] + P[el];
            P[p] = mx(A[el] + P[p], P[p] + P[el], -__LONG_LONG_MAX__);
            el--;
            continue;
        }
        if(c == 1)
        {
            A[p] = mx(A[p] + A[el], A[p] + P[el], A[el] + P[p]);
            P[p] = P[p] + P[el];
            el--;
            continue;
        }
        A[p] = mx(A[p] + P[el], A[el] + P[p], -__LONG_LONG_MAX__);
        P[p] = P[p] + P[el];
        el--;
    }
    cout << mx(P[0], A[0], -__LONG_LONG_MAX__) << endl;
    return 0;
    
}  // el = eliminated p = person   A px  P qx