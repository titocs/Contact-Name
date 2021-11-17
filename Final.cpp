#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

COORD coord = {0, 0};
void gotoxy(int x,int y){ // x koordinat x, y koordinat y
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// built in function untuk menyembunyikan kursor
void hidecursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

int i, j;
FILE *satu, *dua;

void jeda(int j){	
	int i, k;
    for(i=0; i<j; i++)
		k=i;
}

struct daftar {
	char nama[50], alamat[50], nomor[50];
} kontak;

char hapus[50], nama[50];

// declarasi fungsi fungsi menu
void menu();
void tambah_kontak();
void lihat_kontak();
void hapus_kontak();

// deklarasi fungsi kursor
void window(int, int, int, int);
void curser(int);
void highlight(int, int);

// fungsi UTAMA
int main(){
	hidecursor();
	menu();
	return 0;
}

void menu(){
	system("COLOR 1");
	// system("cls") berfungsi untuk menghapus layar
	system("cls");
	int i;
    char ch;
    const char *menu[]= {"   Tambah Kontak","   Lihat Kontak","   Hapus Kontak","   Keluar"};
    system("cls");
    // a, b penambahan ke kiri dan kanan
    // c, d penambahan atas bawah
    window(25, 50, 5, 15);
    /// backup window(25, 50, 20, 30);
    gotoxy(33, 18);
    cout << ("MAIN MENU");
    for(i=0; i<=3; i+=2){
        gotoxy(30, 7+i);
        printf("%s\n\n\n", menu[i]);
    }
    // panggil kursor
    curser(4);
}

void curser(int no){
    int count = 1;
    char ch = '0';
    gotoxy(30, 23);
    highlight(no, count);
    ch = getch();
    if(ch == '\r'){
        if(no == 4){
            if(count == 1)
				tambah_kontak();
            else if(count == 2)
				lihat_kontak();
            else if(count == 3)
				hapus_kontak();
            else
				exit(0);
        }
    }
}

void highlight(int no, int count){
    if(no == 4){
        gotoxy (30, 7);
        printf("   Tambah Kontak");
        gotoxy (30, 9);
        printf("   Lihat Kontak");
        gotoxy (30, 11);
        printf("   Hapus Kontak");
        gotoxy (30, 13);
        printf("   Keluar");

        switch(count){
        case 1:
            gotoxy (30, 7);
            printf(" - Tambah Kontak");
            break;
        case 2:
            gotoxy (30, 9);
            printf(" - Lihat Kontak");
            break;
        case 3:
            gotoxy (30, 11);
            printf(" - Hapus Kontak");
            break;
        case 4:
            gotoxy (30, 13);
            printf(" - Keluar");
        }
    }
}

void tambah_kontak(){
	system("cls");
	system("COLOR 1F");
	//satu = fopen("daftarnama.txt", "r");
	//if( satu == NULL ){
	//	satu = fopen("daftarnama.txt", "w");
	//}
	satu = fopen("daftarnama.dll", "a");

	for(i=0; i<1; i++){
		fflush(stdin);
		printf("\n\n\n\n\n\t\t\t\t--------MENU MEMBUAT KONTAK--------\n\n");
		printf("\t\t\tNAMA : ");
		scanf("%[^\n]", &kontak.nama);
		fflush(stdin);
		printf("\n\t\t\tNOMOR : ");
		scanf("%[^\n]", &kontak.nomor);
		fflush(stdin);
		printf("\n\t\t\tALAMAT : ");
		scanf("%[^\n]", &kontak.alamat);
		printf("\n");
		fflush(stdin);
		fwrite(&kontak, sizeof(kontak), 1, satu);
		printf("\n\t\t\tMenyimpan kontak");
		for(i=0; i<=6; i++){
			jeda(100000000);
           	printf(".");
        }
    	printf("\n");
    	printf("\t\t\tBerhasil menambahkan kontak\n");				
	}
	printf("\n\t\t\tTekan ENTER untuk melanjutkan");
	getch();
	fclose(satu);
	menu();
}

void lihat_kontak(){	
	system("cls");
	system("COLOR 1F");
	printf("\n\n\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DAFTAR NAMA KONTAK \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
	for(i=97; i<=122; i++){
		satu = fopen("daftarnama.dll", "r");
        fflush(stdin);
        if(satu == NULL){
			printf("Tidak ada list kontak");
			exit(0);
		}
        while(fread(&kontak, sizeof(kontak), 1, satu) == 1){
            if(kontak.nama[0] == i || kontak.nama[0] == i-32){
			    printf("\n\t\t\tNAMA : %s\n", kontak.nama);
			    printf("\t\t\tNOMOR : %s\n", kontak.nomor);
			    printf("\t\t\tALAMAT : %s\n", kontak.alamat);
			    i++;
            }
        }
        fclose(satu);
    }
	printf("\n");
	printf("\n\t\t\tTekan ENTER untuk melanjutkan");
	getch();
	menu();
}

void hapus_kontak(){
	system("cls");
	system("COLOR 1F");
	fflush(stdin);
	printf("\n\n\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2 MENU HAPUS KONTAK \xB2\xB2\xB2\xB2\n\n");
	printf("\n\t\t\tMasukkan nama kontak yang akan dihapus : ");
	scanf("%[^\n]", &hapus);
		
	satu = fopen("daftarnama.dll", "r");
	dua = fopen("ubah.dat", "w");
		
	if(strcmp(hapus, kontak.nama) == 0){
		while( fread(&kontak, sizeof(kontak), 1, satu)!= 0){
			if(strcmp(hapus, kontak.nama)!=0)
    	        fwrite(&kontak, sizeof(kontak), 1, dua);
			}
    	fclose(satu);
       	fclose(dua);
        
       	remove("daftarnama.dll");
       	rename("ubah.dat", "daftarnama.dll");
		
		printf("\n\t\t\tSedang menghapus kontak");
		for(i=0; i<=6; i++){
        	jeda(100000000);
      		printf(".");
       	}
        printf("\n\n\n\t\t\tBerhasil! Nama telah dihapus\n\n");
    }
    else{
        printf("\n\t\t\tSedang menghapus kontak");
		for(i=0; i<=6; i++){
        	jeda(100000000);
	  		printf(".");
		}
    	printf("\n\t\t\tERROR ! nama kontak tidak terdaftar");
        exit(0);
	}
		
    printf("\t\t\tTekan ENTER untuk melanjutkan");
    getch();
    menu();
}

void window(int a, int b, int c, int d){	
    int i;
    system("cls");
	system("COLOR 4");

	// garis vertikal
    for (i=a; i<=b; i++){
        gotoxy(i, 17);
        printf("\xcd");
        gotoxy(i, 19);
        printf("\xcd");
        gotoxy(i, c);
        printf("\xcd");
        gotoxy(i, d);
        printf("\xcd");
    }

	//vertikal menu bagian kiri
    gotoxy(a, 17);
    printf("\xc9");
    gotoxy(a, 18);
    printf("\xba");
    gotoxy(a, 19);
    printf("\xc8");
    
    //vertikal menu bagian kanan
    gotoxy(b, 17);
    printf("\xbb");
    gotoxy(b, 18);
    printf("\xba");
    gotoxy(b, 19);
    printf("\xbc");

	// garis vertikal kiri kanan void menu()
    for(i=c; i<=d; i++){
        gotoxy(a, i);
        printf("\xba");
        gotoxy(b, i);
        printf("\xba");
    }
    gotoxy(a, c);
    printf("\xc9");
    gotoxy(a, d);
    printf("\xc8");
    gotoxy(b, c);
    printf("\xbb");
    gotoxy(b, d);
    printf("\xbc");
}
