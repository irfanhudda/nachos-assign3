#include "syscall.h"

int
main()
{
  int x;
  
  PrintString("Parent PID: ");
  PrintInt(GetPID());
  PrintChar('\n');
  int *shm = (int *)ShmAllocate(3*sizeof(int)); 
  PrintString("Parent PID: ");
  PrintInt(GetPID());
  PrintChar('\n');
  //int shm[3];
  shm[0] = 1000;
  shm[1] = 100000;
  shm[2] = 1;
  int i;
  for(i = 0; i < 10; i++)
    {
      x = Fork();
      if (x == 0) 
        {
          shm[0] += 1;
          shm[1] += 2;
          shm[2] += 3;
          PrintString("shm[0] : ");
          PrintInt(shm[0]);
          PrintChar('\n');
          PrintString("shm[1] : ");
          PrintInt(shm[1]);
          PrintChar('\n');
          PrintString("shm[2] : ");
          PrintInt(shm[2]);
          PrintChar('\n');
          return 0;
        }
    } 
  {
    Join(x);
      
    PrintString("shm[0] : ");
    PrintInt(shm[0]);
    PrintChar('\n');
    PrintString("shm[1] : ");
    PrintInt(shm[1]);
    PrintChar('\n');
    PrintString("shm[2] : ");
    PrintInt(shm[2]);
    PrintChar('\n');
    shm[0] += 1;
    
    PrintString("shm[0] : ");
    PrintInt(shm[0]);
    PrintChar('\n');
    PrintString("shm[1] : ");
    PrintInt(shm[1]);
    PrintChar('\n');
    PrintString("shm[2] : ");
    PrintInt(shm[2]);
    PrintChar('\n');
    PrintString("Parent after fork waiting for child: ");
    PrintInt(x);
    PrintChar('\n');
  }
  return 0;
}
