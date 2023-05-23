#include<bits/stdc++.h>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
using namespace std;
vector<int> v[10005];
int visit[10005], dis[100005];

void ssp(int node,int d)
{
    visit[node] = 1;
    dis[node] = d;
    for(auto child:v[node]){
        if(visit[child]==0) ssp(child,d+1);
    }
}
int main()
{
    sync;
    int n;
    cin>>n;
    int e = n-1;
    while(e--){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }

    ssp(1,0);
    int q;
    cin>>q;
    int mn = INT_MAX, ans = 0;
    while(q--){
        int id;
        cin>>id;


        if(dis[id]<mn){
            mn = dis[id];
            ans = id;
        }else if(dis[id]==mn){
            ans = min(ans,id);
        }
    }

    cout<< ans << endl;

    return 0;

}
