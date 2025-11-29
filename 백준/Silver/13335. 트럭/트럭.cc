#include<iostream>
#include<vector>
#include<queue>
#include<deque>

using namespace std;

struct Truck
{
	int weight;
	int time;
};


int checkWeight(deque<Truck>& dq, int l)
{
	int sum = 0;
	for (Truck t : dq)
	{
		sum += t.weight;
	}
	return l - sum;
}

int main()
{
	int n, w, l;

	cin >> n >> w >> l;
	vector<int> arr(n);

	for (int i = 0; i < arr.size(); i++)
	{
		cin >> arr[i];
	}

	deque<Truck> bridge;
	//큐의 길이는 w 
	//큐 내부에 값들은 L보다 작거나 같아야함.
	int time = 0;
	int index = 0;

	while (true)
	{
		time++;

		if (index == arr.size() && bridge.empty())
		{
			break;
		}


		if (bridge.size() < w && index < arr.size())
		{
			Truck t;
			t.weight = arr[index];
			t.time = 0;
			if (bridge.size() == 0)
			{
				bridge.push_back(t);
				index++;
			}
			else if (index < arr.size()		&& checkWeight(bridge,l) >= arr[index])
			{
				//다리 위에 트럭이 무조건 있다 
				t.weight = arr[index];
				t.time = 0;
				bridge.push_back(t);
				index++;
				

			}


		}

		for (int i = 0; i < bridge.size();i++)
		{
			bridge[i].time++; //다리 위에 있는 트럭의 시간들 전부 +1;
		}


		if (bridge.front().time >= w)
		{
			bridge.pop_front(); //트럭 퇴장

		}




	}
	//문제 무게 합산을 안했음 
	//트럭 전체 무게 그리고 해당 무게를 버틸수 있으면 트럭을 또 올릴수있다. 근데 지금 인덱스에서 다음거만 확인을 하니까 










	cout << time;


}