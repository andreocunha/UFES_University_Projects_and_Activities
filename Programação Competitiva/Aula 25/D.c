#include <stdlib.h>
#include <stdio.h>

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int a[30005];
	for(int t=1; t<=n-1; t++) {
		scanf("%d",&a[t]);
	}
	int flag=0;
	for(int t=1; t<n;) {
		t=t+a[t];
		if(t==m) {
			flag=1;
		}
	}

	if(flag==1) {
        printf("YES\n");
	} else {
        printf("NO\n");
	}
	return 0;
}