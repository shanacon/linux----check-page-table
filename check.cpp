#include<syscall.h>
#include<sys/types.h>
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
int main()
{
  unsigned long addr ;
  cin>>hex>>addr;
  syscall(360,addr);
}
