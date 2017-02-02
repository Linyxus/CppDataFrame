#include <iostream>
using namespace std;
#include "DataColumn.hxx"
#include "DebugTools.hxx"

int main()
{
    //#1 DataColumn
    cout << "Test DataColumn:" << endl;
    vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8};
    DataColumn<int> dc(data);
    display(dc.getData());

    vector<int> res = dc > 5;
    display(res, [&](int i){ cout << "[" << i << "] = " << dc.getData()[i] << endl; });

    return 0;
}
