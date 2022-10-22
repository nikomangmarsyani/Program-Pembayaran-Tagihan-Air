#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ADMINISTRASI 5000

void identitas();
int main();
int rumah_tangga();
int rumah_tangga_bersubsidi();
int rumah_tangga_non_subsidi();
int usaha();
int niaga_kecil();
int niaga_sedang();
void close();
int ulang();
int Exit();


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
}

int main(){
    int menu;
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
        getchar();
		ulang();
    }
    if(menu==2){
        usaha();
        getchar();
		ulang();
    }
    else{
        Exit();
    } 
    return 0;
}

int rumah_tangga(){
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
        getchar();
		ulang();
    }else{
        rumah_tangga_non_subsidi();
        getchar();
		ulang();
    }
    return 0;
}

int rumah_tangga_bersubsidi(){
    float bulan_ini, bulan_lalu, tanggal;
    char nama[100];
    printf("\n\t||===============================================||");
    printf("\n\t||            RUMAH TANGGA BERSUBSIDI            ||");
    printf("\n\t||===============================================||");
    printf("\n\tMasukkan nama Anda : ");
    scanf("%s[^\n]", nama);
    printf("\n\tMasukkan tanggal pembayaran : ");
    while (scanf("%f", &tanggal)==0 || tanggal < 1 || tanggal > 31){
        printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan karakter yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tMasukkan tanggal pembayaran : ");
        while((getchar())!='\n');
	}
    printf("\n\tMasukkan pemakaian sebelumnya (m^3) : ");
    while (scanf("%f", &bulan_lalu)==0){
        printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan karakter yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tMasukkan pemakaian sebelumnya (m^3) : ");
        while((getchar())!='\n');
    }
    printf("\n\tMasukkan pemakaian saat ini (m^3) : ");
    while (scanf("%f", &bulan_ini)==0 || bulan_ini < bulan_lalu){
        printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan karakter yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tMasukkan pemakaian saat ini (m^3) : ");
        while((getchar())!='\n');
    }
    float pemakaian = bulan_ini - bulan_lalu;
    close();

    float biaya_pemakaian;
    if (tanggal >= 1 && tanggal <= 15 && pemakaian >= 0 && pemakaian <= 10){
        biaya_pemakaian = ADMINISTRASI + 1000 + 5000;
        printf("\n\t||===============================================||");
        printf("\n\t||               PDAM KOTA DENPASAR              ||");
        printf("\n\t||===============================================||");
        printf("\n\tGolongan Rumah Tangga Bersubsidi");
        printf("\n\tNama : %s", nama);
        printf("\n\tTanggal Pembayaran : %.2f", tanggal);
        printf("\n\tPemakaian Bulan Ini         = %.2f (m^3)", pemakaian);
        printf("\n\tBiaya Administrasi          = Rp 5000");
        printf("\n\tBiaya BPM Rumah Tangga      = Rp 1000");
        printf("\n\tBiaya Denda                 = Rp 0");
        printf("\n\tBiaya Pemakaian Air (m^3)   = Rp 5000");
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah tagihan Anda : Rp %.2f", biaya_pemakaian);

    }else if (tanggal >= 1 && tanggal <= 15 && pemakaian > 10){
        biaya_pemakaian = ADMINISTRASI + 1000 + (5000 + (pemakaian - 10) * 1000);
        printf("\n\t||===============================================||");
        printf("\n\t||               PDAM KOTA DENPASAR              ||");
        printf("\n\t||===============================================||");
        printf("\n\tGolongan Rumah Tangga Bersubsidi");
        printf("\n\tNama : %s", nama);
        printf("\n\tTanggal Pembayaran : %.2f", tanggal);
        printf("\n\tPemakaian Bulan Ini         = %.2f (m^3)", pemakaian);
        printf("\n\tBiaya Administrasi          = Rp 5000");
        printf("\n\tBiaya BPM Rumah Tangga      = Rp 1000");
        printf("\n\tBiaya Denda                 = Rp 0");
        float biaya_pemakaian_air = (5000 + (pemakaian - 10) * 1000);
        printf("\n\tBiaya Pemakaian Air (m^3)   = Rp %.2f", biaya_pemakaian_air);
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah tagihan Anda : Rp %.2f", biaya_pemakaian);

    }else if (tanggal >= 16 && tanggal <= 31 && pemakaian >= 0 && pemakaian <= 10 && pemakaian <= 100){
        biaya_pemakaian = ADMINISTRASI + 1000 + 5000 + 1000;
        printf("\n\t||===============================================||");
        printf("\n\t||               PDAM KOTA DENPASAR              ||");
        printf("\n\t||===============================================||");
        printf("\n\tGolongan Rumah Tangga Bersubsidi");
        printf("\n\tNama : %s", nama);
        printf("\n\tTanggal Pembayaran : %.2f", tanggal);
        printf("\n\tPemakaian Bulan Ini         = %.2f (m^3)", pemakaian);
        printf("\n\tBiaya Administrasi          = Rp 5000");
        printf("\n\tBiaya BPM Rumah Tangga      = Rp 1000");
        printf("\n\tBiaya Denda                 = Rp 1000");
        printf("\n\tBiaya Pemakaian Air (m^3)   = Rp 5000");
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah tagihan Anda : Rp %.2f", biaya_pemakaian);
    
    }else if (tanggal >= 16 && tanggal <= 31 && pemakaian > 10 || pemakaian > 100){
        biaya_pemakaian = ADMINISTRASI + 1000 + (5000 + (pemakaian - 10) * 1000) + 2000;
        printf("\n\t||===============================================||");
        printf("\n\t||               PDAM KOTA DENPASAR              ||");
        printf("\n\t||===============================================||");
        printf("\n\tGolongan Rumah Tangga Bersubsidi");
        printf("\n\tNama : %s", nama);
        printf("\n\tTanggal Pembayaran : %.2f", tanggal);
        printf("\n\tPemakaian Bulan Ini         = %.2f (m^3)", pemakaian);
        printf("\n\tBiaya Administrasi          = Rp 5000");
        printf("\n\tBiaya BPM Rumah Tangga      = Rp 1000");
        printf("\n\tBiaya Denda                 = Rp 2000");
        float biaya_pemakaian_air = (5000 + (pemakaian - 10) + 1000);
        printf("\n\tBiaya Pemakaian Air (m^3)   = Rp %.2f", biaya_pemakaian_air);
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah tagihan Anda : Rp %.2f", biaya_pemakaian);    
    }
}

