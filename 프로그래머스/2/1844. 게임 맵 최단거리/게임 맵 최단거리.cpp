#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

static bool visited[100][100];

int solution(vector<vector<int> > maps)
{
    pair<int, int> startIndex = { 0,0 };
    queue<pair<int, int>> q;

    q.push(startIndex);

    int dy[4] = { 1, -1,0,0 };
    int dx[4] = { 0,0,1,-1 };


    while (!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = cury + dy[i];
            int nextX = curx + dx[i];

            if ((nextY >= 0 && nextY < maps.size()) && (nextX >= 0 && nextX < maps[nextY].size()) && visited[nextY][nextX] == false && maps[nextY][nextX] >= 1)
            {
                visited[nextY][nextX] = true;
                maps[nextY][nextX] =  maps[nextY][nextX] + maps[cury][curx];
                q.push({ nextY,nextX });

            }
        }

    }

    


    int answer = maps[maps.size()-1][maps[0].size()-1];

    if (answer != 1)
    {
    return answer;

    }
    return -1;


 
    /*
    * 상하 좌우 움직임
    * 이미 방문한 곳은 재방문 금지 
    * 1값은 갈수있는 곳 0은 벽인데 1값을 진행하면서 count를 증가시키거나 자신이 건너온 노드갯수를 저장하면 될거같음
    * 
    * 도착지점에 도착하지 못할경우 -1이니 해당 인덱스 까지 값을 저장한 후에 해당 값이 1로 유지가 되면 그때 -1을 리턴함
    */
}
