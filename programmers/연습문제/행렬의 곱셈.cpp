#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int arr1ColSize = arr1.front().size();
    int arr1RowSize = arr1.size();
    int arr2ColSize = arr2.front().size();
    
    for (int i = 0; i < arr1RowSize; i++) {
        vector<int> temp;
        for (int k = 0; k < arr2ColSize; k++) {
            int sum = 0;
            for (int j = 0; j < arr1ColSize; j++) {
                sum += arr1[i][j] * arr2[j][k];
            }
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }
    return answer;
}