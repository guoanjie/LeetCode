#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::queue;
using std::string;
using std::unordered_set;
using std::vector;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> words;
        vector<bool> used(wordList.size(), false);
        words.push(make_pair(beginWord, 1));
        while (!words.empty()) {
            auto curr = words.front();
            words.pop();
            for (size_t i = 0; i < wordList.size(); ++i) {
                if (used[i])
                    continue;
                if (canTransform(curr.first, wordList[i])) {
                    if (wordList[i] == endWord)
                        return curr.second + 1;
                    words.push(make_pair(wordList[i], curr.second + 1));
                    used[i] = true;
                }
            }
        }
        return 0;
    }
private:
    bool canTransform(string beginWord, string endWord) {
        int count = 0;
        for (int i = 0; i < beginWord.size(); ++i) {
            if (beginWord[i] != endWord[i])
                ++count;
            if (count > 1)
                return false;
        }
        return count == 1;
    }
};

int main() {
    vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    cout << Solution().ladderLength("hit", "cog", wordList) << endl;
    return 0;
}
