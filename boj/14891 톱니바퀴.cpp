#include <iostream>
#include <deque>
using namespace std;
deque<int> wheels[4];
int k;
void move_wheels(int num, int dir, int from){

    //dir => -1: 반시계, 1: 시계
    //idx: 2,6 확인
    int top, flag=1;

    if(num!=3 && wheels[num][2] != wheels[num+1][6]&&from!=1){

        move_wheels(num+1,-dir, -1);
    }
    if(num!=0 && wheels[num][6] != wheels[num-1][2] && from!=-1){

        move_wheels(num-1,-dir, 1);
    }

    if(dir == -1){
        top = wheels[num].front();
        wheels[num].pop_front();
        wheels[num].push_back(top);
    }
    else{
        top = wheels[num][7];
        wheels[num].pop_back();
        wheels[num].push_front(top);
    }

    return;
}
int main(){
    int tmp, num, dir, ans=0;
    for(int i=0; i<4; i++){
        cin>>tmp;
        for(int j=0; j<7; j++){
            wheels[i].push_front(tmp%10);
            tmp = tmp/10;
        }
        wheels[i].push_front(tmp);
    }

    cin>>k;
    for(int i=0; i<k; i++){
        cin>>num>>dir;
        move_wheels(num-1,dir,0);
    }

    if(wheels[0][0]) ans+=1;
    if(wheels[1][0]) ans+=2;
    if(wheels[2][0]) ans+=4;
    if(wheels[3][0]) ans+=8;

    cout<<ans;

    return 0;
}