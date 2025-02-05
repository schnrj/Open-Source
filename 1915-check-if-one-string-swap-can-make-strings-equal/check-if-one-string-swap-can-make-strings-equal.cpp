class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count=0;
        map<char,int>m1,m2;
        for(int i=0;i<s1.size();i++){
            m1[s1[i]]++;
            m2[s2[i]]++;

        }
        if(m1==m2){
 for(int i=0;i<s1.size();i++){
           if(s1[i]!=s2[i]) count++;
        }
         if(count>2) return false;
        else return true;
        }
        else return false;
        // for(int i=0;i<s1.size();i++){
        //    if(s1[i]!=s2[i]) count++;
        // }
       
    }
};