#ifndef AD
#define AD

string GetStr(){
string s;
cin>>s;
return s;
}

int GetLen(string s){
    int l = 0;
    for(int i = 0;s[i]!='\0';i++){
        l++;
    }
    return l;
}

string GoToValid(string s,int len){
    string corr;
    for(int i = 0;i<len;i++){
        char ch = s[i];
        if(isupper(ch)){
            ch = tolower(ch);
        }
        if(ch<97||ch>122){
            cout<<"WRONG\r\n!LETTERS ONLY!";
            break;
        }
        corr+=ch;
    }
    return corr;
}

#endif
