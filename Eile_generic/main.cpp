#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;

template <typename T>
struct QueueNew
{

    void Enqueue(T item);
    T Dequeue();
    void PrintQueue();
    T ElementAt(int elementNumber);

private:
    T* _queue = nullptr;
    int _count = 0;

    void _createAndCopyArray();
    void _removeFirstCreateAndCopyArray();
};

int main()
{
    try
    {
        QueueNew<string> b;
        b.Enqueue("Labas");
        b.Enqueue("Vakaras");
        b.PrintQueue();
        b.Dequeue();
        cout << b.ElementAt(0) << endl;
        cout << "Dequeue" << endl;
        b.PrintQueue();
    }
    catch (const exception& e)
    {
        cout << "Klaida: " << e.what();
    }
}

template <typename T>
void QueueNew<T>::Enqueue(T item)
{
    _count++;
    _createAndCopyArray();
    _queue[_count - 1] = item;
}

template <typename T>
T QueueNew<T>::Dequeue()
{
    if (_count > 0)
    {
        T item = _queue[0];
        _removeFirstCreateAndCopyArray();
        return item;
    }
    else
    {
        throw invalid_argument("Eileje nera skaiciu");
    }
}

template <typename T>
void QueueNew<T>::PrintQueue()
{
    for (int i = 0; i < _count; i++)
    {
        cout << _queue[i] << " ";
    }
    cout << endl;
}

template <typename T>
void QueueNew<T>::_createAndCopyArray()
{
    T* copy = _queue;
    _queue = new T[_count];
    for (int i = 0; i < _count - 1; i++)
    {
        _queue[i] = copy[i];
    }
    delete[] copy;
}

template <typename T>
void QueueNew<T>::_removeFirstCreateAndCopyArray()
{
    for (int i = 0; i < _count - 1; i++)
    {
        _queue[i] = _queue[i + 1];
    }
    _count--;

    T* copy = _queue;
    _queue = new T[_count];
    for (int i = 0; i < _count; i++)
    {
        _queue[i] = copy[i];
    }
    delete[] copy;
}

template <typename T>
T QueueNew<T>::ElementAt(int elementNumber)
{
    if(elementNumber < _count)
    {
        return _queue[elementNumber];
    }
    else throw invalid_argument("Sito elemento eileje nera");
}

