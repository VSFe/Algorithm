#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(vector<vector<string>> relation) {
    int size = relation[0].size();
    vector<int> sol;
    
    for(int i = 1; i <= size; i++) {
        vector<int> is_include;
        for(int j = size - i; j > 0; j--) is_include.push_back(0);
        for(int j = 0; j < i; j++) is_include.push_back(1);
        
        int firstValue = 0;
        bool firstOk = true;
        for(int j = 0; j < is_include.size(); j++) 
            if(is_include[j])
                firstValue += pow(2, j);

        for(int num: sol) {
            if((num & firstValue) == num) {
                firstOk = false;
                break;
            }
        }
        
        if(firstOk) {
            set<string> s;
            for(int j = 0; j < relation.size(); j++) {
                string tmp = "";
                for(int k = 0; k < size; k++) {
                    if(is_include[k]) tmp += relation[j][k];
                }
                s.insert(tmp);
            }
            
            if(s.size() == relation.size()) {
                sol.push_back(firstValue);
            }
        }
        
        while(next_permutation(is_include.begin(), is_include.end())) {
            bool isOk = true;
            int idxValue = 0;

            for(int j = 0; j < is_include.size(); j++) 
                if(is_include[j])
                    idxValue += pow(2, j);

            for(int num: sol) {
                if((num & idxValue) == num) {
                    isOk = false;
                    break;
                }
            }

            if(!isOk) continue;
            
            set<string> s;
            for(int j = 0; j < relation.size(); j++) {
                string tmp = "";
                for(int k = 0; k < size; k++) {
                    if(is_include[k]) tmp += relation[j][k];
                }
                s.insert(tmp);
            }
            
            if(s.size() == relation.size()) {
                sol.push_back(idxValue);
            }
        }
    }
    return sol.size();
}

// Driver
int main() {
    int N, M; cin >> N >> M;
    vector<vector<string>> vec(N, vector<string>(M));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> vec[i][j];
    
    cout << solution(vec);
}