#include<iostream>

using namespace std;

class mobile{
     int mobile_id;
     string mobile_name;
     int quantity;
     int price;

     public:

     mobile(){};
     mobile(int id, string name, int num, int cost){
            mobile_id=id;
            mobile_name=name;
            quantity=num;
            price=cost;
     }

     void accept(){
        cout<<"Enter mobile id: ";
        cin>>mobile_id;
        cout<<"Enter mobile name: ";
        cin>>mobile_name;
        cout<<"Enter quantity: ";
        cin>>quantity;
        cout<<"Enter price: ";
        cin>>price;
     }

     void display(){
        cout<<"Mobile id: "<<mobile_id<<endl;
        cout<<"Mobile name: "<<mobile_name<<endl;
        cout<<"Quantity: "<<quantity<<endl;
        cout<<"Price: "<<price<<endl;
     }

};

int main(){
    mobile m1[10];

    bool flag=true;
    int choice;
    int i=0;

    do
    {
    cout<<"1. Add mobile\n2. Display mobile\n3. Exit\n";
    cin>>choice;

    switch (choice)
    {
      case 1:
        if(i<10){
            m1[i].accept();
            i++;
        }
        else{
            cout<<"Array is full\n";
        }
        break;

        case 2:
        for(int j=0;j<i;j++){
            m1[j].display();
            cout<<"Do you want to delete this mobile?(y/n)\n";
            char ch;
            cin>>ch;

            if(ch=='y'){
                for(int k=j;k<i-1;k++){
                    m1[k]=m1[k+1];
                }
                i--;
                j--;
            }
            else{
                continue;
            }
    
            }
            break;

            case 3:
            cout<<"Exiting...\n";
            flag=false;
            break;

            default:
            cout<<"Invalid choice\n";

        }

    }while (flag);


    return 0;
    } 
    



