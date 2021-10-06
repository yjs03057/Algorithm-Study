#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N,R,Q;
vector<int> edge[100001];
int arr[100001];
bool visited[100001];
int DFS(int u){
    int v;
    visited[u] = 1;

    for (int i = 0; i < edge[u].size(); i++) {
        v = edge[u][i];
        if(visited[v]) continue;
        arr[u] += DFS(v);
    }

    return arr[u];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int u,v,U;

    cin>>N>>R>>Q;
    //초기화
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<=N; i++) arr[i]=1;
    for(int i=0; i<N-1; i++){
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    DFS(R); //root에서 시작

    while(Q--){
        cin>>U;
        cout<<arr[U]<<'\n';
    }

    return 0;
}