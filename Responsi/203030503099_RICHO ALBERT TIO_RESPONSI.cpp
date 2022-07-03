/*
    NAMA  : RICHO ALBERT TIO
    NIM   : 203030503O99
    TUGAS : RESPONSI
*/

//header file memasukan library untuk penggunaan fungsi-fungsi yang berjalan diprogram
#include <iostream>     // fungsi untuk memasukan input pada cin dan output pada cout operasi yang digunakan pada program
#include <stdlib.h>      // fungsi Untuk memasukan operasi pembanding dan operasi konversi
#include <conio.h>      //memasukan fungsi Untuk menampilkan hasil antarmuka atau menahan output pada program, dan fungsi lainnya

using namespace std;     /*fungsi untuk memanggil namespace yang memiliki nama ‘std’. Namespace ‘std’ merupakan standar
                          namespace dari C++ yang dapat kita gunakan untuk memanggil class/object/fungsi yang terdapat di dalam namespace tersebut.*/
/* membuat linked list */
struct Node                     // Mendeklarasikan struct dengan nama Node, yang dimana dalam struct terdapat variabel data, mau itu tipe data variabelnya sama atau tipe data yang berbeda
{
 string tahun,buku,pengarang;   // Mendeklarasikan variabel data masukan dengan tipe data string
 Node* next;                    // Fungsi untuk node pointer ini digunakan untuk menujukan satu arah yaitu berikutnya, karena program ini menggunakan single linked list
};

 Node* head;    // pendeklarasikan pointer head untuk data awal atau data depan
 Node* tail;    // pendeklarasikan pointer tail untuk data akhir atau data belakang

// menginisialisasi head dan tail
void inisialisasi()
{
 head = NULL;   // yang artinya head dibernilai NULL atau kondisi masih kosong
 tail = NULL;   // yang artinya tail dibernilai NULL atau kondisi masih kosong
}

// untuk mengecek data kosong
int isempty(){      //fungsi yang dapat mengembalikan nilai, dan fungsi ini, untuk mengecek apak data kosong atau tidak
if (tail==NULL)     //kondisi percabangan if else, jika tail sama dengan NULL(data masih kosong), maka melakukan instruksi berikut
    return 1;       // jika masih kosong data masukan, maka return 1 atau true
   else             // jika ada isinya maka else
    return 0;       // masuk ke return 0 atau false
}

// fungsi untuk menambahkan data dari belakang
void Tambahbelakang()
{
	Node *baru;              //Membuat Node Pointer baru
	baru = new Node;         //Untuk membuat fungsi baru dangan kata kunci new
	cout << "\nMasukkan Data lengkap di bawah ini : " << endl;
	//pada penggunaan getline agar tidak terjadi buffer(masukan pada output terlewatkan) jadi digunakan lah, cin.ignore(1, '\n'); atau bisa juga fflush(stdin);
	cout<<"Masukan Judul Buku         : "; cin.ignore(1, '\n'); getline(cin, baru->buku);   //Memasukan judul buku (getline digunanakan agar dapat mengunakan spasi
	cout<<"Masukan Tahun Terbit Buku  : "; cin>>baru->tahun;                                //Memasukan terbit tahun
	cout<<"Masukan pengarang          : "; fflush(stdin); getline(cin, baru->pengarang);    //Memasukan nama pengarang (getline digunanakan agar dapat mengunakan spasi
	baru->next = NULL;  //bahwa data berikutnya dalam kondisi masih kosong
	if(isempty()==1)    //pecabangan if else dengan fungsi isempty(), mengecek apakah data dalam kondisi kosong,jika kosong maka true atau =1
	{
    //jika kosong maka masuk ke intruksi ini
    head=tail=baru;     //maka head=tail langsung mengarah baru atau data masukan baru langsung masuk ke depan
    tail->next=NULL;    //kemudian tail->next mengarah ke NULL
	}
	else    // jika ada isi datanya maka else
    {
	tail->next=baru; //jadi nama tail berikutnya akan pindah ke baru atau masukan datanya
	tail=baru;   //kemudian nama tail ini berisikan data baru pada masukan
    }
    cout<<"data dimasukan!!\n"; // menampilkan kalimat pada saat sudah melakukan masukan data
    getch();    // untuk menahan ouput agar tertampil
}

