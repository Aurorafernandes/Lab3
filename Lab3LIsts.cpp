// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Lab 3 done by Aurora Fernandes for Software Design and Implementation
// 20/10/2020

#include <iostream>
#include <vector>
#include <ostream>
#include <iterator>
#include <list>
#include <algorithm> //for transform
using namespace std;


void printList(list <int> a)
{
    //function to print lists needed for part 2
    list <int> ::iterator it;

    for (it = a.begin(); it != a.end(); it++)
    {
        cout << *it << ", ";


    }
}

int main()
{

    //part 1
    std::cout << "Hello World!\n";


    vector<int> vecList = { 32, 46, 35, 18, 87, 13, 37, 99, 15, 2, 66 };
    ostream_iterator<int> screen (cout, " ");

    copy(vecList.rbegin(), vecList.rend(), screen);
    cout << endl;

    copy(vecList.rbegin() + 3, vecList.rend() - 1, vecList.rbegin());
    copy(vecList.begin(), vecList.end(), screen);

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;




    list <int> intList1, intList2, intList3;

    intList1 = { 13, 15, 16, 18, 90, 30, 11, 88, 26 };

    intList2 = { 7, 8, 19, 90, 15 };

    intList3 = { 12, 12, 14, 20, 20, 13, 13, 13 };

    //splice: This effectively inserts those elements into the container and removes them from x, altering the sizes of both containers.
    //unique: removes all but the first element from every consecutive group of equal elements in the container.

    cout << "\nBefore splice:" << endl;
    printList(intList1);
    intList1.splice(intList1.begin(), intList2);
    cout << "\nAfter splice:" << endl;
    printList(intList1);
    cout << "\nAfter splice with 1 and 3:" << endl;
    intList1.splice(intList1.begin(), intList3);
    intList1.unique();
    printList(intList1);

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;


    //Part 3


    vector<char> charVec = { '+', '1', 'B', 'Q', '&', 'T', 'G', '#', '3', 'S' };
    ostream_iterator<char> screen1(cout, " ");
    copy(charVec.begin(), charVec.end(), screen);
    cout << endl;
    transform(charVec.begin(), charVec.end() - 2, charVec.begin(), [](unsigned char c) -> unsigned char { return tolower(c); });
    copy(charVec.begin(), charVec.end(), screen);
    cout << endl;
}
