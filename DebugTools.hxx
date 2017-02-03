#include <iostream>
#include <vector>
#include <typeinfo>
#include <initializer_list>
#include "DataFrame.hxx"
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

template<typename T>
void display(initializer_list<T> _list)
{
    cout << "### Display Initializer List:" << endl;
    cout << "### Typeid: " << typeid(_list).name() << endl;
    cout << "### Content: " << endl << "{ ";
    for (auto it = _list.begin(); it != _list.end(); it++)
        cout << *it << " ";
    cout << "}" << endl;
    cout << "### End" << endl << endl;
}

template<typename T>
void display(DataFrame<T> _df)
{
    cout << "### Display DataFrame:" << endl;
    cout << "### Typeid: " << typeid(_df).name() << endl;
    cout << "### Content: " << endl;
    //#1 Display Frame Header
    vector<string> props = _df.getProps();
    cout << " \t";
    for (auto it = props.begin(); it != props.end(); it++) {
        cout << *it << "\t";
    }
    cout << endl;
    //#2 Display Rows
    vector<map<string, T>> rows = _df.getRows();
    for (auto it = rows.begin(); it != rows.end(); it++) {
        cout << it - rows.begin() << "\t";
        for (auto itt = props.begin(); itt != props.end(); itt++)
            cout << (*it)[*itt] << "\t";
        cout << endl;
    }
    cout << "### End" << endl << endl;
}
