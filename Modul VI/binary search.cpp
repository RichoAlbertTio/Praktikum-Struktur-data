#include<iostream>  //untuk fungsi input dan output pada header yang digunakan dan fungsi lainnya
#include <conio.h>  //Untuk menampilkan hasil antarmuka pada output program, menahan, berhenti dan lainnya
using namespace std;    //memasukan fungsi std dan untuk mempersingkat penulisan kode yang berkaitan tentang std

// fungsi sequential_search
void sequential_search(){
    // Mendeklarasikan Variabel
    int i,n;                    // variabel untuk perulangan
    int cari, ketemu;           // variabel untuk mencari data dan kondisi
    int A[100];                 // variabel untuk memasukan data, Muatan data index array nya sampai 100

    cout<<"PROGRAM SEQUENTIAL SEARCH\n";
    cout<<"-------------------------\n";
    //memasukan jumlah data dengan variabel n
    cout<<"Masukan banyak array: ";
    cin >> n;
    cout <<"\n";
    // perulangan untuk memasukan data sesuai dengan jumlah data yang dimasukan
    for(i= 0; i<n; i++)
    {
        // memasukan data sesuai dengan batas jumlah data
        cout<<"masukan data ke "<<"["<<i<<"]"<<" = ";     // i digunakan untuk urutan data masukan
        cin>>A[i];          // masukan dengan variabel A[i] yang dgunakan untuk masukan data sesuai dengan jumlah data
    }
    // Tampilan data yang sudah dimasukan mendatar
    cout<<"\nMasukan data yang masuk  :";
    for(i= 0; i<n; i++){       // digunakan perulangan untuk menampilkan data
     cout<<" "<<A[i]<<" ";     // Dan akan menampilkan data sesuai dengan yang dimasukan
    }
    cout<<endl;
    // Mencari masukan data dengan variabel cari
    cout<<"Input bilangan yang cari : "; cin>>cari;
     cout<<"--------------------------"<<endl;
    cout<<endl;

    ketemu=0;
    // untuk mencari data yang dimasukan digunakanlah perulangan agar dapat mencari datanya sesuai dengan jumlah dan masukan data
    for(i=0; i<n; i++)
    {
        // kondisi yaitu mencari data
        if (A[i]==cari)
        {
            // jika ketemu maka true atau sama dengan 1
            ketemu=1;
            cout<<"Data ditemukan pada indeks ke-"<<i<<endl; // Menampilkan kallimat dengan menunjukan ke variabel sebagai indeks
        }
    }
    // jika tidak ditemukan maka masuk ke kondisi ketemu = 0
    if(ketemu==0)   // jika data tidak ditemukan maka melakukan intruksi ini
    {
        cout<<"Data tidak ditemukan"<<endl; // Menampilkan kallimat
    }
getch();   // digunakan untuk menahan output
}

