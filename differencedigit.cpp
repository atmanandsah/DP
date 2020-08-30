#include<bits/stdc++.h>
using namespace std;
int length;
int difference;
vector<int> result;
void generate(int currnum,int currlength){
    if(currlength == length){
        result.push_back(currnum);
        return;
    }
    int digit = currnum%10;
    int smallno = digit-difference;
    if(smallno>0){
        generate(currnum*10+smallno,currlength+1);
    }

    int largeno = digit+difference;
    if((largeno<10) && (largeno != smallno)){
        generate(currnum*10+largeno,currnum+1);
    }

}
int main(){
    int n,k;
    cin>>n>>k;
    length = n;
    difference = k;
    for(int i=0;i<10;i++){
        if(n!=1 && i==0){
            continue;
        }
        generate(i,1);
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}