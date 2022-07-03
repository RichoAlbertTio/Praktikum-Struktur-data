// memasukan data
#include <iostream>
#include <conio.h>

using namespace std;
/* membuat linked list */
struct Node
{
        char nama[25];
        char nim[20];
        Node *next;
};
Node *head;

/* keadaan awal */
int awal()
{
        head = NULL;
}

/*fungsi untuk mengecek linked list
* apakah kosong atau tidak
* jika kosong maka bernilai 1
* jika tidak kosong maka bernilai 0
*/
int isempty()
{
        if (head == NULL)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

/**
* fungsi untuk menambahkan data dari depan node
*/
void tambahDepan()
{
        Node *baru;
        baru = new Node;
        cout << "Masukkan Data lengkap di bawah ini : " << endl;
        fflush(stdin);
        cout << "Nama : ";
        gets(baru->nama);
        cout << "NIM  : ";
        cin >> baru->nim;
        baru->next = NULL;
        if (isempty() == 1)
        {
                head = baru;
                head->next = NULL;
        }
        else
        {
                baru->next = head;
                head = baru;
        }
        cout << "\nData telah dimasukan";
}

/**
* fungsi untuk menambahkan data dari belakang node
*/
void tambahBelakang()
{
        Node *baru, *bantu;
        baru = new Node;
        cout << "\nMasukkan Data lengkap di bawah ini : " << endl;
        fflush(stdin);
        cout << "Nama : ";
        gets(baru->nama);
        cout << "NIM  : ";
        cin >> baru->nim;
        baru->next = NULL;
        if (isempty() == 1)
        {
                head = baru;
                head->next = NULL;
        }
        else
        {
                bantu = head;
                while (bantu->next != NULL)
                {
                        bantu = bantu->next;
                }
                bantu->next = baru;
        }
        cout << "\nData telah dimasukan";
}

/**
* fungsi untuk menghapus dari depan node
*/
void hapusDepan()
{
        Node *hapus;
        char *data;
        if (isempty() == 0)
        {
                if (head->next != NULL)
                {
                        hapus = head;
                        data = hapus->nim;
                        head = head->next;
                        delete hapus;
                }
                else
                {
                        data = head->nim;
                        head = NULL;
                }
                cout << data << " sudah terhapus \n";
        }
        else
        {
                cout << "Data Masih kosong!!\n";
        }
        cout << "Tekan Enter untuk kembali ke Menu!";
        getch();
}

/**
* fungsi untuk menghapus dari belakang node
*/
void hapusBelakang()
{
        Node *hapus, *bantu;
        char *data;
        if (isempty() == 0)
        {
                if (head->next != NULL)
                {
                        bantu = head;
                        while (bantu->next->next != NULL)
                        {
                                bantu = bantu->next;
                        }
                        hapus = bantu->next;
                        data = hapus->nim;
                        bantu->next = NULL;
                        delete hapus;
                }
                else
                {
                        data = head->nim;
                        head = NULL;
                }
                cout << data << " sudah terhapus� " << endl;
        }
        else
        {
                cout << "Data masih kosong!!" << endl;
        }
        cout << "Tekan Enter untuk kembali ke Menu!";
        getch();
}
/**
* fungsi untuk menampilkan data linked list
*/
void tampilData()
{
        int no = 1;
        Node *bantu;
        bantu = head;
        if (isempty() == 0)
        {
                while (bantu != NULL)
                {
                        cout << "Nomor ke- : " << no << endl;
                        cout << "Nama : " << bantu->nama << endl;
                        cout << "NIM  : " << bantu->nim << endl
                             << endl;
                        no++;
                        bantu = bantu->next;
                }
                cout << endl;
        }
        else
        {
                cout << "Data masih kosong " << endl;
        }
        cout << "Tekan Enter untuk kembali ke menu!";
        getch();
}
/**
* program utama
*/
int main()
{
        int pilihan;
        do
        {
                system("cls");
                cout << "-------------------------\n";
                cout << "|MENU SINGLE LINKED LIST|\n";
                cout << "-------------------------\n";
                cout << "| 1. Tambah Depan       |\n";
                cout << "| 2. Tambah Belakang    |\n";
                cout << "| 3. Hapus Depan        |\n";
                cout << "| 4. Hapus Belakang     |\n";
                cout << "| 5. tampilkan data     |\n";
                cout << "| 6. keluar             |\n";
                cout << "-------------------------\n";
                cout << " PILIHAN ANDA ? = ";
                cin >> pilihan;
                cout << "\n";
                switch (pilihan)
                {
                case 1:
                        tambahDepan();
                        getch();
                        break;

                case 2:
                        tambahBelakang();
                        getch();
                        break;

                case 3:
                        hapusDepan();
                        getch();
                        break;

                case 4:
                        hapusBelakang();
                        getch();
                        break;

                case 5:
                        tampilData();
                        getch();
                        break;

                case 6:
                        exit(true);
                        break;
                default:
                        cout << "Menu tidak tersedia!" << endl;
                        cout << "Tekan Enter untuk kembali ke menu!";
                        getch();
                }
        } while (pilihan != 6);
        return 0;
}
//http://idatriwi.blogspot.com/2018/05/struktur-data-linked-list_1.html
//https://bnwofficial.wordpress.com/2018/04/30/pengertian-macam-macam-dan-penggunaan-linked-list-dalam-c/
