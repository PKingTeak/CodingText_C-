#include<iostream>
#include<vector>
#include<deque>
using namespace std;

static int answer = 0 ;

bool Count(vector<int>& A, vector<int>& B)
{
	bool check[4] = { false, };
	for (int i = 0; i < A.size();i++)
	{
		if (A[i] <= B[i])
		{
			check[i] = true;
		}
	
	}

	for (int i = 0 ; i <4;i++)
	{
		if (!check[i])
		{
			return false;
		}


	}

	return true;
}

void CharToIntPlus(vector<int>& arr, char c)
{
	// {‘A’, ‘C’, ‘G’, ‘T’} 인 문
	switch (c)
	{
	case 'A':
		arr[0]++;
		break;
	case 'C' :
		arr[1]++;
		break;
	case 'G':
		arr[2]++;
		break;
	case 'T':
		arr[3]++;
		break;

	default : 
		cout << "값이 잘못됨(플러스)";
		break;
	}
}


void CharToIntMiner(vector<int>& arr, char c)
{// {‘A’, ‘C’, ‘G’, ‘T’} 인 문
	switch (c)
	{
	case 'A':
		arr[0]--;
		break;
	case 'C':
		arr[1]--;
		break;
	case 'G':
		arr[2]--;
		break;
	case 'T':
		arr[3]--;
		break;

	default:
		cout << "값이 잘못됨(마이너스)";
		break;
	}
}

int main()
{
	int S, P;

	cin >> S >> P;
	vector<int> arr(4);
	vector<int> compareArr(4);
	string input;
	
	deque<char> compare;
	
	
	cin >> input;
	
	for (int i = 0; i < arr.size();i++)
	{
		
		cin >> arr[i];
	}


	for (int i = 0; i < P;i++)
	{
		CharToIntPlus(compareArr, input[i]);
		compare.push_back(input[i]);
	}

	bool Check = Count(arr, compareArr);

	if (Check)
	{
		answer++;
	}


	for (size_t i = P; i < input.size();i++)
	{
		compare.push_back(input[i]);
		CharToIntPlus(compareArr, input[i]);
		
		
		compare.push_front(input[i - P]); //슬라이딩 윈도우
		CharToIntMiner(compareArr, input[i - P]);
		if (Count(arr, compareArr))
		{
			answer++;
		}

		

	}


	cout << answer;

	//O(N)으로 끝내야함


}