#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#pragma pack(1)

	struct dogum_tarihi{
		int gun;
		int ay;
		int yil;
	};
	
	struct Person{
		int numara;
		char isim[25];
		char soyisim[25];
		struct dogum_tarihi dogum;
		float mat_not;
		float tr_not;
		float fen_not;
	};
	
	void menu(int *x){
		printf("\n\t---------- MENU ----------\n");
		printf("\t1-Ogrenci Kaydi Eklemek\n");
		printf("\t2-Ogrenci Kaydi Silmek\n");
		printf("\t3-Ogrenci Kaydini Guncellemek\n");
		printf("\t4-Tum Ogrencileri Ekranda Listelemek\n");
		printf("\t5-Ogrenci Numarasina Gore Kayitlari Siralamak\n");
		printf("\t6-Ogrenci Ismine Gore Kayitlari Siralamak\n");
		printf("\t7-Matematik Notuna Gore Siralamak\n");
		printf("\t8-Fen Notuna Gore Siralamak\n");
		printf("\t9-Turkce Notuna Gore Siralamak\n");
		printf("\t10-Cikis\n");
	}

void KayitSil(){

     struct Person *eg;
     char NoTemp[30];
       
     FILE *prj;
     FILE *tempprj;
     
     printf("Silmek istediginiz kisinin numarasini giriniz : \n");
     scanf("%s", &NoTemp);
     
     prj = fopen("student.bin","r");
     tempprj = fopen("gecicistudent.bin","a");
     
     while(!feof(prj))
     {
            eg = (struct Person*) malloc(sizeof(struct Person));
            fread(eg, sizeof(struct Person) - 2*sizeof(eg), 1, prj);
            if(eg != NULL)
            {
                if(strcmp(eg->numara, NoTemp))
                {
                    fwrite(eg, sizeof(struct Person) - 2*sizeof(eg), 1, tempprj);    
                }
                else if(strcmp(eg->numara, NoTemp))
                {
                    printf("Kayit silindi!\n");
                }
            }
     }
     
     fclose(prj);
     fclose(tempprj);
     remove("student.bin");
     rename("gecicistudent.bin","student.bin");
}


