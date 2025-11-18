#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	int N = 0, K = 0;

	cin >> N >> K;

	vector<int> arr(N, 0);

	for (int i = 0; i < arr.size();i++)
	{
		cin >> arr[i];

	}

	int count = 0;
	vector<int> compare = arr;

	sort(compare.begin(), compare.end());

	while (true)
	{
		for (int i = 0; i < arr.size()-1;i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				count++;
				if (count == K)
				{
					cout << arr[i] << " " << arr[i + 1];
				}
				
			}
		}
		if (compare == arr)
		{
			if (K > count)
			{
				cout << -1;
			}
			break;
		}

	}


	

	return 0;

}
