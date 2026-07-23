#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(int n, vector<vector<int>> results) 
{
    int answer = 0;
    
    vector<vector<bool>> Checker(n + 1, vector<bool>(n+1 , false));

    for (int i = 0; i < results.size();i++)
    {
        int winner = results[i][0];
        int loser = results[i][1];
        Checker[winner][loser] = true;
        

    }

    //이행적 함수 전이 상태를 활용한다.
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for(int j =1 ; j<= n; j++)
            {
                if (Checker[i][k] && Checker[k][j])
                {
                    Checker[i][j] = true;
                }
            }
        }
    }
    
    for (int i = 1; i <= n;i++)
    {
        int know = 0;

        for (int j = 1; j <= n;j++)
        {
            if (i == j)
            {
                continue;
            }

            if (Checker[i][j] || Checker[j][i])
            {
                know++;
            }
        }


        if (know == n - 1)
        {
            answer++;
        }

    }
    return answer;
}

int main()
{
    int n = 5;
    vector<vector<int>> arr = { {4,3},{4,2},{3,2},{1,2},{2,5} };
    solution(n, arr);


    return 0;
}

/*
* 0 1 2 3 4 5
* f f t f f f
* f t f t t t
* f f f f t f
* f f f f f f
* f f t f f f
*/
