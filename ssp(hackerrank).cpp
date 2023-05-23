//Bishu and his Girlfriend

#include<bits/stdc++.h>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
using namespace std;
vector<int> v[10005];
int visit[100005], dis[100005];

void dfs(int node, int d)
{
    visit[node] = 1;
    dis[node] = d;
    for(auto child:v[node]){
        if(visit[child]==0) dfs(child,d+1);
    }
}
int main()
{
    int n;
    cin>>n;
    int e = n-1;
    while(e--){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    int q;
    cin>>q;
    int mn = INT_MAX, ans = 0;
    while(q--){
        int girl;
        cin>>girl;

        if(dis[girl]<mn){
            mn = dis[girl];
            ans = girl;
        }else if(dis[girl]==mn){
            ans = min(ans,girl);
        }
    }

    cout<< ans << "\n";

    return 0;
}
