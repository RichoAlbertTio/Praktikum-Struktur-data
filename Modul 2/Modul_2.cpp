/*
NAMA      : RICHO ALBERT TIO
NIM       : 203030503099
JURUSAN   : TEKNIK INFORMATIKA
PRAKTIKUM : STRUKTUR DATA
*/

// Memasukan library
#include <stdlib.h>
#include <conio.h>
#include <iostream>

// Mendeklarasikan konstanta
#define MAX 20

using namespace std;
// deklarasi variabel
int i, depan;
int stack[MAX];
int top = -1;

// mendeklarasikan nama struct dan variabel didalamnya
struct listmusik
{
    string pencipta_lagu;
    string judul;
    string penyanyi;
} list[MAX];

// untuk mengecek kondisi penuh atau tidak
bool isfull()
{
    if (top == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// untuk mengecek kondisi kosong atau tidak
bool isempty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// untuk memasukan inputan
void input()
{
    if (!isfull())
    {
        top++;
        cout << "\n---------Masukan list musik---------" << endl;
        cout << "\n Masukan Judul Lagu\t: ";
        getline(cin, list[top].judul);
        cout << " Masukan Penyanyi\t: ";
        getline(cin, list[top].penyanyi);
        cout << " Masukan Pencipta Lagu\t: ";
        getline(cin, list[top].pencipta_lagu);
    }
    else
        cout << " Data penuh!" << endl;
}

// untuk intruksi fungsi dequeue(fifo) yang terakhir di input akan keluar terlebih dahulu
void dequeue()
{
    if (depan < top + 1)
    {
        cout << endl
             << "\nData yang dikeluarkan dalam antrian" << endl
             << endl;
        cout << "Judul Lagu\t: " << list[depan].judul << endl;
        cout << "Penyanyi\t: " << list[depan].penyanyi << endl;
        cout << "Pencipta Lagu\t: " << list[depan].pencipta_lagu << endl;
        depan++;
        if (depan == top + 1 && top == MAX - 1)
        {
            void awal();
        }
    }
    else
    {
        cout << "Antrian kosong" << endl;
    }
}

// untuk instruksi fungsi pop(lifo)
void pop()
{
    if (!isempty())
    {
        cout << "\nData yang dihapus " << endl;
        cout << "Judul Lagu\t: " << list[top].judul << endl;
        cout << "Penyanyi\t: " << list[top].penyanyi << endl;
        cout << "Pencipta lagu\t: " << list[top].pencipta_lagu << endl;
        top--;
    }
    else
        cout << "Data kosong!" << endl;
}

// untuk intruksi fungsi depan dan belakang
void awal()
{
    depan = 0;
    top = -1;
}

// untuk intruksi menampilkan data secara stack
void print()
{
    if (isempty())
    {
        cout << "Data kosong" << endl;
    }
    else
    {
        cout << " Isi Stack " << endl;
        for (i = top; i >= depan; i--)
        {
            cout << "\n List ke-" << i + 1 << endl;
            ;
            cout << "Judul Lagu\t: " << list[i].judul << endl;
            cout << "Penyanyi\t: " << list[i].penyanyi << endl;
            cout << "Pencipta Lagu\t: " << list[i].pencipta_lagu << endl;
        }
    }
}

// untuk instruksi fungsi menghapus data
void clear()
{
    cout << "Semua data terhapus" << endl;
    top = -1;
}

// program utama menu
int main()
{
    int Pilih;
    do
    {
        system("cls");
        cout << " ---------- Menu ---------" << endl;
        cout << "\n 1. Memasukan Data";
        cout << "\n 2. Dequeue";
        cout << "\n 3. Pop";
        cout << "\n 4. Menampilkan Data ";
        cout << "\n 5. Menghapus Data";
        cout << "\n 6. Keluar";
        cout << "\n-------------------------" << endl;
        cout << "\nMenu yang dipilih: ";
        cin >> Pilih;
        cin.ignore();

        // fungsi untuk memilih pilihan instruksi
        switch (Pilih)
        {
        case 1:
            input();
            getch();
            break;

        case 2:
            dequeue();
            getch();
            break;

        case 3:
            pop();
            getch();
            break;

        case 4:
            print();
            getch();
            break;

        case 5:
            clear();
            getch();
            break;

        case 6:
            exit(true);
            break;
        default:
            cout << "Menu tidak tersedia!" << endl;
            getch();
        }
    } while (Pilih != 6);
    return 0;
}
