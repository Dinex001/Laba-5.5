#include <iostream>

using namespace std;

int f(const int n, const int level, int& depth);
int S(const int p, const int q, int& depth);

int main()
{
    int p;      // нижня межа суми
    int q;      // верхня межа суми
    int depth = 0;  // глибина рекурсії (найбільша серед усіх викликів f)

    cout << "p = "; cin >> p;
    cout << "q = "; cin >> q;
    cout << endl;

    int result = S(p, q, depth);

    cout << endl;
    cout << "S(" << p << ", " << q << ") = " << result << endl;
    cout << "depth = " << depth << endl;

    return 0;
}

// рекурсивна функція f(n):
//   n % 10,   якщо n % 10 > 0
//   0,        якщо n == 0
//   f(n / 10) в іншому випадку
// level - поточний рівень рекурсії, depth - глибина рекурсії
int f(const int n, const int level, int& depth)
{
    if (level > depth)
        depth = level;

    cout << "  level = " << level << endl;

    if (n % 10 > 0)
        return n % 10;
    else
        if (n == 0)
            return 0;
        else
            return f(n / 10, level + 1, depth);
}

// сума f(i) для i від p до q
int S(const int p, const int q, int& depth)
{
    int s = 0;
    for (int i = p; i <= q; i++)
    {
        cout << "i = " << i << endl;
        s += f(i, 1, depth);
    }
    return s;
}