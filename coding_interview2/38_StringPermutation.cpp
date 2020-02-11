//
// Created by Silin Li on 22:24 02/11/2020.
// 

#include <iostream>
#include "Sort.h"

using namespace std;

namespace test38{
void PermutationCore(char *str, char *begin) {
    if (*begin == '\0') {
        printf("%s\n", str);
    }
    else {
        for (char *ch = begin; *ch != '\0'; ++ch) {
            std::swap(*ch, *begin);
            PermutationCore(str, begin + 1);
            std::swap(*ch, *begin);
        }
    }
}

void Permutation(char *str) {
    if (!str)
        return;;
    PermutationCore(str, str);
}
// ====================测试代码====================
void Test(char* pStr)
{
    if(pStr == nullptr)
        printf("Test for nullptr begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    Permutation(pStr);

    printf("\n");
}
void run() {


    Test(nullptr);

    char string1[] = "";
    Test(string1);

    char string2[] = "a";
    Test(string2);

    char string3[] = "ab";
    Test(string3);

    char string4[] = "abc";
    Test(string4);

}
}

int main(int argc, char **argv) {
    test38::run();
    return 0;
}

