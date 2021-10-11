#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N,S,D;
vector<int> edges[100001];
int visited[100001]; //D보다 크면 꼭 방문해야 함
bool vst[100001];
int DFS(int cur){
    int nxt;
    int ret,depth=0;
    visited[cur]=1;

    for(int i=0; i<edges[cur].size(); i++){
        nxt = edges[cur][i];
        if(visited[nxt]) continue;
        ret = DFS(nxt);
        depth = max(depth,ret);
    }
    visited[cur] += depth;

    return visited[cur];
}
int Route(int cur){
    int nxt,ret=1;
    vst[cur]=1;
    for(int i=0; i<edges[cur].size(); i++){
        nxt = edges[cur][i];
        if(!vst[nxt] && visited[nxt]>D){
            ret += Route(nxt);
        }
    }
    return ret;
}
int main(){
    int u,v;

    cin>>N>>S>>D;
    memset(visited, 0, sizeof(visited));
    memset(vst, false, sizeof(vst));
    for(int i=1; i<N; i++){
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    //거리 D 이하는 그 곳에 가지 않고도 전단지를 돌릴 수 있음
    DFS(S);
    //거리재기
    cout<<(Route(S)-1)*2; // 시작점 빼주기

    return 0;
}