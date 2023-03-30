#include "fun.h"

int main()
{ 
    list<studentukas> mas;
    studentukas laikinas;
    string pavadinimas,ats;

    while(ats!="f"&&ats!="i"&&ats!="g"&&ats!="s")
    {
        cout<<"-Duomenu ivedimas ranka(i)\n-Nuskaitymas is failo(f)\n-Failo generavimas(g)\n-Failo skirstymas(s)\n----Iveskite raide----\n";
        cin>>ats; 
    }
    if(ats=="f")
    {  
        cout<<"Irasykite failo pavadinima: ";
        cin>>pavadinimas;
     
        skaitymas(pavadinimas,mas); 
        rasymas("output.txt",mas);
        
        cout<<"\nStudentu duomenys sekmingai isvesti i faila 'output.txt'";   
    }
    else if(ats=="g")
    {
        cout<<"Irasykite failo pavadinima: ";
        cin>>pavadinimas; 
        auto start = std::chrono::high_resolution_clock::now(); 
        fileGen(pavadinimas);  
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> difference = end - start;
        cout <<"visas programos laikas:" << difference.count() << " s\n"; 
    }
    else if(ats=="s")
    {
        cout<<"Irasykite failo pavadinima: ";
        cin>>pavadinimas; 
        auto start = std::chrono::high_resolution_clock::now(); 
        skirstymas(pavadinimas);  
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> difference = end - start;
        cout <<"visas programos laikas:" << difference.count() << " s\n"; 
    }
    else if(ats=="i")
    {
       do{
        pildyk(laikinas);
        mas.push_back(laikinas);
        laikinas.pazymiukai.clear();

        while((ats!="t")&&(ats!="n"))
        {
        cout<<"Ar norite ivesti informacija apie kitus studentus?(t/n)?";
        cout<<"t-prideti dar studenta, n-baigti ivedima"<<endl;
        cin>>ats;
        }
        }while(ats=="t");
        
        cout<<setw(30)<<left<<"Vardas"<<setw(30)<<left<<"Pavarde"<<setw(30)<<left<<"Galutinis(vid)"<<setw(30)<<left<<"Galutinis(med)"<<endl;
        cout<<setw(20)<<"-----------------------------------------------------------------------------------------------------------"<<endl; 
        for(auto &i: mas)
        {
        spausdinimas(i); 
        }
        for(auto &i: mas) 
        {
         i.pazymiukai.clear();
        }
           
    }
 mas.clear();
return 0;
}
