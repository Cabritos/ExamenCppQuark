#pragma once
#include <string>

using namespace std;

class Imprimible
{
public:
	virtual string imprimir() const = 0;
	virtual ~Imprimible() = 0;
};