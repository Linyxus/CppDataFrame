#include <iostream>
using namespace std;
#include "DataColumn.hxx"
#include "DataFrame.hxx"
#include "DebugTools.hxx"

int main()
{
    //#1 DataColumn
    cout << "Test DataColumn:" << endl;
    vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8};
    DataColumn<int> dc(data);
    display(dc.getData());

    cout << ">>> dc > 5" << endl;
    vector<int> res = dc > 5;
    display(res, [&](int i){ cout << "[" << i << "] = " << dc.getData()[i] << endl; });

    //#2 DataFrame
    DataFrame<int> df({"[1]", "[2]", "[3]"});
    df.append({1, 2, 3});
    df.append({4, 5, 6});
    df.append(vector<int>({7, 8, 9}));
    cout << "Test DataFrame:" << endl;
    display(df);
    //#2.1 DataFrame[string]
    cout << "Test DataFrame[string]:" << endl;
    cout << ">>> df[\"[1]\"]:" << endl;
    DataColumn<int> col = df["[1]"];
    display(col.getData());
    cout << ">>> df[\"[3]\"]:" << endl;
    col = df["[3]"];
    display(col.getData());
    //#2.2 DataFrame[{str1, str2, ...}]
    cout << "Test DataFrame[{str1, str2, ...}]" << endl;
    cout << ">>> df[{\"[1]\", \"[2]\"}]:" << endl;
    DataFrame<int> dff = df[{"[1]", "[2]"}];
    display(dff);
    //#2.3 DataFrame[rowIndex]
    cout << "Test DataFrame[rowIndex] and modify:" << endl;
    cout << ">>> df[0][\"[1]\"] = 100" << endl;
    df[0]["[1]"] = 100;
    display(df);
    //#2.4 DataFrame[{id1, id2, ...}]
    cout << "Test DataFrame[{id1, id2, ...}]" << endl;
    cout << ">>> df[{0, 1}]:" << endl;
    dff = df[{0, 1}];
    display(dff);
    //#2.5 Final Test
    cout << "Final Test" << endl;
    cout << ">>> df[df[\"[1]\"] < 10]:" << endl;
    dff = df[df["[1]"] < 10];
    display(dff);

    return 0;
}
