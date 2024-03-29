#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int result[8];
bool visited[8];
vector<int> v;

void dfs(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << result[i] << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        result[cnt] = v[i];
        dfs(cnt + 1);
        result[cnt] = 0;
        visited[i] = false;
    }
}

int main() {
    cin >> n >> m;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    dfs(0);
}