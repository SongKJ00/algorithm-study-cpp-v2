#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > adjs;
vector<bool> visited;

void dfs(int v) {
  cout << v << " ";
  visited[v] = true;
  vector<int> v_adjs = adjs[v];
  for (size_t i = 0; i < v_adjs.size(); i++) {
    if (!visited[v_adjs[i]]) {
      dfs(v_adjs[i]);
    }
  }
}

void bfs(int v) {
  queue<int> q;
  visited[v] = true;
  q.push(v);

  while (!q.empty()) {
    v = q.front(); q.pop();
    cout << v << " ";
    vector<int> v_adjs = adjs[v];
    for (size_t i = 0; i < v_adjs.size(); i++) {
      if (!visited[v_adjs[i]]) {
        q.push(v_adjs[i]);
        visited[v_adjs[i]] = true;
      }
    }
  }
}

int main(void) {
  int N, M ,V;
  cin >> N >> M >> V;

  adjs.resize(N+1);
  visited.resize(N+1);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    adjs[a].push_back(b);
    adjs[b].push_back(a);
  }
  for (int i = 0; i < adjs.size(); i++) {
    std::sort(adjs[i].begin(), adjs[i].end());
  }

  dfs(V);
  cout << "\n";

  fill(visited.begin(), visited.end(), false);

  bfs(V);
  cout << "\n";
}