// fungsi untuk menghapus dari depan Node
void Hapusdepan()
{
	Node *temp;             //Membuat Node Pointer baru yang digunakan untuk menyimpan data
	if (isempty()==1){      //kondisi pengecekan apakah kondisi data masih kosong maka isempty()==1 atau true
        cout<<"data masih kosong"<<endl; //menampilkan kalimat
        //dan jika ada isinya maka masuk ke kondisi, isempty()==0 atau false
	}
	if (isempty()==0)       //kondisi mengecek apakah kondisi terisi maka masuk ke intruksi berikut ini
	{if(head->next!=NULL)   //mengecek kembali paka data berikutnya tidak kosong berarti masukan datanya lebih dari 1
	{
    //jika isi datanya lebih dari satu  melakukan penghapusan berikut
    cout<<"data depan terhapus";
    temp=head;  // pertama pointer temp ini digunakan untuk menyimpan data head
    head=head->next; //kemudian nama dari head ini dipindahkan ke data berikunya
    delete temp;    //karena data head sudah ada di temp, maka dalam penghapusan data depan kita gunakan delete temp
	}
	//jika kondisi terisi hanya satu data maka else
	else
	{
     cout<<"Data terhapus dan Kosong\n";    //menampilkan kalimat
     head=tail=NULL;                        //karena hanya 1 data maka langsung kita bikin head=tail=NULL;,yang artinya data dideklarasikan menjadi kosong
    }
  }
}

//fungsi untuk menghapus dari belakang node
void Hapusbelakang()
{
	Node *akhir, *temp; //Membuat Node Pointer baru yang digunakan untuk menyimpan data
	if (isempty()==1){  //mengecek data apakah masih kosong datanya, maka akan menampilkan kalimat
        cout<<"data masih kosong"<<endl;    //menampilkan kalimat
	}
	//dan jika ada isinya pada data maka isempty()==0 atau false
  	if (isempty()==0){
        if(head!=tail)    //jika head!=tail, maka isi data lebih dari satu data
	{
     temp=head;           // temp diletakan sama dengan head
     while(temp->next!=tail){ //jika temp->next!=tail, yang artinya memiliki lebih dari 1 data isinya
        temp=temp->next;
     }
     cout<<"data belakang terhapus";
     akhir=tail;    //dari pointer akhir menyimpan data tail
     tail=temp;     //kemudian nama tail dipindahkan ke temp
     delete akhir;  // gunakan delete ke akhir,karena akhir yang menyimpan data tail. dalam penghapusan data belakang, data yang akhir dihapus, maka nama tail akan berpindah ke temp dan temp menjadi tail
     tail->next=NULL;
	}
	//dan jika kondisi hanya satu data isinya maka else
	else
    {
        cout<<"data terhapus dan data kosong";  //menampilkan kalimat
        head=tail=NULL;     //karena hanya 1 data maka langsung kita bikin head=tail=NULL;,yang artinya data menjadi kosong
    }
  	}
}

// fungsi untuk Mencetak data
void cetak()
{
  int no = 1;   //memberi no urut pada data
  Node *bantu;  //Membuat Node Pointer baru dengan tipe data struct
  bantu = head; //letak bantu = head
  //mengecek kondisi jika, kondisi dalam keadaan masih kosong maka masuk ke instruksi ini
  if (isempty()==1)
 {
  cout<<" Data Dalam Keadaan Kosong"<<endl; //menmpilkan kalimat
 }
 // jika terisi datanya maka akan menampilkan data maka masuk ke instruksi ini (else)
  else
 {
    cout<<"=================================================================\n";
    cout<<"|                   Menampilkan Data Buku                       |\n";
    cout<<"=================================================================\n";
  while(bantu !=NULL)   //Mengecek kondisi pada perulangan while (apakah masukan tidak dalam keadaan kosong )jika iya maka melakukan penampilan data dan jika tidak maka menampilkan kalimat "data kosong"
 {
    cout<<"Data ke-"<<no<<endl; //menampilkan nomor urut data
    cout << "\nJudul Buku 	: " << bantu->buku<<endl;       // menampilkan data judul buku
    cout << "Tahun Terbit	: " << bantu->tahun<<endl;      // menampilkan data tahun buku
    cout << "Pengarang       : " << bantu->pengarang<<endl; // menampilkan data nama pengarang buku
    cout<<"=================================================================\n";
  no++; //nomor urut ini aka bertambah sampai dengan masukan data dimasukan
  bantu = bantu->next; // jadi untuk menampilkan datanya, pada akhir code digunakan bantu=bantu->next; yang artinya penampilan data, dari data awal kedata berikutnya sesuai dengan masukan data
  }
}
}

