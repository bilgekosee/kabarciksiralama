#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
//prototipler
void bubble(int work[], size_t size, int (*compare)(int a,int b));
int ascending(int a,int b);
int descending(int a,int b);

int main(void)
{
	int order;//artan sýralama için 1 veya azalan sýralama için iki
	size_t counter;//sayaç
	
	//sýralanmýþ a dizinini yükle
	int a[SIZE]={2,6,4,8,10,12,89,68,45,37};
	printf("%s","enter 1 to sort in ascending order,\n"
	"enter 2 to sort in descending order:");
	scanf("%d",&order);
	puts("\nData items in original order");
	
	//orijinal diziyi göster
	for(counter=0;counter<SIZE;++counter)
	{
		printf("%5d",a[counter]);
		
	}
	//diziyi artan þekilde sýrala ;artan sýralama talebini belirtmek için 
	//argüman olarak ascending fonksiyonunu aktar
	
	if(order==1){
		bubble(a,SIZE,ascending);
		puts("\nData itemms in ascending order");
	}
	else//descending fonksiyonunu aktar
	{
		bubble(a,SIZE,descending);
		puts("\nData items in descending order");
	}
	
	
	//sýralý diziyi göster
	for(counter=0;counter<SIZE;++counter)
	{
		printf("%5d",a[counter]);
	}
	puts("\n");
	
}
//çok amaçlý kabarcýk sýralama; compare parametresi sýralama þeklini belirleyen karþýlaþtýrma
//fonksiyonuna iþaret eden bir iþaretçidir
void bubble(int work[],size_t size, int (*compare)(int a,int b))
{
	unsigned int pass;//pass sayacý
	size_t count;//karþýlaþtýrma sayacý
	void swap(int *elementPtr,int *element2Ptr);//prototip
	
	//pass geçiþleri kontrol eden döngü
	for(pass=1;pass<size;++pass){
		//her pas geçiþ için karþýlaþtýrma numarasýný kontrol eden döngü
		for(count=0;count<size;++count)
		{
			//bitiþik elemanlar sýralamaya uymuyor ise yerlerini deðiþtir
			if((*compare)( work[count],work[count+1])){
				swap( &work[count],&work[count+1]);
			}
		}
	}
}

//elementPtr ve element2Ptr nin iþaret ettikleri bellek bölgelerindeki deðerleri deðiþtir
void swap(int *elementPtr,int *element2Ptr)
{
	int hold;//geçici olarak saklama deðiþkeni 
	hold=*elementPtr;
	*elementPtr=*element2Ptr;
	*element2Ptr=hold;
	
}//swap yer deðiþtirme fonksiyon sonu
//elemanlarýn artan sýralama þekline göre 
//sýraya uygun olup olmadýklarýný belirle 

int ascending(int a,int b)
{
	return b<a;//b deðeri a dan daha düþük ise deðiþtirilmelidir
}
//elemanlarý azalan sýra þekline göre 
//sýrya uygun olup olmadýklarýný belirle 
int descending(int a,int b)
{
	return b>a;//b deðeri a dan büyük ise deðiþtirilmelidir 
}






































