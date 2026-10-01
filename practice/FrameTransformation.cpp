#include <Eigen/Dense>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Edge {
    string to;
    Eigen::Matrix4d T;
};

class FrameTransform {
   private:
    unordered_map<string, vector<Edge>> graph_;

   public:
    void setFrame(const string& from, const string& to, const Eigen::Matrix4d& T_from_to) {
        graph_[from].push_back({to, T_from_to});
        graph_[to].push_back({from, T_from_to.inverse()});
    }

    bool getFrame(const string& from, const string& to, Eigen::Matrix4d& result) const {
        if (from == to) {
            result = Eigen::Matrix4d::Identity();
            return true;
        }

        if (!graph_.count(from) || !graph_.count(to)) {
            return false;
        }

        struct State {
            string frame;
            Eigen::Matrix4d T;
        };

        queue<State> q;
        unordered_set<string> visited;

        q.push({from, Eigen::Matrix4d::Identity()});
        visited.insert(from);

        while (!q.empty()) {
            State current = q.front();
            q.pop();

            for (const Edge& edge : graph_.at(current.frame)) {
                if (visited.count(edge.to)) continue;

                Eigen::Matrix4d T_from_next = edge.T * current.T;

                if (edge.to == to) {
                    result = T_from_next;
                    return true;
                }

                visited.insert(edge.to);

                q.push({edge.to, T_from_next});
            }
        }

        return false;
    }
};

int main() {
    FrameTransform tf;

    Eigen::Matrix4d T_map_base = Eigen::Matrix4d::Identity();
    T_map_base(0, 3) = 10;

    Eigen::Matrix4d T_base_lidar = Eigen::Matrix4d::Identity();
    T_base_lidar(0, 3) = 2;

    Eigen::Matrix4d T_lidar_camera = Eigen::Matrix4d::Identity();
    T_lidar_camera(1, 3) = 3;

    tf.setFrame("map", "base", T_map_base);
    tf.setFrame("base", "lidar", T_base_lidar);
    tf.setFrame("lidar", "camera", T_lidar_camera);

    Eigen::Matrix4d T_map_camera;

    bool found = tf.getFrame("map", "camera", T_map_camera);

    assert(found);

    cout << T_map_camera << endl;
    return 0;
}
