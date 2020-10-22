/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   PROGRAMLAMAYA GİRİŞ DERSİ
**					2019-2020 BAHAR DÖNEMİ
**
**				ÖDEV NUMARASI:YAZ OKULU ÖDEVİ
**				ÖĞRENCİ ADI SOYADI: SONGÜL BAYER
**				ÖĞRENCİ NUMARASI:B191210065
**              DERSİN ALINDIĞI GRUP:1-C
****************************************************************************/

#include <iostream>//cout,cin vs için
#include <fstream>//dosyalama işlemleri için
#include<string>//string türü için
#include<clocale>//türkçe karakter için
#include<iomanip>//setw() için eklenen kütüphane
#include<stdio.h>//standart input output dosyalarini programiniza eklemek içi
#include<Windows.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "turkish");//TÜRKÇE KARAKTERLERİ OKUNABİLECEK DURUMA GETİRDİK.
    int secim, i = 1;
    int no3;
    int UrunNo;//değişkenleri tanımladık
    string urunAdi;
    int  kullanılanAdet;
    string birim;
    int birimFiyati;
    string markasi;
    int ProjeNo;
    string ProjeAdi;
    string ProjeYurutucuFirma;
    string ProjeSorumlusu;
    string ProjeKontroloru;
    char islem;
    char cevap = 'E||e';
    do
    {

        cout << "Yapmak istediğiniz işlemi seçiniz" << endl;//KULLANICIYA YAPMAK İSTEDİĞİ İŞLEMİ SORDUK.
        cout << "1-ÜRÜN EKLEME" << endl;
        cout << "2-ÜRÜN SİLME" << endl;
        cout << "3-ÜRÜN ARAMA" << endl;
        cout << "4-ÜRÜN RAPORLAMA" << endl;
        cout << "5-PROJE EKLEME" << endl;
        cout << "6-PROJE SİLME" << endl;
        cout << "7-PROJE ARAMA" << endl;
        cout << "8-PROJE RAPORLAMA" << endl;
        cout << "9-AYLIK HAKEDİŞ EKLEME" << endl;
        cout << "10-PROGRAMDAN ÇIKIŞ" << endl;

        cin >> secim;

    } while (secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5 && secim != 6 && secim != 7 && secim != 8 && secim != 9);
    if (secim == 1)
    {
        int urunno1;
        ifstream DosyaOku("urunDosyası.txt");//DOSYA OKUMA İŞLEMİ YAPTIK.
        ofstream DosyaYaz("urunDosyası.txt", ios::app);//DOSYA YAZMA İŞLEMİ YAPTIK.
        cout << "ekleyeceğiniz ürün nosunu giriniz:" << endl;
        cin >> urunno1;
        while (!DosyaOku.eof())//TXT DOSYASININ SONUNA GELENE KADAR OKUMA İŞLEMİ YAPTIK.
        {
            DosyaOku >> UrunNo >> urunAdi >> kullanılanAdet >> birim >> birimFiyati >> markasi;//DOSYAYI BİLGİLERİ YAZMA SIRALAMAMIZA GÖRE OKUTTUK.
            if (urunno1==UrunNo)//AYNI ÜRÜN NOSUNA SAHİP OLMAMAK KOŞULU İLE KULLANICIDAN EKLEMEK İSTEDİĞİ ÜRÜN NOSUNU VER ARDINDAN ÜRÜN BİLGİLERİNİ İSTEDİK
            {
                cout << "AYNI ÜRÜNÜ 2 KERE EKLEYEMEZSİNİZ." << endl;
            }
            else
            {
                cout << "\n Ürün No: "; cin >> UrunNo;
                cout << "\n Ürün Adı: "; cin >> urunAdi;
                cout << "\n Kullanılan Adet: "; cin >> kullanılanAdet;
                cout << "\n Ürün Birimi: "; cin >> birim;
                cout << "\n Ürün Birim Fiyatı: "; cin >> birimFiyati;
                cout << "\n Ürün Markası: "; cin >> markasi;

                DosyaYaz << UrunNo << ' ' << urunAdi << ' ' << kullanılanAdet << ' ' << birim << ' ' << birimFiyati << ' ' << markasi << "\n";//KULLANICININ GİRDİĞİ ÜRÜN BİLGİLERİNİ DOSYAYA DÜZENİ BOZMAMAK KAYDI İLE YAZDIRDIK.
                break;
            }

        }
        cout << " İŞLEM TAMAMLANDI...YAPMAK İSTEDİĞİNİZ DİĞER İŞLEM NUMARASINI GİRİNİZ:";//İŞLEM BİTTİKTEN SONRA KULLANICIDAN YAPMAK İSTEDİĞİ DİĞER İŞLEMİ SORDUK.
        cin >> secim;
    }
    if (secim == 2)
    {
       
        int No;
        cout << "SİLİNECEK URUN NOSUNU GİRİNİZ"; cin >> No;//KULLANICIDAN DOSYADA BULUNAN VE SİLMEK İSTEDİĞİ ÜRÜN NOSUNU SORDUK.
        ifstream DosyaOku("urunDosyası.txt");//TXT DOSYAMIZIN OKUNMASI İŞLEMİNİ YAPTIK.
        ofstream DosyaYaz("urunDosyası.tmp");//YEDEK BİR TXT DOSYASI OLUŞTURDUK.
        while (!DosyaOku.eof())
        {
            DosyaOku >> UrunNo >> urunAdi >> kullanılanAdet >> birim >> birimFiyati >> markasi;
            if (No == UrunNo)
            {
                cout << "\n dosyadaki kayıt \n";
                cout << UrunNo << endl;
                cout << urunAdi << endl;
                cout << birim << endl;
                cout << birimFiyati << endl;
                cout << markasi << endl;
            }
            else
            {
                DosyaYaz << UrunNo << ' ' << urunAdi << ' ' << kullanılanAdet <<' '<< birim << ' ' << birimFiyati << ' ' << markasi << "\n";
            }

        }
        //DOSYALARI KAPATTIK.
        DosyaYaz.close();
        DosyaOku.close();
        //ASIL VERİ DOSYASINI DİSKTEN SİLDİK.
        remove("urunDosyası.txt");
        //YEDEK DOSYA İSMİNİ ASIL DOSYA İSMİ OLARAK DEĞİŞTİRDİK.
        rename("urunDosyası.tmp", "urunDosyası.txt");
        cout << " İŞLEM TAMAMLANDI...YAPMAK İSTEDİĞİNİZ DİĞER İŞLEM NUMARASINI GİRİNİZ:";
        cin >> secim;


      
       
    }
    if (secim == 3)
    {
        do
        {
            int No;
            cout << "aramak istediğiniz ürün numarasını giriniz"; cin >> No;
            ifstream DosyaOku("urunDosyası.txt");
            while (!DosyaOku.eof())
            {
                DosyaOku >> UrunNo >> urunAdi>> kullanılanAdet >> birim >> birimFiyati >> markasi;
                if (No == UrunNo)
                {
                    cout << "\n Bulunan Kayıt:\n";
                    cout << UrunNo << endl;
                    cout << urunAdi << endl;
                    cout <<  kullanılanAdet << endl;
                    cout << birim << endl;
                    cout << birimFiyati << endl;
                    cout << markasi << endl;


                }
            }
            cout << "\n başka kayıt yaptıracak mısınız?(e/h)"; cin >> cevap;
        } while ((!(cevap == 'h' || cevap == 'H')));
        cout << " İŞLEM TAMAMLANDI...YAPMAK İSTEDİĞİNİZ DİĞER İŞLEM NUMARASINI GİRİNİZ:";
        cin >> secim;
    }
    if (secim == 4)
    {
        ifstream DosyaOku("urunDosyası.txt");//RAPORLAMA İŞLEMİNİ İKİ KAİDEYE BAĞLI OLARAK YAPTIK.KULLANICIĞI BU İSTEDİĞİ 2 ÖZELLİKTEN BİRİSİNE GÖRE RAPORLAMA YAPACAK.
        cout << "1-urun numarasına göre sıralama" << endl;
        cout << "2-urun markasına göre sıralama" << endl;
        int cevap;
        cout << "1 e göre mi 2 ye göre mi raporlamak istersini?:" << endl;
        cin >> cevap;
        if (cevap==1)
        {
            while (DosyaOku >> UrunNo >> urunAdi >> kullanılanAdet >> birim >> birimFiyati >> markasi)//DOSYAYI BAŞINDAN SONUNA KADAR OKUYUP ÜRÜN NOLARINI EKRANA ÇIKARTICAK.
            {
               
                cout << UrunNo << endl;
            }
            DosyaOku.close();
        }
        if (cevap==2)
        {
            while (DosyaOku >> UrunNo >> urunAdi >> kullanılanAdet >> birim >> birimFiyati >> markasi)
            {
                cout << markasi << endl;
            }
        }
        cout << " İŞLEM TAMAMLANDI...YAPMAK İSTEDİĞİNİZ DİĞER İŞLEM NUMARASINI GİRİNİZ:";
        cin >> secim;
        
    }
    if (secim == 5)
    {
        ofstream DosyaYaz("urundosyası.txt", ios::app);
        do
        {
            cout << "\n Proje No: "; cin >> ProjeNo;
            cout << "\n proje Adı: "; cin >> ProjeAdi;
            cout << "\n Proje Yürütücü Firma: "; cin >> ProjeYurutucuFirma;
            cout << "\n Proje Sorumlusu: "; cin >> ProjeSorumlusu;
            cout << "\n Proje Kontrolörü: "; cin >> ProjeKontroloru;
            DosyaYaz << ProjeNo << ' ' << ProjeAdi << ' ' << ProjeYurutucuFirma << ' ' << ProjeSorumlusu << ' ' << ProjeKontroloru << "\n";
            cout << "\n başka kayıt yaptıracak mısınız?(e/h)"; cin >> cevap;
        } while (!(cevap == 'H' || cevap == 'h'));
        cout << "DOSYA YAZIM TAMAMLANDI...";
        cout << " İŞLEM TAMAMLANDI...YAPMAK İSTEDİĞİNİZ DİĞER İŞLEM NUMARASINI GİRİNİZ:";
        cin >> secim;
    }
    if (secim==6)
    {
        int ArananNo;
        cout << "SİLİNECEK PROJE NOSUNU GİRİNİZ"; cin >> ArananNo;
        ifstream DosyaOku("projeDosyası.txt");
        ofstream DosyaYaz("projeDosyası.tmp");
        while (!DosyaOku.eof())
        {
            DosyaOku >> ProjeNo >> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontroloru;
            if (ArananNo==ProjeNo)
            {
                cout << "\n dosyadaki kayıt \n";
                cout << ProjeNo << endl;
                cout << ProjeAdi<< endl;
                cout << ProjeYurutucuFirma << endl;
                cout << ProjeSorumlusu << endl;
                cout << ProjeKontroloru << endl;
            }
            else
            {
                DosyaYaz << ProjeNo << ' ' << ProjeAdi << ' ' << ProjeYurutucuFirma << ' ' << ProjeSorumlusu << ' ' << ProjeKontroloru << "\n";
            }
                
        }
        //DOSYALARI KAPATTIK
        DosyaYaz.close();
        DosyaOku.close();
        //ASIL VERİ DOSYASINI DİSKTEN SİLDİK.
        remove("projeDosyası.txt");
        //YEDEK DOSYANIN İSMİNİ ASIL DOSYA İSMİ OLARAK DEĞİŞTİRDİK.
        rename("projeDosyası.tmp", "projeDosyası.txt");
        cout << " İŞLEM TAMAMLANDI...YAPMAK İSTEDİĞİNİZ DİĞER İŞLEM NUMARASINI GİRİNİZ:";
        cin >> secim;

    }
    if (secim==7)
    {
        do
        {
            int ArananNo;
            cout << "aramak istediğiniz ürün numarasını giriniz"; cin >> ArananNo;
            ifstream DosyaOku("projeDosyası.txt");
            while (!DosyaOku.eof())
            {
                DosyaOku >> ProjeNo >> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontroloru;
                if (ArananNo == ProjeNo)
                {
                    cout << "\n Bulunan Kayıt:\n";
                    cout << ProjeNo << endl;
                    cout << ProjeAdi << endl;
                    cout << ProjeYurutucuFirma << endl;
                    cout << ProjeSorumlusu << endl;
                    cout << ProjeKontroloru << endl;
                }
            }
            cout << "\n başka kayıt yaptıracak mısınız?(e/h)"; cin >> cevap;
        } while ((!(cevap == 'h' || cevap == 'H')));
        cout << " İŞLEM TAMAMLANDI...YAPMAK İSTEDİĞİNİZ DİĞER İŞLEM NUMARASINI GİRİNİZ:";
        cin >> secim;
    }
    if (secim==8)
    {
        ifstream DosyaOku("projeDosyası.txt");
        cout << "1-proje numarasına göre sıralama" << endl;
        cout << "2-proje adına göre sıralama" << endl;
        int cevap;
        cout << "1 e göre mi 2 ye göre mi raporlamak istersini?:" << endl;
        cin >> cevap;
        if (cevap == 1)
        {
            while (DosyaOku >> ProjeNo >> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontroloru)
            {

                cout << ProjeNo << endl;
            }
            DosyaOku.close();
        }
        if (cevap == 2)
        {
            while (DosyaOku >> ProjeNo >> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontroloru)
            {
                cout << ProjeAdi << endl;
            }
        }
        cout << " İŞLEM TAMAMLANDI...YAPMAK İSTEDİĞİNİZ DİĞER İŞLEM NUMARASINI GİRİNİZ:";
        cin >> secim;
    }
    if (secim==9)
    {
        int secim3;
        int UrunNo;
        int ProjeNo;
        ofstream DosyaYaz("hakedişDosyası.txt", ios::app);
        ifstream DosyaOku("urunDosyası.txt");
        ifstream Dosyaoku("projeDosyası.txt");
        int donem;
        int uNO;
        int pNO;
        //HAKEDİŞ DOSYASINA YAPMAK İSTEDİĞİ İŞLEMLERİ SIRALADIK.
        cout << "HAKEDİŞ DOSYASINA YAPACAĞINIZ İŞLEMİ SEÇİNİZ" << endl;
        cout << "1-HAKEDİŞ DÖNEMİ BİLGİLERİ EKLEME"<<endl;
        cout << "2-ÜCRET ÖDEMEM." << endl;
        cout << "3-KULLANILAN ÜRÜNLERİ GÜNCELLE" << endl;
        cout << "4-KULLANILAN ÜRÜNLERİ LİSTELE" << endl;
        cout << "5-KULLANILAN ÜRÜNLERDE ARAMA YAPMA" << endl;
        cout << "6-KULLANILAN ÜRÜNLERİ SİLMEK" << endl;
        cout << "7-PROGRAMDAN ÇIKIŞ" << endl;
        cin >> secim3;
        if (secim3==1)
        {
           cout<< "EKLEMEK İSTEDİĞİNİZ HAKEDİŞ DÖNEMİNİ GİRİNİZ:" << endl;
           cin >> donem;
           DosyaYaz << donem<<' ';
           cout << "GİRDİĞİNİZ HAKEDİŞ DÖNEMİNDE UYGULANAN PROJE NO GİRİNİZ:" << endl;
           cin >> pNO;
           cout << "GİRDİĞİNİZ HAKEDİŞ DÖNEMİNDE KULLANILAN ÜRÜN NO GİRİNİZ:" << endl;
           cin >> uNO;

           do
           {
               while (!Dosyaoku.eof())
               {
                   Dosyaoku >> ProjeNo >> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontroloru;
                   DosyaOku >> UrunNo >> urunAdi >> kullanılanAdet >> birim >> birimFiyati >> markasi;
                   if (pNO == ProjeNo && uNO==UrunNo)
                   {
                       cout << "\n BULUNAN KAYIT:\n";
                       cout << ProjeNo << endl;
                       DosyaYaz << ProjeNo << ' ';

                       cout << urunAdi << endl;
                       cout << kullanılanAdet << endl;
                       DosyaYaz << UrunNo << ' ' << urunAdi << ' ' << kullanılanAdet << ' ' << birimFiyati;
                      
                   }

               }cout << "\n BAŞKA PROJE EKLEYECEK MİSİNİZ?" << endl;
                       cin >> cevap;
               
              

           } while (cevap == 'E' || cevap == 'e');
          
           cout << "yazma işlemi tamamladnı...YAPMAK İSTEDİĞİNİZ DİĞER İŞLEM NUMARASINI GİRİNİZ:";
           cin >> secim3;

        }
        if (secim3 == 2)
        {
            ifstream DosyaOku("hakedişDosyası.txt");
            cout << "ÜCRET ÖDEMESİNİ YAPACAĞINIZ ÜRÜN NOSUNU GİRİNİZ:" << endl;
            
            cin >> no3;
            int TUTAR;

            DosyaOku >> donem >> ProjeNo >> UrunNo >> urunAdi >> kullanılanAdet >> birimFiyati;
            if (no3 == UrunNo)
            {

                cout << "ÖDENMESİ GEREKEN TUTAR HESAPLANIYOR..." << endl;
                cout << kullanılanAdet * birimFiyati << endl;
            }
            cout << " İŞLEM TAMAMLANDI...YAPMAK İSTEDİĞİNİZ DİĞER İŞLEM NUMARASINI GİRİNİZ:";
            cin >> secim3;


        }
        if (secim3 == 3)
        {
            int ArananNo2;
            cout << "silmek istediğiniz ürün numarasını giriniz:" << endl;
            cin >> ArananNo2;
            ifstream DosyaOku("hakedişDosyası.txt");
            ofstream DosyaYaz("hakedişDosyası.tmp");
            do
            {
                while (!DosyaOku.eof())
                {
                    DosyaOku >> donem >> ProjeNo >> UrunNo >> urunAdi >> kullanılanAdet >> birimFiyati;
                    if (ArananNo2==no3)
                    {
                        cout << "ÜCRETİNİ ÖDEDİĞİNİZ ÜRÜNÜ SİLEMEZSİNİZ" << endl;
                    }
                    else
                    {
                        cout << "\n silincek ürün \n";
                        cout << urunAdi << endl;
                        DosyaYaz << donem << ' ' << ProjeNo << ' ' << UrunNo << ' ' << urunAdi << ' ' << kullanılanAdet << ' ' << birimFiyati << "\n";
                    }


                }
                DosyaYaz.close();
                DosyaOku.close();
                remove("hakedişDosyası.txt");
                rename("hakedişDosyası.tmp", "hakedişDosyası.txt");
                cout << "başka ürün silecek misiniz?" << endl;
                cin >> cevap;
            } while (!(cevap == 'H' || cevap == 'h'));
            cout << " İŞLEM TAMAMLANDI...YAPMAK İSTEDİĞİNİZ DİĞER İŞLEM NUMARASINI GİRİNİZ:";
            cin >> secim3;

        }
        if (secim3 == 4)
        {
            int ArananNo3;
            cout << "GÜNCELLEMEK İSTEDİĞİNİZ ÜRÜNÜN NOSUNU GİRİNİZ:" << endl;
            cin >> ArananNo3;
            ifstream DosyaOku("hakedişDosyası.txt");
            ofstream DosyaYaz("hakedişDosyası.tmp");
            do
            {
                while (!DosyaOku.eof())
                {
                    DosyaOku >> donem >> ProjeNo >> UrunNo >> urunAdi >> kullanılanAdet >> birimFiyati;
                    if (ArananNo3 == UrunNo)
                    {
                        cout << "\n Dosyadaki Kayıt: \n" << endl;
                        cout << UrunNo << endl;
                        cout << urunAdi << endl;
                        cout << kullanılanAdet << endl;
                        cout << birimFiyati << endl;
                        cout << "\n Kayıt İçin Yeni Değerler Girin" << endl;
                        cout << "URUN NO:"; cin >> UrunNo;
                        cout << "URUN ADI:"; cin >> urunAdi;
                        cout << "KULLANILAN ADET:"; cin >> kullanılanAdet;
                        cout << "ÜRÜNÜN BİRİM FİYATI:"; cin >> birimFiyati;
                        DosyaYaz << donem << ' ' << ProjeNo << ' ' << UrunNo << ' ' << urunAdi << ' ' << kullanılanAdet << ' ' << birimFiyati << "\n";


                    }
                    else
                    {
                        DosyaYaz << donem << ' ' << ProjeNo << ' ' << UrunNo << ' ' << urunAdi << ' ' << kullanılanAdet << ' ' << birimFiyati << "\n";
                    }
                }
                DosyaYaz.close();
                DosyaOku.close();
                remove("hakedişDosyası.txt");
                rename("hakedişDosyası.tmp", "hakedişDosyası.txt");
                cout << "başka ürün güncelleyecek misiniz?" << endl;
                cin >> cevap;
            } while (!(cevap == 'h' || cevap == 'H'));
            cout << " İŞLEM TAMAMLANDI...YAPMAK İSTEDİĞİNİZ DİĞER İŞLEM NUMARASINI GİRİNİZ:";
            cin >> secim3;
        }
        if (secim3 == 5)
        {
            ifstream DosyaOku("hakedişDosyası.txt");
            cout << "KULLANILAN ÜRÜNLERİN LİSTESİ:" << endl;
            while (DosyaOku >> donem >> ProjeNo >> UrunNo >> urunAdi >> kullanılanAdet >> birimFiyati)
            {
                cout << urunAdi << endl;

            }DosyaOku.close();
            cout << " İŞLEM TAMAMLANDI...YAPMAK İSTEDİĞİNİZ DİĞER İŞLEM NUMARASINI GİRİNİZ:";
            cin >> secim3;


        }
        if (secim3 == 6)
        {
            ifstream DosyaOku("hakedişDosyası.txt");
            int no2;

            cout << "kullanılan ürünlerden görmek istediğiniz ürünün nosunu giriniz:" << endl;
            cin >> no2;
            do
            {
                if (no2 == UrunNo)
                {
                    DosyaOku >> donem >> ProjeNo >> UrunNo >> urunAdi >> kullanılanAdet >> birimFiyati;
                    cout << "ÜRÜN ADI: " << urunAdi << endl;
                    cout << "ÜRÜN NO: " << UrunNo << endl;
                    cout << "BİRİM FİYATI: " << birimFiyati;

                }
                cout << "BAŞKA ÜRÜN LİSTEYECEK MİSİNİZ?" << endl;
                cin >> cevap;

            } while (!(cevap == 'h' || cevap == 'H'));
            cout << " İŞLEM TAMAMLANDI...YAPMAK İSTEDİĞİNİZ DİĞER İŞLEM NUMARASINI GİRİNİZ:";
            cin >> secim3;

        }
        
        if (secim3==7)
        {
            return 0;

        }

    }
      
       
          
    if (secim==10)
    {
        return 0;
    }

}

