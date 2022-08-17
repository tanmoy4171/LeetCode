class Solution {
public:
    string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    string convertToMorse(string s) {
        string res;
        for (char c: s) res.append(morse[c - 'a']);
        return res;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> seen;
        for (string s: words) seen.insert(convertToMorse(s));
        return seen.size();
    }
};