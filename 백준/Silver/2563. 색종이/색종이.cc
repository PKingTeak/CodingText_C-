#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static int paper[100][100] = { 0, };

void paintPaper(pair<int,int>& pos , int& area)
{

	int largey = pos.first + 10;
	int largex = pos.second + 10;

	for (int i = pos.first; i < largey;i++)
	{
		for (int j = pos.second; j < largex; j++)
		{
			if (paper[i][j] == 0)
			{
				area++;	
				paper[i][j] = 1;
			}
		}
	}


	

}

int main()
{
	int n;
	cin >> n;

	int area = 0;

	vector<pair<int, int>> spot(n);
	for (int i = 0;i < spot.size();i++)
	{
		cin >> spot[i].first;
		cin >> spot[i].second;
		
		paintPaper(spot[i],area);
	}//종이 시작지점


	cout << area;



	
	

	
}