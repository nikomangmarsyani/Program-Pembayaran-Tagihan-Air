#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
 
const int Administrasi = 5000;
 
//deklarasi variabel global
float tarif[5][3] = {{3740, 4020, 6300},         //index 0-Rumah Tangga Bersubsidi
                     {6940, 10400, 10700},       //index 1-Rumah Tangga Non Bersubsidi
                     {10100, 10750, 11850},      //index 2-Niaga Kecil
                     {11300, 11950, 13950},      //index 3-Niaga Sedang
                     {12500, 13150, 16650}};     //index 4-Niaga Besar
 
float BPM[2] = {9500, 15000};   //index 0-BPM Rumah Tangga
                                //index 1-BPM Usaha
 
float denda[3] = {0, 1000, 2000};   //index 0-Tanggal 1 - 15 dan Tanggal 16 - 31 && Pemakaian <10 m^3
                                    //index 1-Tanggal 16 - 31 && Pemakaian >=10 m^3 && Pemakaian < 100 m^3
                                    //index 2-Tanggal 16 - 31 && Pemakaian > 100 m^3
 
char golongan[5][50] = {"Rumah Tangga Bersubsidi",  //index 0-Rumah Tangga Bersubsidi
                        "Rumah Tangga Non Subsidi", //index 1-Rumah Tangga Non Bersubsidi
                        "Niaga Kecil",              //index 2-Niaga Kecil
                        "Niaga Sedang",             //index 3-Niaga Sedang
                        "Niaga Besar"};             //index 4-Niaga Besar
 
//deklarasi fungsi
void identitas();
void main();
void rumah_tangga();
void rumah_tangga_bersubsidi();
void rumah_tangga_non_subsidi();
void usaha();
void niaga_kecil();
void niaga_sedang();
void niaga_besar();
int proses(int index_golongan, int index_tarif, int index_bpm);
int cetak_bukti_pembayaran(int index_golongan, char nama[100], float pemakaian, float tarif1, float tarif2, float tarif3, int Administrasi, float BPM, float biaya, float output_denda, float total_bayar);
void close();
void ulang();
void Exit();
 
void identitas(){
    printf("\n\t||===============================================||");
    printf("\n\t||                  SELAMAT DATANG               ||");
    printf("\n\t||===============================================||");
    printf("\n\t||             Program ini dibuat oleh:          ||");
    printf("\n\t||                                               ||");
    printf("\n\t||           Ni Putu Mirah Kartika Cahyani       ||");
    printf("\n\t||                    2205551048                 ||");
    printf("\n\t||                                               ||");
    printf("\n\t||                Ni Komang Marsyani             ||");
    printf("\n\t||                    2205551052                 ||");
    printf("\n\t||===============================================||");
    close();
}
 
void main(){
    int menu;
    identitas();
    printf("\n\t||===============================================||");
    printf("\n\t||   PROGRAM MENGHITUNG TAGIHAN PENGGUNAAN AIR   ||");
    printf("\n\t||===============================================||");
    printf("\n\t||Pilihan Golongan Pengguna :                    ||");
    printf("\n\t|| 1. Rumah tangga                               ||");
    printf("\n\t|| 2. Usaha                                      ||");
    printf("\n\t|| 3. Exit                                       ||");
    printf("\n\t||===============================================||");
    printf("\n\tInputkan pilihan :");
    while (scanf("%d", &menu)==0 || menu < 1 || menu > 3){
		printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan pilihan yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tInputkan pilihan :");
        while((getchar())!='\n');
	}
    close();
 
    if(menu==1){
        rumah_tangga();
        ulang();
    }
    else if(menu==2){
        usaha();
        ulang();
    }
    else{
        Exit();
    }
}
 
void rumah_tangga(){
    int menu2;
    printf("\n\t||===============================================||");
    printf("\n\t||                  RUMAH TANGGA                 ||");
    printf("\n\t||===============================================||");
    printf("\n\t||Pilih Golongan Rumah Tangga :                  ||");
    printf("\n\t|| 1. Rumah tangga bersubsidi                    ||");
    printf("\n\t|| 2. Rumah tangga non subsidi                   ||");
    printf("\n\t||===============================================||");
    printf("\n\tInputkan pilihan :");
    while (scanf("%d", &menu2)==0 || menu2 < 1 || menu2 > 2){
		printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan pilihan yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tInputkan pilihan :");
        while((getchar())!='\n');
	}
    close();
 
    if(menu2==1){
        rumah_tangga_bersubsidi();
    }else{
        rumah_tangga_non_subsidi();
    }
}
 
