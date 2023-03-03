#include "fun.h"

int main()
{ 
    vector<studentukas> mas;
    studentukas laikinas;
    string pavadinimas,ats;
    while(ats!="f"&&ats!="i")
    {
        cout<<"duomenu ivedimas ranka(i) ar nuskaitymas is failo(f)?(i/f)";
        cin>>ats; 
    }
    if(ats=="f")
    {
        cout<<"Irasykite failo pavadinima: ";
        cin>>pavadinimas;
        skaitymas(pavadinimas,"output.txt");  
        
        cout<<"\nStudentu duomenys sekmingai isvesti i faila 'output.txt'";
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
   mas.clear();   
}

return 0;
}
