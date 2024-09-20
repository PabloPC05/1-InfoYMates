#include <iostream>
#ifndef THORA_H
#define THORA_H
struct tHora{
    int hh; 
    int mm; 
    int ss;
};

bool operator<(tHora const& a, tHora const& b);

std::istream &operator>>(std::istream & entrada, tHora& hora);

std::ostream &operator<<(std::ostream & salida, tHora const& hora); 

#endif