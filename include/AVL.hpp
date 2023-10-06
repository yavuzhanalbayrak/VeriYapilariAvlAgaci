/**
* @file         AVL.hpp
* @description  Avl sınıfının başlık dosyası.
* @courseVeri   Yapıları İkinci Öğretim B Grubu
* @assignment   2. Ödev
* @date         22.12.2021
* @author       Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
*/
#ifndef AVL_HPP
#define AVL_HPP
#include<iostream>
#include "DogruKuyrugu.hpp"
using namespace std;

class Avl
{
public:

	Avl();
	~Avl();
	void ekle(DogruKuyruk* dogrukuyruk);
	int yukseklik();
	void postOrder();

private:

	DogruKuyruk* kok;
	DogruKuyruk* solaDondur(DogruKuyruk* DogruKuyruk);
	DogruKuyruk* sagaDondur(DogruKuyruk* DogruKuyruk);
	void postOrder(DogruKuyruk* kok);
	int yukseklik(DogruKuyruk* aktifDogruKuyruk);
	DogruKuyruk* ekle(DogruKuyruk* dogrukuyruk,DogruKuyruk* aktifDogruKuyruk);
	
};
#endif