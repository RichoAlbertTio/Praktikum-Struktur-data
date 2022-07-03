/*
Nama      : RICHO ALBERT TIO
Nim       : 203030503099
Praktikum : Struktur Data (c)
Modul     : VI
*/

#include <iostream>  //untuk fungsi input dan output pada header yang digunakan dan fungsi lainnya
#include <conio.h>   //Untuk menampilkan hasil antarmuka pada output program, menahan, berhenti dan lainnya
using namespace std; //memasukan fungsi std dan untuk mempersingkat penulisan kode yang berkaitan tentang std

// fungsi tidak mengembalikan nilai (void), dengan nama fungsi sequential_search
void sequential_search()
{
  // Mendeklarasikan Variabel
  int i, n;   // variabel untuk perulangan
  int cari;   // variabel untuk mencari data dan kondisi
  int A[100]; // variabel untuk memasukan data, Muatan data index array nya sampai 100
  bool ketemu;
  cout << "PROGRAM SEQUENTIAL SEARCH\n";
  cout << "-------------------------\n";
  //memasukan jumlah data dengab parameter n (sebagai nilai batas)
  cout << "Masukan banyak array: ";
  cin >> n;
  cout << "\n";
  // perulangan untuk memasukan data sesuai dengan jumlah data yang dimasukan
  for (i = 0; i < n; i++) // i (sebagai nilai awal) = 1; jika (awal) i <= n (batas); maka i bertambah 1 sampai nilai n (batas)
  {
    // memasukan data sesuai dengan batas jumlah data
    cout << "masukan data ke "
         << "[" << i << "]"
         << " = "; // i digunakan untuk urutan data masukan
    cin >> A[i];   // masukan dengan variabel A dan [i] yang dgunakan untuk masukan data sesuai dengan jumlah data
  }
  // Tampilan data yang sudah dimasukan mendatar
  cout << "\nMasukan data yang masuk  :";
  for (i = 0; i < n; i++)
  {                             // digunakan perulangan untuk menampilkan data
    cout << " " << A[i] << " "; // Dan akan menampilkan data sesuai dengan yang dimasukan
  }
  // Tampilan indeks data
  cout << "\nUrutan indeks data       :";
  for (i = 0; i < n; i++)
  {                          // digunakan perulangan untuk menampilkan indeks urutan pada data masukan
    cout << "[" << i << "]"; //Menampilkan indeks
  }
  cout << endl;
  // Mencari masukan data dengan variabel cari
  cout << "Masukan bilangan yang cari : ";
  cin >> cari;
  cout << "--------------------------" << endl;
  cout << endl;

  ketemu = false;
  // untuk mencari data yang dimasukan digunakanlah perulangan agar dapat mencari datanya sesuai dengan jumlah dan masukan data
  for (i = 0; i < n; i++)
  {
    // kondisi yaitu mencari data masukan dengan varibel cari (A[i]==cari)
    if (A[i] == cari)
    {
      // jika ketemu maka true atau sama dengan 1
      ketemu = true;
      cout << "Data ditemukan pada indeks ke-" << i << endl; // Menampilkan kallimat dengan menunjukan ke variabel sebagai indeks
    }
  }
  // jika tidak ditemukan maka masuk ke kondisi ketemu = 0 atau false
  if (ketemu == false) // jika data tidak ditemukan maka melakukan intruksi ini
  {
    cout << "Data tidak ditemukan" << endl; // Menampilkan kallimat
  }
  getch(); // digunakan untuk menahan output
}

