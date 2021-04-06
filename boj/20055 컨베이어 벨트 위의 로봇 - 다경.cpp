#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
int n, k, ans=0, cnt;
deque<int> belt; //내구도
deque<int> robots; //robots 위치 저장
deque<int> robots_to_delete;
bool if_robot[100]; //로봇이 있는지 없는지
int main(){
    int tmp, loc, move_flag=0;
    cin>>n>>k;
    for(int i=0; i<2*n; i++){
        cin>>tmp;
        belt.push_back(tmp);
    }

    //로봇의 위치는 0 ~ n-1

    memset(if_robot, false, sizeof(if_robot));
    while(cnt<k){

        // 1.벨트 한 칸 회전
        tmp = belt[belt.size()-1];
        for(int i=belt.size()-1; i>0; i--){
            belt[i] = belt[i-1];
        }
        belt[0] = tmp;
        // 로봇 위치도 바뀌어야 함
        for(int i=0; i<robots.size(); i++){
            if_robot[robots[i]] = 0;
            robots[i] = robots[i]+1; //벨트 한 칸 증가에 따라 로봇 위치도 한 칸 증가
            if_robot[robots[i]] = 1;

            if(robots[i] == n-1){
                //내려갈 위치
                if_robot[n-1] = 0;

                //robots[i] 삭제할 예정
                robots[i] = -1;
            }
        }


        // 2.가장 먼저 벨트에 올라간 로봇부터 한 칸 이동
        // 이동 칸 범위: 1~n-1 -> n-1에 가자마자 내려가기
        int size = robots.size(); //중간에 pop해주기 때문에, 사이즈 고정 필요
        for(int i=0; i<size; i++){
            loc = robots.front(); //i번째 로봇 위치 들어있음
            robots.pop_front();
            move_flag=0;

            if(loc == -1) continue;

            if(belt[loc+1]>0 && !if_robot[loc+1]) {
                move_flag=1;
                if_robot[loc] = 0;
                belt[loc + 1]--;

                if(loc+1!=n-1){
                    //내려가는 위치가 아닐 경우
                    robots.push_back(loc+1);
                    if_robot[loc+1] = 1;
                }
            }
            if(move_flag==0) robots.push_back(loc); //얘 이동 못 했음

            //0일 경우
            if(move_flag && belt[loc+1]==0) cnt++;
        }

        // 3.올라가는 위치에 로봇이 없다면 하나 올린다.
        if(belt[0]>0 && !if_robot[0]){
            //로봇이 올라감
            belt[0]--;
            robots.push_back(0);
            if_robot[0] = 1;
            if(belt[0]==0) cnt++;
        }

        ans++;
    }

    cout<<ans<<endl;

    return 0;
}