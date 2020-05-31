/**
DFS can be used to detect cycles in a graph.

There is a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that is from a node to itself (self-loop) or one of its ancestors in the tree produced by DFS.

For a disconnected graph, Get the DFS forest as output (for loop on nodes). To detect cycle, check for a cycle in individual trees by checking back edges.

how to know if edge is back edge? keep track of current stack of nodes made by DFS by using recStack vector. 

1- Each node we visit, mark it visited and mark it as in the recStack.
2- loop on children of the current node
3- if the child is visited before, check if it is in the recStack, if it is, this means that we have edge from it to an ancestor of current node, and an edge from current node to it, i.e cycle so return 1.

4- if it is not visited, dfs on it and check if it returns 1 then return 1, i.e cycle so no need to continue.

5- remove node from the stack because it has finished all its edges so no edge from it no anothe edge now.

Note that we can visit a node twice here for example edge 1 to 0 we will first visit 0 and then visit 1 then 0, so we've visited 0 twice, first one we mark it, second one we check if it is in the recStack but it will not be in it because no edge from it to 1 so no cycle.
*/

bool detectCycle(vector<vector<int>>& graph,vector<bool>& visited, vector<bool>& recStack, int node) {
    visited[node] = true;
    recStack[node] = true;

    for (auto child : graph[node]) {
        if (!visited[child]) {
            if (detectCycle(graph, visited, recStack, child))
                return 1;

        }else if(recStack[child])
            return 1;
    }
    recStack[node] = false;
    return 0;
}
