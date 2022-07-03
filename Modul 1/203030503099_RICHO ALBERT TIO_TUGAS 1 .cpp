/*
NAMA      : RICHO ALBERT TIO
NIM 	  : 203030503099
PRAKTIKUM : STRUKTUR DATA
KELAS 	  : C
*/
// Memasukan libary
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <stdlib.h>

// Agar mempersingkat penulisan fungsi std
using namespace std;

// nama struct
struct dataBuku{
// mendeklasikan variabel
	string nim;
	string nama; 
	string email;
}buku[50];

// fungsi yang tidak mengembalikan nilai
void inputData(){
	int masuk;
// memasukan jumlah data
	cout << "Jumlah Data yang dimasukkan:	";
	cin >> masuk;
/* perulangan yang berfungsi agar jumlah data yang kita masukin dapat memasukan data nama, nim , dan
	email sebanyak jumlah data tersebut.
*/
	for(int i = 0; i < masuk; i++){
		cout << "\nInputkan data ke-" << i+1 << endl;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "nim: ";
		getline(cin, buku[i].nim);
		cout << "nama: ";
		getline(cin, buku[i].nama);
		cout << "email: ";
		getline(cin, buku[i].email);
	}
}
// fungsi yang tidak mengembalikan nilai
void cetakData(){
	int cetak;
// memasukan jumlah data yang cetak
	cout << "Jumlah Data yang dicetak:	";
	cin >> cetak;
	cin.ignore();
/* melakukan perulangan  yang berfungsi agar jumlah data yang kita cetak dapat menampilkan data nama, nim , dan
	email sebanyak jumlah data yang ingin di cetak.
*/
	for (int i = 0; i < cetak; ++i){
		cout << "\nInputkan data ke-" << i+1 << endl;
		cout << "nim: " << buku[i].nim << endl;
		cout << "nama: " << buku[i].nama << endl;
		cout << "email: " << buku[i].email << endl;
	}
}

int main()
{
    int x;
    while(x!=3){
	system("cls");
	cout << "		Data Mahasiswa	   	  " << endl;
	cout << "---------------------------------" << endl;
	cout << "                 Menu" << endl;
	cout << "1. Masukkan Data Mahasiswa" << endl;
	cout << "2. Cetak Data Mahasiswa" << endl;
	cout << "3. Keluar" << endl;
	cout << "---------------------------------" << endl;
//  memasukan data yang di pilih
	cout << "Pilihan: ";
	cin >> x;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
// menggunakan case sebagai intruksi pilihan . nanti akan berjalan sesuai intruksi yang dinginkan
		switch(x){
			case 1:
				inputData();			// memanggil fungsi
				system("pause");
				break;
			case 2:
				cetakData();			// memanggil fungsi
				system("pause");
				break;
			default:
				cout << "Terimakasih" << endl;
				break;
		}
    }
}

