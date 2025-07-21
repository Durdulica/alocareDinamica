#ifndef EXERCITII_H
#define EXERCITII_H
#include <iostream>
using namespace std;

void afisVec(const int* arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int* stergerePoz(int *arr, int&n,int poz) {

    int *scrie = new int[n - 1]{};

    for(int i = poz; i < n; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    for(int i = 0; i < n; i++) {
        scrie[i] = arr[i];
    }

    delete[]arr;
    return scrie;
}

void ex1() {
    int n = 8, poz = 3;
    int *arr = new int[n]{1, 2, 3, 4, 5, 6, 7, 8};

    arr = stergerePoz(arr, n, poz);
    delete[] arr;
}

int* inserarePoz(int *arr, int&n, int poz) {
    int *scrie = new int[n + 1]{};
    for(int i = n; i > poz; i--) {
        scrie[i] = arr[i - 1];
    }

    n++;

    for(int i = 0; i <= poz; i++) {
        scrie[i] = arr[i];
    }

    delete[] arr;
    return scrie;
}

void ex2() {
    int n = 8, poz = 3;
    int *arr = new int[n]{1, 2, 3, 4, 5, 6, 7, 8};

    arr = inserarePoz(arr, n, poz);

    delete[] arr;
}

//se da un vec. Sa se stearga din vec. toate elem. care sun nr. prime

bool isPrim(int nr) {
    if(nr < 2) return false;

    for(int i = 2; i <= nr / 2; i++) {
        if(nr % i == 0) return false;
    }
    return true;
}

int* stergerePrimeVec(int *arr, int&n) {
    for(int i = 0; i < n; i++) {
        if(isPrim(arr[i])) {
            arr = stergerePoz(arr, n, i);
            i--;
        }
    }

    int *scrie = new int[n]{};

    for(int i = 0; i < n; i++) {
        scrie[i] = arr[i];
    }

    delete[] arr;


    return scrie;
}

void ex3() {
    int n = 5;
    int *arr = new int[n]{1,2,3,4,5};

    arr = stergerePrimeVec(arr, n);
    afisVec(arr, n);
    delete[] arr;
}

//sa se stearga dintr-un vec. toate elem. pare

int* stergerePareVec(int *arr, int &n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            arr = stergerePoz(arr, n, i);
            i--;
        }
    }

    int *scrie = new int[n]{};

    for(int i = 0; i < n; i++) {
        scrie[i] = arr[i];
    }

    delete[] arr;

    return scrie;
}

void ex4() {
    int n = 7;
    int *arr = new int[n]{7,9,4,2,1,6,5};

    arr = stergerePareVec(arr, n);
    afisVec(arr, n);
    delete[] arr;
}

//sa se trans. vec. prin duplicarea a fiecare aparitie a val. minime.

int minVec(int *arr, int n) {
    int min = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(arr[i] < min) min = arr[i];
    }
    return min;
}

int* duplicareMinVec(int *arr, int &n) {
    int min = minVec(arr, n);
    for(int i = 0; i < n; i++) {
        if(arr[i] == min) {
            arr = inserarePoz(arr, n, i);
            i++;
        }
    }

    int *scrie = new int[n]{};

    for(int i = 0; i < n; i++) {
        scrie[i] = arr[i];
    }

    delete[] arr;

    return scrie;
}

void ex5() {
    int n = 7;
    int *arr = new int[n]{7,9,4,2,1,6,1};

    arr = duplicareMinVec(arr, n);
    cout << n << endl;
    afisVec(arr, n);

    delete[] arr;
}

//sa se stearga din vec. toate elem. egale cu cea mai mica val. din vec.

int* stergereMinVec(int *arr, int &n) {
    int min = minVec(arr, n);

    for(int i = 0; i < n; i++) {
        if(arr[i] == min) {
            arr = stergerePoz(arr, n, i);
            i--;
        }
    }

    int *scrie = new int[n]{};

    for(int i = 0; i < n; i++) {
        scrie[i] = arr[i];
    }

    delete[] arr;

    return scrie;
}

void ex6() {
    int n = 7;
    int *arr = new int[n]{7,1,4,2,1,6,1};

    arr = stergereMinVec(arr, n);
    afisVec(arr, n);
    delete[] arr;
}

//sa se stearga elem care se repeta dintr-un vec.

struct dubluri {
    int poz;
    int val;
};