int rumah_tangga_non_subsidi(){
    float bulan_ini, bulan_lalu, tanggal;
    char nama[100];
    printf("\n\t||===============================================||");
    printf("\n\t||            RUMAH TANGGA NON SUBSIDI           ||");
    printf("\n\t||===============================================||");
    printf("\n\tMasukkan nama Anda : ");
    scanf("%s[^\n]", nama);
    printf("\n\tMasukkan tanggal pembayaran : ");
    while (scanf("%f", &tanggal)==0 || tanggal < 1 || tanggal > 31){
        printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan karakter yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tMasukkan tanggal pembayaran : ");
        while((getchar())!='\n');
	}
    printf("\n\tMasukkan pemakaian sebelumnya (m^3) : ");
    while (scanf("%f", &bulan_lalu)==0){
        printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan karakter yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tMasukkan pemakaian sebelumnya (m^3) : ");
        while((getchar())!='\n');
    }
    printf("\n\tMasukkan pemakaian saat ini (m^3) : ");
    while (scanf("%f", &bulan_ini)==0 || bulan_ini < bulan_lalu){
        printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan karakter yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tMasukkan pemakaian saat ini (m^3) : ");
        while((getchar())!='\n');
    }
    float pemakaian = bulan_ini - bulan_lalu;
    close();

    float biaya_pemakaian;
    if (tanggal >= 1 && tanggal <= 15 && pemakaian >= 0 && pemakaian <= 10){
        biaya_pemakaian = ADMINISTRASI + 1000 + 5000;
        printf("\n\t||===============================================||");
        printf("\n\t||               PDAM KOTA DENPASAR              ||");
        printf("\n\t||===============================================||");
        printf("\n\tGolongan Rumah Tangga Non Subsidi");
        printf("\n\tNama : %s", nama);
        printf("\n\tTanggal Pembayaran : %.2f", tanggal);
        printf("\n\tPemakaian Bulan Ini         = %.2f (m^3)", pemakaian);
        printf("\n\tBiaya Administrasi          = Rp 5000");
        printf("\n\tBiaya BPM Rumah Tangga      = Rp 1000");
        printf("\n\tBiaya Denda                 = Rp 0");
        printf("\n\tBiaya Pemakaian Air (m^3)   = Rp 5000");
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah tagihan Anda : Rp %.2f", biaya_pemakaian);

    }else if (tanggal >= 1 && tanggal <= 15 && pemakaian > 10){
        biaya_pemakaian = ADMINISTRASI + 1000 + (5000 + (pemakaian - 10) * 1000);
        printf("\n\t||===============================================||");
        printf("\n\t||               PDAM KOTA DENPASAR              ||");
        printf("\n\t||===============================================||");
        printf("\n\tGolongan Rumah Tangga Non Subsidi");
        printf("\n\tNama : %s", nama);
        printf("\n\tTanggal Pembayaran : %.2f", tanggal);
        printf("\n\tPemakaian Bulan Ini         = %.2f (m^3)", pemakaian);
        printf("\n\tBiaya Administrasi          = Rp 5000");
        printf("\n\tBiaya BPM Rumah Tangga      = Rp 1000");
        printf("\n\tBiaya Denda                 = Rp 0");
        float biaya_pemakaian_air = (5000 + (pemakaian - 10) * 1000);
        printf("\n\tBiaya Pemakaian Air (m^3)   = Rp %.2f", biaya_pemakaian_air);
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah tagihan Anda : Rp %.2f", biaya_pemakaian);

    }else if (tanggal >= 16 && tanggal <= 31 && pemakaian >= 0 && pemakaian <= 10 && pemakaian <= 100){
        biaya_pemakaian = ADMINISTRASI + 1000 + 5000 + 1000;
        printf("\n\t||===============================================||");
        printf("\n\t||               PDAM KOTA DENPASAR              ||");
        printf("\n\t||===============================================||");
        printf("\n\tGolongan Rumah Tangga Non Subsidi");
        printf("\n\tNama : %s", nama);
        printf("\n\tTanggal Pembayaran : %.2f", tanggal);
        printf("\n\tPemakaian Bulan Ini         = %.2f (m^3)", pemakaian);
        printf("\n\tBiaya Administrasi          = Rp 5000");
        printf("\n\tBiaya BPM Rumah Tangga      = Rp 1000");
        printf("\n\tBiaya Denda                 = Rp 1000");
        printf("\n\tBiaya Pemakaian Air (m^3)   = Rp 5000");
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah tagihan Anda : Rp %.2f", biaya_pemakaian);
    
    }else if (tanggal >= 16 && tanggal <= 31 && pemakaian > 10 || pemakaian > 100){
        biaya_pemakaian = ADMINISTRASI + 1000 + (5000 + (pemakaian - 10) * 1000) + 2000;
        printf("\n\t||===============================================||");
        printf("\n\t||               PDAM KOTA DENPASAR              ||");
        printf("\n\t||===============================================||");
        printf("\n\tGolongan Rumah Tangga Non Subsidi");
        printf("\n\tNama : %s", nama);
        printf("\n\tTanggal Pembayaran : %.2f", tanggal);
        printf("\n\tPemakaian Bulan Ini         = %.2f (m^3)", pemakaian);
        printf("\n\tBiaya Administrasi          = Rp 5000");
        printf("\n\tBiaya BPM Rumah Tangga      = Rp 1000");
        printf("\n\tBiaya Denda                 = Rp 2000");
        float biaya_pemakaian_air = (5000 + (pemakaian - 10) + 1000);
        printf("\n\tBiaya Pemakaian Air (m^3)   = Rp %.2f", biaya_pemakaian_air);
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah tagihan Anda : Rp %.2f", biaya_pemakaian);    
    }
}

