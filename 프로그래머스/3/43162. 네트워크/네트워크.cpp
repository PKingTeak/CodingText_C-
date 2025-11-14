#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


int solution(int n, vector<vector<int>> computers)
{

	int answer = 0;

	vector<bool> Visited(n, false);

	queue<int> Q;



	for (int i = 0; i < n;i++)
	{
		if (!Visited[i])
		{
			Q.push(i);
			answer++;
			Visited[i] = true;
			while (!Q.empty())
			{
				int num = Q.front();
				Q.pop();

				for (int j = 0; j < computers[num].size(); j++)
				{
					if (computers[num][j] == 1 && Visited[j] == false)
					{
						Q.push(j);
						Visited[j] = true;

					}
				}
			}
		}
	}











	return answer;
}