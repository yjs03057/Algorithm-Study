#include <iostream>
#include <vector>
using namespace std;

int V,E;
int visited[401][401]; //visited[i][j]: i에서 j까지 가는데 거리
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    int ans=987654321;

    //입력
    cin>>V>>E;
    //초기화
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++) visited[i][j]=987654321;
    }
    for(int i=0; i<E; i++){
        cin>>a>>b>>c;
        visited[a][b] = c;
    }

    //최소 사이클 도로 길이의 합
    for(int k=1; k<=V; k++){
        for(int i=1; i<=V; i++){
            for(int j=1; j<=V; j++){
                if(visited[i][j] > visited[i][k]+visited[k][j]){
                    visited[i][j] = visited[i][k]+visited[k][j];
                }
            }
        }
    }

    //출력
    for(int k=1; k<=V; k++){
        ans = min(ans, visited[k][k]);
    }
    if(ans>=987654321) ans = -1;
    cout<<ans;

    return 0;
}