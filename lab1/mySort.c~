void mySort(int d[], unsigned int n){
  int i,x,j;
  for(i=1;i<n;i++){
    x=d[i];
    j=1;
    while(x<d[i-j] && j<=i){
      d[i-j+1]=d[i-j];
      d[i-j]=x;
      j++;
    }
  }
}