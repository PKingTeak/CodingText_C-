#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

bool visited[25][25] = { false, };
vector<int> answer;



void BFS(vector<vector<int>>& maps, pair<int,int> startpos)
{
	
	queue<pair<int, int>> Q;
	Q.push(startpos);


	int dy[4] = { 1,-1,0,0 };
	int dx[4] = { 0,0,1,-1 };
	
	int count = 1;
	while (!Q.empty())
	{
		int cury = Q.front().first;
		int curx = Q.front().second;
		visited[cury][curx] = true;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nexty = cury + dy[i];
			int nextx = curx + dx[i];

			if ((nexty >= 0 && nexty < maps.size()) && (nextx >= 0 && nextx < maps[nexty].size()) && maps[nexty][nextx] == 1 && visited[nexty][nextx] == false)
			{
				visited[nexty][nextx] = true;
				count++;
				Q.push({ nexty,nextx });

			}
		}
	}

	answer.push_back(count);


}

void findStartPos(vector<vector<int>>& maps)
{
	for (int i = 0; i < maps.size(); i++)
	{
		for (int j = 0; j < maps[i].size();j++)
		{
			if (visited[i][j] == false && maps[i][j] == 1)
			{
				BFS(maps, { i,j });

			}
		}
	}
}


int main()
{
	int N;

	cin >> N;

	vector<vector<int>> maps(N,vector<int>(N));
	

	for (int i = 0; i < maps.size(); i++)
	{
		for (int j = 0; j < maps[i].size();j++)
		{
			char input;
			cin >> input;
			 maps[i][j] = input - '0';
		}
	}

	findStartPos(maps);
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int num : answer)
	{
		cout << num << "\n";
	}



	
	

}