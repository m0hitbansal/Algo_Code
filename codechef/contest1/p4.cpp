#include<iostream>
#include<algorithm>
using namespace std;
int  main() {
  int t;
  cin>>t;
  while(t>0){
    int n;
    cin>>n;
    int a[n]={0};
    int l[n];
    int r[n];
    int c[n];
    int b[n];
    int max=0;
    for(int i=0;i<n;i++){
      cin>>c[i];
    }
    for(int i=0;i<n;i++){
      cin>>b[i];
    }
    for(int i=0;i<n;i++){
      int p=i-c[i];
      if(p<0)
      p=0;
      int q=i+c[i];
      if(q>n-1)
      q=n-1;
      l[i]=p;
      r[i]=q;
    }
    for(int i=0;i<n;i++){
      cout<<l[i]<<" "<<r[i]<<endl;
    }
    sort(l,l+n);
    sort(r,r+n);
    for(int i=0;i<n;i++){
      a[l[i]]++;
    }
    int temp=a[0];
    int k=0;
    for(int i=1;i<n;i++){
      temp+=a[i];
      a[i]=temp;
      if(r[k]==i){
        temp--;
        while(k<n&&r[k]==i)
        k++;
      }
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    /*for(int i=0;i<n;i++){
      int l=i-c[i];
      int m=i+c[i];
      if(l<0)
        l=0;
      if(m>n-1)
        m=n-1;
      for(int j=l;j<=m;j++)
          a[j]+=1;
    }*/

    sort(a,a+n);
    sort(b,b+n);
    int p=0;
    for(int j=0;j<n;j++){
      if(a[j]==b[j])
      p++;
    }
    if(p==n)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    t--;
  }
  return 0;
}
