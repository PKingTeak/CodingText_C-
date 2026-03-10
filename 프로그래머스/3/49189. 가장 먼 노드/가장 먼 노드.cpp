#include <string>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge)
{
	vector<int> dist(n + 1, -1);
	vector<vector<int>> vertexs(n + 1, vector<int>());

	//vertexs에 edge들을 다 넣어줘야함
	for (int i = 0; i < edge.size();i++)
	{
		for (int j = 0; j < edge[i].size();j += 2)
		{
			int start = edge[i][j];
			int end = edge[i][j + 1];

			vertexs[start].push_back(end);
			vertexs[end].push_back(start);
		}
	}

	queue<int> Q;
	Q.push(1); //startindex = 1에서 부터 떨어진 거리니까
	dist[1] = 0;

	while (!Q.empty())
	{
		int startnode = Q.front();

		Q.pop();

		for (int i = 0; i < vertexs[startnode].size();i++)
		{
			if (dist[vertexs[startnode][i]] < 0)
			{
			Q.push(vertexs[startnode][i]);
			dist[vertexs[startnode][i]] = dist[startnode] + 1;
			}
		}


	}

	//각 거리마다 visited 1과의 떨어진 거리 측정
	int answer = 0;
	//가장 먼 노드 탐색
	sort(dist.begin(), dist.end());
	for (int i = 0; i < dist.size();i++)
	{
		if (dist[i] == dist.back())
		{
			answer++;
		}
	}

	return answer;

}