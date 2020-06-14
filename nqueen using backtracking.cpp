#include<iostream>
#include<time.h>
clock_t start,stop;
using namespace std;
 
int board[20],count=0;
 
int main()
{
 int n,i,j;
 void queen(int row,int n);
 
 cout<<"Enter number of Queens:"<<endl;
 cin>>n;;
   start=clock();
 queen(1,n);
  stop=clock();
  cout<<"no.of solutions:"<<count<<endl;
    cout<<"\nThe time taken for execution is :"<<(double)(stop-start)/CLOCKS_PER_SEC;
 return 0;
}
 

void print(int n)
{
 int i,j;

 
 for(i=1;i<=n;++i)
   cout<<"  ";
 
 for(i=1;i<=n;++i)
 {
  cout<<endl<<endl;
  for(j=1;j<=n;++j)
  {
      
   if(board[i]==j)
    cout<<"1"<<"  "; 
   else
    cout<<"0"<<"  "; 
  }

 }
   cout<<endl<<endl;
  
}

int place(int row,int column)
{
 int i;
 for(i=1;i<=row-1;++i)
 {
  
  if(board[i]==column)
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
 }
 
 return 1; 
}
 
void queen(int row,int n)
{
 int column;
 for(column=1;column<=n;++column)
 {
  if(place(row,column))
  {
   board[row]=column; 
   if(row==n) 
   {
    count++;
    print(n);
   }
   else 
    queen(row+1,n);
  }
 }
}
