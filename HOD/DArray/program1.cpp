#include <iostream>
#include <set>
using namespace std;

int x = -1;

class DArray
{
private:
    int _size;
    int count;
    int *array;
    void doubleSize();

public:
    DArray();
    DArray(int);
    DArray(const DArray &);
    DArray &operator=(const DArray &);
    int &operator[](int);
    void push_back(int);
    int size() const;
    int operator[](int index) const;
    DArray &operator+=(const DArray &);
};

DArray::DArray() : _size(1), count(0)
{
    array = new int[_size];
}
DArray::DArray(int value) : count(0)
{
    _size = value;
    array = new int[_size];
    for (int i{0}; i < value; i += 1)
    {
        push_back(value);
    }
}

DArray::DArray(const DArray &obj)
{
    _size = obj._size;
    count = obj.count;
    array = new int[obj._size];
    for (int i{}; i < obj._size; i++)
    {
        array[i] = obj.array[i];
    }
}
DArray &DArray::operator=(const DArray &obj)
{
    if (this != &obj)
    {
        _size = obj._size;
        count = obj.count;
        array = new int[obj._size];
        for (int i{}; i < obj._size; i++)
        {
            array[i] = obj.array[i];
        }
    }
    return *this;
}

int &DArray::operator[](int index)
{
    if (index >= 0 && index < _size)
    {
        return array[index];
    }
    cout << "Index Out of Bounds" << endl;
    return x;
}

int DArray::operator[](int index) const
{
    if (index >= 0 && index < _size)
    {
        return array[index];
    }
    cout << "Index Out of Bounds" << endl;
    return x;
}

void DArray::push_back(int val)
{
    if (count >= _size)
    {
        doubleSize();
    }

    array[count] = val;
    count += 1;
}

int DArray::size() const
{
    return count;
}

DArray &DArray::operator+=(const DArray &lhs)
{
    cout<<"Hello"<<endl;
    int smallSize{};
    if (this->_size < lhs._size)
    {
        smallSize = _size;
    }
    else
        smallSize = lhs._size;

    for (int i{}; i < lhs._size; i += 1)
    {
        this->array[i] = this->array[i] + lhs.array[i];
    }
    return *this;
}

ostream &operator<<(ostream &os, const DArray &arr)
{
    for (int i{}; i < arr.size(); i++)
    {
        os << arr[i] << " ";
    }
    return os;
}

DArray doSomething(DArray arr)
{
    int size = arr.size();
    for (int i{}; i < arr.size(); i++)
    {
        arr[i] = arr[i] + 1;
    }
    return arr;
}
void DArray::doubleSize()
{
    _size *= 2;
    int *newArray = new int[_size];
    for (int i{}; i < count; i++)
    {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

DArray operator+(const DArray &lhs, const DArray &rhs)
{

    int lhsSize = lhs.size();
    int rhsSize = rhs.size();

    int smallSize{};
    if (lhsSize < rhsSize)
        smallSize = lhsSize;
    else
        smallSize = rhsSize;
    DArray result{smallSize};

    for (int i{}; i < smallSize; i += 1)
    {
        result[i] = lhs[i] + rhs[i];
    }

    return result;
}

int main()
{
    DArray arr1;
    int num;
    cin >> num;

    while (num >= 0)
    {
        arr1.push_back(num);
        cin >> num;
    }
    cout << arr1 << endl;
    DArray arr2 = arr1;
    cout << arr2 << endl;
    arr2 = doSomething(arr1);
    cout << arr2 << endl;
    DArray arr4;
    arr4 = arr2 + 3;
    cout << arr4 << endl;
    arr4 = arr1 + arr2;
    cout << arr4 << endl;

    arr4 = 3 + arr1;
    cout << arr4 << endl;

    arr1 += arr1;
    cout<<arr1<<endl;

    arr1 += 1;
    cout<<arr1<<endl;

    return 0;
}
