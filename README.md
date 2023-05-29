

Naudojimosi instrukcija:

 Kopijuoti repozitoriją: git clone https://github.com/LauritaR/objektinio-projektas2.git

 Pereiti į nukopijuotą repozitoriją: cd{aplanko pavadinimas}/objektinio-projektas2

 Pasirinkti norimą vektorio realizaciją: cd {vector_class/vector_struct}

 Kompiliuoti programą su Makefile pagalba: make

 Paleisti programą: .\main

--------------------------------------------------------
V1.2
--------------------------------------------------------

1.2 programos 'vector_class' versijoje buvo realizuota "Rule of five"

--------------------------------------------------------
V1.1
--------------------------------------------------------
1.1 versija buva sukurta naujoje repozitorijoje, bet visa ansktesnių versijų istorija išliko.

Buvo išrinkta greičiausiai veikianti programa vykdoma su 2 strategija ir naudojanti std::vector konteinerį.
Programos efektyvumo pagerinimui papildomai buvo pakeista skaitymo 
funckija(void skaitymas(string read_studentukas, vector<studentukas>& stud)). 
Subrepozitorijoje esantys 2 failai:

- vector_class, kur struktūra(struct) studentukas pakeista į klasę(class)
- vector_struct, kur išliko struktūra(struct), bet rezultatų palyginimo tikslumui,
  buvo taip pat pakeista skaitymo funkcija.
--------------------------------------------------------
Spartos analizė
--------------------------------------------------------
*100.000* eilučių programa

|Metodas     |Prog. laikas(s)|
|------------|---------------|
|class       |0.90582        |
|struct      |0.725655       |

*1.000.0000* eilučių programa
|Metodas     |Prog. laikas(s)|
|------------|---------------|
|class       |8.49505        |
|struct      |8.13277        |


---------------------------------------------------------
Optimizavimo flag'ų analizė
--------------------------------------------------------
Analizė vykdoma su 10.000.000 eilučių failu.

|Flag        |Prog. laikas(s)|.exe failo dydis|
|------------|---------------|----------------|
|be flag'o   |101.19         |306KB           |                      
|-O1         |93.8994        |306KB           |
|-O2         |92.5572        |307KB           |
|-O3         |90.8742        |309KB           |

--------------------------------------------------------
V1.0
--------------------------------------------------------
1.0 versijoje pakeista:
- 1 strategijos aplanke yra 3 programos(deque, vector, list), kuriose funkcija *skirstymas* 
iš bendro konteinerio skirsto studentus į du naujus konteinerius(vargšeliai ir šaunuoliai).
- 2 strategijos aplanke yra 3 programos(deque, vector, list), kuriose funkcija *skirstymas*
iš bendro konteinerio išrenka studentus, kurių galutinis pažymys žemesnis nei 5.0 ir perkelia į
vargšelių konteinerį, o studentai pasilikę bendrame yra įrašomi į failą "šaunuoliai.txt".

Papildomai:
- programa vykdoma su lietuviškomis raidėmis
- vietoje atskiros palyginimo funkcijos naudajama lambda f-ja
- 2 strategijoje naudojami std::partition ir std::erase algoritmai  
----------------------------------------------------------------------------------------
Atminties sunaudojimo analizė( su 10 milijonų eilučių failu)
-------------------------------

|Iki programos paleidimo |5.3 GB iš 8 GB |
|------------------------|---------------|
|1 strategija            | 7.9 GB iš 8 GB|
|2 strategija            | 6.5 GB iš 8 GB|
------------------------------------------

Spartos analizė
---------------------------
1 strategija 
------------
std::vector

|Įrašų sk.   |Skirstymas(s)|
|------------|------------ |
|1000        |0.0003532    |
|10000       |0.0048455    |
|100000      |0.0377872    |
|1000000     |0.348431     |
|10000000    |3.90934      |
---------------------------------------------------------

std::list

|Įrašų sk.   |Skirstymas(s)|
|------------|------------ |
|1000        |0.0015332    |
|10000       |0.0141803    |
|100000      |0.154896     |
|1000000     |1.4539       |
|10000000    |20.6571      |
---------------------------------------------------------

std::deque

|Įrašų sk.   |Skirstymas(s)|
|------------|------------ |
|1000        |0.0008126    |
|10000       |0.0094796    |
|100000      |0.0976827    |
|1000000     |0.992627     |
|10000000    |110.854      |
---------------------------------------------------------

2 strategija 
std::vector

|Įrašų sk.   |Skirstymas(s)|
|------------|------------ |
|1000        |0.0002473    |
|10000       |0.003065     |
|100000      |0.0407415    |
|1000000     |0.412657     |
|10000000    |2.67465      |
---------------------------------------------------------

std::list

|Įrašų sk.   |Skirstymas(s)|
|------------|------------ |
|1000        |0.0008075    |
|10000       |0.0128341    |
|100000      |0.188565     |
|1000000     |1.36492      |
|10000000    |17.9615      |
---------------------------------------------------------

std::deque

|Įrašų sk.   |Skirstymas(s)|
|------------|------------ |
|1000        |0.0007834    |
|10000       |0.0082497    |
|100000      |0.0851111    |
|1000000     |0.883319     |
|10000000    |142.217      |
---------------------------------------------------------

Nors atminties išnaudojimas 2 strategijoje yra visais atvejais efektyvesnis,
studentų skirstymo greitis ne visada yra efektyvesnis už skirstymo trukmę 1 strategijos programose.

------------------------------------------------------
V0.5
-----------------------------------------------------
0.5 versijoje pakeista:
sukurtos 3 atskiros programos