// fungsi tidak mengembalikan nilai (void), dengan nama fungsi binary_search
void binary_search()
{
  // mendeklarasikan variabel
  int n, awal, akhir, tengah, temp, key; // variabel n
  int angka[100];                        // variabel untuk memasukan data, Muatan data index array nya sampai 100
  bool ketemu = false;                   // variabel ketemu dengan tipe data boleaam untuk kondisi pada data
  cout << "PROGRAM BINARY SEARCH\n";
  cout << "=======================\n";
  // Memasukan jumlah data dengan variabel n
  cout << "Masukan jumlah data : ";
  cin >> n;
  // perulangan untuk memasukan data sesuai dengan jumlah data yang dimasukan
  for (int i = 0; i < n; i++) // i (sebagai nilai awal) = 1; jika (awal) i <= n (batas); maka i bertambah 1 sampai nilai n (batas)
  {
    cout << "Angka ke - [" << i << "] : "; // i digunakan untuk urutan data masukan
    cin >> angka[i];                       // masukan dengan variabel A dan [i] yang dgunakan untuk masukan data sesuai dengan jumlah data
  }
  // Tampilan data yang belum diurutkan
  cout << "\nData yang sebelum diurutkan adalah: ";
  for (int i = 0; i < n; i++) // digunakan perulangan untuk menampilkan data yang dimasukan sesuai dengan jumlah data
  {
    cout << " " << angka[i] << " "
         << " "; // Dan akan menampilkan data sesuai dengan yang dimasukan
  }
  // proses pengurutan data menggunakan pengurutan data secara ascending
  for (int i = 0; i < n; i++) // masukan datanya akan masuk ke ini, didalam perulangnya ada perulang lagi yang digunakan untuk membandingkan
  {
    for (int j = 0; j < n - 1; j++) // untuk membandingkan data sebelahnya dari data diawal jadi untuk mengurutkan
    {
      // perbandingan if pecabangan antara masukan data awal ke masukan data berikutnya atau disebelahnya
      if (angka[j] > angka[j + 1])
      {
        temp = angka[j];         // temp digunakan untuk menyimpan data sementara varibel angka[j]
        angka[j] = angka[j + 1]; // angka[j] digantikan dengan angka [j+1] atau data berikutnya
        angka[j + 1] = temp;     // angka [j+1] sama dengan temp yang memiliki simpanan data sementara dari angka[j]
        // maka dari tersebut terjadi pertukaran, dan akan mengurutuktkan dari data terkecil keterbesar
      }
    }
  }
  cout << "\n=========================================================================\n";
  //Menampilkan masukan data yang sudah diurutkan
  cout << "Data yang telah diurutkan adalah  : ";
  for (int i = 0; i < n; i++) // digunakan perulangan untuk menampilkan data yang telah melewati proses pengurutan data
  {
    cout << " " << angka[i] << " "
         << " "; // Dan akan menampilkan data sesuai dengan data yang telah diurutkan
  }
  cout << "\nUrutan indeks data                : ";
  for (int i = 0; i < n; i++) // digunakan perulangan untuk menampilkan data yang telah melewati proses pengurutan data
  {
    cout << "[" << i << "]"
         << " "; // Dan akan menampilkan data sesuai dengan data yang telah diurutkan
  }
  cout << "\n=========================================================================\n";
  //Mencari data dengan variabel key
  cout << "Masukan angka yang dicari: ";
  cin >> key;
  // variabel yang digunakan untuk proses dalam mencari data
  awal = 0;      // data awal
  akhir = n - 1; // data akhir
  //Dalam pencarian datanya dari array yaitu membagi 2 dari banyak jumlah datanya terus sama datanya ditemukan atau datanya.
  while (awal <= akhir)
  {
    tengah = (awal + akhir) / 2; //dicari posisi data tengah dengan rumus (awal + akhir) / 2.
    // kodisi pecabangan if else, apakah cari datanya = angka[tengah]
    if (key == angka[tengah])
    {
      //jika ia maka pencariannya ketemu, jika tidak maka else dan masuk keproses selanjutnya
      ketemu = true;
      break;
    }
    //Jika cari data lebih kecil angka[tengah], maka proses akan dilakukan kembali tetapi, posisi akhir dianggap sama dengan posisi tengah -1.jika else maka masuk ke intruksi berikutnya
    else if (key < angka[tengah])
    {
      akhir = tengah - 1;
    }
    // Jika cari data lebih besar pun proses akan dilakukan kembali tetapi posisi awal dianggap sama dengan posisi tengah +1.jika masih belum ditemukan pencarian kembali ke while(awal<=akhir)
    else
    {
      awal = tengah + 1;
    }
  }
  /*Jika pencarian data masih belum ditemukan maka kembali perkondisian while(awal<=akhir) dan didalam prosesnya sampai data ditemukan dari proses-prosesnya, jika tidak ada
   ada yang masukan, maka pada ouputnya akan menampilkan kalimat Angka tidak ditemukan                                                */

  // Berarti datanya ditemukan
  if (ketemu == true) // kondisi jika ketemu sama dengan true atau data yang dicari ditemukan
  {
    cout << "Angka ditemukan! ";                     //Menampilkan kalimat
    cout << "Data berada pada indeks ke-" << tengah; // Menampilkan kalimat serta menunjukan index yang dicari melalaui pencarian data
    cout << endl;
  }
  else                                // jika data tidak di temukan else dan maka masuk ke instruksi ini
    cout << "Angka tidak ditemukan!"; //Menampilkan kalimat
  cout << endl;
  getch();
}

