#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
int N,M;
long double ans=0.0;
int parent[1001];
vector<pair<int,int>> location; //좌표 <x,y>
vector<pair<long double,pair<int,int>>> edges; //<거리, <x,y>>
int find(int u){
    if(u==parent[u]) return u;

    return find(parent[u]);
}
void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u==v) return;
    parent[v] = u;
}

void make_edge(int u, int v){
    long double dist;
    dist = sqrt(pow(location[u].first - location[v].first,2)
                + pow(location[u].second - location[v].second,2));
    edges.push_back({dist,{u,v}});
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y;
    long double dist;

    cin>>N>>M;

    location.push_back({-1,-1}); //tmp
    for(int i=0; i<N; i++){ //좌표
        cin>>x>>y;
        location.push_back({x,y});
    }
    //가능한 모든 간선 만들기
    for(int i=1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            make_edge(i,j);
        }
    }
    //이미 연결된 통로
    for(int i=0; i<M; i++){
        //location의 idx
        cin>>x>>y;
        edges.push_back({0,{x,y}}); //이미 주어진 간선이므로 가중치 0
    }

    //MST
    sort(edges.begin(), edges.end());
    //초기화
    for(int i=0; i<=N; i++) parent[i]=i;
    for(int i=0; i<edges.size(); i++){
        dist=edges[i].first;
        x=edges[i].second.first, y=edges[i].second.second;
        if(find(x)==find(y)) continue;
        merge(x,y);
        ans += dist;
    }

    cout<<fixed;
    cout.precision(2);
    cout<<ans;

    return 0;
}