dubluri* alocareStruct(dubluri *vec, int &dim, int nr, int&ind) {
    for(int i = 0; i < dim; i++) {
        if(vec[i].val == nr) {
            ind = -1;
            break;
        }
    }

    if(ind != -1) {
        dubluri *temp = new dubluri[dim + 1];
        for(int i = 0; i < dim; i++) {
            temp[i] = vec[i];
        }

        temp[dim].poz = ind;
        temp[dim].val = nr;
        dim++;
        delete[] vec;
        return temp;
    }
    return vec;
}

int* stergereDubluriVec(int *arr, int&n) {
    dubluri *vec = new dubluri[1]{};
    int dim = 0;
    for(int i = 0; i < n; i++) {
        int aux = i;
        vec = alocareStruct(vec,dim,arr[i],i);

        if(i == -1) {
            arr = stergerePoz(arr, n, aux);
            i = aux - 1;
        }
    }

    int *scrie = new int[n]{};

    for(int i = 0; i < n; i++) {
        scrie[i] = arr[i];
    }

    delete[] arr;
    delete[] vec;
    return scrie;
}

void ex7() {
    int n = 6;
    int *arr = new int[n]{1,2,3,2,2,5};

    arr = stergereDubluriVec(arr, n);
    afisVec(arr, n);
    delete[] arr;
}

//sa se insereze in sir dupa fiecare elem. par dublul sau

int* inserareDubluParVec(int *arr, int &n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            arr = inserarePoz(arr, n, i);
            i++;
            arr[i] = arr[i - 1] * 2;
        }
    }

    int *scrie = new int[n]{};
    for(int i = 0; i < n; i++) {
        scrie[i] = arr[i];
    }

    delete[] arr;
    return scrie;
}

void ex8() {
    int n = 5;
    int *arr = new int[n]{7,3,4,1,6};

    arr = inserareDubluParVec(arr, n);
    afisVec(arr, n);

    delete[] arr;
}

//sa se insereze inaintea fiecarui elem. patrat pergect radacina sa patr.

bool ePatrPerf(int nr, int &sqrt) {

    for(int i = 1; i <= nr; i++) {
        if(nr == i * i) {
            sqrt = i;
            return true;
        }
    }
    return false;
}

int* inserareRadacinaVec(int *arr, int &n) {
    for(int i = 0; i < n; i++) {
        int temp = -1;
        if(true) {
            arr = inserarePoz(arr, n, i);
            i++;
            arr[i] = 0;
        }
    }

    int *scrie = new int[n]{};

    for(int i = 0; i < n; i++) {
        scrie[i] = arr[i];
    }

    delete[] arr;
    return scrie;
}

void ex9() {
    int n = 5;
    int *arr = new int[n]{7,3,4,1,9};

    arr = inserareDubluParVec(arr, n);
    cout << n << endl;
    afisVec(arr, n);

    delete[] arr;
}

//sa se insereze intre oricare 2 nr de aceeasi paritate media lor aritmetica

int* inserareMedieVec(int *arr, int &n) {
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] % 2 == arr[i + 1] % 2) {
            arr = inserarePoz(arr, n, i);
            i++;
            arr[i] = (arr[i - 1] + arr[i + 1]) /2;
        }
    }

    int *scrie = new int[n]{};

    for(int i = 0; i < n; i++) {
        scrie[i] = arr[i];
    }

    delete[] arr;
    return scrie;
}

void ex10() {
    int n = 5;
    int *arr = new int[n]{1,21,3,4,8};

    arr = inserareMedieVec(arr, n);
    afisVec(arr, n);

    delete[] arr;
}

//sa se insereze intre oricare 2 nr de aceeasi paritate media lor aritmetica pana nu se mai poate adauga niciun elem. nou

int* inserareMedieVec1(int *arr, int &n) {
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] % 2 == arr[i + 1] % 2 && arr[i] + 1 != arr[i + 1] && arr[i] != arr[i + 1]) {
            arr = inserarePoz(arr, n, i);
            i++;
            arr[i] = (arr[i - 1] + arr[i + 1]) /2;
        }
    }

    int *scrie = new int[n]{};

    for(int i = 0; i < n; i++) {
        scrie[i] = arr[i];
    }

    delete[] arr;
    return scrie;
}

void ex11() {
    int n = 6, temp = 0;
    int *arr = new int[n]{1,41,3,3,4,8};

    while(temp != n) {
        temp = n;
        arr = inserareMedieVec1(arr, n);
        afisVec(arr, n);
    }

    afisVec(arr, n);

    delete[] arr;
}

