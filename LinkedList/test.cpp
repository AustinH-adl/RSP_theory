#include "LinkedList.h"


int main() {
    LinkedList list(1);

    list.InsertFront(2);

    list.InsertFront(3);


    list.InsertIndex(5,1);

    while(!list.Empty()) {
        list.printRoot();
        list.DeleteFront();
    }

    return 0;
}
