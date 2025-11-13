#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>& numbers,int target, int depth ,int sum, int& answer)
{

    if (depth == numbers.size())
    {

        if (sum == target)
        {
            answer++;
        }
        return;
    }

    dfs(numbers, target, depth+1,sum + numbers[depth], answer);
    dfs(numbers, target, depth+1,sum - numbers[depth], answer);


    
}

int solution(vector<int> numbers, int target) 

{
    int answer = 0;

    
    

    dfs(numbers, target, 0, 0, answer);

    return answer;



}