//Menu Utama Program
int main()
{
awal:            // menggunaka goto label (sebagai pernyataan untuk mengarah ke menu untuk mengulang kembali)
  system("cls"); // Untuk membersihkan layar output
  int pilih;     // variabel pilih digunakan untuk memilih menu program
  char ulang;    // variabel yang digunakan untuk mengulang instruksi menu
  // menampilakan kalimat pada menu
  cout << "=----------- MENU UTAMA --------------=" << endl;
  cout << "=---------- SEARCHING DATA -----------=" << endl;
  cout << "= 1. Sequential Search                =" << endl;
  cout << "= 2. Binary search                    =" << endl;
  cout << "= 3. Exit                             =" << endl;
  cout << "=======================================" << endl;
  cout << endl;
  //Memasukan pilihan menu
  cout << "Masukan pilihan anda : ";
  cin >> pilih; //variabel untuk memilih instruksi pada menu
  // pemilihan menunya menggunakan kondisi percabangan case
  switch (pilih)
  {
    // pilihan 1
  case 1:
    sequential_search(); //Memanggil nama fungsi
    getch();             // menahan output
    break;               // Menutup instruksi pada pilihan 1
                         // pilihan 2
  case 2:
    binary_search(); //Memanggil nama fungsi
    getch();         // menahan output
    break;           // Menutup instruksi pada pilihan 2
                     // pilihan 3
  case 3:
    exit(1); // digunakan untuk keluar dari output program
    break;   // Menutup instruksi pada pilihan 3
  default:
    cout << "Pilihan Salah" << endl; // kondisi jika memilih data tidak sesuai dengan menu pilihan 1 sampai 3
    getch();                         //  Menahan output
    goto awal;                       //  maka akan menggulang lagi kemenu, kecuali jika perintah nya instruksi 3 maka tidak menampilkan menu
  }
  // Mnggulang kembali kemenu
  cout << "\nApakah Anda ingin mengulang?Tekan[y/t] : ";
  cin >> ulang; // variabel digunkan untuk kondisi untuk menggulang kemenu atau tidak
  cout << "\n\n";
  // kondisi percabangan if else, jika kita ketik y atau Y, maka akan melakukan ini
  if (ulang == 'y' || ulang == 'Y')
  {
    goto awal; // yaitu kembali kembali kemenu
  }
  // jika diketik variabel apa saja, tapi pada program dipakai t biar lebih mengarah untuk pernyataan t(tidak), maka melakukan instruksi ini
  else
  {
    exit(1); // yaitu keluar dari output program atau keluar
  }
  getch(); // menahan output
  return 0;
}

// perbedaaan antara sequential dan binary search
/* 1. kalau binary search ia mengurutkan data dulu kemudian mencari datanya sedangkan sequential search dapat langsung mencari data
   2. Untuk pencarian data sequential ia dimulai dari awal sampai datanya ditemukan
   3. Untuk pencarian data secara binary search masukan jumlah datanya dibagi 2, sehingga pencarian lebih mudah juga karena datanya sudah terurut
*/
