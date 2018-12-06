#include <iostream>
using namespace std;
#include "AD.h"

char sq[6][6];
int alph[26]={0};
int main(){
cout<<"Enter message\r\n>";
string mess = GetStr();
cout<<"Now enter key\r\n>";
string key = GetStr();
int m_len = GetLen(mess);
int k_len = GetLen(key);
char ch = 97;
int in = 0;
for(int i = 0;i<6;i++){
    for(int j = 0;j<6;j++){
        if(ch<=122){
           sq[i][j]=ch;
           ch++;
        }else{
            sq[i][j]=in;
            in++;
        }
    }
}
string enc1;
string adfgvx="adfgvx";
mess = GoToValid(mess,m_len);
for(int i = 0;i<m_len;i++){
    char ch=mess[i];
    for(int z = 0;z<6;z++){
        for(int s = 0;s<6;s++){
            if(ch==sq[z][s]){
                enc1+=adfgvx[z];
                enc1+=adfgvx[s];
            }
        }
    }
}
key = GoToValid(key,k_len);
int e_len = GetLen(enc1);
bool c = 0;
while(!c){
    if((e_len%k_len)!=0){
        enc1+='aa';
        e_len=GetLen(enc1);
    }else{c=1;}
}
int ind_i=e_len/k_len;
char sq2[ind_i][k_len]={0};
int itf = 0;
for(int i = 0;i<ind_i;i++){
    for(int j = 0;j<k_len;j++){
        sq2[i][j]=enc1[itf];
        itf++;
    }
}

string n_key;
for(int i = 0;i<26;i++){
    char ch=97+i;
    for(int j = 0;j<k_len;j++){
        if(key[j]==ch){
            ch-=97;
            alph[ch]=1;
        }
    }
}
for(int i =0;i<26;i++){
    if(alph[i]==1){
       n_key+=i+97;
    }
}
char sq3[ind_i][k_len]={0};
for(int i = 0;i<k_len;i++){
    char ch1=n_key[i];
    int ind=0;
    for(int j = 0;j<k_len;j++){
        if(ch1==key[j]){
            ind = j;
        }
    }
    for(int j = 0;j<ind_i;j++){
        sq3[j][i]=sq2[j][ind];
    }
}
string encrypted;
for(int i = 0;i<k_len;i++){
    for(int j =0;j<ind_i;j++){
        encrypted+=sq3[j][i];
    }
}
cout<<encrypted;
return 0;
}
