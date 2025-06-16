// 🧠 Memoized Recursive Approach to check if s2 is a scrambled string of s1
class Solution {
public:
    unordered_map<string, bool> mp; // Memoization map to store already computed results

    bool isScramble(string s1, string s2) {
        // ✅ Base case: if both strings are already equal
        if (s1 == s2)
            return true;

        // 🔑 Form a unique key using both strings for memoization
        string key = s1 + "-" + s2;

        // 📦 Return cached result if already computed
        if (mp.find(key) != mp.end())
            return mp[key];

        int n = s1.length();

        // ❌ If lengths differ, s2 can't be a scrambled version of s1
        if (n != s2.length())
            return mp[key] = false;

        // 🪓 Try all possible split positions
        for (int i = 1; i < n; i++) {
            // 🔁 Check for scrambled match with swap
            bool swapped = isScramble(s1.substr(0, i), s2.substr(n - i, i)) &&
                           isScramble(s1.substr(i, n - i), s2.substr(0, n - i));

            // 🔁 Check for scrambled match without swap
            bool notSwapped = isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                              isScramble(s1.substr(i, n - i), s2.substr(i, n - i));

            // ✅ If either is true, return and cache the result
            if (swapped || notSwapped)
                return mp[key] = true;
        }

        // 🚫 No valid scramble match found
        return mp[key] = false;
    }
};
