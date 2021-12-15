class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>v1,v2;
        int n1=version1.size(),n2=version2.size();
        int dig=0,p=1;
        for(int i=0;i<n1;i++){
            if(version1[i]!='.'){
                if(version1[i]!='0' || dig>0){
                dig=p*dig+(version1[i]-'0');
                p*=10;
                }
            }
            else{
                p=1;
                v1.push_back(dig);
                dig=0;
            }
        }
        v1.push_back(dig);
        dig=0,p=1;
        for(int i=0;i<n2;i++){
            if(version2[i]!='.'){
                if(version2[i]!='0' || dig>0){
                dig=p*dig+(version2[i]-'0');
                p*=10;}
            }
            else{
                p=1;
                v2.push_back(dig);
                dig=0;
            }
        }
        v2.push_back(dig);
        int i=0,j=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]>v2[j]){
                return 1;
            }
            else if(v1[i]<v2[j]){
                return -1;
            }
            i++;
            j++;
        }
        while(i<v1.size()){
            if(v1[i]>0){
                return 1;
            }
            i++;
        }
        while(j<v2.size()){
            if(v2[j]>0){
                return -1;
            
        }j++;
        
    }
        return 0;
    }
};