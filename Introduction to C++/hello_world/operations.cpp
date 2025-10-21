#include "std_lib_facilities.h"

int main() {
    // ---- int and double examples ----
    int a = 5, b = 2;
    double x = 5.0, y = 2.0;

    cout << "Integers: a = " << a << ", b = " << b << "\n";
    cout << "a + b = " << (a + b) << "\n";
    cout << "a - b = " << (a - b) << "\n";
    cout << "a * b = " << (a * b) << "\n";
    cout << "a / b = " << (a / b) << " (integer division)\n";
    cout << "a % b = " << (a % b) << " (remainder)\n";
    cout << "++a = " << (++a) << " (increment)\n";
    cout << "--b = " << (--b) << " (decrement)\n\n";

    cout << "Doubles: x = " << x << ", y = " << y << "\n";
    cout << "x + y = " << (x + y) << "\n";
    cout << "x - y = " << (x - y) << "\n";
    cout << "x * y = " << (x * y) << "\n";
    cout << "x / y = " << (x / y) << " (floating division)\n";
    cout << "sqrt(x) = " << sqrt(x) << "\n\n";

    // ---- comparisons ----
    cout << "Comparisons (a=6, b=1 now):\n";
    cout << "a == b? " << (a == b) << "\n";
    cout << "a != b? " << (a != b) << "\n";
    cout << "a > b? "  << (a > b) << "\n";
    cout << "a >= b? " << (a >= b) << "\n";
    cout << "a < b? "  << (a < b) << "\n";
    cout << "a <= b? " << (a <= b) << "\n\n";

    // ---- char examples ----
    char c1 = 'A';
    char c2 = c1 + 1; // moves forward in ASCII
    cout << "Chars: c1 = " << c1 << ", c2 = " << c2 << "\n";
    cout << "c1 < c2? " << (c1 < c2) << "\n\n";

    // ---- bool examples ----
    bool flag1 = true, flag2 = false;
    cout << "Booleans: flag1 = " << flag1 << ", flag2 = " << flag2 << "\n";
    cout << "flag1 && flag2 = " << (flag1 && flag2) << "\n";
    cout << "flag1 || flag2 = " << (flag1 || flag2) << "\n";
    cout << "!flag1 = " << (!flag1) << "\n\n";

    // ---- string examples ----
    string s1 = "Hello";
    string s2 = "World";
    cout << "Strings: s1 = " << s1 << ", s2 = " << s2 << "\n";
    cout << "s1 + s2 = " << (s1 + s2) << " (concatenation)\n";
    s1 += "!";
    cout << "s1 after += \"!\" = " << s1 << "\n";
    cout << "s1 == s2? " << (s1 == s2) << "\n";
    cout << "s1 != s2? " << (s1 != s2) << "\n";
    cout << "s1 < s2? "  << (s1 < s2) << " (lexicographic compare)\n";

    return 0;
}
