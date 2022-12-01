#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<cstdlib>
#define ll long long int
using namespace std;
ll n, x, ans = 0; set <pair<ll,  ll> > st;
ll mini(ll n1, ll n2, ll n3, ll n4)
{
    ll a = n1-n3;
    ll b = n2-n4;
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    if(a > b) a = b;
    return a;
}
bool xx(pair<pair<ll, ll> , ll>a, pair<pair<ll, ll> , ll> b)
{
    return ((b.first.first > a.first.first));
}
bool yy(pair<pair<ll, ll> , ll>a, pair<pair<ll, ll> , ll> b)
{
    return ((b.first.second > a.first.second));
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n; ll A[n+1][2], B[n+1]; x = n-1; vector <pair<ll, ll> >V[n+1];
   pair<pair<ll, ll> , ll>X[n]; pair<pair<ll, ll>, ll>Y[n];
    for (ll i = 1; i <= n; i++)
    { 
        cin >> A[i][0] >> A[i][1]; 
        B[i] = 0; 
        X[i-1].first.first = A[i][0];
        Y[i-1].first.first = A[i][0];
        X[i-1].first.second = A[i][1];
        Y[i-1].first.second = A[i][1];
        X[i-1].second = i;
        Y[i-1].second = i;
    }
    sort(X, X + n, xx);
    sort(Y, Y + n, yy);
    for (ll i = 0; i < n-1; i++)
    {
        ll d = mini(X[i].first.first, X[i].first.second, X[i+1].first.first, X[i+1].first.second);
        V[X[i].second].push_back(make_pair(X[i+1].second, d));
        V[X[i+1].second].push_back(make_pair(X[i].second, d));
        //st.insert(make_pair(d , X[i].second));
        //st.insert(make_pair(d , X[i+1].second));
        d = mini(Y[i].first.first, Y[i].first.second, Y[i+1].first.first, Y[i+1].first.second);
        //st.insert(make_pair(d , Y[i].second));
        //st.insert(make_pair(d , Y[i+1].second));
        V[Y[i].second].push_back(make_pair(Y[i+1].second, d));
        V[Y[i+1].second].push_back(make_pair(Y[i].second, d));
    }

    // for (ll i = 0; i < n; i++)
    // {
    //     cout << X[i].first.first << X[i].first.second << endl;
    // }
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << Y[i].first.first << Y[i].first.second << endl;
    // }
    // for (ll i = 2; i <= n; i++)
    // {
    //     st.insert(make_pair(mini(A[1][0], A[1][1], A[i][0], A[i][1]), i));
    // }
    //B[1]++;

    st.insert(make_pair(0 , 1));     // w, indx

    while(st.size())
    {
        pair <ll,ll> pp = *st.begin(); ll nd = pp.second; ll w = pp.first; st.erase(st.begin());
        if(B[nd]) continue;
        //cout << st.begin()->first << st.begin()->second << endl;
        B[nd]++; x--; ans = ans + w; 
        for (ll i = 0; i < V[nd].size(); i++)
        {
            ll op = V[nd][i].first, we = V[nd][i].second;
            //cout << op << we << endl;
            if(B[op]) continue;
            st.insert(make_pair(we, op));
        }
    }
    cout << ans;
}