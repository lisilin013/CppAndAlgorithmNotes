//
// Created by Silin Li on 17:32 01/30/2020.
// 
#include "List.h"

using namespace std;
namespace test18{
void run() {
    Algorithm::List<int> list;
    for (int i = 0; i < 10; ++i) {
        list.insertByPose(i, i);
    }
    cout << "original list:\n";
    list.traversal();

    cout << "eraseByPose node: " << endl;
    auto node = list.getNodeByValue(9);
    list.eraseByNodeAdvanced(node);//O(1)
    list.traversal();


}
}

int main(int argc, char **argv) {
    test18::run();
    return 0;
}

