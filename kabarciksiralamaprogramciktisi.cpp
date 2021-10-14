#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
//prototipler
void bubble(int work[], size_t size, int (*compare)(int a,int b));
int ascending(int a,int b);
int descending(int a,int b);

int main(void)
{
	int order;//artan s�ralama i�in 1 veya azalan s�ralama i�in iki
	size_t counter;//saya�
	
	//s�ralanm�� a dizinini y�kle
	int a[SIZE]={2,6,4,8,10,12,89,68,45,37};
	printf("%s","enter 1 to sort in ascending order,\n"
	"enter 2 to sort in descending order:");
	scanf("%d",&order);
	puts("\nData items in original order");
	
	//orijinal diziyi g�ster
	for(counter=0;counter<SIZE;++counter)
	{
		printf("%5d",a[counter]);
		
	}
	//diziyi artan �ekilde s�rala ;artan s�ralama talebini belirtmek i�in 
	//arg�man olarak ascending fonksiyonunu aktar
	
	if(order==1){
		bubble(a,SIZE,ascending);
		puts("\nData itemms in ascending order");
	}
	else//descending fonksiyonunu aktar
	{
		bubble(a,SIZE,descending);
		puts("\nData items in descending order");
	}
	
	
	//s�ral� diziyi g�ster
	for(counter=0;counter<SIZE;++counter)
	{
		printf("%5d",a[counter]);
	}
	puts("\n");
	
}
//�ok ama�l� kabarc�k s�ralama; compare parametresi s�ralama �eklini belirleyen kar��la�t�rma
//fonksiyonuna i�aret eden bir i�aret�idir
void bubble(int work[],size_t size, int (*compare)(int a,int b))
{
	unsigned int pass;//pass sayac�
	size_t count;//kar��la�t�rma sayac�
	void swap(int *elementPtr,int *element2Ptr);//prototip
	
	//pass ge�i�leri kontrol eden d�ng�
	for(pass=1;pass<size;++pass){
		//her pas ge�i� i�in kar��la�t�rma numaras�n� kontrol eden d�ng�
		for(count=0;count<size;++count)
		{
			//biti�ik elemanlar s�ralamaya uymuyor ise yerlerini de�i�tir
			if((*compare)( work[count],work[count+1])){
				swap( &work[count],&work[count+1]);
			}
		}
	}
}

//elementPtr ve element2Ptr nin i�aret ettikleri bellek b�lgelerindeki de�erleri de�i�tir
void swap(int *elementPtr,int *element2Ptr)
{
	int hold;//ge�ici olarak saklama de�i�keni 
	hold=*elementPtr;
	*elementPtr=*element2Ptr;
	*element2Ptr=hold;
	
}//swap yer de�i�tirme fonksiyon sonu
//elemanlar�n artan s�ralama �ekline g�re 
//s�raya uygun olup olmad�klar�n� belirle 

int ascending(int a,int b)
{
	return b<a;//b de�eri a dan daha d���k ise de�i�tirilmelidir
}
//elemanlar� azalan s�ra �ekline g�re 
//s�rya uygun olup olmad�klar�n� belirle 
int descending(int a,int b)
{
	return b>a;//b de�eri a dan b�y�k ise de�i�tirilmelidir 
}






































