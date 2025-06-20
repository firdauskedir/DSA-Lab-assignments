#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> visited = {beginWord};

        while (!q.empty()) {
            auto [word, level] = q.front(); q.pop();
            for (int i = 0; i < word.length(); ++i) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    temp[i] = c;
                    if (temp == endWord) return level + 1;
                    if (dict.count(temp) && !visited.count(temp)) {
                        visited.insert(temp);
                        q.push({temp, level + 1});
                    }
                }
            }
        }

        return 0;
    }
};

int main() {
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    Solution sol;
    cout << "Length of shortest transformation: " << sol.ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}
