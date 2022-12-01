#include <iostream>
#define ll long long int
#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 5;
vector <ll>v1[mx]; vector <ll>v2[mx];
ll n, m, *a, *b; 

void dfsf(ll p)
{
    //if(a[p] != 0) return;
    a[p]++;
    for (ll i = 0; i < v1[p].size(); i++)
    {
        if(a[v1[p][i]] == 0) dfsf(v1[p][i]); 
    }
}
void dfsb(ll p)
{
    //if(b[p] != 0) return;
    b[p]++;
    for (ll i = 0; i < v2[p].size(); i++)
    {
        if(b[v2[p][i]] == 0) dfsb(v2[p][i]); 
    }
}

int main() 
{    
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c; cin >> a >> b; 
        v1[a].push_back(b);
        v2[b].push_back(a);
    }
    ll A[n+1], B[n+1], chch = 1;
    for (ll i = 1; i <= n; i++) A[i] = B[i] = 0;
    a = A; b = B;
    dfsf(1);
    dfsb(1);
    for (ll i = 1; i <= n; i++)
    {
        if(A[i] == 0 || B[i] == 0)
        {
            cout << "NO" << endl;// << A[i] << B[i] << i; 
            chch = 0;
            break;
        }
    } 
    if(chch) cout << "YES" << endl; 
}