void rumah_tangga_bersubsidi(){
    printf("\n\t||===============================================||");
    printf("\n\t||            RUMAH TANGGA BERSUBSIDI            ||");
    printf("\n\t||===============================================||");
    proses(0, 0, 0);
}
 
void rumah_tangga_non_subsidi(){
    printf("\n\t||===============================================||");
    printf("\n\t||            RUMAH TANGGA NON SUBSIDI           ||");
    printf("\n\t||===============================================||");
    proses(1, 1, 0);
}
 
void usaha(){
    int menu3;
    printf("\n\t||===============================================||");
    printf("\n\t||                  GOLONGAN USAHA               ||");
    printf("\n\t||===============================================||");
    printf("\n\t|| 1. Niaga kecil                                ||");
    printf("\n\t|| 2. Niaga sedang                               ||");
    printf("\n\t|| 3. Niaga besar                                ||");
    printf("\n\t||===============================================||");
    printf("\n\tInputkan pilihan :");
    while (scanf("%d", &menu3)==0 || menu3 < 1 || menu3 > 3){
		printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan pilihan yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tInputkan pilihan :");
        while((getchar())!='\n');
	}
    close();
 
    if(menu3==1){
        niaga_kecil();
    }else if(menu3==2){
        niaga_sedang();
    }else{
        niaga_besar();
    }
}
 
void niaga_kecil(){
    printf("\n\t||===============================================||");
    printf("\n\t||                    NIAGA KECIL                ||");
    printf("\n\t||===============================================||");
    proses(2, 2, 1);
}
 
void niaga_sedang(){
    printf("\n\t||===============================================||");
    printf("\n\t||                    NIAGA SEDANG               ||");
    printf("\n\t||===============================================||");
    proses(3, 3, 1);
}
 
void niaga_besar(){
    printf("\n\t||===============================================||");
    printf("\n\t||                     NIAGA BESAR               ||");
    printf("\n\t||===============================================||");
    proses(4, 4, 1);
}
 
