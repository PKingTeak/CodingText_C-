#include <string>
#include <vector>
#include<algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    sort(times.begin(), times.end());
    
    long long left  = 1;
    long long right  = (long long)times.back() * (long long)n; //최악을 생각해야함

    long long mid = (left + right) / 2;

    //범위 가 넓기 때문에 가운데를 기준으로 탐색을 해야함. 
    while (left < right)
    {//최악 60 
        //30 에서 탐색 무슨기준으로?
        long long member = 0;
        for (int i = 0; i < times.size();i++)
        {
            member += mid / times[i];

        }

        if (member >= n)
        {
            right = mid;
        }
        else
        {
            left = mid + 1; //어쩌피 미드보다크면 그다음 최소를 넣어야함. 
        }

        mid = (left + right) / 2;
    }
        
    return left;
       
    
}


int main()
{
    int n = 6;
    vector<int> times = { 7,10 };

    solution(n, times);
}

/*
입국심사를 기다리는 사람은 1명 이상 1,000,000,000명 이하입니다.
각 심사관이 한 명을 심사하는데 걸리는 시간은 1분 이상 1,000,000,000분 이하입니다.
심사관은 1명 이상 100,000명 이하입니다.
*/