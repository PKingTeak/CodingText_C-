#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct FishInfo
{
	int x, y;
	int moveValue;

};





FishInfo EatingFish(vector<vector<int>>& ocean , pair<int,int> startpos , int sharkSize)
{
	//재방문이 가능하기 때문에 visited 는 필요가 없음.
	FishInfo result;

	int resultMove = 0;

	vector<vector<int>> dist (ocean.size(),vector<int>(ocean.size(),-1)); //여기에 이동한 값을 계속 저장할꺼임
	
	
	
	queue<pair<int,int>> Q;
	Q.push(startpos);
	
	int dy[4] = { -1,0,0,1 }; //상 좌 우 하
	int dx[4] = { 0,-1,1,0 };

	dist[startpos.first][startpos.second] = 0;

	
	while (!Q.empty())
	{
	
		int cury = Q.front().first;
		int curx = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nexty = cury + dy[i];
			int nextx = curx + dx[i];

			if ((nexty >= 0 && nexty < ocean.size()) && (nextx >= 0 && nextx < ocean[0].size())&& dist[nexty][nextx] == -1 && ocean[nexty][nextx] <= sharkSize)
			{
				dist[nexty][nextx]  = dist[cury][curx]+1;
				Q.push({ nexty,nextx });
			}
		}

		


	}


	int bestdist = 401;
	int besty = -1;
	int bestx = -1;



	//여기서 찾아야함
	for (int i = 0; i < ocean.size();i++)
	{
		for (int j = 0; j < ocean[i].size(); j++)
		{
			int fish = ocean[i][j];
			if (fish == -1 || dist[i][j] == -1)
			{
				continue;
			}

			int d = dist[i][j];

			if (fish >= 1 && fish < sharkSize)
			{
				//먹을수 있다.
				if (bestdist > d)
				{

				bestdist = d;
				besty = i;
				bestx = j;//값을 저장 
				}
				else if (d == bestdist)
				{
					if (i < besty || (i == besty && j < bestx))
					{
						besty = i;
						bestx = j;
					}//거리가 같은상황이면 위에 왼쪽에 위치한 녀석을 먼저 먹는다. 
				}
			}
			


		}
	}

	FishInfo answerfish;
	answerfish.x = bestx;
	answerfish.y = besty;
	answerfish.moveValue = bestdist;


	if (bestx == -1 || besty == -1)
	{

		return { -1, -1, -1 };
	}



	return answerfish;


}


int main()
{
	int N;

	cin >> N;

	vector<vector<int>> Ocean(N, vector<int>(N, 0));
	pair<int, int> startpos;
	int size = 2;
	int totalTime = 0;
	int exp = 0;



	for (int i = 0; i < Ocean.size();i++)
	{
		for (int j = 0;j < Ocean[i].size();j++)
		{
			cin >> Ocean[i][j];
			if (Ocean[i][j] == 9)
			{
				startpos = { i,j };
				Ocean[i][j] = 0;
			}
		}
	}


	while (true)
	{
		FishInfo next = EatingFish(Ocean, startpos, size);
		if (next.moveValue == -1)
		{
			break;
		}


		totalTime += next.moveValue;
		startpos = { next.y,next.x };

		Ocean[next.y][next.x] = 0; //물고기 먹었음

		exp++;
		if (exp >= size)
		{
			size++;
			exp = 0;
		}

	}


	cout << totalTime;

	return 0;
}