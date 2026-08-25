// class Solution {
// public:
//     vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
//         vector<int> res;
//         for(int i=0;i<queries.size();i++){
//             int mini = INT_MAX;
//             for(int j=0;j<intervals.size();j++){
//                 if(queries[i]==intervals[j][0] || queries[i]==intervals[j][1]){
//                     int length = intervals[j][1]-intervals[j][0]+1 ; 
//                     mini = min(mini, length);
//                 }
//             }
//             if(mini==INT_MAX){
//                 res.push_back(-1);

//             }
//             else{
//                 res.push_back(mini);
//             }
//         }
//         return res;
//     }
// };
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int q = queries.size();
        
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }
        
        sort(intervals.begin(), intervals.end());
        sort(sortedQueries.begin(), sortedQueries.end());
    
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        vector<int> res(q, -1);
        int i = 0; 
        
        for (auto& qPair : sortedQueries) {
            int queryVal = qPair.first;
            int queryIdx = qPair.second;
            
            while (i < n && intervals[i][0] <= queryVal) {
                int size = intervals[i][1] - intervals[i][0] + 1;
                minHeap.push({size, intervals[i][1]});
                i++;
            }
            

            while (!minHeap.empty() && minHeap.top().second < queryVal) {
                minHeap.pop();
            }

            if (!minHeap.empty()) {
                res[queryIdx] = minHeap.top().first;
            }
        }
        
        return res;
    }
};
