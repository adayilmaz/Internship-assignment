//
//  main.cpp
//  internship assignment
//
//  Created by Ada Yılmaz on 22.03.2023.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Masa {
    int bahis; //200-5000
    int masaTipi; // 0100 -> hızlı, 0010 -> teke tek, 0001 -> rövanş
    
    Masa(int bahis_, int tip_): bahis(bahis_), masaTipi(tip_){}
};

int main() {
    
    bool incorrectAnswer = true;
    string cevap;
    int tip=0, minBahis, maxBahis;
    
    vector<Masa> Masalar = { {500,6}, {2000,3}, {100,4}, {3500,1}, {1200,0}, {2000,5}, {350,2}, {800,6}, {4500,5}, {500,3}, {2000,7}, {100,1}, {3500,2}, {1200,4}, {2000,6}, {350,5}, {800,4}, {4500,2}}, uygunMasalar;
    
    
    while(incorrectAnswer){
        cout << "200$ - 5.000$ aralığında arzu ettiğiniz minimum ve maximum bahis miktarlarını giriniz: ";
        cin >> minBahis >> maxBahis;
        
        if(minBahis >= 200 && minBahis <= 5000 && maxBahis >= 200 && maxBahis <= 5000){
            incorrectAnswer = false;
        }else{
            cout << "Bahis miktarınız belirtilen değer aralığında olmalıdır." << endl;
        }
    }
    
    cout << "Hızlı oyun (Evet/Hayır): ";
    cin >> cevap;
    if(cevap == "Evet"){ tip |= 4; }

    cout << "Teke tek oyun (Evet/Hayır): ";
    cin >> cevap;
    if(cevap == "Evet"){ tip |= 2; }
    
    cout << "Rövanş oyunu (Evet/Hayır): ";
    cin >> cevap;
    if(cevap == "Evet"){ tip |= 1; }
    
    
    
    cout << endl << "Seçimlerinize uygun masalar: " << endl;

    for(auto &masa: Masalar){
        if(masa.bahis <= maxBahis && masa.bahis >= minBahis && masa.masaTipi == tip){
            uygunMasalar.push_back(masa);
            
            cout << "Bahis miktarı: " << masa.bahis;
            if(tip&4){
                cout << "\t Hızlı";
            }
            if(tip&2){
                cout << "\t Teke tek";
            }
            if(tip&1){
                cout << "\t Rövanş";
            }
            cout << endl;
        }
    }
    
    
    return 0;
}