// Fungsi cari data
void cari()
{
    Node *bantu;    //Membuat Node Pointer baru dengan tipe data struct
	bantu=head;     //letak bantu = head
	string cari;    //variabel cari digunakan untuk mencari data
	//pada penggunaan getline agar tidak terjadi buffer(masukan pada output terlewatkan) jadi digunakan lah, cin.ignore(1, '\n'); atau bisa juga fflush(stdin);
	cout<<"\nJudul Buku Yang Dicari \t: ";cin.ignore(1, '\n'); getline(cin, cari); //Memasukan judul buku dengan variabel cari (getline digunanakan agar dapat mengunakan spasi
    //jika isempty()==1 maka data dalam keadaan masih kosong
	if(isempty()==1)
	{
		cout<<"Data Kosong";    //manampilkan kalimat
	}
	//jika isempty()==0 maka data dalam keadaan terisi
	if(isempty()==0){
    cout<<"\nMenemukan Data Yang Dicari :\n\n";
	{
		while(bantu!=NULL)  //Mengecek kondisi pada perulangan while (apakah masukan tidak dalam keadaan kosong ) jika iya maka melalkuan pencarian dan jika tidak datanya kosong
	{
    //maka kondisi ini menggunakan bantu->buku untuk masukan data yang sudah dimasukan pada tambah belakang
	if(bantu->buku==cari)   //untuk instruksi carunya menggunakan bantu->buku==cari
	{
	    cout<<"=================================================================\n";
        cout<<"|                   Menampilkan Data Buku                       |\n";
        cout<<"=================================================================\n";
        //Meanampilkan kalimat
        cout << "\nJudul Buku 	: " << bantu->buku<<endl;       // menampilkan data judul buku
        cout << "Tahun Terbit	: " << bantu->tahun<<endl;      // menampilkan data tahun buku
        cout << "Pengarang       : " << bantu->pengarang<<endl; // menampilkan data nama pengarang buku
        cout<<"=================================================================\n\n";
	}
	// jadi untuk mencari datanya, pada akhir code digunakan bantu=bantu->next; yang artinya pecarian data dari data awal kedata berikutnya
	bantu=bantu->next;
	}
}
getch();   // untuk menahan ouput agar tertampil
}
}

void mencari()
{
    Node *bantu1,*bantu2, *awal, *tengah, *akhir, *jumlah;
    string cari;
    tengah=jumlah;
    for(awal=0;awal<=tengah-1;awal++)
    {
        bantu1=bantu1->next;
    }
    bantu2=bantu1->data;

    temp=head;
    while(temp!=NULL)
    {
        if(tengah==0)
        {
            printf("nNilai berada di awaln");
            return 0;
        }
        else if(bantu2==nilai)
        {
            printf("nNilai ditemukan di posisi ke-   %d",tengah);
        }
        else if (nilai<bantu2)
        {
            for(a=0;a<tengah;a++)
            {
                if(nilai==temp->data)
                {
                    printf("nNilai ditemukan di posisi ke-%d",a+1);
                    return 0;
                }
                else
                {
                    temp=temp->next;
                }
            }
        }
        else if(nilai>bantu2)
        {
            for(a=0;a<tengah;a++)
            {
                temp=temp->next;
            }
            for(a=tengah;a<=jumlah;a++)
            {
                if(nilai==temp->data)
                {
                    printf("nNilai ditemukan di posisi ke-%d",a+1);
                    return 0;
                }
                else
                {
                    temp=temp->next;
                }
            }
        }
    }

}

