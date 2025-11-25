#include <stdio.h>
#include <string.h>
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
    {"P03","Pepsi","Chai",150,1}
};
int count=3;

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
		fgets(newUnit,50,stdin);
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
	int newStatus;
	while(1){
		printf("Nhap trang thai moi: ");
		if(scanf("%d",&newStatus)!=1){
			printf("Vui long nhap so!!\n");
			while(getchar()!='\n');
			continue;
		}
		if(newStatus!=0&&newStatus!=1){
			printf("Vui long nhap 0 hoac 1!!\n");
			continue;
		}
		break;
	}
	products[index].status=newStatus;
	printf("Doi trang thai hang hoa %s thanh cong!!\n",productId);
}

void searchProduct(){
	char sch[50];
	printf("Nhap ID hoac ten hang hoa can tra cuu: ");
	fflush(stdin);
	fgets(sch,50,stdin);
	sch[strcspn(sch,"\n")]=0;
	int found=0;
	printf("-----------KET QUA TRA CUU-----------\n");
	for(int i=0;i<count;i++){
		if(strcmp(products[i].productId,sch)==0||strstr(products[i].name,sch)!=0){
			printf("+------------+------------------------------+------------+-------------------+------------+\n");
			printf("| Ma         | Ten                          | Don vi     | So luong ton kho  | Trang thai |\n");
			printf("+------------+------------------------------+------------+-------------------+------------+\n");
			printf("| %-10s | %-28s | %-10s | %-17d | %-10d |\n",
	        products[i].productId,
	        products[i].name,
	        products[i].unit,
	        products[i].qty,
	        products[i].status);
			printf("+------------+------------------------------+------------+-------------------+------------+\n");
			found++;
		}
	}
	if(found==0){
		printf("Khong tim thay vat tu!!\n");
	}else{
		printf("Tim thay tong so %d vat tu!!\n",found);
	}
}

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
		case 9:
			printf("Thoat chuong trinh!!\n");
			return 0;
		default:
			printf("Lua chon khong hop le!!\n");		
	}
	}while(choice!=9);
	return 0;
}
