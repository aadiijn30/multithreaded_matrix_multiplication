#include<iostream>
#include<vector>
#include<chrono>
#include<thread>
using namespace std;

//MATRIX MULTIPLICATION

void matrix_multiplication(int x_rows,int x_columns,int y_rows,int y_columns,vector<int>&x,vector<int>&y,vector<int>&z,int start,int end)
{ 
  for(int r=start;r<end;++r)
  {
    for(int c=0;c<x_columns;++c)
    {
      for(int c1=0;c1<y_columns;++c1)
      {
        z[r*y_columns+c1]+=(x[r*x_columns+c])*(y[c*y_columns+c1]);
      }
    }
  }
}


int main()
{
#define x_rows 4000
#define x_columns 4100
#define y_rows 4100
#define y_columns 5000
vector<int>x(x_rows*x_columns);
vector<int>y(y_rows*y_columns);
vector<int>z(x_rows*y_columns,0);
vector<thread>t;
auto cores=thread::hardware_concurrency();
int value=1;
for(auto &t:x) t=value++;
value=10;
for(auto &t:y) t=value++;
int r,c,c1;
auto start=chrono::high_resolution_clock::now();

//THREAD CREATION

int batch_size=0;
if(x_rows%cores!=0){batch_size=(x_rows/cores)+1;}
else batch_size=(x_rows/cores);
int s=0,e;
for(int i=0;i<cores;i++)
{
  e=s+batch_size;
  if(e>x_rows) e=x_rows;
  t.push_back(thread(matrix_multiplication,x_rows,x_columns,y_rows,y_columns,ref(x),ref(y),ref(z),s,e));
  s+=batch_size;
}
for(auto &it:t) it.join();

auto end=chrono::high_resolution_clock::now();
auto diff=end-start;
cout<<"Took "<<chrono::duration_cast<chrono::seconds>(diff).count()<<" seconds"<<endl;
return 0;
}
