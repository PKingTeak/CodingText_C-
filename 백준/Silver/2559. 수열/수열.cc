#include<iostream>
#include<vector>

using namespace std;


int main()
{
	int N, K;

	cin >> N >> K;

	vector<int> arr(N);
	
	for (int i = 0; i < arr.size();i++)
	{
		cin >> arr[i];
	}
	

	int maxsum =0;
	int cursum = 0;

	//첫번째만 넣어주기
	for (int i = 0; i < K; i++)
	{
		maxsum += arr[i];
	}
	cursum = maxsum;

	for (int i = K; i < arr.size();i++)
	{
		
		cursum += arr[i];
		cursum -= arr[i - K];

		maxsum = max(maxsum, cursum);

	}


	cout << maxsum;

//슬라이딩 윈도우 사용해서 점점 앞으로 전진



}