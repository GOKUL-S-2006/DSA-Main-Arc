📘 C++ Floating Point Precision & Rounding (CP Guide)
🔹 1. Printing Decimal Values (setprecision)
✅ Syntax
cout << fixed << setprecision(n) << value;
🔍 What it does

fixed → prints in normal decimal format (not scientific)

setprecision(n) → prints n digits after decimal

💡 Example
#include <bits/stdc++.h>
using namespace std;

int main() {
    double x = 3.141592653589793;
    cout << fixed << setprecision(4) << x << endl;
}
📌 Output
3.1416
🔹 2. Important Concept

👉 setprecision does NOT change the variable

double x = 3.141592653589793;

cout << fixed << setprecision(2) << x << endl; // 3.14
cout << x << endl; // still 3.141592653589793
🔹 3. Rounding a Variable (Actual Value Change)
✅ Trick
x = round(x * 100) / 100;
🧠 Idea

👉 Shift → Round → Shift back

🔍 Step-by-step

For x = 3.1415926535

Multiply:

x * 100 = 314.15926535

Round:

round(...) = 314

Divide:

314 / 100 = 3.14
🔹 4. General Formula

To keep n decimal places:

x = round(x * pow(10, n)) / pow(10, n);
⚡ Examples
🔸 2 decimal places
x = round(x * 100) / 100;
🔸 4 decimal places
x = round(x * 10000) / 10000;
🔹 5. When to Use What
Situation	Use
Only need formatted output	setprecision
Need to modify value	round() trick
Competitive programming output	fixed + setprecision
🔹 6. Competitive Programming Tip 🚀

Always use this for decimal output:

ios::sync_with_stdio(false);
cin.tie(NULL);

cout << fixed << setprecision(6);
🔹 7. Common Mistakes ❌

Using setprecision thinking it changes value ❌

Forgetting fixed → weird scientific output ❌

Using rounding when only printing is needed ❌

🔹 8. Bonus: Pi Constant
double pi = 3.141592653589793;

or

#include <cmath>
double pi = M_PI; // may not work everywhere
🔥 Final Summary

setprecision(n) → controls output only

round(x * 10^n) / 10^n → modifies value

Use fixed to avoid scientific notation

In CP → formatting matters a lot (avoid WA)
