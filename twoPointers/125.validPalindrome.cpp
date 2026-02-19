//A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
//  it reads the same forward and backward. Alphanumeric characters include letters and numbers.

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;

    while (i < j) {

        // Skip non-alphanumeric from left
        while (i < j && !isalnum(s[i])) i++;

        // Skip non-alphanumeric from right
        while (i < j && !isalnum(s[j])) j++;

        // Compare lowercase characters
        if (tolower(s[i]) != tolower(s[j]))
            return false;

        i++;
        j--;
    }

    return true;
}

int main() {
    string s;
    getline(cin, s);

    if (isPalindrome(s))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
