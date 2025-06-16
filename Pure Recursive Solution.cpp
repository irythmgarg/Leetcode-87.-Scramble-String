class Solution {
public:
    bool isScramble(string s1, string s2) {
        // If both strings are equal, no need to scramble
        if(s1 == s2)
            return true;

        int n = s1.length();

        // If lengths are not the same, it can't be a valid scramble
        if(s1.length() != s2.length()) {
            return false;
        }

        // Try all possible split positions
        for(int i = 1; i < n; i++) {
            // Case 1: Check if swapping the substrings gives a match
            bool swaped = isScramble(s1.substr(0, i), s2.substr(n - i, i)) &&
                           isScramble(s1.substr(i, n - i), s2.substr(0, n - i));

            // Case 2: Check if NOT swapping the substrings gives a match
            bool notswaped = isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                              isScramble(s1.substr(i, n - i), s2.substr(i, n - i));

            // If either scenario results in a match, return true
            if(swaped || notswaped)
                return true;
        }

        // If no valid scenario found, return false
        return false;
    }
};
