class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });

        stack<double> groups; // step 
        for (int i = 0; i < cars.size(); i++) {
            double step = double(double(target - cars[i].first) / double(cars[i].second));
            while (!groups.empty() && groups.top() <= step) {
                groups.pop();
            }
            groups.push(step);
        }

        return groups.size();
    }
};
