#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int T,n,m,t;
int s,g,h;
int a,b,d;
int x;
set<int> goals;
int visited[2001];
priority_queue<pair<int,int>> pq; //<-거리,목적지>
int cur,cost,n_cur,n_cost;
int main(){

    cin>>T;
    while(T>0){

        cin>>n>>m>>t; //교차로, 도로, 목적지 후보 개수
        cin>>s>>g>>h; //g-h 지나감

        //초기화
        vector<pair<int,int>> roads[2001]; //<거리,목적지>
        goals.clear();
        for(int i=0; i<=n; i++) visited[i] = 2000000000;

        //도로
        for(int i=0; i<m; i++){
            cin>>a>>b>>d;
            //g-h 도로만 2*d-1 => 가중치 홀수
            if((a==g&&b==h)||(a==h&&b==g)){
                roads[a].push_back({2*d-1,b});
                roads[b].push_back({2*d-1,a});
                continue;
            }
            //그 외 => 가중치 짝수
            roads[a].push_back({d*2,b});
            roads[b].push_back({d*2,a});
        }
        //목적지 후보
        for(int i=0; i<t; i++){
            cin>>x;
            goals.insert(x);
        }

        //시작점(s)에서 각 목적지 후보로 가는 최단경로 구하기
        pq.push({0,s});
        visited[s]=0;
        while(!pq.empty()){
            cur = pq.top().second, cost = -pq.top().first;
            pq.pop();

            if(cost>visited[cur]) continue;

            for(int i=0; i<roads[cur].size(); i++){
                n_cost=roads[cur][i].first;
                n_cur=roads[cur][i].second;

                if(visited[n_cur] > cost+n_cost){ //최단거리 갱신
                    visited[n_cur] = cost+n_cost;
                    pq.push({-(cost+n_cost),n_cur});
                }
            }
        }

        //최단경로에 g-h 포함되어야 ans에 추가
        for(auto gg: goals){
            //홀수면 g-h지난 것
            if(visited[gg]%2!=0) cout<<gg<<' ';
        }

        T--;
    }

    return 0;
}