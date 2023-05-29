#include "fun.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
//rule of five testai
    vector<studentukas> mas;
    studentukas laikinas;
    string pavadinimas,ats="";
     
    studentukas obj1("Studentas", "Studentaitis", {5,4,10}, 10);
    studentukas obj2(obj1);
    studentukas obj3;
    obj3=obj1;
    cout<<obj1<<'\n'<<obj2<<'\n'<<obj3<<'\n';
    studentukas obj4(std::move(obj3));
    cout<<obj3<<'\n'<<obj4<<'\n';
    studentukas obj5;
    obj5=std::move(obj4);
    cout<<obj4<<'\n'<<obj5<<'\n';
//testu pabaiga
    while(ats!="f"&&ats!="i"&&ats!="g"&&ats!="s"&&ats!="e")
    {
        cout<<"-Duomenų įvedimas ranka(i)\n-Nuskaitymas iš failo(f)\n-Failo generavimas(g)\n-Failo skirstymas(s)\n-Išeiti(e)\n----Įveskite raidę----\n";
        cin>>ats; 
    }
    if(ats=="f")
    {  
        cout<<"Įrašykite failo pavadinimą: ";
        cin>>pavadinimas;
     
        skaitymas(pavadinimas,mas); 
        rasymas("output.txt",mas);
        
        cout<<"\nStudentų duomenys sėkmingai išvesti į failą 'output.txt'";   
    }
    else if(ats=="g")
    {
        cout<<"Irašykite failo pavadinimą: ";
        cin>>pavadinimas; 
        auto start = std::chrono::high_resolution_clock::now(); 
        fileGen(pavadinimas);  
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> difference = end - start;
        cout <<"Visas programos laikas:" << difference.count() << " s\n"; 
    }
    else if(ats=="s")
    {
        cout<<"Irašykite failo pavadinimą: ";
        cin>>pavadinimas; 
        auto start = std::chrono::high_resolution_clock::now(); 
        skirstymas(pavadinimas);  
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> difference = end - start;
        cout <<"Visas programos laikas:" << difference.count() << " s\n"; 
    }
    else if(ats=="i")
    {
       do{
        pildyk(laikinas);
        mas.push_back(laikinas);
        laikinas.laisvinamaVieta();

        do
        {
        cout<<"Ar norite įvesti informaciją apie kitus studentus?(t/n)?";
        cout<<"t-pridėti studentą, n-baigti įvedimą"<<endl;
        cin>>ats;
        if ((ats != "t") && (ats != "n")) {
            cout << "Neteisingas pasirinkimas. Prašome ivesti 't' arba 'n'." << endl;
        }
        }while((ats!="t")&&(ats!="n"));
        }while(ats=="t");
        
        cout<<setw(30)<<left<<"Vardas"<<setw(30)<<left<<"Pavardė"<<setw(30)<<left<<"Galutinis(vid)"<<setw(30)<<left<<"Galutinis(med)"<<endl;
        cout<<setw(20)<<"-----------------------------------------------------------------------------------------------------------"<<endl; 
        for(auto &i: mas)
        {
        spausdinimas(i); 
        }
        for(auto &i: mas) 
        {
         i.laisvinamaVieta();
        }
         mas.clear();   
    }
    else if(ats=="e")
    {
        exit(0);
    }
return 0;
}
