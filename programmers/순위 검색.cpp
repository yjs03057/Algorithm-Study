#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string, vector<int>> info_score;

    string s;
    int score;

    //info 파싱
    for(int i=0; i<info.size(); i++){
        vector<string> v(4);
        stringstream ss;
        ss.str(info[i]);
        for(int idx=0; idx<4; idx++){
            ss >> v[idx];
        }
        ss >> score;

        // '-' 조합 ('-'로 인한 모든 경우의 수 생성)
        for(int j=0; j<=4; j++){
            string s1(j,'0');
            string s2(4-j,'1');
            string condi = s1+s2;
            do{
                string s3="";
                for(int k=0; k<4; k++){
                    if(condi[k]=='0') s3+=v[k];
                    else s3+='-';
                }
                info_score[s3].push_back(score);
            }while(next_permutation(condi.begin(), condi.end()));
        }
    }

    //정렬
    for(auto& i: info_score){
        stable_sort(i.second.begin(), i.second.end());
    }

    //query 파싱
    for(int i=0; i<query.size(); i++){
        stringstream ss;
        string key="";
        ss.str(query[i]);
        for(int idx=0; idx<7; idx++){
            ss >> s;
            if(s=="and") continue;
            key += s;
        }
        ss >> score;
        cout<<key<<endl;

        vector<int> v = info_score[key];
        int ans = lower_bound(v.begin(), v.end(), score) - v.begin();
        answer.push_back(v.size()-ans);
    }

    return answer;
}

int main(){

    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};

    vector<int> ans = solution(info,query);
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<' ';


    return 0;
}