int usaha(){
    int menu3;
    printf("\n\t||===============================================||");
    printf("\n\t||                  GOLONGAN USAHA               ||");
    printf("\n\t||===============================================||");
    printf("\n\t|| 1.  | Niaga kecil                             ||");
    printf("\n\t|| 2.  | Niaga sedang                            ||");
    printf("\n\t||===============================================||");
    printf("\n\tInputkan pilihan :");
    while (scanf("%d", &menu3)==0 || menu3 < 1 || menu3 > 2){
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
        getchar();
		ulang();
    }else{
        niaga_sedang();
        getchar();
		ulang();
    }
    return 0;
}

int niaga_kecil(){
    float bulan_ini, bulan_lalu, tanggal;
    char nama[100];
    printf("\n\t||===============================================||");
    printf("\n\t||                    NIAGA KECIL                ||");
    printf("\n\t||===============================================||");
    printf("\n\tMasukkan nama Anda : ");
    scanf("%s[^\n]", nama);
    printf("\n\tMasukkan tanggal pembayaran : ");
    while (scanf("%f", &tanggal)==0 || tanggal < 1 || tanggal > 31){
        printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan karakter yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tMasukkan tanggal pembayaran : ");
        while((getchar())!='\n');
	}
    printf("\n\tMasukkan pemakaian sebelumnya (m^3) : ");
    while (scanf("%f", &bulan_lalu)==0){
        printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan karakter yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tMasukkan pemakaian sebelumnya (m^3) : ");
        while((getchar())!='\n');
    }
    printf("\n\tMasukkan pemakaian saat ini (m^3) : ");
    while (scanf("%f", &bulan_ini)==0 || bulan_ini < bulan_lalu){
        printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan karakter yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tMasukkan pemakaian saat ini (m^3) : ");
        while((getchar())!='\n');
    }
    float pemakaian = bulan_ini - bulan_lalu;
    close();

    float biaya_pemakaian;
    if (tanggal >= 1 && tanggal <= 15 && pemakaian >= 0 && pemakaian <= 10){
        biaya_pemakaian = ADMINISTRASI + 2000 + 5000;
        printf("\n\t||===============================================||");
        printf("\n\t||               PDAM KOTA DENPASAR              ||");
        printf("\n\t||===============================================||");
        printf("\n\tGolongan Niaga Kecil");
        printf("\n\tNama : %s", nama);
        printf("\n\tTanggal Pembayaran : %.2f", tanggal);
        printf("\n\tPemakaian Bulan Ini         = %.2f (m^3)", pemakaian);
        printf("\n\tBiaya Administrasi          = Rp 5000");
        printf("\n\tBiaya BPM Usaha             = Rp 2000");
        printf("\n\tBiaya Denda                 = Rp 0");
        printf("\n\tBiaya Pemakaian Air (m^3)   = Rp 5000");
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah tagihan Anda : Rp %.2f", biaya_pemakaian);

    }else if (tanggal >= 1 && tanggal <= 15 && pemakaian > 10){
        biaya_pemakaian = ADMINISTRASI + 2000 + (5000 + (pemakaian - 10) * 1000);
        printf("\n\t||===============================================||");
        printf("\n\t||               PDAM KOTA DENPASAR              ||");
        printf("\n\t||===============================================||");
        printf("\n\tGolongan Niaga Kecil");
        printf("\n\tNama : %s", nama);
        printf("\n\tTanggal Pembayaran : %.2f", tanggal);
        printf("\n\tPemakaian Bulan Ini         = %.2f (m^3)", pemakaian);
        printf("\n\tBiaya Administrasi          = Rp 5000");
        printf("\n\tBiaya BPM Usaha             = Rp 2000");
        printf("\n\tBiaya Denda                 = Rp 0");
        float biaya_pemakaian_air = (5000 + (pemakaian - 10) * 1000);
        printf("\n\tBiaya Pemakaian Air (m^3)   = Rp %.2f", biaya_pemakaian_air);
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah tagihan Anda : Rp %.2f", biaya_pemakaian);

    }else if (tanggal >= 16 && tanggal <= 31 && pemakaian >= 0 && pemakaian <= 10 && pemakaian <= 100){
        biaya_pemakaian = ADMINISTRASI + 2000 + 5000 + 1000;
        printf("\n\t||===============================================||");
        printf("\n\t||               PDAM KOTA DENPASAR              ||");
        printf("\n\t||===============================================||");
        printf("\n\tGolongan Niaga Kecil");
        printf("\n\tNama : %s", nama);
        printf("\n\tTanggal Pembayaran : %.2f", tanggal);
        printf("\n\tPemakaian Bulan Ini         = %.2f (m^3)", pemakaian);
        printf("\n\tBiaya Administrasi          = Rp 5000");
        printf("\n\tBiaya BPM Usaha             = Rp 2000");
        printf("\n\tBiaya Denda                 = Rp 1000");
        printf("\n\tBiaya Pemakaian Air (m^3)   = Rp 5000");
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah tagihan Anda : Rp %.2f", biaya_pemakaian);
    
    }else if (tanggal >= 16 && tanggal <= 31 && pemakaian > 10 || pemakaian > 100){
        biaya_pemakaian = ADMINISTRASI + 2000 + (5000 + (pemakaian - 10) * 1000) + 2000;
        printf("\n\t||===============================================||");
        printf("\n\t||               PDAM KOTA DENPASAR              ||");
        printf("\n\t||===============================================||");
        printf("\n\tGolongan Niaga Kecil");
        printf("\n\tNama : %s", nama);
        printf("\n\tTanggal Pembayaran : %.2f", tanggal);
        printf("\n\tPemakaian Bulan Ini         = %.2f (m^3)", pemakaian);
        printf("\n\tBiaya Administrasi          = Rp 5000");
        printf("\n\tBiaya BPM Usaha             = Rp 2000");
        printf("\n\tBiaya Denda                 = Rp 2000");
        float biaya_pemakaian_air = (5000 + (pemakaian - 10) + 1000);
        printf("\n\tBiaya Pemakaian Air (m^3)   = Rp %.2f", biaya_pemakaian_air);
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah tagihan Anda : Rp %.2f", biaya_pemakaian);    
    }
}

