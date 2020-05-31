/**
The idea is to find if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses. Topological sort is only possible if the graph is DAG(directed acyclec graph). So we write code to check if the graph is DAG or not by using function that checks if the graph has cycles or not, we also handle the case if the graph is not connected by for loop, if all graphs are DAG, then we return true that TopSort is valid, otherwise, we return false.
*/

class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> vis;
    vector<bool> recStack;
    
    enum Status {
    PATH, CYCLE
};

Status detectCycle(int node) {
    vis[node] = true;
    recStack[node] = true;

    for (auto child : graph[node]) {
        if (!vis[child]) {
            if (detectCycle(child) == CYCLE)
                return CYCLE;

        }else if(recStack[child])
            return CYCLE;
    }
    recStack[node] = false;
    return PATH;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);
        vis = vector<bool>(numCourses);
        recStack =  vector<bool>(numCourses);
        
        for (auto preq : prerequisites)
            graph[preq[0]].push_back(preq[1]);
        
        for (int i=0;i<numCourses;i++) {
            if (!vis[i])
                if (detectCycle(i))
                    return false;
        }
        
        return true;
    }
};