// fungsi binary_search
void binary_search () {
     // mendeklarasikan variabel
     int n, kiri, kanan, tengah, temp, key;
     int  angka[100];    // variabel untuk memasukan data, Muatan data index array nya sampai 100
     bool ketemu = false;   // variabel ketemu dengan tipe data boleaam untuk kondisi pada data
     cout<<"PROGRAM BINARY SEARCH\n";
     cout<<"=======================\n";
     // Memasukan jumlah data dengan variabel n
     cout << "Masukan jumlah data : ";
     cin >> n;
      // perulangan untuk memasukan data sesuai dengan jumlah data yang dimasukan
     for(int i=0; i<n; i++)
     {
      cout << "Angka ke - [" << i << "] : "; // i digunakan untuk urutan data masukan
      cin >> angka[i];  // masukan dengan variabel angka[i] yang dgunakan untuk masukan data sesuai dengan jumlah data
     }
     // Tampilan data yang belum diurutkan
     cout << "\nData yang sebelum diurutkan adalah: ";
     for(int i=0; i<n; i++)     // digunakan perulangan untuk menampilkan data yang dimasukan sesuai dengan jumlah data
       {
        cout<<" "<<angka[i]<<" "<<" ";   // Dan akan menampilkan data sesuai dengan yang dimasukan
       }
       // proses pengurutan data
       for (int i=0; i<n; i++) // masukan datanya akan masuk ke ini, didalam perulangnya ada perulang lagi yang digunakan untuk membandingkan
        {
         for(int j=0; j< n-1; j++) // untuk membandingkan data sebelahnya dari data diawal jadi untuk mengurutkan
         {
          if(angka [j] > angka [j+1]) // jika angka [j] > angka [j+1] maka angka melakukan proses berikut
         {
         temp = angka[j];   // temp = angka[j] (didalam temp ada angka[j])
         angka[j] = angka[j+1]; // angka[j] = angka[j+1] atau angka berikutnya
         angka[j+1] = temp; // angka berikutnya sama dengan temp
         // dari proses tersebut tejadi pengurutan data dengan membandingkan kemudian datanya ditukar sehingga jadi pengurutan data
         }
       }
     }
 cout << "\n=========================================================================\n";
 //Menampilkan masukan data yang sudah diurutkan
 cout << "Data yang telah diurutkan adalah  : ";
 for(int i=0; i<n; i++) // digunakan perulangan untuk menampilkan data yang telah melewati proses pengurutan data
 {
  cout<<" "<< angka[i] <<" "<<" "; // Dan akan menampilkan data sesuai dengan data yang telah diurutkan
 }
 cout << "\n=========================================================================\n";
 //Mencari data dengan variabel key
 cout << "Masukan angka yang dicari: ";
 cin >> key;
// variabel yang digunakan untuk proses dalam mencari data
 kiri = 0;      //data awal
 kanan = n-1;   // data akhir
 // menggulang kondisi apah kiri <=kanan jika ia masuk ke berikutnya
 while(kiri<=kanan)
 {
 // te
  tengah=(kiri + kanan) /2; //dicari posisi data tengah dengan rumus (awal + akhir) / 2.
  if(key == angka[tengah]) // apakah key == angka[tengah] jika ia maka ketemu datannya jika tidak maka ke proses brikutnya
  {
   // ketemu datanya maka true  jika tidak maka keberkutnya
   ketemu=true;
   break;
  }
  // apakah key < angka [tengah] jika ai maka masuk ke proses jika tidak maka masuk ke proses berkutnya
  else if (key < angka [tengah])
  {
   kanan = tengah -1;
  }
  // jika lebih besar maka masuk ke proses ini
  else
  {
   kiri = tengah +1;
  }
 }
 // dan jika masih belum ditemukan maka ia akan mengecekembali pada while(kiri<=kanan) dan prosesnya sampai data ditemukan jika tidak maka akan menampilkan data tidak ditemukan
 // Berarti datanya ditemukan
 if (ketemu == true)   // kondisi jika ketemu sama dengan true atau data yang dicari ditemukan
 {
  cout << "Angka ditemukan! ";      //Menampilkan kalimat
  cout << "Data berada pada indek ke-" << tengah;   // Menampilkan kalimat serta menunjukan index yang dicari melalaui pencarian data
  cout << endl;
 }
 else   // jika data tidak di temukan else dan maka masuk ke instruksi ini
  cout << "Angka tidak ditemukan!";   //Menampilkan kalimat
  cout <<endl;
getch();
}

//Menu Utama Program
int main (){
awal:
system("cls");  // Untuk membersihkan layar output
int pilih;      // variabel pilih digunakan untuk memilih menu program
char ulang;     // digunakan untuk mengulang instruksi
// menampilakan kalimat pada menu
cout<<"=----------- MENU UTAMA --------------="<<endl;
cout<<"=---------- SEARCHING DATA -----------="<<endl;
cout<<"= 1. Sequential Search                ="<<endl;
cout<<"= 2. Binary search                    ="<<endl;
cout<<"= 3. Exit                             ="<<endl;
cout<<"======================================="<<endl;
cout<<endl;
//Memasukan pilihan menu
cout<<"Masukan pilihan anda : ";
cin>> pilih;    //variabel untuk memilih instruksi pada menu
switch(pilih){
                                // pilihan 1
case 1: sequential_search();    //Memanggil nama fungsi
        getch();
        break;
                                // pilihan 2
case 2: binary_search() ;       //Memanggil nama fungsi
        getch();
        break;
                                 // pilihan 3
case 3:exit (1);                 // digunakan untuk keluar dari output program
        break;
default : cout<<"Pilihan Salah"<<endl;  // kondisi jika memilih data tidak sesuai dengan menu pilihan 1 sampai 3
          getch();               //  Menahan output
goto awal;  //  maka akan menggulang lagi kemenu, kecuali jika perintah nya instruksi 3 maka tidak menampilkan menu
}
    // Mnggulang kembali kemenu
    cout<<"\nApakah Anda ingin mengulang?Tekan[y/t] : ";
    cin>>ulang; // variabel digunkan untuk kondisi untuk menggulang kemenu atau tidak
    cout<<"\n\n";
  // kondisi jika kita ketik y atau Y, maka akan melakukan ini
  if (ulang=='y'||ulang=='Y'){
    goto awal;      // yaitu kembali kembali kemenu
  }
  // jika diketik t maka melakukan instruksi ini
  else{
  exit(1);  // yaitu keluar dari output program atau keluar
  }
  getch (); // menahan output
  return 0;
}

