#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(){
    BinarySearchTree bst(50);
    //inserts some values
    int insertValues[] = {25,75,100,12,62,1,99,2,0,37,39};
    for(int i = 0; i < 11; i++){
        bst.insert(insertValues[i]);
    }
    //searches for some values and prints the result
    int searchValues[] = {25,75,100,52,12,62,91,1,99,16,20,2,0,37,39,50};
    for(int i = 0; i < 16; i++){
        cout << searchValues[i] << ": "
             << ((bst.search(searchValues[i])) ? "true" : "false") << endl;
    }
    bst.display();
    return 0;
}
