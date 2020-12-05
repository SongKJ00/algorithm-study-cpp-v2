#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[101][101];
bool visited[101][101];

typedef struct _PosInfo {
  int y;
  int x;
  int depth;
} PosInfo;

int main(void) {
  memset(map, 0, sizeof(map));
  memset(visited, false, sizeof(visited));

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string line;
    cin >> line;
    for (int j = 0; j < line.size(); j++) {
      int val = line[j] - '0';
      map[i+1][j+1] = val;
    }
  }

  int answer = 0;
  queue<PosInfo> q;
  PosInfo start = {1, 1, 1};
  q.push(start);

  while (!q.empty()) {
    auto curr_pos = q.front(); q.pop();
    int y = curr_pos.y;
    int x = curr_pos.x;
    int depth = curr_pos.depth;
    visited[y][x] = true;

    if (y == N && x == M) {
      answer = depth;
      break;
    }

    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};
    for (int dir = 0; dir < 4; dir++) {
      int next_y = y + dy[dir];
      int next_x = x + dx[dir];
      if (next_y < 0 || next_y > N || next_x < 0 || next_x > M) { continue; }
      if (!visited[next_y][next_x] && map[next_y][next_x]) {
        q.push({next_y, next_x, depth+1});
        visited[next_y][next_x] = true;
      }
    }
  }

  cout << answer << endl;
}