int proses(int index_golongan, int index_tarif, int index_bpm){
    char nama[100];
    int tanggal;
    float bulan_ini, bulan_lalu, pemakaian, biaya, total_bayar, output_denda;
 
    printf("\n\tMasukkan nama Anda : ");
    scanf("%[^\n]s", nama);
    printf("\n\tMasukkan tanggal pembayaran : ");
    while (scanf("%d", &tanggal)==0 || tanggal < 1 || tanggal > 31){
        printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan karakter yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tMasukkan tanggal pembayaran : ");
        while((getchar())!='\n');
	}
    printf("\n\tMasukkan pemakaian sebelumnya (m^3) : ");
    while (scanf("%f", &bulan_lalu)==0 || bulan_lalu<0){
        printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan karakter yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tMasukkan pemakaian sebelumnya (m^3) : ");
        while((getchar())!='\n');
    }
    printf("\n\tMasukkan pemakaian saat ini (m^3) : ");
    while (scanf("%f", &bulan_ini)==0 || bulan_ini<bulan_lalu){
        printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan karakter yang benar.\n");
        printf("\n\tPemakaian Bulan Ini > Pemakaian Bulan Lalu.\n");
        printf("\t----------------------------------------------");
        printf("\n\tMasukkan pemakaian saat ini (m^3) : ");
        while((getchar())!='\n');
    }
 
    pemakaian = bulan_ini - bulan_lalu;
 
    if(tanggal<=15){
        if(pemakaian>=0 && pemakaian<=10){
            output_denda=denda[0];
            biaya=pemakaian*tarif[index_tarif][0];
            total_bayar=Administrasi+BPM[index_bpm]+biaya+output_denda;
        }
        else if(pemakaian>10 && pemakaian<=20){
            output_denda=denda[0];
            biaya=((10*tarif[index_tarif][0])+((pemakaian-10)*tarif[index_tarif][1]));
            total_bayar=Administrasi+BPM[index_bpm]+biaya+output_denda;
        }
        else if(pemakaian>20){
            output_denda=denda[0];
            biaya=((10*tarif[index_tarif][0])+(10*tarif[index_tarif][1])+((pemakaian-20)*tarif[index_tarif][2]));
            total_bayar=Administrasi+BPM[index_bpm]+biaya+output_denda;
        }
    }else if(tanggal>15){
        //dengan denda
        if(pemakaian>=0 && pemakaian<=10){
            output_denda=denda[0];
            biaya=pemakaian*tarif[index_tarif][0];
            total_bayar=Administrasi+BPM[index_bpm]+biaya+output_denda;
        }
        else if(pemakaian>10 && pemakaian<=20){
            output_denda=denda[1]*pemakaian;
            biaya=((10*tarif[index_tarif][0])+((pemakaian-10)*tarif[index_tarif][1])+output_denda);
            total_bayar=Administrasi+BPM[index_bpm]+biaya+output_denda;
        }
        else if(pemakaian>20 && pemakaian<=100){
            output_denda = denda[1]*pemakaian;
            biaya=((10*tarif[index_tarif][0])+(10*tarif[index_tarif][1])+((pemakaian-20)*tarif[index_tarif][2])+output_denda);
            total_bayar=Administrasi+BPM[index_bpm]+biaya+output_denda;
        }
        else if(pemakaian>100){
            output_denda=denda[2]*pemakaian;
            biaya=((10*tarif[index_tarif][0])+(10*tarif[index_tarif][1])+((pemakaian-20)*tarif[index_tarif][2])+output_denda);
            total_bayar=Administrasi+BPM[index_bpm]+biaya+output_denda;
        }
    }
 
    printf("\n\t||===============================================||");
    printf("\n\t||               PDAM KOTA DENPASAR              ||");
    printf("\n\t||===============================================||");
    printf("\n\tNama Pelanggan           : %s", nama);
    printf("\n\tGolongan                 : %s", golongan[index_golongan]);
    printf("\n\tTanggal Pembayaran       : %d", tanggal);
    printf("\n\tPemakaian                : %.2f m^3", pemakaian);
    printf("\n\t---------------------------------------------------");
    printf("\n\tTarif yang Dikenakan (0-10)m^3   : %.2f/m^3", tarif[index_tarif][0]);
    printf("\n\tTarif yang Dikenakan (20-100)m^3 : %.2f/m^3", tarif[index_tarif][1]);
    printf("\n\tTarif yang Dikenakan (>100)m^3   : %.2f/m^3", tarif[index_tarif][2]);
    printf("\n\t---------------------------------------------------");
    printf("\n\tRincian Biaya: ");
    printf("\n\tBiaya Administrasi       : Rp. %d.00", Administrasi);
    printf("\n\tBiaya Pemeliharaan Meter : Rp. %.2f", BPM[index_bpm]);
    printf("\n\tBiaya Pemakaian          : Rp. %.2f", biaya);
    printf("\n\tDenda                    : Rp. %.2f", output_denda);
    printf("\n\t===================================================");
    printf("\n\tTotal Biaya yang Anda Keluarkan adalah Rp. %.2f", total_bayar);
    printf("\n\t===================================================");
 
    int cetak;
    printf("\n\t||===============================================||");
    printf("\n\t|| Apakah anda ingin mencetak bukti pembayaran ? ||");
    printf("\n\t||===============================================||");
    printf("\n\t|| 1. Ya                                         ||");
    printf("\n\t|| 2. Tidak                                      ||");
    printf("\n\t||===============================================||");
    printf("\n\tMasukkan pilihan anda : ");
    while (scanf  ("%d", &cetak)==0 || cetak<0 || cetak>2){
        printf ("\t---------------------------------------");
        printf ("\n\tKarakter yang anda inputkan salah");
        printf ("\n\tSilahkan inputkan ulang");
        printf ("\n\t---------------------------------------");
        printf("\n\tMasukkan pilihan anda : ");
        while (cetak=getchar() != '\n');
    }
    if(cetak==1){
        cetak_bukti_pembayaran(index_golongan, nama, pemakaian, tarif[index_tarif][0], tarif[index_tarif][1], tarif[index_tarif][2], Administrasi, BPM[index_bpm], biaya, output_denda, total_bayar);
    }else{
        ulang();
    }
}
 
