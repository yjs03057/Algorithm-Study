#include <iostream>
#include <queue>
using namespace std;

int N,E;
long long visited[801];
vector<pair<long long,int>> v[801]; //<-거리, 도착지>
priority_queue<pair<long long,int>> pq;
int a,b,c,v1,v2;

long long dijkstra(int start, int end){
    for(int i=0; i<=N; i++) visited[i]=987654321; //초기화
    visited[start]=0;

    pq.push({0,start});
    while(!pq.empty()){
        a = pq.top().second;
        c = -pq.top().first;
        pq.pop();

        if(c > visited[a]) continue;

        for(int i=0; i<v[a].size(); i++){
            if(c-v[a][i].first < visited[v[a][i].second]){
                pq.push({-(c-v[a][i].first), v[a][i].second});
                visited[v[a][i].second] = c-v[a][i].first;
            }
        }
    }

    return visited[end];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long ans1[3];
    long long ans2[3];

    cin>>N>>E;
    for(int i=1; i<=E; i++){
        cin>>a>>b>>c;
        v[a].push_back({-c,b});
        v[b].push_back({-c,a});
    }
    cin>>v1>>v2;
    // ans1: 1 -> v1 -> v2 -> N
    // ans2: 1 -> v2 -> v1 -> N
    ans1[0] = dijkstra(1,v1);
    ans2[0] = visited[v2];
    ans1[1] = dijkstra(v1,v2);
    ans2[1] = dijkstra(v1,N);
    ans1[2] = dijkstra(v2,N);
    ans2[2] = dijkstra(v2,v1);

    if(ans1[0]+ans1[1]+ans1[2] < ans2[0]+ans2[1]+ans2[2]){
        if(ans1[0]==987654321 || ans1[1]==987654321 || ans1[2]==987654321){
            cout<< -1;
        }
        else{
            cout<< ans1[0]+ans1[1]+ans1[2];
        }
    } else{
        if(ans2[0]==987654321 || ans2[1]==987654321 || ans2[2]==987654321){
            cout<< -1;
        }
        else{
            cout<< ans2[0]+ans2[1]+ans2[2];
        }
    }

    return 0;
}