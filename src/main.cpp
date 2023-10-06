/**
* @file         main.cpp
* @description  Programın ana kodunun yazılı olduğu dosya.
* @course       Veri Yapıları İkinci Öğretim B Grubu
* @assignment   2. Ödev
* @date         22.12.2021
* @author       Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <math.h>
#include "Nokta.hpp" 
#include "DogruKuyrugu.hpp"
#include "AVL.hpp"

using namespace std;
int main()
{
    Avl agac;
    int arama=0;
    string sayi="";
    char sayiekle;
    string bilgi;
    int diziUzunluk;
    string koordinatlar[2000];
    ifstream Noktalar(".\\doc.\\Noktalar.txt");
   
  
   
    
    
    while (!Noktalar.eof())//döngü ile Noktalar.txt dosyasının her satırı okundu.
    {
        DogruKuyruk* dogrukuyruk=new DogruKuyruk();
        getline(Noktalar,bilgi);//satır okuma.
        if(bilgi.length()==0) break;//son satır boş ise döngü kapanır.
        diziUzunluk=bilgi.length()+2;
        arama=0; 
        int sayac=0;
        for (int i = 0; i < bilgi.length(); i++)
        {
            for (int j = arama; j < bilgi.length(); j++)
            {
                    
                sayiekle=bilgi.at(j);

                if(sayiekle==' '){//boşluk geldiğinde sayı tamamlandığı için döngü bozuldu.
                       
                    arama=j+1;
                    break;

                }
                else if((int)sayiekle>47 && (int)sayiekle<58){//koordinatı oluşturan rakamlar yan yana eklenip sayı oluşturuldu.
                    sayi+=sayiekle;
                    arama=j+1;

                }
                    
                    
            }
            if(sayi!=""){//sayı tamamlanıp döngü bozulduğu için sayı koordinatlar dizisine eklendi.
                koordinatlar[i]=sayi;
                sayi="";
                sayac++;
            }
            else{//koordinatların 3'lü olmaması durumunda sona otomatik olarak 0 atandı.
                if(i%3==0) break;
                koordinatlar[i]="0";
                sayac++;
                    
            }
               
                
            }
            if(sayac==1){//ilk noktanın 3'lü olmaması durumunda oluşan hata engellendi.
                koordinatlar[1]="0";
                koordinatlar[2]="0";
                sayac=3;
            }
            else if(sayac==2){
                koordinatlar[2]="0";
                sayac=3;
            }    
        
            dogrukuyruk->ekle(sayac,koordinatlar,dogrukuyruk);//noktalar düğüme eklendi.
            agac.ekle(dogrukuyruk);//düğümler ağaca eklendi.
            
          
        }
        agac.postOrder();//ağaç post order dolaşıldı.
        

    return 0;
   
}