//sa se determine toate perm. spre st. ale vec.

void permStVec(int *arr, int n) {
    int *temp = new int(arr[0]);
    for(int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = *temp;
    delete temp;
}

void ex12() {
    int n = 5;
    int *arr = new int[n]{7,2,8,4,5};

    for(int i = 0; i < n; i++) {
        permStVec(arr, n);
        afisVec(arr, n);
    }
    delete[] arr;
}

//Gigel a gasit un sir cu n nr nat. In fiecare zi Gigel parcurge sirul si cand gaseste o pereche de elem consec
//egale o elim si se opreste. Det. in cate zile va elim. Gigel elem. din sir si care sunt val din dir dupa elim.

int* elimPerechiVec(int *arr, int&n, int&zile) {
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] == arr[i + 1]) {
            arr = stergerePoz(arr, n, i);
            arr = stergerePoz(arr, n, i);
            i--;
            zile++;
        }
    }

    int *scrie = new int[n]{};

    for(int i = 0; i < n; i++) {
        scrie[i] = arr[i];
    }

    delete[] arr;

    return scrie;
}

void ex13() {
    int n = 8, zile = 0;
    int *arr = new int[n]{1,2,3,3,2,2,3,3};

    arr = elimPerechiVec(arr, n,zile);
    cout << zile << endl;
    afisVec(arr, n);
    delete[] arr;
}

///se citeste un vec. de max. 200  nr. intregi de max. 4 cif. fiecare
//sa se stearga al 3lea elem. prim din vec.

int* transfer(int *nou, int *vechi, int dim) {
    for (int i = 0; i < dim; i++) {
        nou[i] = vechi[i];
    }
    delete[] vechi;
    return nou;
}

int* elim3PrimVec(int *arr, int&n) {
    int ct = 0;
    for(int i = 0; i < n; i++) {
        if(isPrim(arr[i])) {
            ct++;
            if(ct == 3) {
                arr = stergerePoz(arr, n, i);
                break;
            }
        }
    }

    int *scrie = new int[n]{};

    scrie = transfer(scrie, arr, n);
    return scrie;
}

void ex14() {
    int n = 5;
    int *arr = new int[n]{1,2,3,4,5};

    arr = elim3PrimVec(arr, n);
    afisVec(arr, n);
    delete[] arr;
}

//sa se stearga toate elem. ce au c. p. 2 cif., iar prima = ultima;

int oglindit(int nr) {
    int o = 0;
    while(nr) {
        o = nr % 10 + o * 10;
        nr /= 10;
    }
    return o;
}

int* elimPrimUltimVec(int *arr, int&n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] % 10 == oglindit(arr[i]) % 10) {
            arr = stergerePoz(arr, n, i);
            i--;
        }
    }

    int *scrie = new int[n]{};

    scrie = transfer(scrie, arr, n);

    return scrie;
}

void ex15() {
    int n = 5;
    int *arr = new int[n]{11,232,34534,4234,534};

    arr = elimPrimUltimVec(arr, n);
    afisVec(arr, n);
    delete[] arr;
}

//sa se elim. toate 0 din vec.

int* elim0Vec(int *arr, int&n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            arr = stergerePoz(arr, n, i);
            i--;
        }
    }

    int *scrie = new int[n]{};

    scrie = transfer(scrie, arr, n);

    return scrie;
}

void ex16() {
    int n = 5;
    int *arr = new int[n]{9,0,0,5,0};

    arr = elim0Vec(arr, n);
    afisVec(arr, n);
    delete[] arr;
}

//sa se stearga toate elem din interiorul intervalului [a,b]

int* elimElemIntervalVec(int *arr, int&n, int a, int b) {
    if(a > b) swap(a, b);

    for(int i = 0; i < n; i++) {
        if(arr[i] >= a && arr[i] <= b) {
            arr = stergerePoz(arr, n, i);
            i--;
        }
    }

    int *scrie = new int[n]{};
    scrie = transfer(scrie, arr, n);
    return scrie;
}

void ex17() {
    int n = 5,a = 1, b = 3;
    int *arr = new int[n]{1,2,3,4,5};

    arr = elimElemIntervalVec(arr, n, a, b);
    afisVec(arr, n);
    delete[] arr;
}

//sa se elim. toate elem. ce au cifra/cifrele din mij un patr. perf.

int ctCifNr(int nr) {
    int ct = 0;
    while(nr) {
        ct++;
        nr /= 10;
    }
    return ct;
}

