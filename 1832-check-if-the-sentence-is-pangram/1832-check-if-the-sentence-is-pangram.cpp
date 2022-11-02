class Solution {
public:
    bool checkIfPangram(string sentence) {
        return set<char>(begin(sentence), end(sentence)).size() == 26;
    }
};