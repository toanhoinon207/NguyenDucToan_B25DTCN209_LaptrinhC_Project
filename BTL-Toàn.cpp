#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Work{
	private :
		int ID;
		string content;
		int hours;
		string crDate;
		bool status;
	public:
		Work(){}
		
		Work(int maCV,string noiDung,int gio,string ngayTao){
			ID=maCV;
			content=noiDung;
			hours=gio;
			crDate=ngayTao;
			status=false;
		}
		
		int getId(){
			return ID;
		}
		
		bool isDone(){
			return status;
		}
		
		void setContent(string newContent){
			content=newContent;
		}
		
		void done(){
			status=true;
		}
		
		void input(int maCV){
	        ID=maCV;
	        cin.ignore();
	        cout<<"Nhap noi dung: ";
	        getline(cin,content);
	        cout<<"Nhap so gio: ";
	        cin>>hours;
	        cout<<"Nhap ngay tao (dd/MM/yyyy): ";
	        cin>>crDate;
	        status=false;
    	}
    	
    	void output() {
        cout<<"Ma CV: "<<ID<< endl;
        cout<<"Noi dung: "<<content<<endl;
        cout<<"So gio: "<< hours <<endl;
        cout<<"Ngay tao: "<<crDate<<endl;
        cout<<"Trang thai: ";
        if(status)
            cout<<"Hoan thanh";
        else
            cout<<"Dang lam";
        cout<<endl;
        cout<<"---------------------\n";
    }
};
class WorkManager{
	private:
		vector<Work> works; 
    	int autoId=1;
	public:
		WorkManager() {
	        works.push_back(Work(autoId++,"Hoc C++",2,"25/12/2025"));
	        works.push_back(Work(autoId++,"Lam BTVN",3,"26/12/2025"));
    	}
    	
		void showList(){
	        if(works.empty()){
	            cout<<"Danh sach rong!\n";
	            return;
	        }
	        for(int i=0;i<works.size();i++){
	            works[i].output();
	        }
    	}
    	
    	void addWork(){
	        Work w;
	        w.input(autoId++);
	        works.push_back(w);
	        cout<<"Them cong viec thanh cong!\n";
	    }
	    
	    void updateWork() {
	        int ID;
	        cout<<"Nhap ma cong viec: ";
	        cin>>ID;
	        for (int i=0; i<works.size();i++){
	            if(works[i].getId() ==ID){
	                cin.ignore();
	                string newContent;
	                cout<<"Nhap noi dung moi: ";
	                getline(cin,newContent);
	                works[i].setContent(newContent);
	                cout<<"Cap nhat thanh cong!\n";
	                return;
	            }
	        }
	        cout << "Khong tim thay cong viec!\n";
	    }
	    
	    void changeStatus() {
	        int ID;
	        cout<<"Nhap ma cong viec: ";
	        cin>>ID;
	        for(int i=0;i<works.size();i++){
	            if(works[i].getId()==ID){
	                if(works[i].isDone()){
	                    cout<<"Cong viec da hoan thanh!\n";
	                    return;
	                }
	                works[i].done();
	                cout<<"Chuyen trang thai thanh cong sang hoan thanh!\n";
	                return;
	            }
	        }
	        cout<<"Khong tim thay cong viec!\n";
	    }
	    void filterStatus(){
	        int choice;
	        cout<<"0. Dang lam\n1. Hoan thanh\nChon: ";
	        cin>>choice;
	        for(int i=0;i<works.size();i++){
	            if((choice==0&&!works[i].isDone())||(choice == 1 && works[i].isDone())){
	                works[i].output();
	            }
	        }
	    }
};	
int main(){
	WorkManager manager;
	int choice;
	do {
        cout<<"+----------------MENU---------------+\n";
        cout<<"|1. Hien thi danh sach              |\n";
        cout<<"|2. Them cong viec                  |\n";
        cout<<"|3. Cap nhat noi dung CV            |\n";
        cout<<"|4. Chuyen trang thai               |\n";
        cout<<"|5. Loc cong viec theo trang thai   |\n";
        cout<<"|6. Thoat                           |\n";
        cout<<"+-----------------------------------+\n";
        cout<<"Nhap lua chon: ";
        cin>>choice;

        switch (choice){
            case 1:
				manager.showList();
				break;
            case 2:
				manager.addWork();
				break;
            case 3:
				manager.updateWork();
				break;
            case 4:
				manager.changeStatus();
				break;
            case 5:
				manager.filterStatus();
				break;
            case 6:
				cout<<"Thoat chuong trinh!\n";
				break;
            default:
				cout<<"Lua chon khong hop le!\n";
        }
    }while(choice!=6);
	return 0;
}
