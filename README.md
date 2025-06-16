# Leetcode-87.-Scramble-String
# 🔀 Scramble String Problem - README

## 📘 Problem Statement

Given two strings `s1` and `s2` of the same length, determine if `s2` is a scrambled version of `s1`.

A **scrambled string** is defined using binary trees. A string can be partitioned recursively into two non-empty substrings and swapped any number of times. The goal is to check if by performing such operations, we can transform `s1` into `s2`.

---

## 💡 Intuition

We want to check if `s1` can be split into parts that, when scrambled (possibly recursively), can result in `s2`. At each index `i`, we check two possibilities:

1. 🔁 **Not Swapped:** Left of `s1` matches left of `s2`, right with right.
2. 🔀 **Swapped:** Left of `s1` matches right of `s2`, right with left.

If either case is true for any index `i`, `s1` can be transformed into `s2`.

---

## 🚀 Approaches

### 1️⃣ Pure Recursive Approach (without memoization)

**Logic:**

* Check all split positions from 1 to `n-1`.
* For each split, recurse on both parts with and without swapping.
* Base case: if `s1 == s2`, return true.

**Drawback:**

* High time complexity due to redundant recursive calls.

**Time Complexity:** Exponential (worst-case O(4^n))
**Space Complexity:** O(n) (recursion stack)

---

### 2️⃣ Recursive + Memoization (Top-down DP)

**Logic:**

* Same recursive logic as above.
* Memoize results for `s1 + '-' + s2` in a hashmap to avoid recomputation.
* Greatly optimizes performance by reducing repeated calculations.

**Time Complexity:** O(n^4)

* There are O(n^2) possible pairs of substrings.
* Each pair may need up to O(n) time to compute.

**Space Complexity:** O(n^3)

* For the memoization map and recursion stack.

---

## 🧪 Example

**Input:**
`s1 = "great"`, `s2 = "rgeat"`

**Output:** `true`

**Explanation:**

* Swap "gr" and "eat" → "eatgr"
* Further swap "ea" and "tgr" → "rgeat"
* Result matches `s2`

---

## 📊 Comparison

| Approach                | Time Complexity | Space Complexity | Suitable For      |
| ----------------------- | --------------- | ---------------- | ----------------- |
| Pure Recursion          | Exponential     | O(n)             | Small inputs only |
| Memoized Recursion (DP) | O(n^4)          | O(n^3)           | Optimal solution  |

---

## ✍️ Author

**Ridham Garg**

🎓 B.Tech Computer Engineering, Thapar University, Patiala

🆔 Roll Number: 102203014

---

## 🎉 Conclusion

This classic problem shows how recursion with memoization can optimize brute force methods significantly. It also builds understanding of string manipulation, recursion trees, and dynamic programming fundamentals.
