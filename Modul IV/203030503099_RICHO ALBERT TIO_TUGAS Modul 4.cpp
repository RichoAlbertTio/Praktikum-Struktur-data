/*
    NAMA  : RICHO ALBERT TIO
    NIM   : 203030503O99
    MODUL : IV
*/
//header file memasukan library untuk penggunaan fungsi-fungsi yang berjalan diprogram
#include <stdio.h>  //untuk fungsi input dan output pada header yang digunakan dan fungsi lainnya
#include <conio.h>  //Untuk menampilkan hasil antarmuka pada output program, berhenti dan lainnya
#include <stdlib.h> //Untuk operasi pembanding dan operasi konversi
#include <iostream> //Sebagai fungsi input dan output operasi yang digunakan pada program
using namespace std;

typedef struct Node{    //Mendeklarasikan struct
	int data;           //variabel data tipe datanya integer dalam struct
	Node *kiri;         //pointer untuk menunjuk node kiri
	Node *kanan;        //pointer untuk menunjuk node kanan
}Node;                  //deklarasi node

Node *root = NULL;      //deklarasi node root bahwa keadaan awal masih kosong

//fungsi yang tidak mengembalikan nilai yaitu void fungsi untuk memasukan data dengan parameter isi dengan tipe data char
void addNode (Node **root, char isi)
{
	if((*root)==NULL)                   //Jika Node root sama dengan NULL atau masih kosong maka lanjut ke perintah berikutnya agar dapat menambahkan data
	{
		Node *baru;                     //membuat node baru
		baru = new Node;                //mendeklarasikan node yang baru dibuat
		baru -> data = isi;             //mendeklarasikan Node baru menunjukaan struct data menjadi variabel databaru
		baru -> kiri = NULL;            //node baru kiri dideklarasikan nilai nya menjadi NULL atau keadaan masih kosong
		baru -> kanan = NULL;           //node baru kanan dideklarasikan nilai nya menjadi NULL atau keadaan masih kosong
        (*root) = baru;                 //node root menjadi data baru
        (*root) -> kiri = NULL;         //node root menujukan ke arah kiri dan menjadi NULL
        (*root) -> kanan = NULL;        //node root menujukan ke arah kanan dan menjadi NULL
		cout<<"Data Bertambah!";        //pada saat sudah memasukan data dalam program maka akan menampilkan kalimat data bertambah
    }
    else if (isi<(*root)->data)         //data yang diinput lebih kecil dari node root, maka akan di letakan di node sisi kiri
        addNode(&(*root)->kiri,isi);    //Jika nilai data lebih kecil ditempatkan pada bagian Node kiri
    else if (isi>(*root)->data)         //data yang diinput lebih besar dari node root, maka akan di letakan di node sisi kanan
        addNode(&(*root)->kanan,isi);   //Jika nilai data lebih kecil ditempatkan pada bagian Node kanan
    else if (isi==(*root)->data)        //jika data yang diinput sama dengan node root, maka data tidak dapat dimasukan dalam program dan akan menampilkan data sudah ada
        cout<<"Data Sudah ada!";        // menampilkan kalimat data sudah ada
	}
//fungsi yang tidak mengembalikan nilai yaitu void fungsi menyusun data secara preOrder
void preOrder(Node *root)
{
	if(root!=NULL)                      // jika data tidak sama dengan NULL maka data akan disusun secara preorder
	{
 		cout<<root->data<<" ";          // menampilkan node yang dikunjungi
	preOrder(root->kiri);               // mengunjungi node kiri
	preOrder(root->kanan);              // mengunjungi node kanan
	}
}

// fungsi yang tidak mengembalikan nilai yaitu void fungsi menyusun data secara inOrder
void inOrder(Node *root)
{
	if(root!=NULL)                      // jika data tidak sama dengan NULL maka data akan disusun secara inOrder dan intruksi seperti berikutnya berikut ini
	{
 	inOrder(root->kiri);                // mengunjungi node kiri
		cout<<root->data<<" ";          // menampilkan node yang dikunjungi
	inOrder(root->kanan);               // mengunjungi node kanan
	}
}

//fungsi yang tidak mengembalikan nilai yaitu void fungsi menyusun data secara postOrder
void postOrder(Node *root)
{
	if(root!=NULL)                      // jika data tidak sama dengan NULL atau datanya tidak kosong maka data akan disusun secara postorder dan instruksi seperti berikut ini
	{
 		postOrder(root->kiri);          // mengunjungi node kiri
 		postOrder(root->kanan);         // mengunjungi node kanan
 			cout<<root->data<<" ";      // menampilkan node yang dikunjungi
	}
}

// fungsi yang mengembalikan nilai yaitu int fungsi untuk mengukur kedalaman
int height(Node *root)
{
 	if(root == NULL)    //Jika root sama denagan NULL atau data masih kosong maka akan menjalankan instruksi ditidak menampilkan apa-apa atau return 0
 	return 0;
 	else                //jika root ada data yang terisi maka akan menjalankan intruksi berikut ini
	{
 		int a = height(root->kiri);     //Variabel a tipe data integer untuk mengukur kedalaman di bagian kiri
 		int b = height(root->kanan);    //Variabel b tipe data integer untuk mengukur kedalaman di bagian kanan
 		int big = a > b ? a : b;      //counter variabel big dengan tipe data integer untuk mencari data kedalaman terbesar dari variabel a(kiri) dan b(kanan)
 		return (big + 1);              // menjalankan intruksi data kedalaman terbesar akan ditambah 1
	}
}

