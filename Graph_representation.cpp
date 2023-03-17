#include<bits/stdc++.h>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
using namespace std;
vector<int> v[100000];

int main()
{
    sync;

    int node,edge;
    cin>>node>>edge;
    int x,y;

    while(edge--){
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }

    for(int i=1; i<=node; i++){
        cout<< i;
        for(int j=0; j<v[i].size(); j++){
            cout<< "-> " << v[i][j];
        }
        cout<< "\n";
    }

    return 0;
}
