#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> topologicalSort(int n, vector<int>& indegree, unordered_map<int, vector<int>>& graph) {
    queue<int> q;
    vector<int> result;
    
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        for (int neighbor : graph[node]) {
            if (--indegree[neighbor] == 0) q.push(neighbor);
        }
    }
    
    return result.size() == n ? result : vector<int>();
}

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    int groupId = m;
    for (int i = 0; i < n; i++) {
        if (group[i] == -1) group[i] = groupId++;
    }

    unordered_map<int, vector<int>> itemGraph, groupGraph;
    vector<int> itemIndegree(n, 0), groupIndegree(groupId, 0);
    
    for (int i = 0; i < n; i++) {
        for (int prev : beforeItems[i]) {
            itemGraph[prev].push_back(i);
            itemIndegree[i]++;
            if (group[prev] != group[i]) {
                groupGraph[group[prev]].push_back(group[i]);
                groupIndegree[group[i]]++;
            }
        }
    }

    vector<int> itemOrder = topologicalSort(n, itemIndegree, itemGraph);
    vector<int> groupOrder = topologicalSort(groupId, groupIndegree, groupGraph);
    if (itemOrder.empty() || groupOrder.empty()) return {};

    unordered_map<int, vector<int>> groupedItems;
    for (int item : itemOrder) {
        groupedItems[group[item]].push_back(item);
    }

    vector<int> result;
    for (int g : groupOrder) {
        for (int item : groupedItems[g]) {
            result.push_back(item);
        }
    }
    
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> group(n);
    for (int i = 0; i < n; i++) cin >> group[i];
    vector<vector<int>> beforeItems(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        beforeItems[i].resize(k);
        for (int j = 0; j < k; j++) cin >> beforeItems[i][j];
    }
    vector<int> result = sortItems(n, m, group, beforeItems);
    if (result.empty()) {
        cout << "[]" << endl;
    } else {
        for (int item : result) cout << item << " ";
        cout << endl;
    }
    return 0;
}