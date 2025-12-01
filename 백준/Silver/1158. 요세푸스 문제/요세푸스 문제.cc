#include<iostream>
#include<queue>
#include<vector>
//큐로
using namespace std;

int main()
{
	int N , K;

	cin >> N >> K;

	queue<int> Q;

	vector<int> answer;

	for (int i = 1; i <= N	;i++)
	{
		Q.push(i);
	}

	int turn = 0;
	while (!Q.empty())
	{
		int curnum = Q.front();
		Q.pop();
		if (turn == K-1) //인덱스는 0부터 시작이니까
		{
			answer.push_back(curnum);
			turn = 0;
			
		}
		else
		{
			Q.push(curnum); //아닌건 다시 넣어
			turn++;
		}
		
	}

	cout << "<" << answer[0];
	for (int i = 1 ;i < answer.size();i++)
	{
		cout << ", " << answer[i];
	}
	cout << ">";

}