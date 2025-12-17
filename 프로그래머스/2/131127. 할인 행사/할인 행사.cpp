#include<iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int FindIndex(vector<string>& want , string key )
{
    for (int i = 0; i < want.size();i++)
    {
        if (key == want[i])
        {
            return i;
        }
    }
    return -1;
}

bool Compare(vector<int>& num, vector<int>& compare)
{
    bool checker[10] = {false,};
    for (int i = 0; i < num.size();i++)
    {
        if (num[i] != compare[i])
        {
            return false;
        }
              
    }

    return true;

    
}


int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    int answer = 0;
    vector<int> compare(number.size());
    
    deque<string> slides;
    
    for (int i = 0; i < 10; i++)
    {
        slides.push_back(discount[i]);
    }

    for (int i = 0; i < want.size();i++)
    {
        int count = 0;
        for (int j = 0; j < slides.size();j++)
        {
            if (slides[j] == want[i])
            {
                count++;
            }
        }
        compare[i] = count;
        //처음에만 다 넣고 나머지는 계속 비교하면서 하면될듯?
    }
    if (Compare(number, compare))
    {
        answer++;
    }


    for(int i = 10 ; i < discount.size();i++)
    {
    
       

        slides.push_back(discount[i]);
        int index = FindIndex(want, discount[i]);
        int subindex = FindIndex(want, slides.front());
        slides.pop_front();
        if (index >= 0)
        {
            compare[index]++;
        }

        if (subindex >= 0)
        {
            compare[subindex]--;
        }

        if (Compare(number, compare))
        {
            answer++;
        }
        
        

     
    }

    


    return answer;
}


int main()
{
    vector<string> want = { "apple" };
    vector<int> number = { 10 };
    vector<string> discount = { "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana" };

   int answer = solution(want, number, discount);
   cout << answer;
}