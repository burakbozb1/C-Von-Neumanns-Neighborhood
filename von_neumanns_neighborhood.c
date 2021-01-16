/*
07.11.2020
Burak Boz
Von Neumann's Neighborhood
*/

#include <stdio.h>

void main()
{
	printf("*** Von Neumann Neighborhood | Soru 2 - Burak Boz ***\n\n");
	int i=0;//Döngülerde kullanýlacak deðiþken
	int j=0;//Döngülerde kullanýlacak deðiþken
	int **matris;//Matrisin oluþturulmasý
	
	printf("Lutfen n sayisini girin:");
	int n=0;//Komþu sayýsýný belirlemek için kullanýlan ana deðiþken
	scanf("%d",&n);
	int matrisBoyut=((n+1)*2)+1;//Alýnan ana deðiþkene göre matris boyutunun hesaplanmasý
	
	int ortaNokta=(matrisBoyut/2);//Merkez nokta
	
	
	matris = (int **)calloc(matrisBoyut,sizeof(int*));
	for(i=0;i<matrisBoyut;i++)//Bu döngüde matris sýfýrlanýyor
	{
		matris[i] = (int*)calloc(matrisBoyut,sizeof(int));
	}
	
	int adet=1;//Her satýrda kaç adet 1 olacaðýný belirlemek için kullanýlan deðiþken
	int baslangicNoktasi=ortaNokta;//Her satýrda 1 lemeye baþlarken kullanýlacak baþlangýç noktasý
	int tmp=0;//Baþlangýç noktasýnýn deðerinin kaybolmamasý için tutulan geçici deðiþken
	for(i=1;i<matrisBoyut-1;i++)//Bu döngüde en üst ve en alt satýr hariç tüm satýrlar iþlenecek
	{
		if(i<=ortaNokta)//Matrisin üst bölgesini kontrol etmek için
		{//Bu döngüde üst bölgedeki satýrlara 1'ler yerleþtiriliyor
		
			printf("%d. satirda %d adet 1 bulunmaktadir\n",i+1,adet);
			tmp=baslangicNoktasi;
			for(j=0;j<adet;j++)
			{
				matris[i][baslangicNoktasi]=1;
				baslangicNoktasi++;
			}
			baslangicNoktasi=tmp;
			adet=adet+2;
			baslangicNoktasi--;
		}
		else//Matrisin alt bölgesini kontrol etmek için
		{//Bu döngüde alt bölgedeki satýrlara 1'ler yerleþtiriliyor
		
			if(i==ortaNokta+1)//Bölgeler arasýndaki geçiþ için gerekli kontrol
			{
				adet=adet-2;
				baslangicNoktasi++;
			}
			
			
			adet=adet-2;
			baslangicNoktasi++;
			tmp=baslangicNoktasi;
			for(j=0;j<adet;j++)
			{
				matris[i][baslangicNoktasi]=1;
				baslangicNoktasi++;
			}
			baslangicNoktasi=tmp;
			
			printf("%d. satirda %d adet 1 bulunmaktadir\n",i+1,adet);
		}
	}
	printf("\n\n");
	//Matrisin yazdýrýlmasý için gerekli kodlar
	for(i=0;i<matrisBoyut;i++)
	{
		for(j=0;j<matrisBoyut;j++)
		{
			printf("%d",matris[i][j]);
		}
		printf("\n");
	}
	
	int hucreSayisi=0;//Kullanýlan 1 sayýsýnýn hesaplanmasýnda kullanýlacak deðiþken
	hucreSayisi = 2*n*(n+1)+1;
	printf("\n\nKullanilan 1 sayisi:%d",hucreSayisi);
	
}
