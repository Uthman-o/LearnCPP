#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class CourseSchedule {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // prequisites = {course, prereq}

        for (const auto& edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];

            graph[prereq].push_back(course);
            indegree[course]++;
        }

        // Print graph
        cout << "\nGraph:\n";

        for (int i = 0; i < numCourses; ++i) {
            cout << i << " -> ";
            for (int course : graph[i]) {
                cout << course << " ";
            }
            cout << endl;
        }

        // Print indegrees
        cout << "\nIndegrees:\n";
        for (int i = 0; i < numCourses; ++i) {
            cout << "Course " << i << ": " << indegree[i] << endl;
        }

        queue<int> q;

        // Courses that can be taken immediately;
        for (int course = 0; course < numCourses; ++course) {
            if (indegree[course] == 0) {
                q.push(course);
            }
        }

        int completed = 0;

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            completed++;

            // Courses affected by completing this courses

            for (int nextCourse : graph[course]) {
                indegree[nextCourse]--;

                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        cout << "Completed " << completed << endl;
        return completed == numCourses;
    }
};

int main() {
    CourseSchedule C;

    int numCourses = 4;
    // vector<vector<int>> courses{{0, 1}, {1, 2}, {2, 0}, {3, 1}, {3, 2}};
    vector<vector<int>> courses{{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    bool result = C.canFinish(numCourses, courses);
    cout << boolalpha << result << endl;

    {
        vector<vector<int>> courses{};
        bool result = C.canFinish(4, courses);

        cout << boolalpha << result << endl;
    }

    {
        vector<vector<int>> courses{};
        bool result = C.canFinish(1, courses);

        cout << boolalpha << result << endl;
    }

    return 0;
}
