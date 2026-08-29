class Solution {
public:

    bool dfs(int course,
             vector<vector<int>>& graph,
             vector<int>& state,
             stack<int>& st) {

        // Cycle detected
        if (state[course] == 1)
            return false;

        // Already completely processed
        if (state[course] == 2)
            return true;

        // Currently visiting
        state[course] = 1;

        for (int next : graph[course]) {

            if (!dfs(next, graph, state, st))
                return false;
        }

        // Completely processed
        state[course] = 2;

        // Add to stack after processing neighbors
        st.push(course);

        return true;
    }


    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        // Build graph
        for (auto& p : prerequisites) {

            int course = p[0];
            int prerequisite = p[1];

            graph[prerequisite].push_back(course);
        }

        vector<int> state(numCourses, 0);
        stack<int> st;

        // DFS every course
        for (int course = 0; course < numCourses; course++) {

            if (state[course] == 0) {

                if (!dfs(course, graph, state, st))
                    return {};
            }
        }

        // Get topological ordering
        vector<int> answer;

        while (!st.empty()) {

            answer.push_back(st.top());
            st.pop();
        }

        return answer;
    }
};