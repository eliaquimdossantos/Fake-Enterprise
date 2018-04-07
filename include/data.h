#ifndef DATA_H
#define DATA_H
#include <iostream>

class Data{
private:
	short dia;
	short mes;
	short ano;
public:
	Data(const short dia_, const short mes_, const short ano_);
	Data();
	~Data();
	friend std::istream& operator>> (std::istream &i, Data &d);
	friend std::ostream& operator<< (std::ostream &o, Data d);
	friend bool operator== (Data a, Data b);
	int tempoDecorrido(Data agora);
};

#endif