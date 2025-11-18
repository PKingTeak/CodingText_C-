#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;



void Visiable(vector<int>& nums)
{
	for (int i : nums)
	{
		cout << i << " ";
	}
	cout << "\n";
}

int main()
{
	vector<int> nums(5, 0);

	for (int i = 0; i < nums.size();i++)

	{
		cin >> nums[i];

	}

	int startindex = 0;

	vector<int> answer = { 1,2,3,4,5 };

	while (nums != answer)
	{
		for (int i = 0;i < 4;i++)
		{

			if (nums[i] > nums[i + 1])
			{

			swap(nums[i], nums[i+1]);
			Visiable(nums);
			}

		}

	}
		return 0;
}