class Solution {
public:
    bool isValid(string word) {

        string sachu="bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
        if(word.size()<3) return false;
        int count=0;
        bool de=false;
        bool vow=false;
        bool cons=false;

        for(int i=0;i<word.size();i++){
            if((word[i]>=48&&word[i]<=57)||(word[i]>=65&&word[i]<=90)||(word[i]>=97&&word[i]<=122)){
                    de=true;
            }
            else return false;

            if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'||word[i]=='A'||word[i]=='E'||word[i]=='I'||word[i]=='O'||word[i]=='U'){
                vow=true;
            }
            if(sachu.find(word[i])!=string::npos){
                cons=true;
            }

        }
        if(vow&&cons) return true;
        else return false;
    }
};