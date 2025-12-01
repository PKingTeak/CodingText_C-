#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int main()
{
	int N;
	cin >> N;

	int Input = 0;
	
	int Arr[] = { 1,1,2,4 };


	while (N--)
	{
		cin >> Input;
		vector<long long> dp(Input + 1, 0);
		
		for (int i = 0; i < min((int)dp.size(), 4); i++)
		{
			dp[i] = Arr[i];
		}
		
		for (int i = 4; i <= Input; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		


		cout << dp[Input]<< "\n";
	}
}