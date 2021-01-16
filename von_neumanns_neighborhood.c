/*
07.11.2020
Burak Boz
Von Neumann's Neighborhood
*/

#include <stdio.h>

void main()
{
	printf("*** Von Neumann Neighborhood | Soru 2 - Burak Boz ***\n\n");
	int i=0;//D�ng�lerde kullan�lacak de�i�ken
	int j=0;//D�ng�lerde kullan�lacak de�i�ken
	int **matris;//Matrisin olu�turulmas�
	
	printf("Lutfen n sayisini girin:");
	int n=0;//Kom�u say�s�n� belirlemek i�in kullan�lan ana de�i�ken
	scanf("%d",&n);
	int matrisBoyut=((n+1)*2)+1;//Al�nan ana de�i�kene g�re matris boyutunun hesaplanmas�
	
	int ortaNokta=(matrisBoyut/2);//Merkez nokta
	
	
	matris = (int **)calloc(matrisBoyut,sizeof(int*));
	for(i=0;i<matrisBoyut;i++)//Bu d�ng�de matris s�f�rlan�yor
	{
		matris[i] = (int*)calloc(matrisBoyut,sizeof(int));
	}
	
	int adet=1;//Her sat�rda ka� adet 1 olaca��n� belirlemek i�in kullan�lan de�i�ken
	int baslangicNoktasi=ortaNokta;//Her sat�rda 1 lemeye ba�larken kullan�lacak ba�lang�� noktas�
	int tmp=0;//Ba�lang�� noktas�n�n de�erinin kaybolmamas� i�in tutulan ge�ici de�i�ken
	for(i=1;i<matrisBoyut-1;i++)//Bu d�ng�de en �st ve en alt sat�r hari� t�m sat�rlar i�lenecek
	{
		if(i<=ortaNokta)//Matrisin �st b�lgesini kontrol etmek i�in
		{//Bu d�ng�de �st b�lgedeki sat�rlara 1'ler yerle�tiriliyor
		
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
		else//Matrisin alt b�lgesini kontrol etmek i�in
		{//Bu d�ng�de alt b�lgedeki sat�rlara 1'ler yerle�tiriliyor
		
			if(i==ortaNokta+1)//B�lgeler aras�ndaki ge�i� i�in gerekli kontrol
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
	//Matrisin yazd�r�lmas� i�in gerekli kodlar
	for(i=0;i<matrisBoyut;i++)
	{
		for(j=0;j<matrisBoyut;j++)
		{
			printf("%d",matris[i][j]);
		}
		printf("\n");
	}
	
	int hucreSayisi=0;//Kullan�lan 1 say�s�n�n hesaplanmas�nda kullan�lacak de�i�ken
	hucreSayisi = 2*n*(n+1)+1;
	printf("\n\nKullanilan 1 sayisi:%d",hucreSayisi);
	
}
