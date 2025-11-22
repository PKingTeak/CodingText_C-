#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
#include <unordered_set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer (n,1);

    unordered_set<string> beforeWord;

    char c;
    for (int i = 0; i < words.size()-1;i++)
    {
        c = words[i].back();
        beforeWord.insert(words[i]);
        answer[(i % n)]++;
        if (words[i+1].front() != c)
        {
            //잘못말했을 경우 
			return { (i +1)%n+1 ,answer[(i+1) % n]};
        }
        if(beforeWord.find(words[i+1]) !=beforeWord.end())
        {
			return { (i+1)%n+1,answer[(i+1) % n]};
            //return 지금 번호
        }
        

    }


    //탈락자를 return 해라

    return { 0,0 };
}

int main()
{
    int N = 3;
    vector<string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };

    solution(N, words);

}