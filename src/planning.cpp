#include "planning.h"
#include <cmath>
#include <vector>

using namespace std;

Planner::Planner(const vector<vector<bool>> &grid) : grid(grid) {
  rows = grid.size();
  cols = grid[0].size();
}

bool Planner::isvalid(int x, int y) const {
  return (x >= 0 && x < rows && y >= 0 && y < cols && !grid[x][y]);
}

double Planner::heuristic(int x1, int y1, int x2, int y2) const {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

vector<pair<int, int>> Planner::pathplanning(pair<int, int> start,
                                             pair<int, int> goal) {
    vector<pair<int, int>> path;

    // Directions: up, down, left, right
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    // Structures for A*
    vector<vector<double>> g(rows, vector<double>(cols, 1e9));  // cost so far
    vector<vector<pair<int,int>>> parent(rows, vector<pair<int,int>>(cols, {-1,-1}));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Min-heap for open set (f, (x,y))
    auto cmp = [](auto &a, auto &b){ return a.first > b.first; };
    priority_queue<pair<double, pair<int,int>>,
                   vector<pair<double, pair<int,int>>>,
                   decltype(cmp)> open(cmp);

    // Initialize start
    g[start.first][start.second] = 0.0;
    open.push({heuristic(start.first, start.second, goal.first, goal.second), start});

    while (!open.empty()) {
        auto current = open.top().second;
        open.pop();

        int cx = current.first, cy = current.second;
        if (visited[cx][cy]) continue;
        visited[cx][cy] = true;

        // Goal reached
        if (current == goal) {
            // Reconstruct path
            while (current != start) {
                path.push_back(current);
                current = parent[current.first][current.second];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        for (auto d : dirs) {
            int nx = cx + d.first, ny = cy + d.second;
            if (!isvalid(nx, ny)) continue;

            double newCost = g[cx][cy] + 1.0; 
            if (newCost < g[nx][ny]) {
                g[nx][ny] = newCost;
                double f = newCost + heuristic(nx, ny, goal.first, goal.second);
                open.push({f, {nx, ny}});
                parent[nx][ny] = {cx, cy};
            }
        }
    }
    return path;
}

}