// fungsi tidak mengembalikan nilai yaitu void fungsi leveltree dengan parameter level dengan tipe data integer
void leveltree (Node *root, int level)
{
	if (root == NULL)  //jika root sama dengan NULL atau root datanya masih kosong maka tidak menjalankan apa-apa atau return
	{
		return ;
	}
	if (level == 1)    //Jika level sama dengan 1, maka akan menjalankan instruksi berikut ini jika tidak sama dengan satu maka ke intruksi berikutnya
	{
		cout<<root->data<<" ";  // menampilkan data yang ada pada root
	}
	else if (level > 1)         // jika level lebih besar dari 1. maka akan menjalankan instruksi berikut ini
	{
		leveltree (root -> kiri, level -1);     //root akan menujukan ke bagian node kiri dengan variabel level bernilai -1
		leveltree (root -> kanan, level -1);    //root akan menunjukan ke bagian node kanan dengan variabel level bernilai -1
	}
}
// fungsi yang tidak mengembalikan nilai yaitu void fungsi mencari secara bfs
void BFS (Node *root)
{
	int h = height (root);        // memanggil fungsi tinggi ke dalam variabel h
	for (int i = 1; i <= h; ++i)  // perulangan for yaitu variabel i sama denagan 1, dan niai i lebih kecil sama dengan h maka i akan bertambah 1 sesuai dengan datanya
	leveltree (root, i);           //Memanggil fungsi leveltree dengan menambahkan variabel pengulangan i
}

// program utama fungsi menu program
int main()
{
    char pil;       //mendeklarasikan variabel pil dengan tipe data char
    int isi;        //mendeklarasikan variabel isi dengan tipe data integer
    while (true)    //Pengulangan untuk menu program dengan menggunakan dengan while
	{
        system("cls");  //membersihkan layar pada output
            // menampilakan kalimat pada menu
        	cout<<" ======================"<<endl;
        	cout<<"|       M E N U        |"<<endl;
       	    cout<<"|     Binary Tree      |"<<endl;
       	    cout<<" ======================"<<endl;
       		cout<<"| 1.Input Data         |"<<endl;
        	cout<<"| 2.DFS                |"<<endl;
        	cout<<"| 3.BFS                |"<<endl;
        	cout<<"| 4.Keluar             |"<<endl;
			cout<<" ======================"<<endl;
        	cout<<" Pilihan Anda : ";
        	cin>>pil;               //Inputan untuk pilihan menu dengan variabel pil yang sudah di deklarasikan tipe datanya
        // untuk mengunakan case maka variabel pil di pasangkan dengan switch
        switch(pil)
		{
		case '1':                       // pemilihan no 1 pada menu
			cout<<""<<endl;
			cout<<"================"<<endl;
			cout<<"Inputkan Data "<<endl;
			cout<<"================"<<endl;
            cout<<"Masukan Data : ";
			cin>>isi ;                  //Inputan unutk memasukan data dengan variabel isi
            addNode(&root,isi);
            getch();    // agar dapat menampilakan intruksi
            break;      // mengakhiri intruksi pilihan 1

		case '2':                       // pemilihan no 2 pada menu
			cout<<" ==========================="<<endl;
        	cout<<"|        HASIL DFS          |"<<endl;
            cout<<" ==========================="<<endl;
			cout<<" PreOrder  : ";preOrder(root);       //Memanggil fungsi preOrder
			cout<<"\n InOrder   : ";inOrder(root);      //Memanggil fungsi inOrder
			cout<<"\n PostOrder : ";postOrder(root);    //Memanggil fungsi postOrder
			cout<<"\n Tinggi    : "<<height(root)<<endl;    //Memanggil fungsi tinggi
			cout<<" ==========================="<<endl;
			getch();    // agar dapat menampilakan intruksi
			break;      // mengakhiri intruksi pilihan 2

		case '3':                       // pemilihan no 3 pada menu
		    cout<<" ==========================="<<endl;
			cout<<"|         HASIL BFS         |"<<endl;
			cout<<" ==========================="<<endl;
			cout<<" BFS       : "; BFS(root);           // memanggil fungsi bfs
			cout<<"\n Tinggi    : "<<height(root);      // memanggil fungsi tinggi
			cout<<"\n==========================="<<endl;
			getch();    // agar dapat menampilakan intruksi
			break;  // mengakhiri intruksi pilihan 3

      	case '4' :              // pemilihan no 4 pada menu
            cout<<"Terima Kasih";   // menampilkan kalimat
            exit(0);                // memanggil fungsi exit
            break;                  // mengakhiri intruksi pilihan 4

		default :                   //Jika pilihan yang dimasukan tidak sesuai dengan pilihan yang terdapat pada menu maka, Akan menampilkan kalimat tersebut
            cout<<"\nMenu Tidak Ada	"<<endl;
            getch(); // agar dapat menampilakan intruksi
	}
}return 0;
}
