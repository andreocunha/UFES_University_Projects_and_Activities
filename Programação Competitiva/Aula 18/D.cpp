#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main(void){
	char s[1009];
	int k;

    scanf("%s %d",s,&k);

	 	int len = strlen( s ); 
        int cur = 0;
        while( k >=1 && cur<len ){
        	if( s[cur] <'9'  ){                                   
        		int t = cur;
        	    for( int i=cur+1;i<len;i++){ 
        	    	 if( i > cur+k)
        	    	     break;
					 if( s[i] > s[t] ) 
        	    		t = i;
        	    	}
		        if( s[cur] != s[t] ){ 
			        k = k - ( t - cur );
				    char tt = s[cur];
				    s[cur]  = s[t];
				    
					for( int j=t;j>=cur+2;j--){
				    	 s[j] = s[j-1];
					}
					s[cur+1] = tt; 
			    }
			}
		    cur++;
		 }
        printf("%s\n",s);
        memset(s,0,sizeof(s));
 	return 0;
}
