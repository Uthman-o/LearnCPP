#include <cassert>
#include <iostream>
#include <queue>
#include <vector>


using namespace std;

class CourseScheduler{
public:
  bool canFinish(int n, const vector<vector<int>>& prerequisites) {
    std::vector<std::vector<int>> graph(n);

    vector<int> indegree(n,0);

    for (const auto& edge: prerequisites) {
      assert(edge.size() == 2);
      int course = edge[0];
      int prereq = edge[1];

      assert(course >= 0 && course < n);
    assert(prereq >= 0 && prereq < n);

      graph[prereq].push_back(course);
      indegree[course]++;
    }

    queue<int> q;

    //Courses with no prere taken immediately

    for (int i = 0; i<n ;++i){
      if(indegree[i] == 0){
        q.push(i);
      }
    }

    int completed = 0;

    while(!q.empty()) {
      int course = q.front();
      q.pop();

      completed++;

      // Taking this course may unlock other CourseScheduler
      for(int nextCourse : graph[course]){
        indegree[nextCourse]--;

        if(indegree[nextCourse] ==0){
          q.push(nextCourse);
        }
      }
    }
     return completed == n;
  }
};

int main(){
  CourseScheduler scheduler;

     // Example 1:
     // 0 -> 1
     assert(scheduler.canFinish(
         2,
         {{1, 0}}
     ) == true);

     // Example 2:
    // 0 -> 1
    // 1 -> 0
    // assert(scheduler.canFinish(
    //     2,
    //     {{1, 0}, {0, 1}}
    // ) == false);

  return 0;
}
