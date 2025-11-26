#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

struct Product{
	char productId[10];
	char name[50];
	char unit[10];
	int qty;
	int status;
};

struct Product products[MAX]={
	{"P01","Sua Tuoi Vinamilk","Hop",120,1},
    {"P02","Mi Hao Hao","Thung",300,1},
    {"P03","Pepsi","Chai",150,1},
    {"P04","Coca Cola","Chai",200,1},
    {"P05","Sprite","Chai",180,1},
    {"P06","Nuoc Tang Luc Redbull","Lon",250,1},
    {"P07","Nuoc Tang Luc Monster","Lon",160,1},
    {"P08","Tra Xanh Khong Do","Chai",220,1},
    {"P09","Tra O Do","Chai",140,1},
    {"P10","Bim Bim Oishi","Goi",500,1},
    {"P11","Bim Bim Poca","Goi",450,1},
    {"P12","Snack Khoai Tay Lay's","Goi",320,1},
    {"P13","Banh Mi Sandwich","Tui",80,1},
    {"P14","Banh Bong Lan","Hop",95,1},
    {"P15","Keo Muc","Goi",210,1},
    {"P16","Keo Dua Ben Tre","Goi",170,1},
    {"P17","Keo Socola","Goi",300,1},
    {"P18","Mi Trieu Khoai","Thung",260,1},
    {"P19","Mi Omachi","Thung",280,1},
    {"P20","Bot Giat OMO","Tui",140,1},
    {"P21","Bot Giat Ariel","Tui",135,1},
    {"P22","Nuoc Rua Chen Sunlight","Chai",190,1},
    {"P23","Nuoc Rua Tay Lifebuoy","Chai",160,1},
    {"P24","Nuoc Xa Downy","Chai",200,1},
    {"P25","Khau Trang Y Te","Hop",350,1},
    {"P26","Giay Ve Sinh Kleenex","Cuon",130,1},
    {"P27","Giay Ve Sinh Bless You","Cuon",115,1},
    {"P28","Sua Dabaco","Hop",190,1},
    {"P29","Duong Bien","Kg",250,1},
    {"P30","Muoi Iot","Kg",280,1}
};
int count=30;

int existId(char id[]);
void addProduct();
void updateProduct();
void changeStatus();
void searchProduct();
void toLower(char s[]);
void showProduct();
void sortProduct();

int main(){
	int choice;
	do{
		printf("+-----QUAN LY CUA HANG TIEN LOI-----+\n");
		printf("|1. Them mat hang moi.              |\n");
		printf("|2. Cap nhat thong tin.             |\n");
		printf("|3. Quan ly trang thai (Khoa/Xoa).  |\n");
		printf("|4. Tra cuu (Tim kiem).             |\n");
		printf("|5. Danh sach (Phan trang).         |\n");
		printf("|6. Sap xep danh sach.              |\n");
		printf("|7. Giao dich xuat/nhap hang hoa.   |\n");
		printf("|8. Lich su xuat/nhap.              |\n");
		printf("|9. Thoat.                          |\n");
		printf("+-----------------------------------+\n");
		printf("Xin moi nhap lua chon: ");
		scanf("%d",&choice);
	switch(choice){
		case 1:
			addProduct();
			break;
		case 2:
			updateProduct();
			break;
		case 3:
			changeStatus();
			break;
		case 4:
			searchProduct();
			break;
		case 5:
			showProduct();
			break;
		case 6: 
			sortProduct();
			break;
		case 9:
			printf("Thoat chuong trinh!!\n");
			return 0;
		default:
			printf("Lua chon khong hop le!!\n");		
	}
	}while(choice!=9);
	return 0;
}

int existId(char id[]){
	for(int i=0;i<count;i++){
		if(strcmp(products[i].productId,id)==0){
			return 1;		
		}
	}
	return 0;
}

