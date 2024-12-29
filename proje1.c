#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>
int main(){
	setlocale(LC_ALL, "turkish");
	int fiyat=0,secim,saat,menu,ekstra,giris_hakki=3;	
	char  kullanici[10],sifre[10],username[]="admin",password[]="1234";
	

	printf("----------------------- ÝNTERNET KAFE YE HOÞGELDÝNÝZ -----------------------\n");
	printf("\n --------------------------------- MENÜ ---------------------------------\n");
	printf("\n ---------- 1 - Giriþ Yap | Herhangi bir tuþ - Sistemden çýkýþ ------------\n");
	scanf("%d",&menu);
	if(menu==1){
		while(giris_hakki>0){			
			printf("\n ------------------------- Yetkili Giriþi Yapýn -------------------------\n");
			printf("			     (%d Hakkýnýz Var)\n",giris_hakki);
			giris_hakki--;
			printf("\n Kullanýcý Adý :");
			scanf("%s",&kullanici);
			printf("\n Þifre :");
			scanf("%s",&sifre);
			if (strcmp(kullanici, username) ==0 && strcmp(sifre, password) ==0) {	
				printf("\n Kullanmak Ýstediðin Bilgisayarý Seç\n");
				printf("\n 1 - Yüksek Kalite Bilgisayar | 2 - Orta Kalite Bilgisayar | 3 - Düþük Kalite Bilgisayar\n");
				scanf("%d",&secim);
				switch(secim){
					case 1:			
						fiyat+=60;
						printf("Saat baþýna %d TL ödeyeceksin \n",fiyat);
						printf("Kaç saat kullanacaksýn (4 SAAT VE ÜZERÝ YÜZDE 10 ÝNDÝRÝM) :");
						scanf("%d",&saat);
						if(saat>=4){
							fiyat*=saat;
							fiyat=fiyat*9/10;
							fiyat+= ekstra_fonksiyon();	
				 			printf("Ýndirimli Fiyat : %d TL ",fiyat);				 			
						}
						else{
							fiyat*=saat;
							fiyat+= ekstra_fonksiyon();	
				 			printf("Fiyat : %d TL",fiyat);
						}
						break;	
						

					case 2: 
						fiyat+=50;
						printf("Saat baþýna %d TL ödeyeceksin \n",fiyat);
						printf("Kaç saat kullanacaksýn (4 SAAT VE ÜZERÝ YÜZDE 10 ÝNDÝRÝM) :");
						scanf("%d",&saat);
						if(saat>=4){
							fiyat*=saat;
							fiyat=fiyat*9/10;
							fiyat+= ekstra_fonksiyon();	
				 			printf("Ýndirimli Fiyat : %d TL",fiyat);
						}
						else{
							fiyat*=saat;
							fiyat+= ekstra_fonksiyon();	
				 			printf("Fiyat : %d TL",fiyat);
						}											
			 			break;
			 			
					case 3:			
						fiyat+=40;
						printf("Saat baþýna %d TL ödeyeceksin \n",fiyat);
						printf("Kaç saat kullanacaksýn (4 SAAT VE ÜZERÝ YÜZDE 10 ÝNDÝRÝM) :");
						scanf("%d",&saat);
						if(saat>=4){
							fiyat*=saat;
							fiyat=fiyat*9/10;
							fiyat+= ekstra_fonksiyon();	
				 			printf("Ýndirimli Fiyat : %d TL",fiyat);
						}
						else{
							fiyat*=saat;
							fiyat+= ekstra_fonksiyon();	
				 			printf("Fiyat : %d TL",fiyat);
						}					
			 			break;

					default:
						printf("Yanlýþ Deðer Girdiniz");
						break;
					
				}
			break;			
			}
			else
				printf("\n YANLIÞ K.ADI/ÞÝFRE \n");
				
		}
					
	}	
	else
		printf("Giriþ Yapmadýnýz.");
}
int ekstra_fonksiyon(){
	int ekstra,fiyat=0;
	char daha=' ';
	while(1){
		printf("\n------------------------------ EKSTRALAR ------------------------------\n");
		printf("\n 1 = TOST(50TL)  2 = SU(10TL)  3 = KOLA/FANTA(40TL)  Herhangi bir tuþ = ALMA :");
		scanf("%d",&ekstra);
		if(ekstra==1){
			fiyat+=50;	
		}
		else if(ekstra==2){
			fiyat+=10;
	
		}
		else if(ekstra==3){
			fiyat+=40;		
		}
		else{
			printf("Ekstra Almadýnýz ====> ");
			break;
		}
		printf("Daha fazla ister misin? (E/H):");
		scanf("%s",&daha);
		if(daha=='e' || daha=='E')
			continue;
		else
			break;
	}
	return fiyat;
}









