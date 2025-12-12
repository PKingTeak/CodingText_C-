#include<iostream>
#include<vector>

using namespace std;

int main()
{

	int N, X;
	cin >> N >> X;
	vector<int> arr(N);

	bool issad = true;
	for (int i = 0;i < arr.size();i++)
	{
		cin >> arr[i];
		if (arr[i] > 0)
		{
			issad = false;
		}
	}

	if (issad == true)
	{
		cout << "SAD";
		return 0;
	}

	int maxvisited = 0;

	for (int i = 0; i < X;i++)
	{
		maxvisited += arr[i];
	}

	int sum = maxvisited;
	int count = 1;

	//첫번째와 비교할때 첫번째가 가장크면 count값이 증가를 안하는 현상이 있음

	for (int i = X; i < arr.size();i++)
	{
		sum += arr[i];
		sum -= arr[i - X];

		if (maxvisited < sum)
		{
			maxvisited = sum;
			count = 1;
			
		}
		else if (maxvisited == sum)
		{
			count++;
		}


	}




	cout << maxvisited << "\n" << count;

	return 0;




}