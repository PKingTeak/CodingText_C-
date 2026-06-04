#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

// 해시맵으로 풀어보기
string solution(vector<string> participant, vector<string> completion) 
{
    
    unordered_map<string, int> maps;
    
    for (string s : completion)
    {
        maps[s] += 1;
    }


    for (auto key : participant)
    {
        maps[key] -= 1;
    }

    for (auto key : maps)
    {
        if (key.second < 0)
        {
            return key.first;
        }
    }
}