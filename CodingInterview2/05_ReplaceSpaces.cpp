//
// Created by Silin Li on 16:05 01/26/2020.
// 

#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <cstring>
using namespace std;

namespace test5{

void ReplaceSpaces(char *string, int storage) {
    // check input
    assert(string);

    // count number of blanks
    int i = 0;
    int length = strlen(string);
    int num_blanks = 0;
    while (i < length) {
        if (isspace(string[i])) {
            ++num_blanks;
        }
        ++i;
    }

    // check storage, must be enough
    int new_length = length + num_blanks*2;
    if (storage < new_length + 1) { // pay attention to '\0'
        cerr << "no enough storage for %20" << endl;
        return;
    }

    // copy from end to start
    int index_origin = length;
    int index_new = new_length;
    while (index_new >= index_origin && index_origin >= 0) {
        if (isspace(string[index_origin])) {
            string[index_new--] = '0';
            string[index_new--] = '2';
            string[index_new--] = '%';
        }
        else {
            string[index_new--] = string[index_origin];
        }
        --index_origin;
    }

}

void run() {
    char str[12] = {'h', 'i', 't', ' ', 's', ' ', 'z', '\0'};
    cout << "len1: " << strlen(str) << endl;
    ReplaceSpaces(str, 12);
    cout << "len2: " << strlen(str) << endl;

    printf("%s", str);
}
}


int main(int argc, char **argv) {
    test5::run();
    return 0;
}

