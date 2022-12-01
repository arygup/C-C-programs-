#include <iostream>
#define ll long long int
#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 5;
vector <pair<ll,ll> >v[mx];
ll n, m; 
void printgraph()
{
    for (ll i = 0; i < n; i++)
    {
        cout << i+1 << endl;
        for (ll j = 0; j < v[i+1].size(); j++)
        {
            pair<ll,ll >p = v[i+1][j];
            cout << p.first << p.second << endl;
        }
    }
}

int main() 
{    
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c; cin >> a >> b >> c; 
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    printgraph();
}