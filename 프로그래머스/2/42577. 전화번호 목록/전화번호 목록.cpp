#include <string>
#include <vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

bool solution(vector<string> phone_book) 
{
    bool answer = true;
  
    unordered_set<string> S;
    for(int i = 0 ;i < phone_book.size();i++)
    {
        S.insert(phone_book[i]);//값 넣기
    }
    
    for(int i =0;i<phone_book.size();i++)
    {
        string& num = phone_book[i];
        string first;
        for(int j = 0; j<num.size()-1;j++)
        {
         first.push_back(num[j]);
            
        if(S.find(first) != S.end())
        {
            return false;
        }
            
        }
       
        
        
    }
  
    
    
    return answer;
}