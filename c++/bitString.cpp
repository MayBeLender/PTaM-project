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

    if (in_str.size() > length) {
        throw std::length_error("Input string length more than BitString length");
        //exit(EXIT_FAILURE);
    }

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
    if (length != b.length) {
        throw std::length_error("BitStrings have different lengths");
        //exit(EXIT_FAILURE);
    }

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

    if (s.size() > length) {
        throw std::length_error("Input string length more than BitString length");
        exit(EXIT_FAILURE);
    }

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
    char_vec.clear();
    char_vec.shrink_to_fit();
}

//Перегрузка Операторов
BitString &BitString::operator=(const BitString &other) {
    if (this == &other) { return *this; }

    char_vec = other.char_vec;
    return *this;
}

BitString BitString::operator<<(int count) {
    if (count < 0) { return(*this >> -count); }

    if (count >= length) {
        return BitString(string(length,'0'));
    }

    string result;
    for (int i = count; i < length; i++) {
        result += char_vec[i];
    }

    return BitString(result + string(count,'0'));
}

BitString BitString::operator>>(int count) {
    if (count < 0) { return(*this << -count); }

    if (count >= length) {
        return BitString(string(length,'0'));
    }

    string result;
    for (int i = 0; i < length - count; i++) {
        result += char_vec[i];
    }

    return BitString(string(count,'0') + result);
}

BitString BitString::operator&(BitString &other) {
    if (length != other.length) {
        throw std::length_error("BitStrings have different lengths");
        //exit(EXIT_FAILURE);
    }

    string result;

    for (int i = 0; i < length; i++) {
        result.push_back(char_vec[i] & other.char_vec[i]);
    }

    return BitString(result);
}

char BitString::operator[](int index) {
    if (index >= length) {
        throw std::out_of_range("Index is out of BitString vector range");
        //exit(EXIT_FAILURE);
    }

    return char_vec[index];
}
