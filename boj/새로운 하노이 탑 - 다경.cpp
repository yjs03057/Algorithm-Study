#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

vector<string> towers;
vector<string> goal;
set<vector<string>> status_set;
map<vector<string>,int> move_cnt;

int play(vector<string> start, vector<string> end){
    queue<vector<string>> q;
    q.push(start);
    while(!q.empty()){
        vector<string> cur=q.front();
        q.pop();

        //성공
        if(cur==end) return move_cnt[cur];

        //원판 옮기기
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i==j) continue;

                //빈 막대일 때
                if(cur[i].empty()) continue;
                vector<string> temp = cur;
                string from=temp[i];
                string to=temp[j];

                //from의 맨 위 원판을 to의 맨 위로 옮기기
                char top=from.back();
                from.pop_back();
                to += top;
                temp[i] = from;
                temp[j] = to;

                //방금 만든 상태가 지금까지 한 번도 안 나온 경우
                if(status_set.count(temp)==0){
                    status_set.insert(temp);
                    move_cnt.insert({temp,move_cnt[cur]+1});
                    q.push(temp);
                }
            }
        }
    }

    return -1;
}

int main(){
    int cnt,A_cnt=0,B_cnt=0,C_cnt=0;
    string plate;
    for(int i=0; i<3; i++){
        cin>>cnt;
        if(cnt!=0) cin>>plate;
        for(int j=0; j<cnt; j++){
            switch (plate[j]) {
                case 'A':
                    A_cnt++;
                    break;
                case 'B':
                    B_cnt++;
                    break;
                case 'C':
                    C_cnt++;
                    break;
            }
        }
        towers.push_back(plate);
        plate="";
    }
    string A(A_cnt,'A');
    string B(B_cnt, 'B');
    string C(C_cnt, 'C');
    goal.push_back(A);
    goal.push_back(B);
    goal.push_back(C);

    cout<<play(towers,goal);

    return 0;
}