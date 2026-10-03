#include <stdio.h>

int main() {
    int n,k,i,j;
    scanf("%d %d",&n,&k);
    int m[n];
    for(i=0;i<n;i++){
        scanf("%d",&m[i]);
    }
    int sum=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(m[i]-m[j]==k || m[j]-m[i]==k){
                sum=sum+1;
            }
        }
    }
    sum=sum/2;
    printf("%d",sum);
    return 0;
}