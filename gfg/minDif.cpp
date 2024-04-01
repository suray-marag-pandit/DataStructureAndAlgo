int i=0,j=s.length()-1;
        while(j>=0 && s[j]==' '){
            j--;
        }
        while(j>=0 && s[j]!=' '){
            i++;
            j--;
        }
        return i;


// Given a binary search tree having n (n>1) nodes, the task is to find the minimum absolute difference between any two nodes.