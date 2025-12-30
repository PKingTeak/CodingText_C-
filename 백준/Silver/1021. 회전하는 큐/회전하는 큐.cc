#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main()
{
	int N, K;

	cin >> N >> K;

	vector<int> nums(K, 0);
	deque<int> dq;

	for (int i = 0; i < K;i++)
	{

		cin >> nums[i];
	}


	for (int i = 1; i <= N;i++)
	{
		dq.push_back(i);
	}

	//앞에 값 - 뒤에값 >0 오른쪽으로
	//앞게 값 - 뒤에값 <0 왼쪽으로 


	int count = 0;
	int left = 0;
	int right = 0;
	int targetindex = 0;
	//왼쪽 오른쪽 판별기

	//왼쪽 오른쪽 어디로 가야하는지만 비교
	for (int k = 0; k < nums.size(); k++)
	{

		for (int i = 0;i < dq.size();i++)
		{
			if (dq[i] == nums[k])
			{
				left = i;
				right = dq.size() - left;
				break;
			}

		}



		if (left <= right)
		{
			while (left--)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				count++;
			}
			//뒤로 추가
		}

		else
		{
			while (right--)
			{
				dq.push_front(dq.back());
				dq.pop_back();
				count++;
			}
			//앞으로 
		}


		dq.pop_front();

	}

	cout << count;



}