void addProduct(){
	if(count==MAX){
		printf("Danh sach day! Them moi hang hoa that bai!!\n");
		return;
	}
	struct Product sp;
	while(1){
		printf("Nhap ID hang hoa: ");
		fflush(stdin);
		fgets(sp.productId,10,stdin);
		sp.productId[strcspn(sp.productId,"\n")]=0;
		if(strlen(sp.productId)==0){
			printf("ID khong duoc de trong!!\n");
			continue;
		}
		if(existId(sp.productId)){
			printf("ID da ton tai!!\n");
			continue;		
		}
		break;
	}
	while(1){
		printf("Nhap ten hang hoa: ");
		fgets(sp.name,50,stdin);
		sp.name[strcspn(sp.name,"\n")]=0;
		if(strlen(sp.name)==0){
			printf("Ten hang hoa khong duoc de trong!!\n");
			continue;
		}
		break;
	}
	while(1){
		printf("Nhap don vi hang hoa: ");
		fgets(sp.unit,10,stdin);
		sp.unit[strcspn(sp.unit,"\n")]=0;
		if(strlen(sp.unit)==0){
			printf("Don vi hang hoa khong duoc de trong!!\n");
			continue;
		}
		break;
	}
	while(1){
		printf("Nhap so luong ton kho: ");
		if(scanf("%d",&sp.qty)!=1){
			printf("Vui long nhap so!!\n");
			while(getchar()!='\n');
			continue;
		}
		if(sp.qty<0){
			printf("So luong ton kho khong hop le!!\n");
			continue;
		}
		break;
	}
	sp.status=1;
	products[count]=sp;
	count++;
	printf("Them moi hang hoa thanh cong!!\n");
}

void updateProduct(){
	char id[10];
	int index=-1;
	printf("Nhap ID hang hoa can cap nhat: ");
	fflush(stdin);
	fgets(id,10,stdin);
	id[strcspn(id,"\n")]=0;
	for(int i=0;i<count;i++){
		if(strcmp(products[i].productId,id)==0){
			index=i;
			break;
		}
	}
	if(index==-1){
		printf("Vat tu %s khong ton tai trong danh sach!!\n",id);
		return;
	}
	printf("-----CAP NHAT THONG TIN HANG HOA-----\n");
	char newName[50];
	while(1){
		printf("Nhap ten hang hoa moi: ");
		fgets(newName,50,stdin);
		newName[strcspn(newName,"\n")]=0;
		if(strlen(newName)==0){
			printf("Ten hang hoa khong duoc de trong!!\n");
			continue;
		}
		break;
	}
	char newUnit[10];
	while(1){
		printf("Nhap don vi hang hoa moi: ");
		fgets(newUnit,10,stdin);
		newUnit[strcspn(newUnit,"\n")]=0;
		if(strlen(newUnit)==0){
			printf("Don vi hang hoa khong duoc de trong!!\n");
			continue;
		}
		break;
	}
	int newQty;
	while(1){
		printf("Nhap so luong ton kho moi: ");
		if(scanf("%d",&newQty)!=1){
			printf("Vui long nhap so!!\n");
			while(getchar()!='\n');
			continue;
		}
		if(newQty<0){
			printf("So luong ton kho khong hop le!!\n");
			continue;
		}
		break;
	}
	strcpy(products[index].name,newName);
	strcpy(products[index].unit,newUnit);
	products[index].qty=newQty;
	printf("Cap nhat hang hoa %s thanh cong!!\n",products[index].productId);
}

void changeStatus(){
	char productId[10];
	int index=-1;
	printf("Nhap ID hang hoa can doi trang thai: ");
	fflush(stdin);
	fgets(productId,10,stdin);
	productId[strcspn(productId,"\n")]=0;
	for(int i=0;i<count;i++){
		if(strcmp(products[i].productId,productId)==0){
			index=i;
			break;
		}
	}
	if(index==-1){
		printf("Vat tu %s khong ton tai trong danh sach!!\n",productId);
		return;
	}
	printf("Trang thai hien tai: %d\n",products[index].status);
	if(products[index].status==1){
		products[index].status=0;
		printf("Doi trang thai hang hoa %s thanh cong!!\n",productId);
	}else{
		printf("Hang hoa %s da duoc khoa!!\n",productId);
	}
}

void toLower(char s[]){
    int i=0;
    while(s[i]!='\0'){
        if(s[i]>='A'&&s[i]<='Z'){
            s[i]=s[i]+32;
        }
        i++;
    }
}

