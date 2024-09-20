#pragma once
#include <vector>
#include <iostream>
class inventario
{
public:
	void nuevo_id(int i, int c);
	void comprar_id(int i, int c);
	void vender(int i);
	void mostrar()const;
private:
	struct par {
		int id, cont;
		bool operator<(par const& p) const{
			return id < p.id;
		}
	};
	std::vector <par> v;
};