int mijNr(int nr) {
    int ct = ctCifNr(nr), p = 1;

    for(int i = 0; i < ct/2; i++) p*= 10;

    if(ct % 2 != 0) {
        nr /= p;
        return nr % 10;
    }

    nr /= (p / 10);
    return nr % 100;
}

int* elimMijPatrPerfVec(int *arr, int&n) {
    for(int i = 0; i < n; i++) {
        int mij = mijNr(arr[i]), p = -1;
        if(ePatrPerf(mij,p)) {
            arr = stergerePoz(arr, n, i);
            i--;
        }
    }

    int *scrie = new int[n]{};

    scrie = transfer(scrie, arr, n);

    return scrie;
}

void ex18() {
    int n = 5;
    int *arr = new int[n]{671,2496,794,4,5};

    arr = elimMijPatrPerfVec(arr, n);
    afisVec(arr,n);

    delete[] arr;
}

//sa se elim. toate elem. alaturate prime intre ele

int cmmdc(int a , int b) {
    if(a==b) {
        return a;
    }
    return  a>b ?cmmdc(a-b, b) : cmmdc(a, b-a);
}

bool primeIntreEle(int a , int b) {
    if(cmmdc(a,b) == 1) {
        return true;
    }
    return false;
}

int* stergerePrimeIntreEleVec(int *arr, int&n) {
    for(int i = 0; i < n - 1; i++) {
        if(primeIntreEle(arr[i],arr[i+1])) {
            arr = stergerePoz(arr, n, i);
            arr = stergerePoz(arr, n, i);
            i--;
        }
    }

    int *scrie = new int[n]{};
    scrie = transfer(scrie, arr, n);
    return scrie;
}

void ex19() {
    int n = 5;
    int *arr = new int[n]{1,2,4,4,8};

    arr = stergerePrimeIntreEleVec(arr, n);
    afisVec(arr,n);

    delete[] arr;
}

//sa se insereze dupa fiecare elem. negativ cubul lui

int* inserareCubElemNegativeVec(int *arr, int&n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] < 0) {
            arr = inserarePoz(arr, n, i);
            i++;
            arr[i] = arr[i] * arr[i] * arr[i];
        }
    }

    int *scrie = new int[n]{};
    scrie = transfer(scrie, arr, n);
    return scrie;
}

void ex20() {
    int n = 5;
    int *arr = new int[n]{1,-2,4,4,8};

    arr = inserareCubElemNegativeVec(arr, n);
    afisVec(arr,n);
    delete[] arr;
}

//sa se insereze dupa al k-lea elem. ce are cif. in ord. consec. de la st. la dr. rasturnatul lui

bool cifreConsecutive(int numar){
    int cifra1 = numar % 10;
    int cifra2 = (numar/10) % 10;
    numar /= 100;
    while(numar){
        if(cifra1 != cifra2 + 1){
            return false;
        }
        cifra1 = cifra2;
        cifra2 = numar / 10;
        numar/=10;
    }
    return true;
}

int* inserareRastKElemConsecVec(int *arr, int&n, int k) {
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(cifreConsecutive(arr[i])) {
            index++;
            if(index == k) {
                arr = inserarePoz(arr, n, i);
                i++;
                arr[i] = oglindit(arr[i]);
            }
        }
    }

    int *scrie = new int[n]{};
    scrie = transfer(scrie, arr, n);
    return scrie;
}

void ex21() {
    int n = 5, k = 2;
    int *arr = new int[n]{123,432,345,4,5};

    arr = inserareRastKElemConsecVec(arr,n,k);
    afisVec(arr,n);

    delete[] arr;
}

//sa se insereze intre oricare 2 elem. palindrome intre ele val. in urma alipiriicelui de al doilea nr. la primul

int lipireAsiB(int a, int b) {
    int p = 1, aux = ctCifNr(b);
    for(int i = 0; i < aux; i++) {
        p *= 10;
    }
    a *= p;
    a += b;
    return a;
}

int* f(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == arr[i + 1]) {
            arr = inserarePoz(arr, n, i);
            i++;
            arr[i] = lipireAsiB(arr[i - 1],arr[i + 1]);
        }
    }

    int *scrie = new int[n]{};
    scrie = transfer(scrie, arr, n);
    return scrie;
}

void ex22() {
    int n = 5;
    int *arr = new int[n]{123,123,345,4,5};

    arr = f(arr,n);
    afisVec(arr,n);
    delete[] arr;
}


#endif //EXERCITII_H