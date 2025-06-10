High-Level Approach (Sliding Window + Frequency Count)
Character Count:

You first count the frequency of all characters in string t using a hash array (hash[256]), where each character maps to its ASCII index.

Sliding Window:

You use two pointers l and r (left and right) to define the current window of string s.

Expand the right pointer r to include new characters into the window.

If the character s[r] is useful (i.e., its count in the hash is > 0), increase cnt (number of matched characters).

Decrease the count of s[r] in the hash regardless, because it's now in the window.

Shrink from Left:

Once all characters of t are found in the current window (cnt == t.length()), try to shrink the window from the left (l) to see if you can still keep it valid but smaller.

If removing a character s[l] from the window means the window is no longer valid (hash[s[l]] > 0 after increment), decrease cnt.

Track Minimum Window:

Keep track of the minimum length and starting index whenever a valid window is found.

Return Result:

If a valid window was found (startindex != -1), return the substring.

Otherwise, return an empty string.

Optimal code:(idea:whenever got the valid window shrink the window and try to get the minimun valid window)

class Solution {
public:
    string minWindow(string s, string t) {
        // Frequency map to count required characters from t
        int required[256] = {0};
        for (char ch : t) {
            required[ch]++;
        }

        int left = 0, right = 0;
        int minLen = INT_MAX;
        int startIndex = -1;
        int matchedCount = 0; // Total characters matched (including duplicates)
        int totalRequired = t.length();

        // Traverse the string s using sliding window
        while (right < s.length()) {
            // Include current character into the window
            if (required[s[right]] > 0) {
                matchedCount++;
            }
            required[s[right]]--;

            // When all required characters are matched
            while (matchedCount == totalRequired) {
                // Update minimum window if the current one is smaller
                int windowLen = right - left + 1;
                if (windowLen < minLen) {
                    minLen = windowLen;
                    startIndex = left;
                }

                // Try to shrink the window from the left
                required[s[left]]++;
                if (required[s[left]] > 0) {
                    matchedCount--;
                }
                left++;
            }

            right++;
        }

        // Return the result based on whether we found a valid window
        if (startIndex == -1) {
            return "";
        }
        return s.substr(startIndex, minLen);
    }
};
TC->O(2N)+O(M)
SC->O(256)

Similar problem:209. Minimum Size Subarray Sum
