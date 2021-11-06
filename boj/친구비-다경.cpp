#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M,k, paid=0;
int fee[10001];
vector<pair<int,pair<int,int>>> friends;
int parent[10001];

int find(int u){
    if(u==parent[u])
        return u;
    parent[u] = find(parent[u]);
    return parent[u];
}
void merge(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v)
        return;

    if(fee[u]<fee[v]){
        parent[v]=u;
    }
    else{
        parent[u]=v;
    }
    return;
}

int main(){
    int v,w,cost;

    cin>>N>>M>>k;
    fee[0] = 987654321,parent[0]=0;
    for(int i=1; i<N+1; i++){
        cin>>fee[i];
        parent[i]=i;
    }
    for(int i=0; i<M; i++){
        cin>>v>>w;
        friends.push_back({cost,{v,w}});
    }
    sort(friends.begin(), friends.end());

    for(int i=0; i<M; i++){
        cost=friends[i].first;
        v=friends[i].second.first, w=friends[i].second.second;
        if(find(v)==find(w)) continue;
        merge(v,w);
    }

    for(int i=1; i<N+1; i++){
        int nxt=find(i);
        if(nxt!=find(0)){
            merge(i,0);
            paid += fee[nxt];
        }
    }

    if(paid>k) cout<<"Oh no";
    else cout<<paid;

    return 0;
}