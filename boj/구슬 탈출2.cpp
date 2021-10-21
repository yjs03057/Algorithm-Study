#include <iostream>
#include <cstring>
using namespace std;

int N,M, ans=987654321;
bool blueEnter,redEnter;
int route[4][2]={{0,1},{0,-1},{1,0},{-1,0}}; //오,왼,아,위
void right(char copy[][10]){
    for (int i = 0; i < N; i++) {
        for (int j = M-2; j >= 0; j--) {
            if (copy[i][j] == 'B' || copy[i][j] == 'R') {
                char now = copy[i][j];
                for (int k = j; k < M; k++) {
                    if (copy[i][k+1] == 'O') {
                        if (now == 'B') blueEnter = true;
                        else if (now == 'R') redEnter = true;
                        copy[i][k] = '.';
                        break;
                    }
                    else if (copy[i][k+1] == '.') {
                        swap(copy[i][k], copy[i][k+1]);
                        continue;
                    }
                    else break;
                }
            }
        }
    }
}
void left(char copy[][10]){
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (copy[i][j] == 'B' || copy[i][j] == 'R') {
                char now = copy[i][j];
                for (int k = j; k > 0; k--) {
                    if (copy[i][k-1] == '.') {
                        swap(copy[i][k], copy[i][k-1]);
                        continue;
                    }
                    else if (copy[i][k-1] == 'O') {
                        if (now == 'B') blueEnter = true;
                        else if (now == 'R') redEnter = true;
                        copy[i][k] = '.';
                        break;
                    }
                    else break;
                }
            }
        }
    }
}
void down(char copy[][10]){
    for (int j = 0; j < M; j++) {
        for (int i = N-2; i >= 0; i--) {
            if (copy[i][j] == 'B' || copy[i][j] == 'R') {
                char now = copy[i][j];
                for (int k = i; k < N; k++) {
                    if (copy[k+1][j] == 'O') {
                        if (now == 'B') blueEnter = true;
                        else if (now == 'R') redEnter = true;
                        copy[k][j] = '.';
                        break;
                    }
                    else if (copy[k+1][j] == '.') {
                        swap(copy[k][j], copy[k+1][j]);
                        continue;
                    }
                    else break;
                }
            }
        }
    }
}
void up(char copy[][10]){
    for (int j = 0; j < M; j++) {
        for (int i = 1; i < N; i++) {
            if (copy[i][j] == 'B' || copy[i][j] == 'R') {
                char now = copy[i][j];
                for (int k = i; k > 0; k--) {
                    if (copy[k-1][j] == '.') {
                        swap(copy[k][j], copy[k-1][j]);
                        continue;
                    }
                    else if (copy[k-1][j] == 'O') {
                        if (now == 'B') blueEnter = true;
                        else if (now == 'R') redEnter = true;
                        copy[k][j] = '.';
                        break;
                    }
                    else break;
                }
            }
        }
    }
}

void solve(int cnt, char map[][10], int idx){
    if(cnt>=10) return;
    char cpmap[10][10];
    memcpy(cpmap, map, sizeof(cpmap));
    redEnter = blueEnter = false;

    if(idx==0) right(cpmap);
    else if(idx==1) left(cpmap);
    else if(idx==2) down(cpmap);
    else up(cpmap);

    //공이 들어갔는지
    if (redEnter && !blueEnter) {
        ans = min(ans, cnt + 1);
        return;
    }
    else if (blueEnter) return;

    for(int i=0; i<4; i++){
        if(idx==i) continue;
        solve(cnt+1, cpmap, i);
    }

    return;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s;
    char map[10][10];

    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>s;
        for(int j=0; j<M; j++) map[i][j] = s[j];
    }

    for(int i=0; i<4; i++){
        solve(0,map,i);
    }
    if(ans!=987654321) cout<<ans;
    else cout<<-1;

    return 0;
}
