// memasukan libary
#include <iostream>
#include <string>
#include <cstdio>

// Agar mempersingkat penulisan fungsi std
using namespace std;

// nama struct
struct Mahasiswa{
// mendeklarasi variabel
	string Nama[30];
	string Nim[20];
	string Email[30];
};

int main (){
//  Menambahkan artian misalnya mhs pada Mahasiswa . yang artinya mhs adalah Mahasiswa
	Mahasiswa mhs[5];
// Mendeklarasi variabel
	int i, n;
{
// Memasukan data jumlah data
cout<<"-----------------------------------"<<endl;
cout<<"Masukan jumlah data : "; cin>>n;
// Melakukan perulangan yang fungsinya, untuk perulangan memasukan data sampai jumlah data yang di input
for(i=0; i<n; i++){
cout<<"-----------------------------------"<<endl;
	cout<<"\nMahasiswa "<< i + 1<<endl;
// Memasukan data Nama, Nim, dan Email
	cout<<"Nama\t:";
	fflush(stdin);
	getline (cin,mhs[i].Nama[i]);
	cout<<"Nim\t:";
	getline (cin,mhs[i].Nim[i]);
	cout<<"Email\t:";
	getline (cin,mhs[i].Email[i]);
	cout<<endl;
}

cout<<"-----------------------------------"<<endl;
// Menampilkan jumlah data
 cout<<"Keluaran jumlah data :"<<n<<endl;
{
// Melakukan perulangan yang fungsinya, untuk menapilkan data sampai jumlah data yang di input
for(i=0; i<n; i++){
cout<<"-----------------------------------"<<endl;
	cout<<"\nMahasiswa "<< i + 1<<endl;
// Menampilkan Nama, Nim, dan Email
	cout<<"Nama\t:"<<mhs[i].Nama[i]<<endl;
	cout<<"Nim\t:"<<mhs[i].Nim[i]<<endl;
	cout<<"Email\t:"<<mhs[i].Email[i]<<endl;
cout<<"-----------------------------------"<<endl;
				}
			}
// Program selesai
return 0;
	}
}

