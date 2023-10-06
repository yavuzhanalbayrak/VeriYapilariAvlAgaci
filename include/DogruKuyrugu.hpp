/**
* @file         DogruKuyrugu.hpp
* @description  DogruKuyruk sınıfının başlık dosyası.
* @courseVeri   Yapıları İkinci Öğretim B Grubu
* @assignment   2. Ödev
* @date         22.12.2021
* @author       Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
*/
#ifndef DOGRUKUYRUK_HPP
#define DOGRUKUYRUK_HPP

#include "Nokta.hpp"
using namespace std;

class DogruKuyruk
{
private:
    
   
public:
    DogruKuyruk* sol;
    DogruKuyruk* sag;
    int toplamUzunluk;
    int ilk;
    int son;
    int kapasite;
    Nokta veriler[200];
    int veriSayisi;
    void ekle(int sayac,string koordinatlar[],DogruKuyruk* dogrukuyruk);
    DogruKuyruk();
    ~DogruKuyruk();
    void Sirala();
    void ToplamUzunluk();

};








#endif
