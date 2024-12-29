#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int ekstra_fonksiyon(FILE *dosya);

int main() {
    setlocale(LC_ALL, "turkish");
    int fiyat = 0, secim, saat, menu, ekstra, giris_hakki = 3;
    char kullanici[10], sifre[10], username[] = "admin", password[] = "1234";
    FILE *dosya = fopen("kullanici_islemleri.txt", "a");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        return 1;
    }

    printf("----------------------- INTERNET KAFE YE HOSGELDINIZ -----------------------\n");
    printf("\n --------------------------------- MENÜ ---------------------------------\n");
    printf("\n ---------- 1 - Giris Yap | Herhangi bir tus - Sistemden cikis ------------\n");
    scanf("%d", &menu);
    if (menu == 1) {
        while (giris_hakki > 0) {
            printf("\n ------------------------- Yetkili Girisi Yapin -------------------------\n");
            printf("			     (%d Hakkiniz Var)\n",giris_hakki);
            giris_hakki--;
            printf("\n Kullanici Adi :");
            scanf("%s", &kullanici);
            printf("\n Sifre :");
            scanf("%s", &sifre);
            if (strcmp(kullanici, username) == 0 && strcmp(sifre, password) == 0) {
                printf("\n Kullanmak Istedigin Bilgisayari Seç\n");
                printf("\n 1 - Yüksek Kalite Bilgisayar | 2 - Orta Kalite Bilgisayar | 3 - Düsük Kalite Bilgisayar\n");
                scanf("%d", &secim);
                switch (secim) {
                    case 1:
                        fiyat += 60;
                        fprintf(dosya, "Yüksek Kalite Bilgisayar Seçildi.\n");
                        printf("Saat basina %d TL odeyeceksin \n", fiyat);
                        printf("Kaç saat kullanacaksin (4 SAAT VE ÜZERI YÜZDE 10 INDIRIM) :");
                        scanf("%d", &saat);
                        if (saat >= 4) {
                            fiyat *= saat;
                            fiyat = fiyat * 9 / 10;
                            fiyat += ekstra_fonksiyon(dosya);
                            fprintf(dosya, "Indirimli Fiyat : %d TL\n", fiyat);
                            printf("Indirimli Fiyat : %d TL ", fiyat);
                        } else {
                            fiyat *= saat;
                            fiyat += ekstra_fonksiyon(dosya);
                            fprintf(dosya, "Fiyat : %d TL\n", fiyat);
                            printf("Fiyat : %d TL", fiyat);
                        }
                        break;

                    case 2:
                        fiyat += 50;
                        fprintf(dosya, "Orta Kalite Bilgisayar Seçildi.\n");
                        printf("Saat basina %d TL ödeyeceksin \n", fiyat);
                        printf("Kaç saat kullanacaksýn (4 SAAT VE ÜZERI YÜZDE 10 INDIRIM) :");
                        scanf("%d", &saat);
                        if (saat >= 4) {
                            fiyat *= saat;
                            fiyat = fiyat * 9 / 10;
                            fiyat += ekstra_fonksiyon(dosya);
                            fprintf(dosya, "Indirimli Fiyat : %d TL\n", fiyat);
                            printf("Indirimli Fiyat : %d TL", fiyat);
                        } else {
                            fiyat *= saat;
                            fiyat += ekstra_fonksiyon(dosya);
                            fprintf(dosya, "Fiyat : %d TL\n", fiyat);
                            printf("Fiyat : %d TL", fiyat);
                        }
                        break;

                    case 3:
                        fiyat += 40;
                        fprintf(dosya, "Düsük Kalite Bilgisayar Seçildi.\n");
                        printf("Saat basina %d TL ödeyeceksin \n", fiyat);
                        printf("Kaç saat kullanacaksýn (4 SAAT VE ÜZERI YÜZDE 10 INDIRIM) :");
                        scanf("%d", &saat);
                        if (saat >= 4) {
                            fiyat *= saat;
                            fiyat = fiyat * 9 / 10;
                            fiyat += ekstra_fonksiyon(dosya);
                            fprintf(dosya, "Indirimli Fiyat : %d TL\n", fiyat);
                            printf("Indirimli Fiyat : %d TL", fiyat);
                        } else {
                            fiyat *= saat;
                            fiyat += ekstra_fonksiyon(dosya);
                            fprintf(dosya, "Fiyat : %d TL\n", fiyat);
                            printf("Fiyat : %d TL", fiyat);
                        }
                        break;

                    default:
                        printf("Yanlis Deger Girdiniz");
                        break;
                }
                break;
            } else
                printf("\n YANLIS K.ADI/SÝFRE \n");

        }

    } else
        printf("Giris Yapmadiniz.");

    fclose(dosya);
    return 0;
}

int ekstra_fonksiyon(FILE *dosya) {
    int ekstra, fiyat = 0;
    char daha = ' ';
    while (1) {
        printf("\n------------------------------ EKSTRALAR ------------------------------\n");
        printf("\n 1 = TOST(50TL)  2 = SU(10TL)  3 = KOLA/FANTA(40TL)  Herhangi bir tus = ALMA :");
        scanf("%d", &ekstra);
        if (ekstra == 1) {
            fiyat += 50;
            fprintf(dosya, "Ekstra: Tost (50 TL) eklendi.\n");
        } else if (ekstra == 2) {
            fiyat += 10;
            fprintf(dosya, "Ekstra: Su (10 TL) eklendi.\n");
        } else if (ekstra == 3) {
            fiyat += 40;
            fprintf(dosya, "Ekstra: Kola/Fanta (40 TL) eklendi.\n");
        } else {
            printf("Ekstra Almadiniz ====> ");
            break;
        }
        printf("Daha fazla ister misin? (E/H):");
        scanf("%s", &daha);
        if (daha == 'e' || daha == 'E')
            continue;
        else
            break;
    }
    return fiyat;
}










