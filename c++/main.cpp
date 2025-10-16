#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void printLine(vector<char> num) {
    //cout << endl;
    for (char x : num) {
        cout << x;
    }
}

bool isRightChar(char simbol) {
    return (simbol == '0' || simbol == '1');
}

void addZeros(vector<char>* num, int count) {
    for (int i = 0; i < count; i++) {
        num->push_back('0');
    }
}

vector<char> getNum(size_t size) {
    string s;
    cin >> s;

    if (s.size() > size) { exit(EXIT_FAILURE); }

    vector<char> result;

    addZeros(&result, size - s.size());

    for (int i = 0; i < s.size(); i++) {
        if (!isRightChar(s[i])) { exit(EXIT_FAILURE); }
        result.push_back(s[i]);
    }

    return result;
}

vector<char> charConjunction(vector<char> num0, vector<char> num1) {
    vector<char> result;
    for (size_t i = 0; i < num0.size(); i++) {
        result.push_back(num0[i] & num1[i]);
    }
    return result;
}

int main()
{
    vector<char> firstNum = getNum(8);
    vector<char> secondNum = getNum(8);
    
    vector<char> result = charConjunction(firstNum, secondNum);
    printLine(result);
}