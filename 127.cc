#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using std::cout;
using std::endl;
using std::queue;
using std::string;
using std::unordered_set;
using std::vector;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.cbegin(), wordList.cend());
        unordered_set<string> visited;
        queue<string> que;
        que.push(beginWord);
        visited.insert(beginWord);
        int length = 1;
        while (!que.empty()) {
            queue<string> q;
            while (!que.empty()) {
                string word = que.front();
                que.pop();
                if (word == endWord)
                    return length;
                for (size_t pos = 0; pos < word.size(); ++pos) {
                    string trans = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        trans[pos] = c;
                        if (visited.find(trans) == visited.end() && wordSet.find(trans) != wordSet.end()) {
                            visited.insert(trans);
                            q.push(trans);
                        }
                    }
                }
            }
            que = q;
            ++length;
        }
        return 0;
    }
};

int main() {
    vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    cout << Solution().ladderLength("hit", "cog", wordList) << endl;
    return 0;
}
