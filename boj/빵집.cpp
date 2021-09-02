//#include <iostream>
//#include <cstring>
//using namespace std;
//int R,C, ans=0;
//char map[10001][501];
//bool visited[10001][501];
//int route[3][2] = {{-1,1},{0,1},{1,1}};
//int DFS(int i,int j){
//    int dx,dy;
//    bool flag=false;
//
//    visited[i][j] = 1; //여기서 visited 처리해주면 더 깔끔
//
//    if(j==C-1){
//        if(visited[i][j]) return 1;
//        else return 0;
//    }
//
//    for(int r=0; r<3; r++){
//        dx=i+route[r][0], dy=j+route[r][1];
//        if(dx<0||dy<0||dx>=R||dy>=C) continue;
//        if(map[dx][dy]=='.' && !visited[dx][dy]){
//            flag = DFS(dx,dy);
//            if(flag) return flag;
//        }
//        if(r==2) return 0;
//    }
//
//    return 0;
//}
//int main(){
//    cin>>R>>C;
//    for(int i=0; i<R; i++){
//        for(int j=0; j<C; j++) cin>>map[i][j];
//    }
//
//    memset(visited,false,sizeof(visited));
//    for(int i=0; i<R; i++){
//        visited[i][0]=1;
//    }
//
//    for(int i=0; i<R; i++){
//        if(map[i][0]=='.' && visited[i][0]){
//            if(DFS(i,0)) ans++;
//        }
//    }
//
//    cout<<ans;
//
//    return 0;
//}