#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct QueueInt {
	void Enqueue(int number); //Pridëti á eilës galà
	int Dequeue();            //Paimti pirmà elementà ið eilës, ir já iðtrinti
	void EmptyQueue();        // iðvalo visà eilæ
	void Sort();              //Rikiavimas didëjimo tvarka
	void SortDesc();          // rikiavimas maþëjimo tvarka

	void PrintQueue();
private:
	int* _queue = nullptr;
	int _count = 0;

	void _createAndCopyArray(int _count);
	void _removeFirstCreateAndCopyArray();
};

int main()
{
	try {
		QueueInt b;
		b.Enqueue(10);
		b.Enqueue(12);
		b.Enqueue(11);
		b.Sort();
		b.PrintQueue();
		b.EmptyQueue();
		b.SortDesc();
		b.PrintQueue();
	}
	catch (const exception& e) {
		cout << "Klaida" << e.what();
	}
}

void QueueInt::Enqueue(int number)
{
	_count++;
	_createAndCopyArray(_count);
	_queue[_count - 1] = number;
}

int QueueInt::Dequeue()
{
	if (_count > 0) {
		int number = _queue[0];
		_removeFirstCreateAndCopyArray();
		return number;
	}
	/*else {
		throw exception("Eileje nera skaiciu");
	}*/
}

void QueueInt::EmptyQueue()
{
    delete[]_queue;
    _queue = nullptr;
}

void QueueInt::Sort()
{
    if(_queue==nullptr)
    {
        cout << "Empty queue" << endl;
        return;
    }
    for(int i=0; i<_count-1; i++)
    {
        int max=i;
        for(int j=i+1; j<_count; j++)
        {
            if(_queue[j]<_queue[max]) max=j;
        }
            if(i!=max)
            swap(_queue[i], _queue[max]);
    }
}

void QueueInt::SortDesc()
{
    if(_queue==nullptr)
    {
        cout << "Empty queue" << endl;
        return;
    }
    for(int i=0; i<_count-1; i++)
    {
        int min=i;
        for(int j=i+1; j<_count; j++)
        {
            if(_queue[j]>_queue[min]) min=j;
        }
            if(i!=min)
            swap(_queue[i], _queue[min]);
    }
}

void QueueInt::PrintQueue()
{
    if(_queue==nullptr)
    {
        cout << "Empty queue" << endl;
        return;
    }
	for (int i = 0; i < _count; i++) {
		cout << _queue[i] << " ";
	}
	cout << endl;
}

void QueueInt::_createAndCopyArray(int _count)
{
	int* copy = _queue;
	_queue = new int[_count];
	for (int i = 0; i < _count - 1; i++) {
		_queue[i] = copy[i];
	}
	delete[] copy;
}

void QueueInt::_removeFirstCreateAndCopyArray()
{
	for (int i = 0; i < _count - 1; i++) {
		_queue[i] = _queue[i + 1];
	}
	_count--;

	_createAndCopyArray(_count+1);
}

// padaryti _createAndCopyArray universalià.
// implementuoti void EmptyQueue();
// implementuoti void Sort();
// implementuoti void SortDesc();

// darbas su struktura, eile uzpildyti maisytom kortom
