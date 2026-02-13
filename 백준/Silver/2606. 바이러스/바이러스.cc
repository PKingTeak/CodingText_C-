#include<iostream>
#include<vector>

using namespace std;

static bool visited[100];
int answer = 0;
void DFS(vector<vector<int>>& computers, int startnode)
{
	
	for(int i = 0;i<computers[startnode].size();i++)
	{
		if (visited[computers[startnode][i]] == false)
		{
			answer++;
			visited[computers[startnode][i]] = true;
			DFS(computers, computers[startnode][i]);
		}
	}
}


int main()
{
	int N;
	int vertex;

	cin >> N >> vertex;
	vector<vector<int>> computers(N+1);

	for (int i = 0; i < vertex;i++)
	{
		pair<int, int> startPos;
		cin >> startPos.first;
		cin >> startPos.second;

		computers[startPos.first].push_back(startPos.second);
		computers[startPos.second].push_back(startPos.first);
		
	}
	visited[1] = true;
	DFS(computers, 1);
	
	cout << answer;


}