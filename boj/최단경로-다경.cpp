#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int V,E,K;
vector<pair<int,int>> roads[20001]; //roads[시작점]: <가중치, 도착점>
int ans[20001];
priority_queue<pair<int,int>> pq; // <가중치, 도착점>
int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int u,v,w,new_w;

    cin>>V>>E;
    cin>>K;
    for(int i=1; i<=V; i++) ans[i]=987654321; //초기화

    for(int i=0; i<E; i++){
        cin>>u>>v>>w;
        roads[u].push_back({w,v});
    }

    ans[K]=0; //시작점과 동일한 도착지

    pq.push({0,K}); //시작
    while(!pq.empty()){
        w = -pq.top().first;
        u = pq.top().second;
        pq.pop();

        if(ans[u]<w) continue;

        for(int j=0; j<roads[u].size(); j++){
            new_w = roads[u][j].first;
            v = roads[u][j].second;
            if(w+new_w < ans[v]){ // v지점까지 더 짧은 경로로 오지 않으면 pq에 넣을 필요 X
                ans[v] = w+new_w;
                pq.push({-ans[v], v});
            }
        }
    }

    for(int i=1; i<=V; i++){
        if(ans[i]==987654321){
            cout<<"INF"<<'\n';
            continue;
        }
        cout<<ans[i]<<'\n';
    }

    return 0;
}