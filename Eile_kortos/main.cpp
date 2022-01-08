#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <unistd.h>

using namespace std;

const string ZENKLAI[] = { "Bugnu", "Piku", "Kryziu", "Sirdziu" };
const string PAVADINIMAI[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Berniukas", "Dama", "Karalius", "Tuzas" };

struct Korta
{
    char Pavadinimas[11];
    char Zenklas[11];
    int verte;
};

struct Kalade
{
    void Enqueue(Korta korta);
	Korta Dequeue();
	void EmptyQueue();
	void PrintQueue();


    private:
    Korta* _queue = nullptr;
	int _count = 0;

	void _createAndCopyArray(int _count);
	void _removeFirstCreateAndCopyArray();
};

int main()
{
    srand(time(NULL));
    int x, y, z;
    Kalade ka;
    z=rand()%101;
    for(int i=0; i<z; i++)
    {
        x=rand() % 4;
        y=rand()%12;
        Korta a;
        strcpy(a.Pavadinimas, PAVADINIMAI[y].c_str());
        strcpy(a.Zenklas, ZENKLAI[x].c_str());
        ka.Enqueue(a);
    }
    ka.PrintQueue();

}

void Kalade::_createAndCopyArray(int _count)
{
	Korta* copy = _queue;
	_queue = new Korta[_count];
	for (int i = 0; i < _count - 1; i++) {
		_queue[i] = copy[i];
	}
	delete[] copy;
}

void Kalade::_removeFirstCreateAndCopyArray()
{
	for (int i = 0; i < _count - 1; i++) {
		_queue[i] = _queue[i + 1];
	}
	_count--;

	_createAndCopyArray(_count+1);
}

void Kalade::Enqueue(Korta korta)
{
	_count++;
	_createAndCopyArray(_count);
	_queue[_count - 1] = korta;
}

Korta Kalade::Dequeue()
{
	if (_count > 0) {
		Korta korta = _queue[0];
		_removeFirstCreateAndCopyArray();
		return korta;
	}
	/*else {
		throw exception("Eileje nera skaiciu");
	}*/
}

void Kalade::EmptyQueue()
{
    delete[]_queue;
    _queue = nullptr;
}

void Kalade::PrintQueue()
{
    if(_queue==nullptr)
    {
        cout << "Empty queue" << endl;
        return;
    }
	for (int i = 0; i < _count; i++) {
		cout << _queue[i].Pavadinimas << " " <<  _queue[i].Zenklas << " " << endl;
	}
	cout << endl;
}
//sukurti eile, duomenu tipas - realieji skaiciai, skaicius sugeneruoti atsitiktine tvarka "dalyba" , main ciklas visu eileje esanciu elementu suma
