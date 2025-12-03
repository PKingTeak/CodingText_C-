#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void rotateIndex(string& cogWheel , int rotateArrow)
{
	if (rotateArrow == 0)
	{
		return;
	}

	if (rotateArrow == 1)
	{
		//시계방향
		char back  = cogWheel.back();
		
		for (int i = cogWheel.size() - 1; i > 0; i--)
		{
			cogWheel[i] = cogWheel[i - 1];
		}
		cogWheel[0] = back;
	}
	else
	{
		char first = cogWheel.front();
		for (int i = 0; i < cogWheel.size()-1;i++)
		{
			cogWheel[i] = cogWheel[i + 1];

		}
		cogWheel.back() = first;
	}
	

}


void Rotation(vector<string>& cogwheels , int wheelnum, int rotatearrow)
{
	int rotate[4] = { 0,0,0,0 }; // 0은 안돌아 1은 시계 -1 은 반시계
	//2번과 3번은 왼쪽 오른쪽 둘다 비교해야함. 
	//1번과 4번은 각각 오른쪽 왼쪽만 비교하면됨.
	rotate[wheelnum-1] = rotatearrow;

	

	for (int i = wheelnum - 1; i > 0;i--) //왼쪽
	{
		if (cogwheels[i - 1][2] != cogwheels[i][6])
		{
			rotate[i - 1] = -rotate[i];
		}
		else
		{
			break;
		}
	}



	for (int i = wheelnum-1; i < 3;i++) // 오른쪽
	{
		if (cogwheels[i][2] != cogwheels[i + 1][6])
		{
			rotate[i + 1] = -rotate[i];
		}
		else
		{
			break;
		}
	}

	
	for (int i = 0;i < 4; i++)
	{
		rotateIndex(cogwheels[i], rotate[i]);
	}
	
}

void Score(vector<string>& cogWheels)
{
	int result = 0;
	for (int i = 0; i < cogWheels.size();i++)
	{
		char first = cogWheels[i].front() - '0';
		if (first == 1)
		{
			result += (1 << i);
		}
	}

	cout << result;
}


int main()
{
	
	vector<string> cogwheels(4);
	for (int i = 0; i < cogwheels.size();i++)
	{
		string input;
		cin >> input;
		cogwheels[i] = input;
	}

	//톱니바퀴 저장후 
	int K;

	cin >> K; //회전수
	for (int i = 0; i < K;i++)
	{
		int num;
		int rotate;
		cin >> num >> rotate;
		Rotation(cogwheels , num, rotate);
	}
	//해당 번호의 톱니바퀴를 회전한다

	
	Score(cogwheels);
}