int niaga_sedang(){
    float bulan_ini, bulan_lalu, tanggal;
    char nama[100];
    printf("\n\t||===============================================||");
    printf("\n\t||                    NIAGA SEDANG               ||");
    printf("\n\t||===============================================||");
    printf("\n\tMasukkan nama Anda : ");
    scanf("%s[^\n]", nama);
    printf("\n\tMasukkan tanggal pembayaran : ");
    while (scanf("%f", &tanggal)==0 || tanggal < 1 || tanggal > 31){
        printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan karakter yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tMasukkan tanggal pembayaran : ");
        while((getchar())!='\n');
	}
    printf("\n\tMasukkan pemakaian sebelumnya (m^3) : ");
    while (scanf("%f", &bulan_lalu)==0){
        printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan karakter yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tMasukkan pemakaian sebelumnya (m^3) : ");
        while((getchar())!='\n');
    }
    printf("\n\tMasukkan pemakaian saat ini (m^3) : ");
    while (scanf("%f", &bulan_ini)==0 || bulan_ini < bulan_lalu){
        printf("\t----------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan karakter yang benar.\n");
        printf("\t----------------------------------------------");
        printf("\n\tMasukkan pemakaian saat ini (m^3) : ");
        while((getchar())!='\n');
    }
    float pemakaian = bulan_ini - bulan_lalu;
    close();

    float biaya_pemakaian;
    if (tanggal >= 1 && tanggal <= 15 && pemakaian >= 0 && pemakaian <= 10){
        biaya_pemakaian = ADMINISTRASI + 2000 + 5000;
        printf("\n\t||===============================================||");
        printf("\n\t||               PDAM KOTA DENPASAR              ||");
        printf("\n\t||===============================================||");
        printf("\n\tGolongan Niaga Sedang");
        printf("\n\tNama : %s", nama);
        printf("\n\tTanggal Pembayaran : %.2f", tanggal);
        printf("\n\tPemakaian Bulan Ini         = %f (m^3)", pemakaian);
        printf("\n\tBiaya Administrasi          = Rp 5000");
        printf("\n\tBiaya BPM Usaha             = Rp 2000");
        printf("\n\tBiaya Denda                 = Rp 0");
        printf("\n\tBiaya Pemakaian Air (m^3)   = Rp 5000");
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah tagihan Anda : Rp %.2f", biaya_pemakaian);

    }else if (tanggal >= 1 && tanggal <= 15 && pemakaian > 10){
        biaya_pemakaian = ADMINISTRASI + 2000 + (5000 + (pemakaian - 10) * 1000);
        printf("\n\t||===============================================||");
        printf("\n\t||               PDAM KOTA DENPASAR              ||");
        printf("\n\t||===============================================||");
        printf("\n\tGolongan Niaga Sedang");
        printf("\n\tNama : %s", nama);
        printf("\n\tTanggal Pembayaran : %.2f", tanggal);
        printf("\n\tPemakaian Bulan Ini         = %.2f (m^3)", pemakaian);
        printf("\n\tBiaya Administrasi          = Rp 5000");
        printf("\n\tBiaya BPM Usaha             = Rp 2000");
        printf("\n\tBiaya Denda                 = Rp 0");
        float biaya_pemakaian_air = (5000 + (pemakaian - 10) * 1000);
        printf("\n\tBiaya Pemakaian Air (m^3)   = Rp %.2f", biaya_pemakaian_air);
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah tagihan Anda : Rp %.2f", biaya_pemakaian);

    }else if (tanggal >= 16 && tanggal <= 31 && pemakaian >= 0 && pemakaian <= 10 && pemakaian <= 100){
        biaya_pemakaian = ADMINISTRASI + 2000 + 5000 + 1000;
        printf("\n\t||===============================================||");
        printf("\n\t||               PDAM KOTA DENPASAR              ||");
        printf("\n\t||===============================================||");
        printf("\n\tGolongan Niaga Sedang");
        printf("\n\tNama : %s", nama);
        printf("\n\tTanggal Pembayaran : %.2f", tanggal);
        printf("\n\tPemakaian Bulan Ini         = %.2f (m^3)", pemakaian);
        printf("\n\tBiaya Administrasi          = Rp 5000");
        printf("\n\tBiaya BPM Usaha             = Rp 2000");
        printf("\n\tBiaya Denda                 = Rp 1000");
        printf("\n\tBiaya Pemakaian Air (m^3)   = Rp 5000");
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah tagihan Anda : Rp %.2f", biaya_pemakaian);
    
    }else if (tanggal >= 16 && tanggal <= 31 && pemakaian > 10 || pemakaian > 100){
        biaya_pemakaian = ADMINISTRASI + 2000 + (5000 + (pemakaian - 10) * 1000) + 2000;
        printf("\n\t||===============================================||");
        printf("\n\t||               PDAM KOTA DENPASAR              ||");
        printf("\n\t||===============================================||");
        printf("\n\tGolongan Niaga Sedang");
        printf("\n\tNama : %s", nama);
        printf("\n\tTanggal Pembayaran : %.2f", tanggal);
        printf("\n\tPemakaian Bulan Ini         = %.2f (m^3)", pemakaian);
        printf("\n\tBiaya Administrasi          = Rp 5000");
        printf("\n\tBiaya BPM Usaha             = Rp 2000");
        printf("\n\tBiaya Denda                 = Rp 2000");
        float biaya_pemakaian_air = (5000 + (pemakaian - 10) + 1000);
        printf("\n\tBiaya Pemakaian Air (m^3)   = Rp %.2f", biaya_pemakaian_air);
        printf("\n\t----------------------------------------------");
        printf("\n\tJumlah tagihan Anda : Rp %.2f", biaya_pemakaian);    
    }
}

