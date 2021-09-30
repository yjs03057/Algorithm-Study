#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int R,C;
string arr[21];
bool visited[21][21]; //지나간 칸 체크
int route[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int ans=0;
map<char, bool> alphabet_visited; //지나간 알파벳 체크
void DFS(int i, int j, int cnt){
    int dx,dy;
    char cur;
    ans = max(ans, cnt);

    for(int r=0; r<4; r++){
        dx = i+route[r][0], dy = j+route[r][1];
        if(dx<0||dy<0||dx>=R||dy>=C) continue;
        cur = arr[dx][dy];
        if(!visited[dx][dy] && !alphabet_visited[cur]){
            visited[dx][dy] = 1;
            alphabet_visited[cur] = 1;
            DFS(dx,dy,cnt+1);
            visited[dx][dy] = 0;
            alphabet_visited[cur] = 0;
        }
    }

    return;
}
int main(){

    cin>>R>>C;
    for(int i=0; i<R; i++){
        cin>>arr[i];
    }
    for(int i=0; i<26; i++){
        alphabet_visited.insert({65+i,false});
    }

    //초기화
    memset(visited, false, sizeof(visited));

    //DFS
    visited[0][0]=1;
    alphabet_visited[arr[0][0]]=1;
    DFS(0,0,1);

    cout<<ans;

    return 0;
}