#include <iostream>
#include "List.h"


int main()
{
    List list;
    // list.insert_beg(1);
    // list.insert_end(3);
    // list.insert_end(5);
    // //list.removeNode(7);
    // //list.removeNode(9);
    /* list.insert_beg(9);
     list.insert_beg(11);
     list.insert_beg(7);*/
    // list.insert_end(13);
    // //list.display();
    // list.reverseList();
    // //list.display();
    // list.reverseList();
    // //list.display();
    // cout << endl;
    
    // list.insert_beg(22);
    // list.insert_beg(22);
//     list.insert_beg(22);
    // list.insert_end(22);
    // //list.display();
    // //list.removeAllElements(22);
    // cout << endl;
    // //list.display();
    // List newList;
    // newList.insert_beg(2);
    // list.display();
    // cout << endl;
    // newList.display();
    // //newList.intersectNode(list.gethead(), newList.gethead());

    // newList.display();
  //  List pal;
    // pal.insert_beg(1);
    // //pal.insert_end(0);
    //list.insert_end(2);
    // pal.insert_end(2);
    // pal.insert_end(2);
    // pal.insert_end(3);
    // pal.insert_end(3);

    list.insert_end(2);
    list.insert_end(1);
    list.insert_end(3);
    list.insert_end(5);
    list.insert_end(6);
    list.insert_end(4);
    list.insert_end(7);
    // pal.insert_end(3);
    // pal.insert_end(3);
    // pal.insert_end(4);


    //pal.removeDuplicate(pal.gethead());
    //list.display();
    list.evenOddListIndex(list.gethead());
    //list.display();

    return 0;
}