void searchProduct(){
	char sch[50];
	printf("Nhap ID hoac ten hang hoa can tra cuu: ");
	fflush(stdin);
	fgets(sch,50,stdin);
	sch[strcspn(sch,"\n")]=0;
	toLower(sch);
	int found=0;
	printf("-----------KET QUA TRA CUU-----------\n");
	printf("+------------+------------------------------+------------+-------------------+------------------+\n");
	printf("| Ma         | Ten                          | Don vi     | So luong ton kho  | Trang thai       |\n");
	printf("+------------+------------------------------+------------+-------------------+------------------+\n");
	for(int i=0;i<count;i++){
		char lowerID[20];
        strcpy(lowerID,products[i].productId);
        toLower(lowerID);
		char lowerName[50];
        strcpy(lowerName,products[i].name);
        toLower(lowerName);
		if(strcmp(lowerID,sch)==0||strstr(lowerName,sch)!=NULL){
			printf("| %-10s | %-28s | %-10s | %-17d | %-16s |\n",
	        products[i].productId,
	        products[i].name,
	        products[i].unit,
	        products[i].qty,
	        products[i].status?"Con su dung":"Het han su dung");
			printf("+------------+------------------------------+------------+-------------------+------------------+\n");
			found++;
		}
	}
	if(found==0){
		printf("Khong tim thay vat tu!!\n");
	}else{
		printf("Tim thay tong so %d vat tu!!\n",found);
	}
}

void showProduct(){
	if(count==0){
		printf("Danh sach hang hoa rong!!\n");
		return;
	}
	int page=1;
	int itemPerPage=10;
	int index=0;
	char ch;
	int end;
	int kq=count/itemPerPage;
    int totalPage=(count%itemPerPage==0)?kq:kq+1;
	while(1){
		printf("Moi ban nhap so trang can xem (1-%d): ",totalPage);
		scanf("%d",&page);
		index=(page-1)*itemPerPage;
		end=index+itemPerPage;
		printf("Trang %d/%d: \n\n",page,totalPage);
		printf("+------------+------------------------------+------------+-------------------+------------------+\n");
		printf("| Ma         | Ten                          | Don vi     | So luong ton kho  | Trang thai       |\n");
		printf("+------------+------------------------------+------------+-------------------+------------------+\n");
		for(int i=index;i<count&&i<end;i++){
			printf("| %-10s | %-28s | %-10s | %-17d | %-16s |\n",
	        products[i].productId,
	        products[i].name,
	        products[i].unit,
	        products[i].qty,
	        products[i].status?"Con su dung":"Het han su dung");
			printf("+------------+------------------------------+------------+-------------------+------------------+\n");
			index++;
		}
		fflush(stdin);
       	printf("Ban co muon thoat khong (y/n)? ");
       	ch=getchar();
       	if(ch=='y'||ch=='Y'){
           break;
		}
	}
}

void sortProduct(){
	if(count==0){
		printf("Danh sach hang hoa rong!!\n");
		return;
	}
	int choice;
	printf("+--------SAP XEP HANG HOA-------+\n");
	printf("|1. Sap xep theo ten (A-Z).     |\n");
	printf("|2. Sap xep tang theo so luong. |\n");
	printf("+-------------------------------+\n");
	printf("Xin moi nhap lua chon: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			for(int i=0;i<count-1;i++){
				for(int j=i+1;j<count;j++){
					if(strcmp(products[i].name,products[j].name)>0){
						struct Product temp=products[i];
						products[i]=products[j];
						products[j]=temp;
					}
				}
			}
			printf("Da sap xep theo ten (A-Z) thanh cong!!\n");
			break;
		case 2:
			for(int i=0;i<count-1;i++){
				for(int j=i+1;j<count;j++){
					if(products[i].qty>products[j].qty){
						struct Product temp=products[i];
						products[i]=products[j];
						products[j]=temp;
					}
				}
			}
			printf("Da sap xep theo so luong thanh cong!!\n");
			break;
		default:
			printf("Lua chon khong hop le!!\n");
			return;
	}
	printf("+------------+------------------------------+------------+-------------------+------------------+\n");
	printf("| Ma         | Ten                          | Don vi     | So luong ton kho  | Trang thai       |\n");
	printf("+------------+------------------------------+------------+-------------------+------------------+\n");
	for(int i=0;i<count;i++){
		printf("| %-10s | %-28s | %-10s | %-17d | %-16s |\n",
	    products[i].productId,
	    products[i].name,
	    products[i].unit,
	    products[i].qty,
	    products[i].status?"Con su dung":"Het han su dung");
		printf("+------------+------------------------------+------------+-------------------+------------------+\n");
	}
}
