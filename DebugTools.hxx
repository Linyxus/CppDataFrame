#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

template<typename T>
void display(vector<T> _vec)
{
    cout << "### Display Vector:" << endl;
    cout << "### Typeid: " << typeid(_vec).name() << endl;
    cout << "### Content: " << endl;
    for (auto it = _vec.cbegin(); it != _vec.cend(); it++)
        cout << *it << endl;
    cout << "### End" << endl << endl;
}

template<typename T, typename R>
void display(vector<T> _vec, R runable)
{
    cout << "### Display Vector:" << endl;
    cout << "### Typeid: " << typeid(_vec).name() << endl;
    cout << "### Content: " << endl;
    for (auto it = _vec.cbegin(); it != _vec.cend(); it++)
        runable(*it);
    cout << "### End" << endl << endl;
}
