// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         stack<int> temp;
//         vector<int> res(temperatures.size(), 0);
//         for(int i=0;i<temperatures.size();i++){
//             for(int j=i+1;j<temperatures.size();j++){
//                 if(temperatures[i]<temperatures[j]){
//                     int result = j - i;
//                     res[i] = result;
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top(); st.pop();
                res[idx] = i - idx;
            }
            st.push(i);
        }

        return res;        
    }
};