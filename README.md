Diegimo ir naudojimo instrukcija:

Diegimas:
Atsidarome projekto Github repozitorija, paspaudžiame ant mygtuko "Code" ir nukopijuojame repozitorijos nuorodą. Atsidarome komandinę eilutę, pasirenkame, kur norime atsisiųsti programą ir klonuojame repozitoriją įklijuodami "git clone https://github.com/mantas001/Projektas-1.git" į komandinę eilutę. Nusigauname vietą kurioje išsaugojome programą įrašydami cd "programos_vieta". (Jei įrenginyje nėra su'setup'intas Makefile, daugiafailės programos kompiliavimui, sekite šią nuorodą -> https://github.com/mantas001/Projektas-1/tree/v1.0 ). Tuomet į komandinę eilutę irašome "make"(tai sukompiliuoja programą) ir "main" - programa paleista.


Naudojimas:
Parinktis "1" apskaičiuoja studento vidurkį su naudotojo įvestais duomenimis. Visais atvejais studentai r86iuojami pagal pasirinktą kriterijų: vardą, pavardę, galutinį įvertinimą didėjimo arba mažėjimo tvarka.
Parinktis "2" generuoja studento pazymius, bet reikalauja įvesti studento vardą ir pavardą.
Parinktis "3" generuoja visus studento duomenis
Parinktis "4" nuskaito duomenis iš failo kuriuos turime.
Parinktis "5" generuoja naujus duomenis.
Parinktis "6" suskirsto studentus į "vargšus" ir "šaunuolius" priklausomai ar jų vidurkis <5 ar >=5. 
Parinktis "7" baigia programos darbą.



****************************************************************
Testavimo sistemos parametrai:
RAM: 16GB, 3200 MHz
CPU: Processor	12th Gen Intel(R) Core(TM) i7-12650H, 2300 Mhz, 10 Core(s), 16 Logical Processor(s)
SSD: 
****************************************************************
V1.0 pradinė:
Konteinerių pakeitimas:
Naudojant vector ir deque tipo konteinerius nuskaitymo, rikiavimo ir įrašymo laikai beveik sutampa (naudojant deque tipo konteinerį programa dirba šiek tiek sparčiau, bet labai minimaliai), o list tipo konteinerio laikai, palyginus su vector ir deque, gerokai išauga - skirtumas akivaizdus. Šiuo atveju list tipo konteinerio naudoti neverta.


2 strategija:
Iš pagrindinio visų studentų konteinerio, "vargšams" atskirti buvo pasirinktas std::partition algoritmas ir pritaikytas programoms su vector, deque ir list konteineriais. Visiems konteinerių tipams sukuriant tik vieną naują konteinerį, vietoje dviejų, programos paspartėja.


3 strategija:
Pratestavus kitus rikiavimo algoritmus (pvz.: "std::remove_copy_if" ir "std::stable_partition"), antroje strategijoje pasirinktas "std::partition" algoritmas "šaunuoliams" ir "vargšams" atskirti  yra efektyviausias iš pateiktų, todėl nereikia jo pakeisti kitu.  


****************************************************************
****************************************************************
Vector konteineriai: 1 strategija:

Nuskaityti 1 000 irasu uztruko: 0.012904 s. 
Surikiuoti 1 000 irasu uztruko: 0.001041 s. 
Irasyti    1 000 irasu uztruko: 0.014665 s.

Nuskaityti 10 000 irasu uztruko: 0.096011 s. 
Surikiuoti 10 000 irasu uztruko: 0.007021 s. 
Irasyti    10 000 irasu uztruko: 0.088916 s.

Nuskaityti 100 000 irasu uztruko: 0.949501 s. 
Surikiuoti 100 000 irasu uztruko: 0.051738 s. 
Irasyti    100 000 irasu uztruko: 0.72446 s.

Nuskaityti 1 000 000 irasu uztruko: 9.31908 s. 
Surikiuoti 1 000 000 irasu uztruko: 0.538232 s.
Irasyti    1 000 000 irasu uztruko: 6.82153 s.

10 mil. eil.:
terminate called after throwing an instance of 'std::bad_alloc' 
what(): std::bad_alloc
(blogas duomenų nuskaitymo būdas)


2 strategija:

Nuskaityti 1 000 irasu uztruko: 0.012008 s.
Surikiuoti 1 000 irasu uztruko: 0.001003 s.
Irasyti    1 000 irasu uztruko: 0.013925 s.

Nuskaityti 10 000 irasu uztruko: 0.123071 s.
Surikiuoti 10 000 irasu uztruko: 0.004986 s.
Irasyti    10 000 irasu uztruko: 0.097473 s.

Nuskaityti 100 000 irasu uztruko: 1.01313 s.
Surikiuoti 100 000 irasu uztruko: 0.035899 s.
Irasyti    100 000 irasu uztruko: 0.837834 s.

Nuskaityti 1 000 000 irasu uztruko: 9.98174 s.
Surikiuoti 1 000 000 irasu uztruko: 0.44293 s.
Irasyti    1 000 000 irasu uztruko: 7.7985 s.
****************************************************************
Deque konteineriai: 1 strategija:

Nuskaityti 1 000 irasu uztruko: 0.010996 s.
Surikiuoti 1 000 irasu uztruko: 0.0011 s. 
Irasyti    1 000 irasu uztruko: 0.016981 s.

Nuskaityti 10 000 irasu uztruko: 0.095798 s.
Surikiuoti 10 000 irasu uztruko: 0.009556 s.
Irasyti    10 000 irasu uztruko: 0.072575 s.

Nuskaityti 100 000 irasu uztruko: 0.954725 s.
Surikiuoti 100 000 irasu uztruko: 0.068273 s.
Irasyti    100 000 irasu uztruko: 0.775124 s.

Nuskaityti 1 000 000 irasu uztruko: 9.23689 s.
Surikiuoti 1 000 000 irasu uztruko: 0.687518 s.
Irasyti    1 000 000 irasu uztruko: 6.70069 s.

10 mil. eil.:
terminate called after throwing an instance of 'std::bad_alloc' 
what(): std::bad_alloc


2 strategija:

Nuskaityti 1 000 irasu uztruko: 0.010045 s.
Surikiuoti 1 000 irasu uztruko: 0.001002 s.
Irasyti    1 000 irasu uztruko: 0.027498 s.

Nuskaityti 10 000 irasu uztruko: 0.100159 s.
Surikiuoti 10 000 irasu uztruko: 0.005029 s.
Irasyti    10 000 irasu uztruko: 0.081226 s.

Nuskaityti 100 000 irasu uztruko: 1.01263 s.
Surikiuoti 100 000 irasu uztruko: 0.054307 s.
Irasyti    100 000 irasu uztruko: 0.853053 s.

Nuskaityti 1 000 000 irasu uztruko: 10.1878 s.
Surikiuoti 1 000 000 irasu uztruko: 0.608668 s.
Irasyti    1 000 000 irasu uztruko: 8.02444 s.
****************************************************************
List konteineriai: 1 strategija:

Nuskaityti 1 000 irasu uztruko: 0.015074 s.
Surikiuoti 1 000 irasu uztruko: 0.003012 s.
Irasyti    1 000 irasu uztruko: 0.015409 s.

Nuskaityti 10 000 irasu uztruko: 0.152652 s.
Surikiuoti 10 000 irasu uztruko: 0.017703 s.
Irasyti    10 000 irasu uztruko: 0.312522 s.

Nuskaityti 100 000 irasu uztruko: 1.51064 s.
Surikiuoti 100 000 irasu uztruko: 0.162504 s.
Irasyti    100 000 irasu uztruko: 0.753468 s.

Nuskaityti 1 000 000 irasu uztruko: 14.8636 s.
Surikiuoti 1 000 000 irasu uztruko: 1.57861 s.
Irasyti    1 000 000 irasu uztruko: 7.05502 s.

10 mil. eil.:
terminate called after throwing an instance of 'std::bad_alloc' 
what(): std::bad_alloc


2 strategija:

Nuskaityti 1 000 irasu uztruko: 0.016327 s.
Surikiuoti 1 000 irasu uztruko: 0.001 s.
Irasyti    1 000 irasu uztruko: 0.011999 s.

Nuskaityti 10 000 irasu uztruko: 0.157058 s.
Surikiuoti 10 000 irasu uztruko: 0.004992 s.
Irasyti    10 000 irasu uztruko: 0.089187 s.

Nuskaityti 100 000 irasu uztruko: 1.59633 s.
Surikiuoti 100 000 irasu uztruko: 0.038583 s.
Irasyti    100 000 irasu uztruko: 1.04881 s.

Nuskaityti 1 000 000 irasu uztruko: 15.5888 s.
Surikiuoti 1 000 000 irasu uztruko: 0.369327 s.
Irasyti    1 000 000 irasu uztruko: 7.9851 s.
****************************************************************