int cetak_bukti_pembayaran(int index_golongan, char nama[100], float pemakaian, float tarif1, float tarif2, float tarif3, int Administrasi, float BPM, float biaya, float output_denda, float total_bayar){
    //menulis file ke txt
 
    //membuat pointer
    FILE *fptr;
 
    //membuka file
    fptr = fopen("Data Pelanggan.txt", "a"); //mode "a" untuk menambahkan file tanpa menghapus data yang sudah ada sebelumnya
 
    if (fptr==NULL){
        printf ("\n\tFile tidak ditemukan");
        exit(0);
    }else{
        fprintf(fptr, "\n\t||===============================================||");
        fprintf(fptr, "\n\t||               PDAM KOTA DENPASAR              ||");
        fprintf(fptr, "\n\t||===============================================||");
        fprintf(fptr, "\n\tNama Pelanggan           : %s", nama);
        fprintf(fptr, "\n\tGolongan                 : %s", golongan[index_golongan]);
        fprintf(fptr, "\n\tPemakaian                : %.2f m^3", pemakaian);
        fprintf(fptr, "\n\t---------------------------------------------------");
        fprintf(fptr, "\n\tTarif yang Dikenakan (0-10)m^3   : %.2f/m^3", tarif1);
        fprintf(fptr, "\n\tTarif yang Dikenakan (20-100)m^3 : %.2f/m^3", tarif2);
        fprintf(fptr, "\n\tTarif yang Dikenakan (>100)m^3   : %.2f/m^3", tarif3);
        fprintf(fptr, "\n\t---------------------------------------------------");
        fprintf(fptr, "\n\tRincian Biaya: ");
        fprintf(fptr, "\n\tBiaya Administrasi       : Rp. %d.00", Administrasi);
        fprintf(fptr, "\n\tBiaya Pemeliharaan Meter : Rp. %.2f", BPM);
        fprintf(fptr, "\n\tBiaya Pemakaian          : Rp. %.2f", biaya);
        fprintf(fptr, "\n\tDenda                    : Rp. %.2f", output_denda);
        fprintf(fptr, "\n\t===================================================");
        fprintf(fptr, "\n\tTotal Biaya yang Anda Keluarkan adalah Rp. %.2f", total_bayar);
        fprintf(fptr, "\n\t===================================================");
 
        fclose(fptr);//tutup file
 
        printf("\n\tPembayaran telah berhasil dicetak!!!\n");
    }
}
 
void close(){
    printf("\n\tSelanjutnya");
    getchar();
    printf("\n\tTekan enter untuk melanjutkan");
    getchar();
    system ("clear");
}
 
void ulang(){
    int ulang;
    close();
	printf("\n\t======================================================\n");
	printf("\t||          Apakah Anda ingin mengulang?            ||\n");
	printf("\t||                                                  ||\n");
	printf("\t|| 1. Ya, saya ingin menghitung kembali             ||\n");
	printf("\t|| 2. Tidak, sudah selesai                          ||\n");
  	printf("\t======================================================\n");
  	printf("\t Masukan angka untuk memilih:");
  	while (scanf("%d", &ulang)==0 || ulang < 1 || ulang > 2){
		printf("\t\t----------------------------------------------");
        printf("\n\t\tKarakter yang Anda inputkan salah!");
        printf("\n\t\tMohon inputkan angka yang benar.\n");
        printf("\t\t----------------------------------------------");
		printf("\n\t\tMasukkan pilihan anda     : ");
		while((getchar())!='\n');
	}
  	if(ulang==1){
		close();
		main();
	}else{
	    close();
		Exit();
	}
}
 
void Exit(){
	printf("\n\n");
	printf("\t====================================================\n");
	printf("\t||    TERIMAKASIH TELAH MENGGUNAKAN PROGRAM INI   ||\n");
	printf("\t||      ~~~~~~ S A M P A I  J U M P A ~~~~~~      ||\n");
  	printf("\t====================================================\n");
}
 