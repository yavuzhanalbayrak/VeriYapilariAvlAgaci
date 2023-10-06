/**
* @file         AVL.cpp
* @description  Avl sınıfının kurucusunu ve fonksiyonlarını oluşturur.
* @course       Veri Yapıları İkinci Öğretim B Grubu
* @assignment   2. Ödev
* @date         22.12.2021
* @author       Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
*/
#include "Avl.hpp"
#include <cmath>
#include <iomanip>
#include<iostream>
using namespace std;
Avl::Avl()
{
    kok= 0;
}
Avl::~Avl()
{

}
void Avl::ekle(DogruKuyruk* yeni)
{
    kok = ekle(yeni,kok);
}
int Avl::yukseklik() 
{
	return yukseklik(kok);
}

void Avl::postOrder() {
	postOrder(kok);
}


void Avl::postOrder(DogruKuyruk* mevcut) 
{
  
	if(mevcut)
    {
        
        postOrder(mevcut->sol);
        postOrder(mevcut->sag);      
        for (int j = 0; j < mevcut->veriSayisi; j++)
        {   
            cout<<mevcut->veriler[j].Yakinlik()<<" ";
        }
        cout<<endl;
    }	
}
int Avl::yukseklik(DogruKuyruk* mevcutDogruKuyruk) 
{
	if(mevcutDogruKuyruk)
    {
        return 1+max(   yukseklik(mevcutDogruKuyruk->sol),
                        yukseklik(mevcutDogruKuyruk->sag));
    }
    return -1;
}
DogruKuyruk* Avl::ekle(DogruKuyruk* dogrukuyruk,DogruKuyruk* mevcutDogruKuyruk) 
{
    if(mevcutDogruKuyruk==0)
        return dogrukuyruk;

	else if(mevcutDogruKuyruk->toplamUzunluk<dogrukuyruk->toplamUzunluk)
    {
        mevcutDogruKuyruk->sag=ekle(dogrukuyruk,mevcutDogruKuyruk->sag);
        if(yukseklik(mevcutDogruKuyruk->sag)-yukseklik(mevcutDogruKuyruk->sol)>1)
        {   
            if(dogrukuyruk->toplamUzunluk>mevcutDogruKuyruk->sag->toplamUzunluk)
                mevcutDogruKuyruk = solaDondur(mevcutDogruKuyruk);
                
            else
            {
                mevcutDogruKuyruk->sag = sagaDondur(mevcutDogruKuyruk->sag);
                mevcutDogruKuyruk =solaDondur(mevcutDogruKuyruk);
            }
        }
    }
    else if(mevcutDogruKuyruk->toplamUzunluk>=dogrukuyruk->toplamUzunluk)
    {
        mevcutDogruKuyruk->sol = ekle(dogrukuyruk,mevcutDogruKuyruk->sol);
        if(yukseklik(mevcutDogruKuyruk->sol)-yukseklik(mevcutDogruKuyruk->sag)>1)
        {

            if(dogrukuyruk->toplamUzunluk<mevcutDogruKuyruk->sol->toplamUzunluk)
                mevcutDogruKuyruk = sagaDondur(mevcutDogruKuyruk);
            else
            {
                mevcutDogruKuyruk->sol = solaDondur(mevcutDogruKuyruk->sol);
                mevcutDogruKuyruk =sagaDondur(mevcutDogruKuyruk);
            }
        }

    }
    return mevcutDogruKuyruk;
}
DogruKuyruk* Avl::solaDondur(DogruKuyruk* buyukEbeveyn) 
{
	DogruKuyruk* sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}
DogruKuyruk* Avl::sagaDondur(DogruKuyruk* buyukEbeveyn) 
{
	DogruKuyruk* solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}