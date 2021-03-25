#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int n, ans=987654321;
int s[20][20];
bool startTeam[20];
int maketeam(int idx, int cnt){
    if(cnt == n/2){
        //계산
        int sTeam=0, lTeam=0;

        for(int i=0; i<n; i++){
            if(startTeam[i]){
                for(int j=i+1; j<n; j++){
                    if(startTeam[j]){
                        sTeam += (s[i][j]+s[j][i]);
                    }
                }
            }
            else{
                for(int j=i+1; j<n; j++){
                    if(!startTeam[j]){
                        lTeam += (s[i][j]+s[j][i]);
                    }
                }
            }
        }

        ans = min(ans, abs(sTeam-lTeam));
        return 1;
    }

    for(int i=idx; i<n/2+cnt; i++){
        startTeam[i] = true;
        maketeam(i+1, cnt+1);
        startTeam[i] = false;
    }

    return 0;
}
int main(){

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>s[i][j];
        }
    }

    memset(startTeam, false, sizeof(startTeam));
    for(int i=0; i<n/2; i++){
        startTeam[i] = true;
        maketeam(i+1, 1);
        startTeam[i] = false;
    }

    cout<<ans<<endl;

    return 0;
}