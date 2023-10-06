/**
* @file         Nokta.hpp
* @description  Nokta sınıfının başlık dosyası.
* @courseVeri   Yapıları İkinci Öğretim B Grubu
* @assignment   2. Ödev
* @date         22.12.2021
* @author       Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
*/
#ifndef NOKTA_HPP
#define NOKTA_HPP

#include <iostream>
#include <math.h>
using namespace std;

class Nokta
{
private:
    
   
public:
    int x;
    int y;
    int z;
    Nokta(int x,int y,int z);
    Nokta();
    ~Nokta();
    float Yakinlik();

};







#endif
