class Solution {
public:

    bool dfs(int course, vector<vector<int>>& graph,
             vector<int>& state) {

        // Currently visiting this node
        if (state[course] == 1)
            return false;

        // Already completely processed
        if (state[course] == 2)
            return true;

        // Mark as currently visiting
        state[course] = 1;

        for (int next : graph[course]) {

            if (!dfs(next, graph, state))
                return false;
        }

        // Completely processed
        state[course] = 2;

        return true;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        // Build graph
        for (auto& prerequisite : prerequisites) {

            int course = prerequisite[0];
            int pre = prerequisite[1];

            graph[pre].push_back(course);
        }

        vector<int> state(numCourses, 0);

        for (int course = 0; course < numCourses; course++) {

            if (!dfs(course, graph, state))
                return false;
        }

        return true;
    }
};