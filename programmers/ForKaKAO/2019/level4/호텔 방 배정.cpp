#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> rooms;

long long find(long long num) {
    if (rooms[num] == 0) return num; // 방이 비어있으면 바로 배정하도록 return
    else return rooms[num] = find(rooms[num]); // 방이 비어있지 않으면 빈방을 찾으면서 가리키는 방 update
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for (int i = 0; i < room_number.size(); i++) {
        long long want = find(room_number[i]);
        answer.push_back(want);
        rooms[want] = want + 1; // 다음 방을 가리키도록 update
    }
    return answer;
}


// #include <string>
// #include <vector>

// using namespace std;

// vector<long long> solution(long long k, vector<long long> room_number) {
//     vector<long long> answer(room_number.size());
//     vector<bool> isUsed(k, false);
    
//     for (int i = 0; i < room_number.size(); i++) {
//         long long want = room_number[i];
//         if (!isUsed[want - 1]) {
//             isUsed[want - 1] = true;
//             answer[i] = want;
//         } else {
//             while (true) {
//                 if (!isUsed[want - 1]) {
//                     isUsed[want - 1] = true;
//                     answer[i] = want;
//                     break;
//                 }
//                 want++;
//             }
//         }
//     }
//     return answer;
// }