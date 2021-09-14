#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> dices[10000];
int main(){
    int cur, m=0, answer=0, sum=0, bottom, top, next_b, next_t;
    int opposite[6] = {5,3,4,1,2,0};
    // A B C D E F
    // F D E B C A

    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<6; j++){
            cin>>cur;
            dices[i].push_back(cur);
        }
    }

    for(int j=0; j<6; j++){
        // A B C D E F 차례로
        bottom=dices[0][j];
        top=dices[0][opposite[j]];
        sum=0, m=0;

        for(int k=0; k<6; k++){
            if(dices[0][k]==bottom || dices[0][k]==top) continue;
            m=max(m,dices[0][k]);
        }
        sum+=m;

        for(int i=1; i<N; i++){
            m=0;
            for(int k=0; k<6; k++){
                if(dices[i][k]==top){
                    next_b=k;
                    next_t=opposite[k];
                    break;
                }
            }
            for(int k=0; k<6; k++){
                if(k==next_t || k==next_b) continue;
                m = max(m, dices[i][k]);
            }
            //bottom = dices[i][next_b];
            top = dices[i][next_t];
            sum += m;
        }
        answer = max(answer, sum);
    }

    cout<<answer;

    return 0;
}