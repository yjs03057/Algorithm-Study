#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M,s,e,cost;
vector<pair<int,int>> buses[1001]; // <비용,목적지>
priority_queue<pair<int,int>> q; // <비용,목적지>
int price[1001]; //도착지까지의 비용

int main(){
    int cur,dest,new_cost;

    cin>>N>>M;
    //init
    for(int i=0; i<=N; i++) price[i]=987654321;
    for(int i=0; i<M; i++){
        cin>>s>>e>>cost;
        buses[s].push_back({cost,e});
    }
    cin>>s>>e;

    q.push({0,s});
    price[s]=0;
    while(!q.empty()){
        cur=q.top().second, cost=q.top().first;
        q.pop();
        if(cur==e || price[cur]<cost) continue; //price[cur]<cost 이 부분 추가로 시간초과 막음
        for(int i=0; i<buses[cur].size(); i++){
            dest=buses[cur][i].second, new_cost=buses[cur][i].first+cost;
            if(new_cost >= price[dest]) continue;
            q.push({new_cost,dest});
            price[dest] = new_cost;
        }
    }

    cout<<price[e];

    return 0;
}