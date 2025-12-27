#include <iostream>
#include <string>

using namespace std;

class Manage{
public:
    virtual void display()=0;
    virtual void add()=0;
    virtual void del()=0;
    virtual void update()=0;
};

class ClassRoom:public Manage{
private:
    string classId;
    string className;
    string specialized;
    string type;
public:
	ClassRoom(){
        classId="P802";
        className="CNTT2";
        specialized="Cong Nghe Thong Tin";
        type="CNTT";
    }
    void add() {
        cout<<"Nhap ma lop: ";
        getline(cin, classId);
        cout<<"Nhap ten lop: ";
        getline(cin,className);
        cout<<"Nhap chuyen nganh: ";
        getline(cin,specialized);
        cout<<"Nhap loai lop (CNTT/Ngoai ngu): ";
        getline(cin,type);
    }

    void display(){
        cout<<"Ma lop: "<<classId<<endl;
        cout<<"Ten lop: "<<className<<endl;
        cout<<"Chuyen nganh: "<<specialized<<endl;
        cout<<"Lop: "<<type<<endl;
    }

    void del(){
        cout<<"Da xoa lop hoc!!"<<endl;
    }
    
    void update() {
        cout << "Cap nhat thong tin lop hoc!!"<<endl;
    }
};

class Student:public Manage{
private:
    string studentId;
    string name;
    string birthDay;
    string email;
    string phoneNum;
public:
	Student(){
		studentId="B25DTCN209";
		name="Nguyen Duc Toan";
		birthDay="03/06/2007";
		email="nguenductoan450@gmail.com";
		phoneNum="0862882747";
	}
    void add() {
        cout << "Nhap ma sinh vien: ";
        getline(cin,studentId);
        cout<<"Nhap ten sinh vien: ";
        getline(cin,name);
        cout<<"Nhap ngay sinh: ";
        getline(cin,birthDay);
        cout<<"Nhap email: ";
        getline(cin,email);
        cout<<"Nhap so dien thoai: ";
        getline(cin,phoneNum);
    }

    void display(){
        cout<<"Ma SV: "<<studentId<<endl;
        cout<<"Ten SV: "<<name<<endl;
        cout<<"Ngay sinh: "<<birthDay<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<"So DT: "<<phoneNum<<endl;
    }

    void del(){
        cout<<"Da xoa sinh vien!!"<<endl;
    }

    void update(){
        cout<<"Cap nhat thong tin sinh vien!!" <<endl;
    }
};

void menu(Manage* ch){
    int choice;
    do{
    	cout<<"+-----MENU-----+\n";
        cout<<"|1. Hien thi   |\n";
        cout<<"|2. Them moi   |\n";
        cout<<"|3. Xoa        |\n";
        cout<<"|4. Cap nhat   |\n";
        cout<<"|5. Quay lai   |\n";
        cout<<"+--------------+\n";
        cout<<"Nhap lua chon: ";
        cin>>choice;
        cin.ignore();
        switch(choice){
        case 1:
			ch->display();
			break;
        case 2:
			ch->add();
			break;
        case 3:
			ch->del();
			break;
        case 4:
			ch->update();
			break;
        }
    }while(choice!=5);
}

int main(){
    int choice;
    do{
        cout<<"+---------MENU---------+\n";
        cout<<"|1. Quan ly lop hoc    |\n";
        cout<<"|2. Quan ly sinh vien  |\n";
        cout<<"|3. Thoat              |\n";
        cout<<"+----------------------+\n";
        cout<<"Nhap lua chon: ";
        cin>>choice;
        cin.ignore();
        if(choice==1){
            Manage* m=new ClassRoom();
            menu(m);
        }
        else if(choice==2){
            Manage* m=new Student();
            menu(m);
        }
    }while(choice!=3);
    return 0;
}