void close(){
    printf("\n\tSelanjutnya");
    getchar();
    printf("\n\tTekan enter untuk melanjutkan");
    getchar();
    system ("clear");
}

int ulang(){
	getchar();
	system ("clear");
    int ulang;
	printf("\n\t\t======================================================\n");
	printf("\t\t||          Apakah Anda ingin mengulang?            ||\n");
	printf("\t\t||                                                  ||\n");
	printf("\t\t|| 1. Ya, saya ingin menghitung kembali             ||\n");
	printf("\t\t|| 2. Tidak, sudah selesai                          ||\n");
  	printf("\t\t======================================================\n");
  	printf("\t\t Masukan angka untuk memilih:");
  	while (scanf("%d", &ulang)==0 || ulang < 1 || ulang > 2){
		printf("\t\t----------------------------------------------");
        printf("\n\t\tKarakter yang Anda inputkan salah!");
        printf("\n\t\tMohon inputkan angka yang benar.\n");
        printf("\t\t----------------------------------------------");
		printf("\n\t\tMasukkan pilihan anda     : ");
		while((getchar())!='\n');
	}
  	if(ulang==1){
		system ("clear");
		main();
	}else{
		Exit();
	}
}

int Exit(){
	system ("clear");
	printf("\n\n");
	printf("\t\t====================================================\n");
	printf("\t\t||    TERIMAKASIH TELAH MENGGUNAKAN PROGRAM INI   ||\n");
	printf("\t\t||      ~~~~~~ S A M P A I  J U M P A ~~~~~~      ||\n");
  	printf("\t\t====================================================\n");
  	return 0;
}