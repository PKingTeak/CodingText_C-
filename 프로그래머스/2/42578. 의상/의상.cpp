#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes)
{
	int answer = 1;
	unordered_map<string, int> cm;

	for (int i = 0; i < clothes.size(); i++)
	{
		cm[clothes[i][1]]++;
	}

	if (cm.size() == 0)
	{
		return -1;
	}
	//여기서 숫자로 조합만 하면돼

	for (auto it = cm.begin(); it != cm.end(); it++)
	{
		
	
		answer *= (it->second+1);
	}

	answer -= 1; //모두 안입는 경우



	return answer;
}

