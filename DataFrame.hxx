#ifndef DATA_FRAME_HXX__
#define DATA_FRAME_HXX__

#include <map>
#include <string>
#include <vector>
#include <initializer_list>
#include "DataColumn.hxx"
using namespace std;

template<typename T>
class DataFrame
{
public:
    DataFrame(initializer_list<string>);
    DataFrame(const vector<string>&);
    bool append(initializer_list<T>);
    bool append(vector<T>);
    const vector<map<string, T>>& getRows() const { return this->rows; }
    const vector<string>& getProps() const { return this->props; }
    DataColumn<T> operator[](string) const;
    const map<string, T>& operator[](int) const;
    map<string, T>& operator[](int);
    DataFrame<T> operator[](initializer_list<string>);
    DataFrame<T> operator[](vector<string>);
    DataFrame<T> operator[](initializer_list<int>);
    DataFrame<T> operator[](vector<int>);
private:
    vector<string> props;
    vector<map<string, T>> rows;
};

template<typename T>
DataFrame<T>::DataFrame(initializer_list<string> _props)
{
    this->props.insert(props.end(), _props.begin(), _props.end());
}

template<typename T>
DataFrame<T>::DataFrame(const vector<string>& _props)
{
    this->props.insert(props.end(), _props.begin(), _props.end());
}

template<typename T>
DataFrame<T> DataFrame<T>::operator[](initializer_list<int> _ids)
{
    DataFrame<T> res(this->props);
    for (auto _it = _ids.begin(); _it != _ids.end(); _it++) {
        vector<T> rec;
        for (auto it = props.begin(); it != props.end(); it++) {
            rec.push_back(rows[*_it][*it]);
        }
        res.append(rec);
    }
    return res;
}

template<typename T>
DataFrame<T> DataFrame<T>::operator[](vector<int> _ids)
{
    DataFrame<T> res(this->props);
    for (auto _it = _ids.begin(); _it != _ids.end(); _it++) {
        vector<T> rec;
        for (auto it = props.begin(); it != props.end(); it++) {
            rec.push_back(rows[*_it][*it]);
        }
        res.append(rec);
    }
    return res;
}

template<typename T>
DataFrame<T> DataFrame<T>::operator[](initializer_list<string> _props)
{
    DataFrame res(_props);
    for (auto it = this->rows.begin(); it != this->rows.end(); it++) {
        vector<T> rec;
        for (auto _it = _props.begin(); _it != _props.end(); _it++) {
            rec.push_back((*it)[*_it]);
        }
        res.append(rec);
    }
    return res;
}

template<typename T>
DataFrame<T> DataFrame<T>::operator[](vector<string> _props)
{
    DataFrame res(_props);
    for (auto it = this->rows.begin(); it != this->rows.end(); it++) {
        vector<T> rec;
        for (auto _it = _props.begin(); _it != _props.end(); _it++) {
            rec.push_back((*it)[*_it]);
        }
        res.append(rec);
    }
    return res;
}

template<typename T>
const map<string, T>& DataFrame<T>::operator[](int _rid) const
{
    return this->rows[_rid];
}

template<typename T>
map<string, T>& DataFrame<T>::operator[](int _rid)
{
    return this->rows[_rid];
}

template<typename T>
DataColumn<T> DataFrame<T>::operator[](string _pname) const
{
    vector<T> vec;

    bool hasProp = false;
    for (auto it = props.begin(); it != props.end(); it++) {
        if (*it == _pname) {
            hasProp = true;
            break;
        }
    }
    if (!hasProp) return DataColumn<T>(vec);
    for (auto it = rows.begin(); it != rows.end(); it++) {
        map<string, T> row = *it;
        vec.push_back(row[_pname]);
    }
    return DataColumn<T>(vec);
}

template<typename T>
bool DataFrame<T>::append(initializer_list<T> _rec)
{
    if (_rec.size() != props.size())
        return false;
    map<string, T> m;
    for (auto _it = _rec.begin(); _it != _rec.end(); _it++) {
        m[props[_it - _rec.begin()]] = *_it;
    }
    rows.push_back(m);
    return true;
}

template<typename T>
bool DataFrame<T>::append(vector<T> _rec)
{
    if (_rec.size() != props.size())
        return false;
    map<string, T> m;
    for (auto _it = _rec.begin(); _it != _rec.end(); _it++) {
        m[props[_it - _rec.begin()]] = *_it;
    }
    rows.push_back(m);
    return true;
}

#endif