//fungsi pengurutan data
void urut()
{
	Node *baru1, *baru2;			//Membuat Node Pointer baru dengan tipe data struct
	string waktu ,judul ,pencipta;	 //variabel untuk menyimpan data digunakan untuk pengurutan data
	baru1 = head;
	// dalam pengurutan datanya menggunakan perulangan yang didalam ada perulangan lagi
	for(baru1 = head; baru1 != NULL; baru1 = baru1->next)  // untuk data sekarang
	{
		for(baru2 = baru1->next; baru2 != NULL; baru2 = baru2->next) // untuk data berikutnya
		{
		// jika data saat sekerang lebih besar dari data berikutnya
			if(baru1->tahun > baru2->tahun)
			//maka melakukan intruksi berikut
			{
            //perutukaran menggunakan fungsi swap merupakan bawaan fungsi dari c++ dengan menukarkan dua buah nilai.
            swap (baru1->tahun,baru2->tahun); //pertukaran bagian data tahun dengan menggunakan fungsi bawaan c++ swap
			swap (baru1->buku,baru2->buku);   //pertukaran bagian data buku dengan menggunakan fungsi bawaan c++ swap
			swap (baru1->pengarang,baru2->pengarang);   //pertukaran bagian data pengarang dengan menggunakan fungsi bawaan c++ swap
			/*
				// cara lainnya seperti ini untuk melakukan pertukaranya
  				judul = baru1->buku ;				// didalam judul menyimpan data baru1->buku atau data sekarang
   				baru1->buku = baru2->buku;			// baru1->buku (data sekarang) digantikan jadi baru2->buku (data berikutnya)
   				baru2->buku = judul;				// baru2->buku (data berikutnya) sama dengan judul yang menyimpan data sekarang
                                                    // maka terjadilah pertukaran

  				waktu = baru1->tahun ;				// didalam waktu menyimpan data baru1->tahun atau data sekarang
   				baru1->tahun = baru2->tahun;		// baru1->tahun (data sekarang) digantikan jadi baru2->tahun (data berikutnya)
   				baru2->tahun = waktu;				// baru2->tahun (data berikutnya) sama dengan waktu yang menyimpan data sekarang
                                                    // maka terjadilah pertukaran

  				pencipta = baru1->pengarang ;			// didalam pencipta menyimpan data baru1->pengarang atau data sekarang
   				baru1->pengarang = baru2->pengarang;	// baru1->pengarang (data sekarang) digantikan jadi baru2->tahun (data berikutnya)
   				baru2->pengarang = pencipta;			// baru2->tahun (data berikutnya) sama dengan pencipta yang menyimpan data sekarang
                                                        // maka terjadilah pertukaran
   			*/
            }
		}
	}
}

// fungsi Menampilkan Pengurutan datanya
void TampilSesudah()
{
    Node *tampil;   //Membuat Node Pointer baru dengan tipe data struct
    tampil=head;    //letakan tampil = head
    //mengecek kondisi, jika isempty()==1 maka data dalam keadaan masih kosong
    if(isempty()==1)
	{
        cout << "\nData Masih Kosong"; //menampilkan kalimat
        return; //yang artinya menjalankan instruksi
    }
    //jika ada ada datanya maka akan menampilkan pengurutan data (yang sudah melewati proses pengurutan)
    else
    {
        cout<<"===================================="<<endl;
        cout<<"|     Urutan Tahun Terbit Buku     |"<<endl;
        cout<<"===================================="<<endl;
    	while(tampil!=NULL) //Mengecek kondisi pada perulangan while (apakah masukan tidak dalam keadaan kosong ) jika iya maka melalkuan pengurutan dan jika tidak datanya kosong
		{
     		cout << "\nJudul Buku 	: " << tampil->buku<<endl;      // menampilkan data judul buku
   	 		cout << "Tahun Terbit	: " << tampil->tahun<<endl;     // menampilkan data tahun buku
   	 		cout << "Pengarang       : " << tampil->pengarang<<endl;// menampilkan data nama pengarang buku
   	 		// jadi untuk menampilkan datanya, pada akhir code digunakan tampil=tampil->next; yang artinya pecarian data dari data awal kedata berikutnya
    		tampil=tampil->next;
    	}
   		cout << "===================================\n";
    }
}

