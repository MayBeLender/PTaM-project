#include "bitString.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isRightChar(char simbol) {
    return (simbol == '0' || simbol == '1');
}

BitString::BitString() {
    clear();

    for (int i = 0; i < length; i++) {
        char_vec.push_back('0');
    }
}

BitString::BitString(string in_str) {
    clear();

    if (in_str.size() > length) { exit(EXIT_FAILURE); }

    for (int i = 0; i < in_str.size(); i++) {
        if (isRightChar(in_str[i])) {
            char_vec.push_back(in_str[i]);
        }
        else {
            char_vec.push_back('0');
        }
    }

    for (int i = 0; i < length - in_str.size(); i++) {
        char_vec.push_back('0');
    }
}

BitString::BitString(const BitString& other) {
    char_vec = other.char_vec;
}

BitString BitString::conjaction(BitString b) {
    if (length != b.length) { exit(EXIT_FAILURE); }

    string result;

    for (int i = 0; i < length; i++) {
        result.push_back(char_vec[i] & b.char_vec[i]);
    }

    return BitString(result);
}

void BitString::clear() {
    char_vec.clear();
}

void BitString::print() {
    for (char a : char_vec) {
        cout << a;
    }
    cout << endl;
}

void BitString::input() {
    string s;
    cin >> s;

    clear();

    if (s.size() > length) { exit(EXIT_FAILURE); }

    for (int i = 0; i < s.size(); i++) {
        if (isRightChar(s[i])) {
            char_vec.push_back(s[i]);
        }
        else {
            char_vec.push_back('0');
        }
    }

    for (int i = 0; i < length - s.size(); i++) {
        char_vec.push_back('0');
    }
}

BitString::~BitString() {
    //delete& char_vec;
    char_vec.clear();
    char_vec.shrink_to_fit();
}