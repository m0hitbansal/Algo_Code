#include<stdio.h>

int  main() {
  int t;
  scanf("%d",&t);
  while(t>0){
    int count=0;
    int n;
  scanf("%d",&n);
    int b[n];
    for(int i=0;i<n;i++){
    scanf("%d",&b[i]);;
    }
    for (int p=0;p<n-1;p++){
        int l=b[p];
      for(int q=p+1;q<n;q++){
          if(p<q-1)
          l^=b[q-1];
          int r=b[q];
        for(int k =q;k<n;k++){
            if(k>q)
             r^=b[k];
             if(r==l)
              count++;
        }
      }
    }
  printf("%d\n",count);
    t--;
  }
  return 0;
}
