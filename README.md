Task1

Am scris trei functii: palindrom, prim si traseuC. 
Prima functie, palindrom, primeste ca argument un numar, construieste rasturnatul acestuia si verifica daca este egal cu auxiliarul, adica numarul initial. 
A doua functie, prim, parcurge prin for toate numerele de la 2 pana la n/2, iar daca nu se gaseste niciun divizor, returneaza 1. Daca se gaseste unul sau mai multi divizori, atunci returneaza 0. 
A treia functie, traseu C, calculeaza o suma circulara, adunandu-se numerele de K ori din K in K cifre. In momentul in care mai exista numere de adunat (cont != 0), suma creste cu elementul din vector de pe pozitia cont2%N.
In SolveTask1() se citeste marimea coloanelor si a randurilor matricei, dupa care se citeste sirul de caractere. Primul for calculeaza lungimea sirului, parcurgandu-l pana la intalnirea lui \0.  
In continuare, se parcurge sirul de caractere, iar la intalnirea unui spatiu sau atingerea lungimii sirului, se imparte sirul in mai multe subsiruri. Astfel, daca sirul cod incepe cu a, cauta pe ce indice se afla cifra cea mai mare din sir, existand patru ifuri, fiecare producand o miscare diferita in matrice, iar contorul de miscare crescand cu 1. Daca sirul incepe cu litera b, conversteste cifrele aflate dupa aceasta intr-un numar intreg. Se verifica daca numarul e palindrom si daca ultimele doua cifre ale acestuia formeaza un numar prim, pentru fiecare if existand cate o miscare diferita in matrice. Daca sirul incepe cu litera c, primele doua cifre de dupa aceasta sunt convertite in int. Ulterior, restul cifrelor, mai putin cele doua sunt stocate sub forma de inturi intr-un vector u. Primele doua cifre, alaturi de vectorul cel din urma, sunt trimise in functia traseuC, verificandu-se in patru ifuri cat da suma circulara % 4. In functie de rezultat, in matrice se produce o miscare diferita.
La final se afiseaza matricea.

Task2

Am facut trei functii: Caesar, Vigenere si Addition, primele doua descifrand in functie de o cheie un cod, iar a treia adunand doua numere dupa ce au fost descifrate. Caesar primeste ca argumente cheia (sub forma de int), sirul si lungimea sirului. In continuare, se parcurge sirul si transforma caracterele in codul ASCII cuvenit lor. Astfel, avem trei ifuri: pentru numere, litere mici si litere mari.
Pentru numere, este o problema cand cheia depaseste numarul de cifre din baza 10, asa ca o micsoram prin k = K%ZECE. Se verifica daca rezultatul scaderii u[i] - k se afla in afara intervalului ASCII repartizat numerelor, si in functie de unde se afla u[i], se descifreaza codul . Astfel u[i] devine u[i] - k + ZECE sau u[i] - k.
Al doilea si al treilea if se comporta similar cu primul, numai ca din u[i] scadem cheia primita ca argument si se verifica daca rezultatul apartine intervalului ASCII destinat literelor mari si, respectiv, celor mici.
Vigenere primeste drept argumente sirul, cheia (sub forma de sir), lungimea sirului si lungimea cheii. In primul for se extinde cheia astfel incat sa fie de lungimea sirului, este transformat fiecare element al acesteia in cod ASCII si se scade 65 din el.
Se parcurge sirul si se descifreaza elementul din vectorul u de pe pozitia i.
Pentru numere, cheia care este  elementul (sub forma de int) de pe pozitia i din vectorul kext % ZECE. Ulterior se procedeaza ca la Caesar.
La final se afiseaza u[i].
Addition primeste ca argumente doua siruri, lungimile lor si o cheie (care este sub forma de int). Se construiesc doi vectori in int (un si vn) ce contin toate numerele descifrate.. 
Avem un while care construieste un vector, sum, adunand numerele atat timp cat ambele au acelasi numar de cifre.
La final, se afiseaza elementele vectorulului sum incepand cu pozitia cont pana la 0.
In SolveTask2() se citeste numarul taskului, codul taskului (caesar / vigenere / addition) , si in functie de acesta apeleaza fucntiile.

Task3

Am facut o functie de citire a sirului, ce citeste caracter cu caracter pana la intalnirea lui EOF.
In SolveTask3() parcurgem sirul si, adaugam intr-o matrice de charruri, pe cate un rand, cate un cuvant din sir.
Urmatorul while verifica daca pe ultimul rand al matricei se afla un caracter care nu este o litera si , in cazul asta, micsoreaza dimensiunea matricei. In continuare, un for formeaza perechile de cuvinte alaturate. Urmeaza doua foruri ce gasesc numarul de aparitii pentru o pereche de cuvinte, si atunci cand, se repeta de mai multe ori, in matricea pairs raman doar perechile unice. Pentru fiecare pereche unica, numarul de aparatii si suma totala cresc.
La final se afiseaza suma pe primul rand, dupa care cate o pereche de cuvinte alaturi de numarul ei de aparitii.