#include<iostream>
using namespace std;

int sum(int num){
    int sum=0;

    while(num!=0){
        sum+=num%10;
        num/=10;
    }
    return sum;
}

int main(){
    int num[10];
    cout<<"Enter a numbers:\n";
  
  for(int i=0;i<10;i++){
    cin>>num[i];
  }

  cout<<"Result:\n";
  for (int i=0;i<10;i++){
    if(num[i]%7==0){
        cout<<num[i]<<" is divisible by 7 and Sum of digits is"<<sum(num[i])<<endl;
    }
    else
    cout<<num[i]<<"is not divisble by 7";
  }

    return 0;
}