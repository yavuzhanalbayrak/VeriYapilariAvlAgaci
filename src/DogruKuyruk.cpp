/**
* @file         DogruKuyruk.cpp
* @description  DogruKuyruk sınıfının kurucusunu ve fonksiyonlarını oluşturur.
* @course       Veri Yapıları İkinci Öğretim B Grubu
* @assignment   2. Ödev
* @date         22.12.2021
* @author       Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
*/

#include "DogruKuyrugu.hpp";

DogruKuyruk::DogruKuyruk(){
    sol=0;
    sag=0;
    ilk=0;
    toplamUzunluk=0;
    son=-1;
    kapasite=1000;
    veriSayisi=0;
}


void DogruKuyruk::ekle(int sayac,string koordinatlar[],DogruKuyruk* dogrukuyruk){
    
    for (int i = 0; i <sayac; i++)                
    {
                            
        Nokta n1(stoi(koordinatlar[i]),stoi(koordinatlar[i+1]),stoi(koordinatlar[i+2]));//nokta oluşturuldu.
                        
        i+=2;//bir sonraki noktaya geçildi.
               
        son++;
                
        veriler[son]=n1;//nokta veriler dizisine eklendi
        veriSayisi++;
                           
    }
    dogrukuyruk->ToplamUzunluk();//düzenlenme öncesi toplam uzunluk bulunup atandı.
    if(veriSayisi>1){
        Sirala();//yakınlığa göre öncelik düzenlendi.
    }
    
}

void DogruKuyruk::Sirala(){

    
    for (int i = 0; i < veriSayisi-1; i++)
    {
        for (int j = i+1; j < veriSayisi; j++)
        {
            if (veriler[i].Yakinlik()>veriler[j].Yakinlik())
            {
                Nokta yedek=veriler[i];
                veriler[i]=veriler[j];
                veriler[j]=yedek;
                
            }
            
        }
        
    }
    
    

}
void DogruKuyruk::ToplamUzunluk(){
     for (int i = 0; i < veriSayisi-1; i++)
        {
            toplamUzunluk+=pow(pow(veriler[i+1].x-veriler[i].x,2)+pow(veriler[i+1].y-veriler[i].y,2)+pow(veriler[i+1].z-veriler[i].z,2),0.5);
        
        }
}


DogruKuyruk::~DogruKuyruk(){
    
}





