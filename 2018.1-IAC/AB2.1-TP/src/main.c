#include <unistd.h>
#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main (int argc, char *argv[], char *envp[]) {
int pid ; /* Process ID */
char mem_usage[50];
char cpu_usage[50];
char kill[50];
clock_t t1,t0;
double td = 0;
pid = fork () ; /* Process reaplication */
sprintf(cpu_usage,"%s%d%s","ps -p ", pid, " -o %cpu | grep -v %CPU");
sprintf(mem_usage, "%s%d%s", "pmap -x ", pid," | grep total | awk '{print $3}'");
sprintf(kill, "%s%d", "kill -9 ", pid);

if ( pid < 0 ) { /*if fork do not work*/
  perror ("Erro: ") ;
  exit (-1) ; /* Ends process with error: -1 */
}
else if( pid > 0 ) /* If i'm parent process*/
{
  for(int i=0;i<10;i++)
  {
    system("clear");
    if(i == 0 || i == 3 || i == 6 || i == 9)
    {
    printf("Processing.\n");
    }
    else if(i == 1 || i == 4 || i == 7)
    {
      printf("Processing..\n");
    }
    else if(i == 2 || i == 5 || i == 8)
    {
      printf("Processing...\n");
    }
    printf("Process ID: %d\n", pid);
    printf("%ds\n", i+1);
    printf("================\n");
    printf("CPU(%%)\n");
    system(cpu_usage);
    printf("MEM(kB)\n");
    system(mem_usage);
    sleep(1);
  }
  system(kill);
}
else /* else, i'm a child process (pid == 0) */
{
  if(strcmp(argv[1],"ucp")==0) /* if argv[1] = ucp -> Execute code using intese cpu*/
  {
    for(;;){}
  }
  if(strcmp(argv[1],"ucp-mem")==0) /* if argv[1] = ucp-mem -> Execute code using intese cpu and memory */
  {
    t0 = clock();
    for (;;) {
      t1 = clock();
     td = (double)(t1 - t0) / CLOCKS_PER_SEC;
      if (td <= 10.0000){
          malloc(15*sizeof(int));
        }
}
  }

}
perror ("Erro: ") ; /* if do not work */

printf ("Tchau !\n") ;
exit(0) ; /* Ends process with success (código 0) */

}
