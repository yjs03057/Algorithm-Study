#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N,M,X;
int U,V; // 학생 X의 가장 높은 등수(U), 가장 낮은 등수(V)
vector<int> better[100001];
vector<int> worse[100001];
bool visited[100001];
int worse_dfs(int cur){
    int ret=1,nxt;
    visited[cur] = 1;

    for(int i=0; i<worse[cur].size(); i++){
        nxt=worse[cur][i];
        if(visited[nxt]) continue;
        ret += worse_dfs(nxt);
    }

    return ret;
}
int better_dfs(int cur){
    int ret=1,nxt;
    visited[cur]=1;

    for(int i=0; i<better[cur].size(); i++){
        nxt=better[cur][i];
        if(visited[nxt]) continue;
        ret += better_dfs(nxt);
    }

    return ret;
}
int main(){
    int A,B;

    cin>>N>>M>>X;
    for(int i=0; i<M; i++){
        cin>>A>>B; //A가 B보다 더 잘함.
        better[B].push_back(A);
        worse[A].push_back(B);
    }

    memset(visited, false, sizeof(visited));
    U = better_dfs(X);
    memset(visited, false, sizeof(visited));
    V = N-worse_dfs(X)+1;
    cout<<U<<' '<<V;

    return 0;
}