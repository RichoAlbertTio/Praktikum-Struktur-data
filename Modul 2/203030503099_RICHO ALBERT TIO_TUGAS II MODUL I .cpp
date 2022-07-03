/*
NAMA      : RICHO ALBERT TIO
NIM 	  : 203030503099
PRAKTIKUM : STRUKTUR DATA
KELAS 	  : C
*/

// Memasukan libary
#include <iostream>

using namespace std;
// function yang mengembalikan nilai dengan parameter n
int fibo (int n) {
	// jika statement if ini terpenuhi maka akan mengambalikan nilai n
	if (n == 0 || n == 1){
		return n;
	}
	// jika kondisi n tidak sama dengan 0 atau 1 maka dia akan masuk ke instruksi ini
	else
	{
		return (fibo(n-1) + fibo(n-2));
	}
}
	/* untuk mengambil fungsi tersebut kita harus memanggilnya ke program utama atau int main. 
	   agar statement di fungsi, dapat berjalan sesuai tujuan nya yaitu fibonacci(deret). 
	   Dari ouputnya fibonacci ini bisa dari 0 atau 1 
	*/
int main(){
	// di int main kita mendeklarikan m dan n=1; dengan tipe data integer;
	int m, n=1;
	// memasukan deret bilangan 
	cout<<"masukan deret bilangan ke ="; 
	cin>>m;
	// melakukan perulangan 
	for (int i=1; i<=m; i++){
	// memanggil nama fungsi dan parameternya 	
		cout<<fibo(n) <<" ";	
		n++;	
	}
	// program selesai
	return 0;
}