// program utama
int main(){
char pilih;     //mendeklarasikan variabel pilih dengan tipe data char, digunakan untu memasukan pemilihan menu
do  // perulangan do digunakan untuk menampilkan menu program dan mengulang intruksi yang ada didalam perulangan hingga kondisi false
{
system("cls"); //membersihkan layar pada output
// Menampilakan tampilan menu program
cout << "=================MENU UTAMA==================\n";
cout << "---------------------------------------------\n";
cout << "|  Pilih Menu Untuk Responsi Struktur Data  |\n";
cout << "---------------------------------------------\n";
cout << "| 1. Tambah Dari Belakang                   |\n";
cout << "| 2. Hapus Dari Depan                       |\n";
cout << "| 3. Hapus Dari Belakang                    |\n";
cout << "| 4. Cetak Semua Data                       |\n";
cout << "| 5. Cari data                              |\n";
cout << "| 6. Mengurutkan data                       |\n";
cout << "| 0. keluar                                 |\n";
cout << "---------------------------------------------\n";
cout << "PILIHAN ANDA  = ";
cin>>pilih; // masukan pemilihan menu program dengan variabel pilih yang
// dalam pemilihan intruksinya digunanakan SWITCH CASE percabangan
switch(pilih){  //SWITCH dimana terdapat nama variabel masukan pilih yang akan diperiksa

        // pilihan instruksi 1
case '1' : Tambahbelakang();      // Memanggil nama fungsi pada case 1 (agar dapat instruksi menjalankan tambah belakang)
         getch();               // untuk menahan ouput agar tertampil
         break;                 // mengakhiri intruksi pilihan 1

        // pilihan instruksi 2
case '2' : Hapusdepan();          // Memanggil nama fungsi pada case 2 (agar dapat instruksi menjalankan hapus depan)
           getch();               // untuk menahan ouput
           break;                 // mengakhiri intruksi pilihan 2

        // pilihan instruksi 3
case '3' : Hapusbelakang();       // Memanggil nama fungsi pada case 3 (agar dapat menjalankan indtruksi hapus belakang)
           getch();               // untuk menahan ouput agar tertampil
           break;                 // mengakhiri intruksi pilihan 3

        // pilihan instruksi 4
case '4' : cetak();               // Memanggil nama fungsi pada case 4 (agar dapat menjalankan intruksi mencetak semua masukan data)
           getch();               // untuk menahan ouput agar tertampil
           break;                 // mengakhiri intruksi pilihan 4

        // pilihan instruksi 5
case '5' : cari();                // Memanggil nama fungsi pada case 5 (agar dapat menjalankan intruksi mencari data)
           getch();               // untuk menahan ouput agar tertampil
           break;                 // mengakhiri intruksi pilihan 5

        // pilihan instruksi 6
case '6' : urut();                // Memanggil nama fungsi pada case 6 (agar dapat menjalankan proses pengurutan datanya)
           TampilSesudah();       // Memanggil nama fungsi pada case 6 (agar dapat menjalankan intruksi menampilkan pengurutan datanya)
           getch();               // untuk menahan ouput agar tertampil
           break;                 // mengakhiri intruksi pilihan 6

        // pilihan instruksi 0
case '0' : cout<<"Terima Kasih"<<endl; // menampilkan kalimat
         exit(0);  //fungsi  yang dapat menghentikan program atau dengan kata lain keluar dari program
         break;    // mengakhiri intruksi pilihan 0

        //Jika pilihan yang dimasukan tidak sesuai dengan pilihan yang terdapat pada menu, maka Akan menampilkan kalimat berikut
default :cout<<"Menu tidak tersedia!"<<endl;  // menampilkan kalimat
         cout << "Tekan Enter untuk kembali ke menu!"; // menampilkan kalimat
         getch();   // Untuk menahan ouput agar tertampil
      }
      }while(pilih != 0); // karena pada menu menggunkan perulngan do menampilkan pernyataan terlebih dahulu, kemudian mengecek kondisi
      //jika pilihan menu tidak sama dengan 0, maka akan menampilkan menu serta fungsinya. dan jika dipilih 0 maka akan keluar
      return pilih; // untuk mengakhiri instruksi
}

https://www.ketutrare.com/2018/07/metode-searching-dan-sorting-double.html
