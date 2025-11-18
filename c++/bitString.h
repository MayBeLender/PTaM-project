#pragma once
#include <vector>
#include <string>
using namespace std;

class BitString {
    unsigned int length = 8;
private:
    vector<char> char_vec;
public:
    BitString();
    BitString(string in_str);
    BitString(const BitString& other);
    void clear();
    void print();
    void input();
    BitString conjaction(BitString b);
    BitString& operator=(const BitString& other);
    BitString operator<<(int count);
    BitString operator>>(int count);
    BitString operator&(BitString& other);
    char operator[](int index);

    ~BitString();
};

//=, <<, >>, &, [].