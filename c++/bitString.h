#pragma once
#include <vector>
#include <string>
using namespace std;

class BitString {
    unsigned int length = 8;
    vector<char> char_vec;

public:
    BitString();
    BitString(string in_str);
    BitString(const BitString& other);
    void clear();
    void print();
    void input();
    BitString conjaction(BitString b);
    ~BitString();
};