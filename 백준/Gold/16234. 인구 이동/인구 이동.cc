#include<iostream>
#include<vector>
#include<queue>

using namespace std;


using namespace std;

static vector<pair<int,int>> calIndex;
static int N , L , R, answer;


bool isOpen(vector<vector<int>>& country , int cury , int curx, int nexty,int nextx)
{
	int maxvalue = max(country[cury][curx], country[nexty][nextx]);
	int minvalue = min(country[cury][curx], country[nexty][nextx]);

	int subvalue = maxvalue - minvalue;

	if (L<= subvalue && subvalue<=R)
	{
		return true;
	}
	return false;

}

int BFS(vector<vector<int>>& country ,pair<int,int> startpos , bool visited[51][51])
{
	
	calIndex.clear();
	int sum = 0;

	int dy[4] = { 1,-1,0,0 };
	int dx[4] = { 0,0,1,-1 };
	


	queue<pair<int, int>> Q;
	Q.push(startpos);
	visited[startpos.first][startpos.second] = true;
	sum += country[startpos.first][startpos.second];
	calIndex.push_back(startpos);
	
	while (!Q.empty())
	{
		int cury = Q.front().first;
		int curx = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4;i++)
		{
			int nexty = cury + dy[i];
			int nextx = curx + dx[i];

			if ((nexty >= 0 && nexty < N) && (nextx >= 0 && nextx < N)  && visited[nexty][nextx] == false)
			{
				bool canOpen = isOpen(country,cury,curx,nexty,nextx);
				if (canOpen)
				{
				Q.push({ nexty,nextx }); //다음값
				visited[nexty][nextx] = true;
				calIndex.push_back({ nexty,nextx });
				sum += country[nexty][nextx];
				}
			}
		}




	}
	return sum;

}


void Calculate(vector<vector<int>>& country,int sum)
{

	sum = sum / (int)calIndex.size();

	for (int i = 0; i < calIndex.size(); i++)
	{
		country[calIndex[i].first][calIndex[i].second] = sum;
	}
	
	calIndex.clear();

}


int main()
{
	
	cin >> N >> L >> R;

	vector<vector<int>> country(N,vector<int>(N));
	answer = 0;

	
	for (int i = 0; i < country.size();i++)
	{
		for (int j = 0;j < country[i].size();j++)
		{
			cin >> country[i][j];
		}
	}

	int sum = 0;
	while (true)
	{
		bool visited[51][51] = { false, }; //최대 방문 가능
		bool ismove = false;
		for (int i = 0; i < country.size();i++)
		{
			for (int j = 0; j < country[i].size(); j++)
			{
				if (visited[i][j] == false)
				{
					sum = BFS(country,{i,j}, visited);
					if (calIndex.size() > 1)
					{
						Calculate(country, sum);
						ismove = true;

					}
				}
			}
		}

		if (!ismove)
		{
			break;
		}
		answer++; //일단 한번도니까
		
	}

	cout << answer;


	
		
}

/*
국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
연합을 해체하고, 모든 국경선을 닫는다.
*/