#include <bits/stdc++.h>
using namespace std;

bool solve1(string s) {
    if (!isalpha(s[0])) {
        return false;
    }
   
    for (int i = 1; i < s.length(); i++) {
        if (isalpha(s[i]) || isdigit(s[i])) {
            continue;
        } else {
            return false;
        }
    }
   
    return true;
}

bool solve2(string s) {
    return s == "<=";
}

bool solve3(string s) {
    return s == "<>";
}

bool solve4(string s) {
    return s == "<";
}

bool solve5(string s) {
    return s == "=";
}

bool solve6(string s) {
    return s == ">=";
}

bool solve7(string s) {
    return s == ">";
}

bool solve8(string s) {
    int dot = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            continue;
        } else if (s[i] == '.') {
            dot++;
            continue;
        } else {
            return false;
        }
    }
   
    return dot == 1;  
}

int main() {
    string s;
    cin >> s;

    int l = 0;
    int r = 0;

    while (r < s.length() && s[r] != '<' && s[r] != '>' && s[r] != '=') {
        r++;
    }

    bool flag1 = solve1(s.substr(l, r));
    if (!flag1) {
        cout << "not accepted" << endl;
        return 0;
    } else {
        cout << "IDENTIFIER" << endl;
    }

    l = r;
    while (r < s.length() && !isdigit(s[r]) && s[r] != '.') {
        r++;
    }

    if (l == r) {
        cout << "not accepted" << endl;
        return 0;
    }

    string comparator = s.substr(l, r - l);
    if (comparator == "<=") {
        cout << "LE" << endl;
    } else if (comparator == "<>") {
        cout << "NE" << endl;
    } else if (comparator == "<") {
        cout << "LT" << endl;
    } else if (comparator == ">=") {
        cout << "GE" << endl;
    } else if (comparator == ">") {
        cout << "GT" << endl;
    } else if (comparator == "=") {
        cout << "EQ" << endl;
    } else {
        cout << "not accepted" << endl;
        return 0;
    }

    l = r;
    if (solve8(s.substr(l))) {
        cout << "Real Number" << endl;
    } else {
        cout << "not accepted" << endl;
        return 0;
    }

    cout << "accepted" << endl;
    return 0;
}