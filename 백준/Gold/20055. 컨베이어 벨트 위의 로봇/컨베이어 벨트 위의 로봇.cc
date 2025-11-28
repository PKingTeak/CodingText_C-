#include<iostream>
#include<deque>

using namespace std;

struct Slot
{
	int force;
	bool isRobot = false;

};

static deque<Slot> dq;
static int N,K;


void Rotaion()
{

	
	int count = 0;

	while (true)
	{
		count++;
		//회전
		dq.push_front(dq.back());
		dq.pop_back();


		if (dq[N - 1].isRobot == true)
		{
			dq[N - 1].isRobot = false;
			
		}

		for (int i = N-2; i >=0; i--)
		{
			if (dq[i].isRobot && dq[i + 1].isRobot == false && dq[i+1].force >0)
			{
				dq[i + 1].isRobot = true;
				dq[i].isRobot = false;
				dq[i+1].force--;
			}
		}


		if (dq[N - 1].isRobot)
		{
			dq[N - 1].isRobot = false;
		}

		if (!dq[0].isRobot && dq[0].force > 0) 
		{
			dq[0].isRobot = true;
			dq[0].force--;
		}


		int zerocount = 0;
		for (Slot i : dq)
		{
			if (i.force == 0)
			{
				zerocount++;
			}
			
		}
		 
		if (zerocount >= K)
		{
			cout << count;
			break;
		}



	}

}



int main()
{

	cin >> N >> K;

	for (int i = 0; i < 2 * N;i++)
	{
		int input;
		cin >> input;
		Slot slot;
		slot.force = input;

		dq.push_back(slot);
	}
	Rotaion();




}