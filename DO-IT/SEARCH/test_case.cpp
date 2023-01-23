#include <iostream>

using namespace std;

int main(int argc, char ** argv){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    FILE *fp; char c = 0;
    time_t t;
    int N, M;
    srand((unsigned) time(&t));
    
    fp = fopen(argv[1], "w");
    if(!fp){
      fprintf(stderr, "open error!\n");
      exit(1);
    }
    N = 500, M = 500;
    fprintf(fp, "%d %d\n", N, M);
    fprintf(fp, "0");
    for(int i = 0; i < N * M - 2; i++){
      int k = rand() % 100;
      if(k >= 30) k = 0;
      else k = 1;
      fprintf(fp, "%d", k);
    }
    fprintf(fp, "0\n");
    

    fclose(fp);
    return 0;
}
