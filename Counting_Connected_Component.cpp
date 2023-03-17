#include<bits/stdc++.h>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
vector<int> v[10005];
int visit[100005];

void dfs(int node){
    visit[node] = 1;

    for(int i=0; i<v[node].size(); i++){
        int child = v[node][i];
        if(visit[child]==0) dfs(child);
    }
}
int main()
{
    sync;
    int n,e,x,y;
    cin>>n>>e;
    while(e--){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        cout<< i;
        for(int j=0; j<v[i].size(); j++){
            cout<< " -> "<< v[i][j];
        } cout<< endl;
    }

    int cnt = 0;

    for(int i=1; i<=n; i++){
        if(visit[i]==0){
            cnt++;
            dfs(i);
        }
    }

    cout<< cnt << "\n";


    return 0;
}
