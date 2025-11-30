#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;

bool linearsearch(string s[], string key, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (key == s[i])
            return true;
    }
    return false;
}

bool binarysearh(string s[], string key, int n)
{
    int lo = 0, hi = n - 1;

    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (s[mid] == key)
            return true;
        else if (s[mid] < key)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter no of movie: ";
    cin >> n;

    string s[10];

    cout << "Enter movie names: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    string key;

    cout << "Enter movie to search: ";
    cin >> key;

    auto start1 = chrono::high_resolution_clock::now();

    if (linearsearch(s, key, n))
        cout << "Result found";
    else
        cout << "Result not found";

    auto end1 = chrono::high_resolution_clock::now();
    auto timeLinear = chrono::duration_cast<chrono::microseconds>(end1 - start1).count();

    // ------------------ Binary Search ------------------
    sort(s, s + n);
    auto start2 = chrono::high_resolution_clock::now();
    if (binarysearh(s, key, n))
        cout << "Result found ";
    else
        cout << "result not found";
    auto end2 = chrono::high_resolution_clock::now();
    auto timeBinary = chrono::duration_cast<chrono::microseconds>(end2 - start2).count();
    cout << "\nTimre: " << timeLinear << "  " << timeBinary;

    return 0;
}