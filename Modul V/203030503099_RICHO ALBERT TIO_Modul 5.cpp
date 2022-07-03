/*
Nama        : Richo Albert Tio
Nim         : 203030503099
mata kuliah : struktur data
modul       : v
*/
#include <iostream>
#include <conio.h>
using namespace std;

// fungsi pengurutan data dengan menggunakan bubble sort
void BubbleSort()
{
	//Deklarasi Data
     int data[100];
     //Deklarasi Pengulangan
     int i, j, n, tmp, jumlah=0;
      cout<<"Program \n\n";
      //Masukan Banyak Data
      cout<<"Masukkan jumlah bilangan : ";
      cin>>n;
     for(i=0; i<n; i++)  {
     		//Memasukan data
             cout<<"Masukkan Angka ke "<<(i+1)<<" = ";
              cin>>data[i];
             jumlah=jumlah+data[i];

        }
	//Tampilan Data sebelum
  cout<<"\nData sebelum diurutkan = "<<endl;
   for(i=0; i<n; i++)
         {
         cout<<data[i]<<" ";
         }
       cout<<endl;
	//Disini Proses pengurutan data Bubble Sort
     for( i=0; i<n; i++)
      {
          for(j=i+1; j<n; j++)
          {
               if(data[i]>data[j])
             {
                 tmp=data[i];
                 data[i]=data[j];
                 data[j]=tmp;
             }
         }
      }
      // Tampilan data setelah
         cout<<"\nData setelah diurutkan  = "<<endl;
       for(i=0; i<n; i++)
       {
        {
           cout<<data[i]<<" ";
            }
       }
getch();
}

// fungsi pengurutan data menggunakan insertion sort
void InsertionSort()
{
 int i,j,n,temp,data[100];
   // Memasukan jumlah data
   cout<<"\nJumlah Data Yang Akan Di Urutkan :";
    cin>>n;

      for(i=1;i<=n;i++){
      	// Memsukan data
        cout<<"Masukkan Data Ke -"<<i<<" = ";
          cin>>data[i];
      }
	  // Tampilan data sebelum
      cout<<"\nData Yang Belum Di Sorting \n";
       for(i=1;i<=n;i++){
           cout<<data[i]<<" ";
         }
		// proses pengurutan data
       for(i=1;i<=n;i++){
          for(j=1;j<=n;j++){
              if(data[i]<data[j]){
                 temp=data[i];
                  data[i]=data[j];
                  data[j]=temp;
               }
            }
         }
        // Tampilan data sesudah
       cout<<"\nData Yang Sudah Di Sorting \n";
       for(i=1;i<=n;i++){
         cout<<data[i]<<" ";
       }
}

// fungsi pengurutan data menggunakan selection sort
void SelectionSort()
{
int x[100];
int i,bd,temp,minindex,j;
cout<<" Program selection sort \n";
 cout<<"\nMasukkan Banyak Data :";
  cin>>bd;
  for(i=1; i<=bd; i++)
   {
   cout<<"Masukkan Nilai Ke"<<i<<" = ";cin>>x[i];
   }
	// tampilan data sebelum pengurutan
  cout<<"\nData sebelum di sort \n";
   for(i=1; i<=bd;i++)
   {
   cout<<x[i]<<" ";
   }
   //perulangan iterasi
   for(i=1; i<=bd-1; i++)
   {
	//Penyimpanan Sementara
   minindex=i;
   //perulangan membandingkan data
   for(j=i+1; j<=bd; j++)
   {
   //Jika x dengan larik minindex lebih dari x dengan array j maka
   if(x[minindex]>x[j])
   {
   //minindex sama dengan j
   minindex=j;
   }
   }
   temp=x[i];
   x[i]=x[minindex];
   x[minindex]=temp;
   }
   // tampilan data sesudah pengurutan
    cout<<"\n\nData setelah di sort \n";
     for(i=1; i<=bd; i++)
     {
      cout<<x[i]<<" ";
     }
   getch();
}

// fungsi pengurutan data menggunkan shell sort
void ShellSort(){
   int val[100];
   int i, n, t;

   cout<<endl;
   cout<<"Masukkan Data : ";cin>>n;
   cout<<endl;
 for(i = 0; i < n; i++)
   {
       cout<<"Data ke-"<<1+i<<"  : ";cin>>val[i];
   }
   // tampilan sebelum diurutkan
   cout<<"\nsebelum pengurutan data \n\n";
		 for (i = 0; i < n; i++){
         cout<<val[i]<<" ";
		 }
	// proses pengurutan data
    for(int w = n/2; w > 0;w=w/2)
    {
       for(int x = w; x < n; x++)
      {
          for (int y = x-w; y >= 0; y-=w)
         {
             if(val[y+w] < val[y])
             {
                t=val[y+w];
               val[y+w]=val[y];
               val[y]=t;
             }
         }
      }
   }
   cout<<endl;
   cout<<"Hasil Pengurutan : \n";
   cout<<endl;
   // sesudah di urutkan
   for(i = 0; i < n; i++)
   {
       cout<<val[i]<<" ";
   }
}

// program utama menu program
int main()
{
char pilih;
do
{
system("cls");
cout<<"---------------------------"<<endl;
cout<<"| Program Pengurutan Data |"<<endl;
cout<<"---------------------------"<<endl;
cout<<"|1. Bubble Sort           |"<<endl;
cout<<"|2. Insertion Sort        |"<<endl;
cout<<"|3. Selection Sort        |"<<endl;
cout<<"|4. Shell Sort            |"<<endl;
cout<<"|5. Keluar                |"<<endl;
cout<<"--------------------------|"<<endl;
cout<<"Masukan Pilihan Menu =";
cin>>pilih;
switch(pilih){
case '1': BubbleSort();
          getch();
          break;

case '2': InsertionSort();
          getch();
          break;

case '3': SelectionSort();
          getch();
          break;

case '4': ShellSort();
          getch();
          break;

case '5': cout<<"terima kasih";
          exit(0);
          break;

default : cout<<" Menu Pilihan Tidak Ditemukan ";
          getch();
    }
}
while(pilih!=5);
return 0;
}
