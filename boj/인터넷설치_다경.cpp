#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int N,P,K;
int ans=987654321;
int cur, to, cost, cur_remain, next_cost;
vector<pair<int,int>> map[1001];
int visited[1001];

bool dijkstra(int mid){
    queue<pair<int,int>> q;
    for(int i=1; i<=N; i++) visited[i] = -1;

    q.push({1,K});
    while(!q.empty()){
        cur = q.front().first;
        cur_remain = q.front().second;
        q.pop();
        if(cur == N) return true;

        for(int i=0; i<map[cur].size(); i++){
            to = map[cur][i].first;
            next_cost = map[cur][i].second;
            if(visited[to] >= cur_remain) continue;
            if(next_cost > mid){
                if(cur_remain==0) continue;
                visited[to] = cur_remain - 1;
                q.push({to, cur_remain-1});
            }
            else{
                visited[to] = cur_remain;
                q.push({to, cur_remain});
            }
        }
    }

    return false; //N과 연결 안 됨
}

int main(){
    //K개의 선을 제외하고 가장 큰 값 => 임계값(=원장선생님이 내야하는 돈) => 이분탐색
    //이분탐색 + 다익스트라
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int l=0,r,mid;

    memset(visited, 0, sizeof(visited));

    cin>>N>>P>>K;
    for(int i=0; i<P; i++){
        cin>>cur>>to>>cost;
        map[cur].push_back({to,cost});
        map[to].push_back({cur,cost});
        r = max(r,cost);
    }

    while(l<=r){
        mid = (l+r)/2;
        if(dijkstra(mid)){
            r = mid-1;
            ans = mid;
        }
        else{
            l = mid+1;
        }
    }

    if(ans==987654321) ans=-1;
    cout<<ans;

    return 0;
}