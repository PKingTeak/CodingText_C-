#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node
{
    int y, x;
    int broken; // 0: 아직 안 부숨, 1: 이미 한 번 부숨
    int dist;   // 시작점부터 거리
};

int BFS(const vector<vector<int>>& maps)
{
    int N = maps.size();
    int M = maps[0].size();

    queue<Node> Q;
    static bool visited[1000][1000][2]; 
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            visited[i][j][0] = false;
            visited[i][j][1] = false;
        }
    }

    Q.push({ 0, 0, 0, 1 });
    visited[0][0][0] = true;

    int dy[4] = { 1,-1,0,0 };
    int dx[4] = { 0,0,1,-1 };

    while (!Q.empty())
    {
        Node cur = Q.front();
        Q.pop();

        int cury = cur.y;
        int curx = cur.x;

      
        if (cury == N - 1 && curx == M - 1)
        {
            return cur.dist;
        }

        for (int i = 0; i < 4; i++)
        {
            int nexty = cury + dy[i];
            int nextx = curx + dx[i];

            // 범위 체크
            if (nexty < 0 || nexty >= N || nextx < 0 || nextx >= M)
                continue;

            // 1) 다음 칸이 빈 칸(0)인 경우
            if (maps[nexty][nextx] == 0)
            {
                // 현재 broken 상태 그대로 방문
                if (!visited[nexty][nextx][cur.broken])
                {
                    visited[nexty][nextx][cur.broken] = true;
                    Q.push({ nexty, nextx, cur.broken, cur.dist + 1 });
                }
            }
            // 2) 다음 칸이 벽(1)이고, 아직 벽을 안 부쉈을 때만 부수기 가능
            else if (maps[nexty][nextx] == 1 && cur.broken == 0)
            {
                if (!visited[nexty][nextx][1])
                {
                    visited[nexty][nextx][1] = true;
                    Q.push({ nexty, nextx, 1, cur.dist + 1 });
                }
            }
        }
    }

   
    return -1;
}

int main()
{

    int N, M;
    cin >> N >> M;

    vector<vector<int>> arrs(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < M; j++)
        {
            arrs[i][j] = input[j] - '0';
        }
    }

    int answer = BFS(arrs);
    cout << answer;

    return 0;
}
