#include "singleLinkedList.cpp"


int main() {

    SingleLinkedList *list = new SingleLinkedList;
    
    // test 1: append test; passed
    std::cout << " > print test after append \n";
    list->append(1);
    list->append(2);
    list->print();
    delete list;

    // test 2: lenght test; passed
    std::cout << " > Length test after appendMultiple \n";
    list = new SingleLinkedList;
    list->appendMultiple(5, 1, 4, 1, 2, 4);
    list->print();
    std::cout << " list len: "<< list->lenght() << "\n";
    delete list;

    // test 3: indexOf test; passed 
    std::cout << " > indexOf test \n";
    list = new SingleLinkedList;
    list->appendMultiple(5, 1, 2, 3, 4, 5);
    list->print();
    std::cout << " index of 3 is " << list->indexOf(3) << "\n";
    delete list;

    // test 4: insert test; passed 
    std::cout << " > insert test \n";
    list = new SingleLinkedList;
    list->appendMultiple(5, 1, 2, 3, 4, 5);
    list->print();
    list->insert(10, 0);
    list->insert(10, list->lenght()/2);
    list->insert(10, list->lenght());
    list->print();

    // test 5: bubbleSort test; 

    return 0;
}
