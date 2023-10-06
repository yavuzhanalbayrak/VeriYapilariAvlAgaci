/**
* @file         Nokta.cpp
* @description  Nokta sınıfının kurucusunu ve fonksiyonlarını oluşturur.
* @course       Veri Yapıları İkinci Öğretim B Grubu
* @assignment   2. Ödev
* @date         22.12.2021
* @author       Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
*/

#include "Nokta.hpp"
Nokta::Nokta(){
    this->x=0;
    this->y=0;
    this->z=0;
}
Nokta::Nokta(int x,int y,int z){
    this->x=x;
    this->y=y;
    this->z=z;
}

float Nokta::Yakinlik(){
    
    float uzunluk=pow(x*x+y*y+z*z,0.5);
    int deger=uzunluk;
    return deger;

}

Nokta::~Nokta(){
}

