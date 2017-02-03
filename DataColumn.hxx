#ifndef DATA_COLUMN_HXX__
#define DATA_COLUMN_HXX__

#include <vector>
using namespace std;

template <typename T>
class DataColumn
{
public:
    DataColumn() { }
    DataColumn(const vector<T>& data) { this->data = data; }
    const vector<T>& getData() const { return this->data; }
private:
    vector<T> data;
};

template<typename T, typename R>
vector<int> _DO_SELECT(const DataColumn<T>& l, R runable)
{
    vector<int> res;
    const vector<T>& data = l.getData();
    for (auto it = data.cbegin(); it != data.cend(); it++) {
        if (runable(*it))
            res.push_back(it - data.cbegin());
    }

    return res;
}

template<typename T>
vector<int> operator<(const DataColumn<T>& l, const T& r)
{
    return _DO_SELECT(l, [=](const T& t) { return t < r; });
}

template<typename T>
vector<int> operator>(const DataColumn<T>& l, const T& r)
{
    return _DO_SELECT(l, [=](const T& t) { return t > r; });
}

template<typename T>
vector<int> operator<=(const DataColumn<T>& l, const T& r)
{
    return _DO_SELECT(l, [=](const T& t) { return t <= r; });
}

template<typename T>
vector<int> operator>=(const DataColumn<T>& l, const T& r)
{
    return _DO_SELECT(l, [=](const T& t) { return t >= r; });
}

template<typename T>
vector<int> operator==(const DataColumn<T>& l, const T& r)
{
    return _DO_SELECT(l, [=](const T& t) { return t == r; });
}

#endif
