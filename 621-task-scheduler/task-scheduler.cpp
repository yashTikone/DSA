class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = tasks.size();

        unordered_map<char, int> freq;
        unordered_map<char, int> free;

        for (int i = 0; i < sz; i++) {
            freq[tasks[i]]++;
            free[tasks[i]] = 1;
        }

        priority_queue<pair<int, char>> pq;

        for (auto i : freq) {
            pq.push({i.second, i.first});
        }

        int seat = 1;

        while (!pq.empty()) {
            vector<pair<int, char>> pulled;
            bool executed = false;

            while (!pq.empty()) {
                pair<int, char> p = pq.top();
                pq.pop();

                int fr = p.first;
                char child = p.second;

                if (free[child] <= seat) {
                    if (fr > 1) {
                        pq.push({fr - 1, child});
                        free[child] = seat + n + 1;
                    }

                    executed = true;
                    break;
                } 
                else {
                    pulled.push_back(p);
                }
            }

            for (auto p : pulled) {
                pq.push(p);
            }

            seat++;
        }

        return seat - 1;
    }
};