-programa išsauganti duomenis į std::list

-programa išsauganti duomenis į std::vector

-programa išsauganti duomenis į std::deque

--------------------------------------------------------
Spartos analizė
--------------------------------------------------------
Įvykdyta su std::vector,std::list, std::deque konteineriais.
Analizei vykdyti naudojamo kompiuterio savybės: 
-------------------------------------------------
|CPU | Intel(R) Core(TM) i5-10300H CPU @ 2.50GHz|
|----|------------------------------------------| 

|RAM |8.0 GB 2933 MHz SODIMM                    |
|----|------------------------------------------|

|SSD |SAMSUNG MZALQ256HAJD-000L2 239 GB         |
-----|------------------------------------------|

--------------------------------------------------------------------------------------
std::vector

|Įrašų sk.   |Nuskaitymas(s)|Rūšiavimas(s)|Skirstymas(s)|
|------------|--------------|-------------|------------ |
|1000        |0.0445709     |0.0023148    |0.0004537    |
|10000       |0.073733      |0.0253448    |0.0048455    |
|100000      |0.195798      |0.321578     |0.0377872    |
|1000000     |1.80126       |4.05832      |0.348431     |
|10000000    |20.1031       |55.2349      |3.90934      |
---------------------------------------------------------

std::list

|Įrašų sk.   |Nuskaitymas(s)|Rūšiavimas(s)|Skirstymas(s)|
|------------|--------------|-------------|------------ |
|1000        |0.0055231     |0.0027437    |0.0031706    |
|10000       |0.0591407     |0.0681479    |0.0164697    |
|100000      |0.408577      |0.673232     |0.201093     |
|1000000     |3.43773       |7.87552      |1.58105      |
|10000000    |30.6906       |88.0197      |21.5473      |
---------------------------------------------------------

std::deque

|Įrašų sk.   |Nuskaitymas(s)|Rūšiavimas(s)|Skirstymas(s)|
|------------|--------------|-------------|------------ |
|1000        |0.0342992     |0.0124093    |0.0018943    |
|10000       |0.0702745     |0.130872     |0.0146999    |
|100000      |0.316461      |1.4222       |0.149341     |
|1000000     |5.32126       |12.9749      |1.38838      |
|10000000    |30.6344       |224.296      |115.064      |
---------------------------------------------------------
Iš spartos analizės rezultatų galima pastebėti, kad greičiausiai programa veikia su std::vector ir lėčiausiai su std::deque
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------
V.04 
-----------------------------------------------------------------------------
0.4 versijoje kodas pakeistas:

-sukurtas failų generatorius

-įrašus iš .txt failo galima surūšiuti pagal tam  tikrą kriterijų(pvz. galutinis pažymys)

-suriūšiuoti duomenys išvedami į 2 naujus failus

--------------------------------------------------------
Spartos analizė
--------------------------------------------------------
Iki releaso


|Įrašų sk.   |Generavimas(s)|Nuskaitymas(s)|Rūšiavimas(s)|Išvedimas(s)|Visos prog.laik.(s)|
|------------|--------------|--------------|-------------|------------|-------------------|
|1000        |0.0401525     |0.00708       |0.0105061    |0.010035    |0.0163428          |
|10000       |0.0254473     |0.0202221     |0.0485532    |0.0120231   |0.0965676          |
|100000      |0.231143      |0.195783      |0.505575     |0.094424    |0.648843           |
|1000000     |2.10708       |1.71754       |5.93503      |0.914495    |7.08606            |
|10000000    |31.5851       |21.2639       |77.7104      |16.13       |98.1792            |
-------------------------------------------------------------------------------------------
Po releaso

|Įrašų sk.   |Generavimas(s)|Nuskaitymas(s)|Rūšiavimas(s)|Išvedimas(s)|Visos prog.laik.(s)|
|------------|--------------|--------------|-------------|------------|-------------------|
|1000        |0.0078938     |0.0021552     |0.0048234    |0.0281778   |0.0341907          |
|10000       |0.0388958     |0.019212      |0.0466427    |0.0110271   |0.0623391          |
|100000      |0.203583      |0.172811      |0.487787     |0.092127    |0.603963           |
|1000000     |1.87688       |1.65513       |5.80829      |0.877655    |6.92962            |
|10000000    |17.4462       |17.9229       |71.4164      |17.8583     |92.7657            |
-------------------------------------------------------------------------------------------


V.03
---------------------------------------------------------------------------------------------
0.3 versijoje kodas pakeistas:
- kodo reorganizavimu į kelias atskiras dalis("fun.cpp" funkcijų failas, "fun.h" su funkcijų header'iais)
- try catch exception handling 


-----------------------------------------------------------------------------------------------
V.02
-----------------------------------------------------------------------------------------------
0.2 versijoje kodas vectorprog.cpp papildytas:
- duomenų skaitymu iš failo
- duomenų išvedimu lentelės pavidalu su galutiniu pažymiu(vidurkiu ir atskirai mediana) ir rūšiavimu pagal vardą
- try catch exception handling

Papildomi du failai(kursiokai.txt, output.txt) įkelti kaip pavyzdys.

--------------------------------------------------------------------------------------------------
V.01
--------------------------------------------------------------------------------------------------
0.1 versijoje kodas papildytas:

- Kodas Cmasyvas.cpp atliktas naudojant dinaminius masyvus. 
- Kodas vectorprog.cpp atliktas naudojant vektorius. 
- Abu jie kreipiasi į failą mylib.h.
 
