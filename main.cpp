#include <iostream>

using namespace std;

void zad1() {
    cout << "Hello World!" << endl;
}

void zad2() {
    int x = 7;
    double y = 7.5;
    char z = 'A';
    cout << x << endl << y << endl << z << endl;
}

void zad3() {
    int a = 3;
    int b = 11;
    cout << a + b << endl;
}

void zad4() {
    double x = 12;
    double y = 7;
    x = x / y;
    cout << x << endl;
}

void zad5() {
    string imie = "Jan";
    string nazwisko = "Praxmajer";
    cout << imie << " " << nazwisko << endl;
}

void zad6() {
    string strand = "ATGCGATATCGGATCGA";
    int nucleotides[4] = {0, 0, 0, 0};
    for (int i = 0; i < strand.length(); i++) {
        switch (strand[i]) {
            case 'A':
                nucleotides[0] += 1;
                break;
            case 'T':
                nucleotides[1] += 1;
                break;
            case 'C':
                nucleotides[2] += 1;
                break;
            case 'G':
                nucleotides[3] += 1;
                break;
            default:
                continue;
        }
    }
    cout << "Zliczanie nukleotydów w sekwencji: " << strand << endl;
    cout << "A: " << nucleotides[0] << " T: " << nucleotides[1] << " C: " << nucleotides[2] << " G: " << nucleotides[3] << endl;
}

void zad7() {
    string strand = "ATGCeGATATCGGATCGA";
    int i = 0;
    while (i < strand.length()) {
        if (strand[i] != 'e') {
            cout << strand[i] << endl;
        } else {
            break;
        }
        i++;
    }
}

void zad8() {
    string strand = "";
    int i = 0;
    cin >> strand;
    do {
        i++;
    }
    while (i < strand.length());
    cout << i;
}

void zad9() {
    string strand = "";
    int len = 0;
    double tab[2] = {0, 0};
    cin >> strand;
    for (int i = 0; i < strand.length(); i++) {
        len++;
        switch (strand[i]) {
            case 'C':
                tab[0] += 1;
                break;
            case 'G':
                tab[1] += 1;
                break;
            default:
                continue;
        }
    }
    cout << len;
    float gc = ((tab[0] + tab[1]) / len) * 100;
    cout << "GC content (%): " << gc << "%" << endl;
}

char zad10() {
    string x = "";
    cin >> x;

    if (x.length() == 1) {
        char character = x[0];
        return char(int(character) + 1);
    }
}

void zad11() {
    cout << "I love C++" << endl;
}

double zad12(double x, double y) {
    return (x * y);
}

bool zad13(int x) {
    return x % 4 == 0;
}

int main() {
    zad1();
    zad2();
    zad3();
    zad4();
    zad5();
    zad6();
    zad7();
    //zad8(); jeden z cin
    //zad9();
    //cout << zad10() << endl;
    zad11();
    cout << zad12(4, 3) << endl;
    cout << zad13(3) << zad13(4) << endl;
    return 0;
}