#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//FUNGSI PENGURUTAN BUBBLE SHORT
void bubble()
{
    int data[100];
    int i, j, k, tmp, jumlah = 0;
    cout << "" << endl;
    cout << "=---- BUBBLE SORTING ----=\n";
    cout << "Masukkan jumlah bilangan : ";
    cin >> k;
    for (i = 0; i < k; i++)
    {
        cout << "Masukkan Angka ke - " << (i + 1) << " : ";
        cin >> data[i];
    }
    cout << "\nData sebelum diurutkan : \n"
         << endl;
    for (i = 0; i < k; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    for (i = 0; i < k; i++)
    {
        for (j = i + 1; j < k; j++)
        {
            if (data[i] > data[j])
            {
                tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
    cout << "\nData setelah diurutkan : \n"
         << endl;
    for (i = 0; i < k; i++)
    {
        {
            cout << data[i] << " ";
        }
    }
    getch();
}

//FUNGSI PENGURUTAN SELECTION SHORT
void selection()
{
    int x[10];
    int i, bd, temp, minindex, j;
    cout << "" << endl;
    cout << "=---- SELECTION SORT ----= \n";
    cout << "Masukkan jumlah bilangan : ";
    cin >> bd;
    for (i = 1; i <= bd; i++)
    {
        cout << "Masukkan angka ke - " << i << " : ";
        cin >> x[i];
    }

    cout << "\nData sebelum di sort :";
    for (i = 1; i <= bd; i++)
    {
        cout << " " << x[i];
    }

    //proses pengurutan
    for (i = 1; i <= bd - 1; i++) //perulangan iterasi
    {
        minindex = i;                 //Penyimpanan Sementara
        for (j = i + 1; j <= bd; j++) //perulangan membandingkan data
        {
            if (x[minindex] > x[j]) //Jika x dengan larik minindex lebih dari x dengan array j maka
            {
                minindex = j; //minindex sama dengan j
            }
        }
        temp = x[i];
        x[i] = x[minindex];
        x[minindex] = temp;
    }
    cout << "" << endl;
    cout << "\nData setelah di diurutkan :";
    for (i = 1; i <= bd; i++)
    {
        cout << " " << x[i];
    }
    getch();
}

//FUNGSI PENGURUTAN INSERTION SHORT
void insertion()

{
    int i, j, n, data[100], simpan, min, posisi;
    cout << "" << endl;
    cout << "=---- INSERTION SORTING ----=\n";
    cout << "Masukkan jumlah bilangan : ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cout << "Masukan Angka ke - " << i << "   : ";
        cin >> data[i];
    }
    for (i = 1; i < n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (data[i] > data[j])
            {
                simpan = data[i];
                data[i] = data[j];
                data[j] = simpan;
            }
        }
    }

    cout << "\nData setelah diurutkan : \n";
    for (i = 1; i <= n; i++)
        cout << data[i] << " ";
    cout << endl;
}

//FUNGSI PENGURUTAN SHELL SHORT
void shell()
{
    int val[100];
    int i, n, t;
    cout << "" << endl;
    cout << "=---- SELL SORTING ----=\n";
    cout << "Masukkan jumlah bilangan : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Masukkan Angka ke - " << 1 + i << "  : ";
        cin >> val[i];
    }
    for (int w = n / 2; w > 0; w = w / 2)
    {
        for (int x = w; x < n; x++)
        {
            for (int y = x - w; y >= 0; y -= w)
            {
                if (val[y + w] < val[y])
                {
                    t = val[y + w];
                    val[y + w] = val[y];
                    val[y] = t;
                }
            }
        }
    }
    cout << "\nData setelah diurutkan : \n";
    for (i = 0; i < n; i++)
    {
        cout << val[i] << " ";
    }
    getch();
}

//Menu Utama Program
int main()
{
awal:
    system("cls");
    int r;
    char ulang;
    cout << "=----------- MENU UTAMA --------------=" << endl;
    cout << "=---------- SORTING DATA -------------=" << endl;
    cout << "= 1. Bubble Sorting                   =" << endl;
    cout << "= 2. Selection Sorting                =" << endl;
    cout << "= 3. Insertion Sorting                =" << endl;
    cout << "= 4. Shell Sorting                    =" << endl;
    cout << "= 5. Exit                             =" << endl;
    cout << "=======================================" << endl;
    cout << endl;
    cout << "Masukan pilihan anda : ";
    cin >> r;
    switch (r)
    {
    case 1:
        bubble();
        break;
    case 2:
        selection();
        break;
    case 3:
        insertion();
        break;
    case 4:
        shell();
        break;
    case 5:
        exit(1);
        break;
    default:
        cout << "Pilihan Salah" << endl;
        goto awal;
    }
    cout << "\nApakah Anda ingin mengulang?Tekan[y/t] : ";
    cin >> ulang;
    cout << "\n\n";
    if (ulang == 'y' || ulang == 'Y')
    {
        goto awal;
    }
    else
    {
        exit(1);
    }
    getch();
    return 0;
}