int main(){
	FILE *prj;
	FILE *tempprj;
	int y,oku;
	struct Person eg;

		
	while(1){
	menu(&y);
	scanf("%d",&y);
	
		if(y==1){	//KAYIT EKLEME
		printf("Ogrencinin Ismini Giriniz :");
		scanf("%s",&eg.isim);
		printf("Ogrencinin Soyismini Giriniz:");
		scanf("%s",&eg.soyisim);
		printf("Ogrencinin Dogum Tarihini Gun-Ay-Yil Olarak Giriniz :");
		scanf("%d",&eg.dogum.gun);
		scanf("%d",&eg.dogum.ay);
		scanf("%d",&eg.dogum.yil);
		printf("Ogrencinin Numarasini Giriniz:");
		scanf("%d",&eg.numara);
		printf("Ogrencinin Matematik Notunu Giriniz :");
		scanf("%f",&eg.mat_not);
		printf("Ogrencinin Fen Notunu Giriniz :");
		scanf("%f",&eg.fen_not);
		printf("Ogrencinin Turkce Notunu Giriniz :");
		scanf("%f",&eg.tr_not);

	prj=fopen("student.bin","r+");		
	if(prj==NULL){
	prj=fopen("student.bin","w+");	
	}
	
	fprintf(prj,"Ad\tSoyad\tDTarihi\t\tNumara\t\tMnot\tFnot\tTnot\n");
		fseek(prj,sizeof(prj),SEEK_END);	
    
	fprintf(prj,"\n%s\t%s\t%d/%d/%d\t%d\t\t%.1f\t%.1f\t%.1f\n",eg.isim,eg.soyisim,eg.dogum.gun,eg.dogum.ay,eg.dogum.yil,eg.numara,eg.mat_not,eg.fen_not,eg.tr_not);
	
	fclose(prj);

		}
		
		
		if(y==2){	//KAYIT SÝLME
		//KayitSil();
    
		}
		if(y==3){	//KAYDI GÜNCELLEME
			


		}
		
		
		
		
		if(y==4){	//TÜM ÖÐRENCÝLERÝ EKRANDA LÝSTELEMEK
		
			FILE* prj= fopen("student.bin","r"); 
			if(!prj){
				printf("Dosya Bulunamadi.");
				exit(-1);
			}
			else{
				do{
					oku=fgetc(prj);
					printf("%c",oku);
				}while(oku!=EOF);
				fclose(prj);
			}
		}
		
		if(y==5){	//ÖÐRENCÝ NUMARASINA GÖRE KAYITLARI SIRALAMAK
		prj= fopen("sorted.bin","r");
		
		int a;
		a= ftell(prj);
		struct Person *arr;
		struct Person temparr;

		arr= (struct Person*)malloc(sizeof(struct Person)*a);
		int i,j;
					 
			for(i=0;i<a;i++){
				fread(&eg,sizeof(struct Person),1,prj);
				arr[i]=eg;
			}
			
			for(i=0;i<a;i++){
				for(j=0;j<a-i-1;j++){
					if(arr[j].numara<arr[j+1].numara){
						temparr = arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temparr;
					}
				}
			}
			fwrite("Ad\tSoyad\tDTarihi\t\tNumara\t\tMnot\tFnot\tTnot\n");
				
			for(i=0;i<a;i++){
    		fprintf("\n%s\t%s\t%d/%d/%d\t%d\t\t%.1f\t%.1f\t%.1f\n",arr[i].isim,arr[i].soyisim,arr[i].dogum.gun,arr[i].dogum.ay,arr[i].dogum.yil,arr[i].numara,arr[i].mat_not,arr[i].fen_not,arr[i].tr_not);
			
				}
				
			fclose(prj);
			
			
		}
		if(y==6){	//ALFABETÝK SIRAYA GÖRE KAYITLARI SIRALAMAK
	/*	prj= fopen("sorted.bin","r");

		int k;
		k= ftell(prj);
		struct Person *arr;
		struct Person temparr;

		arr= (struct Person*)malloc(sizeof(struct Person)*k);
		int i,j;
					 
			for(i=0;i<k;i++){
				fread(&eg,sizeof(struct Person),1,prj);
				arr[i]=eg;
			}
			
			for(i=0;i<k;i++){
				for(j=0;j<k-i-1;j++){
					if(strcmp(arr[j].isim,arr[j+1].isim)>0){
						strcpy(temparr,arr[j]);
						strcpy(arr[j],arr[j+1]);
						strcpy(arr[j+1],temparr);
					}
				}
			}
			printf("\tAd\tSoyad\tDTarihi\t\tNumara\t\tMnot\tFnot\tTnot\n");
				
			for(i=0;i<k;i++){
    		printf("\n%s\t%s\t%d/%d/%d\t%d\t\t%.1f\t%.1f\t%.1f\n",arr[i].isim,arr[i].soyisim,arr[i].dogum.gun,arr[i].dogum.ay,arr[i].dogum.yil,arr[i].numara,arr[i].mat_not,arr[i].fen_not,arr[i].tr_not);
				}
			fclose(prj);
			*/
			
		}
		if(y==7){	//MAT NOTUNA GÖRE KAYITLARI SIRALAMAK
		prj= fopen("sorted.bin","r");
		
		int k;
		k= ftell(prj);
		int *x= (int*)malloc(sizeof(int)*k);
		struct Person arr[k];
		struct Person temparr;
		int i,j;
					 
			for(i=0;i<k;i++){
				fread(&eg,sizeof(struct Person),1,prj);
				arr[i]=eg;
			}
			
			for(i=0;i<k;i++){
				for(j=0;j<k-i-1;j++){
					if(arr[j].mat_not<arr[j+1].mat_not){
						temparr = arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temparr;
					}
				}
			}
			printf("Ad\tSoyad\tDTarihi\t\tNumara\t\tMnot\tFnot\tTnot\n");
				
			for(i=0;i<k;i++){
    		printf("\n%s\t%s\t%d/%d/%d\t%d\t\t%.1f\t%.1f\t%.1f\n",arr[i].isim,arr[i].soyisim,arr[i].dogum.gun,arr[i].dogum.ay,arr[i].dogum.yil,arr[i].numara,arr[i].mat_not,arr[i].fen_not,arr[i].tr_not);
				}
			fclose(prj);

		
		}
		if(y==8){	//FEN NOTUNA GÖRE KAYITLARI SIRALAMAK
		prj= fopen("sorted.bin","r");
		int k;
		k= ftell(prj);
		struct Person *arr;
		struct Person temparr;

		arr= (struct Person*)malloc(sizeof(struct Person)*k);
		int i,j;
					 
			for(i=0;i<k;i++){
				fread(&eg,sizeof(struct Person),1,prj);
				arr[i]=eg;
			}
			
			for(i=0;i<k;i++){
				for(j=0;j<k-i-1;j++){
					if(arr[j].fen_not<arr[j+1].fen_not){
						temparr = arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temparr;
					}
				}
			}
			printf("Ad\tSoyad\tDTarihi\t\tNumara\t\tMnot\tFnot\tTnot\n");
				
			for(i=0;i<k;i++){
    		printf("\n%s\t%s\t%d/%d/%d\t%d\t\t%.1f\t%.1f\t%.1f\n",arr[i].isim,arr[i].soyisim,arr[i].dogum.gun,arr[i].dogum.ay,arr[i].dogum.yil,arr[i].numara,arr[i].mat_not,arr[i].fen_not,arr[i].tr_not);
				}
			fclose(prj);			
			
		}
		if(y==9){	//TÜRKÇE NOTUNA GÖRE KAYITLARI SIRALAMAK
		prj= fopen("sorted.bin","r");
		int k;
		k= ftell(prj);
		struct Person *arr;
		struct Person temparr;

		arr= (struct Person*)malloc(sizeof(struct Person)*k);
		int i,j;
					 
			for(i=0;i<k;i++){
				fread(&eg,sizeof(struct Person),1,prj);
				arr[i]=eg;
			}
			
			for(i=0;i<k;i++){
				for(j=0;j<k-i-1;j++){
					if(arr[j].tr_not<arr[j+1].tr_not){
						temparr = arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temparr;
					}
				}
			}
			printf("Ad\tSoyad\tDTarihi\t\tNumara\t\tMnot\tFnot\tTnot\n");
				
			for(i=0;i<k;i++){
    		printf("\n%s\t%s\t%d/%d/%d\t%d\t\t%.1f\t%.1f\t%.1f\n",arr[i].isim,arr[i].soyisim,arr[i].dogum.gun,arr[i].dogum.ay,arr[i].dogum.yil,arr[i].numara,arr[i].mat_not,arr[i].fen_not,arr[i].tr_not);
				}
			fclose(prj);
			
			
		}
		if(y==10){	//ÇIKIÞ
			break;
			
		}
	}

	
	return 0;
}
