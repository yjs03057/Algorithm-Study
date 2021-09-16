#include <iostream>
#include <cstring>
using namespace std;

int dices[10]; // 1~5
int ans=0;
int map[33]; //다음에 갈 방향 인덱스 저장
int turn[33]; //방향 전환
int score[33]; //해당 인덱스 칸의 값 저장
int loc[4]; //말들의 위치
bool check[33]; //해당 칸에 말이 있는지 확인

void DFS(int sum, int cnt){
    int prev, now, move;

    if(cnt==10){
        ans = max(sum,ans);
        return;
    }

    for(int j=0; j<4; j++){
        //j번째 말이 움직일 경우
        //이동할 칸에 이미 말이 있으면 안 됨.

        prev = now = loc[j];
        move = dices[cnt];
        if(turn[prev]>0){
            now = turn[prev];
            move--;
        }

        while(move>0){
            now = map[now];
            move--;
        }

        // 도착지가 아니고, 말이 이미 있는 경우
        if(now!=21 && check[now]) continue;

        check[prev]=false;
        check[now]=true;
        loc[j]=now;

        DFS(sum+score[now],cnt+1);
        check[prev] = true;
        check[now] = false;
        loc[j]=prev;
    }

    return;
}

int main(){
    memset(turn, 0, sizeof(turn));
    memset(check, false, sizeof(check));
    memset(loc, 0, sizeof(loc));

    //다음에 이동할 인덱스 세팅
    for(int i=0; i<21; i++) map[i]=i+1;
    map[21]=21; //도착 지점
    map[22]=23, map[23]=24, map[24]=25, map[25]=26, map[26]=27;
    map[27]=20, map[28]=29, map[29]=30, map[30]=25;
    map[31]=32, map[32]=25;

    //turn 세팅
    turn[5]=22, turn[10]=31, turn[15]=28;

    //score 세팅
    for(int i=0; i<21; i++) score[i]=i*2;
    score[22]=13, score[23]=16, score[24]=19, score[25]=25;
    score[26]=30, score[27]=35, score[28]=28, score[29]=27;
    score[30]=26, score[31]=22, score[32]=24;

    for(int i=0; i<10; i++) cin>>dices[i];

    DFS(0,0);
    cout<<ans;

    return 0;
}