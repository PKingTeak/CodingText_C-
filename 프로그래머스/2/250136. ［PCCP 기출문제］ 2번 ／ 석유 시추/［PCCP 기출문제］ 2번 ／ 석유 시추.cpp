#include <string>
#include <vector>
#include<queue>
#include <set> 

using namespace std;


bool visited[500][500] = { 0, };
int NodeTeamNum = 1;

int BFS(vector<vector<int>>& _land,vector<vector<int>>& checkLand, pair<int, int> startIndex )
{
	queue<pair<int, int>> Q;
	vector<pair<int, int>> saveNode;//지나온 길들 저장후 다시 해당 인덱스 석유 값을 다 동일하게
	int countNode = 0;
	int counter = 0;
	int dy[4] = { 1,-1,0,0 };
	int dx[4] = { 0,0,1,-1 };

	if (visited[startIndex.first][startIndex.second] == true)
	{
		counter += _land[startIndex.first][startIndex.second];
	}
	else
	{
		Q.push(startIndex);
		countNode++;
		visited[startIndex.first][startIndex.second] = true;
		saveNode.push_back(startIndex);
	}

	while (!Q.empty())
	{
		int curY = Q.front().first;
		int curX = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4;i++)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			if ((nextY >= 0 && nextY < _land.size()) && (nextX >= 0 && nextX < _land[nextY].size()) && _land[nextY][nextX] >= 1 && visited[nextY][nextX] == false)
			{
				Q.push({ nextY,nextX });
				saveNode.push_back({ nextY,nextX });
				countNode++;
				visited[nextY][nextX] = true;
				
			}

		}
	}

	//이제 끝나면


	for (int i = 0; i < saveNode.size();i++)
	{
		_land[saveNode[i].first][saveNode[i].second] = countNode;
		checkLand[saveNode[i].first][saveNode[i].second] = NodeTeamNum;
		//이러면 _land가 전부 끝값으로 채워지고 처음 한번만 시추한 값을 가지게 됨
	}
	counter += countNode;
	NodeTeamNum++;

	return counter;


}



int solution(vector<vector<int>> land) {
	int answer = 0;
	vector<vector<int>> checkLand(land.size(), vector<int>(land[0].size(), 0));

	for (int j = 0; j < land[0].size(); j++) {
		int curNum = 0;
		set<int> seen;  

		for (int i = 0; i < land.size(); i++) {
			if (land[i][j] == 0) continue;                         // 바위면 넘어가기

			if (!visited[i][j]) BFS(land, checkLand, { i, j });     // 처음 보는 석유면 BFS → 번호와 크기가 생김

			int team = checkLand[i][j];
			if (seen.count(team) == 0) {                           // 이번 열에서 처음 보는 덩어리면
				seen.insert(team);
				curNum += land[i][j];                              // 크기 더하기
			}
		}
		answer = max(answer, curNum);
	}
	return answer;

	//아래로 내리는것만 도움받음... 다음에 다른 좋은 방법을 생각해보자
}


int main()
{
	vector<vector<int>> land = { {0, 0, 0, 1, 1, 1, 0, 0 }, { 0, 0, 0, 0, 1, 1, 0, 0 }, { 1, 1, 0, 0, 0, 1, 1, 0 }, { 1, 1, 1, 0, 0, 0, 0, 0 }, { 1, 1, 1, 0, 0, 0, 1, 1 } };
	solution(land);
}

