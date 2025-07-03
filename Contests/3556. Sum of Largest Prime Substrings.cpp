class Solution {
public:
  
    bool isPrime(long long n) {
        if (n < 2) return false;
        for (long long d = 2; d * d <= n; ++d) {
            if (n % d == 0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        set<long long> primes;

        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                long long num = stoll(s.substr(i, j-i+1));
                if (isPrime(num)) {
                    primes.insert(num);
                }
            }
        }

        long long ans = 0;
        int picked = 0;
        for (auto it = primes.rbegin(); it != primes.rend() && picked < 3; ++it) {
            ans += *it;
            picked++;
        }

        return ans;
    }
};
1. Prime Check Function (isPrime)
cpp
Copy
Edit
bool isPrime(long long n)
Checks if a number n is prime by trial division.

Returns false if divisible by any number from 2 to sqrt(n).

2. Set to Store Unique Primes
cpp
Copy
Edit
set<long long> primes;
Stores only unique primes found from the substrings.

Automatically keeps them sorted in ascending order.

3. Iterate All Substrings of s
cpp
Copy
Edit
for (int i = 0; i < s.size(); ++i) {
    for (int j = i; j < s.size(); ++j) {
        long long num = stoll(s.substr(i, j - i + 1));
For every starting index i, extract all substrings ending at j.

Use substr(i, j - i + 1) to get every possible contiguous substring.

Convert the substring into an integer using stoll.

4. Check if the Number is Prime
cpp
Copy
Edit
if (isPrime(num)) {
    primes.insert(num);
}
If the number is prime, insert it into the set.

5. Sum the 3 Largest Primes
cpp
Copy
Edit
long long ans = 0;
int picked = 0;
for (auto it = primes.rbegin(); it != primes.rend() && picked < 3; ++it) {
    ans += *it;
    picked++;
}
Use reverse iterator over the set to get the largest values.

Add the top 3 largest primes to ans.

6. Return the Result
cpp
Copy
Edit
return ans;
Return the total sum of the 3 largest prime substrings.


Total Time Complexity: O(n² × √M) where M is max number value (up to ~10⁷)
Space Complexity: O(k) where k = number of unique prime substrings (typically much less than n²)


