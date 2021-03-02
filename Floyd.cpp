int floyd[100][100][100];
void Floyd(){
   for(int k = 1; k <= n; k++)
       for(int i = 1; i <= n; i++)
           for(int j = 1; j <= n; j++)
               floyd[i][j] = min( floyd[i][k] + floyd[k][j],floyd[i][j] );
    return;
}
void process(){
   for(int i = 0; i <= 200; i++) {
       for(int j = 0; j <= 200; j++) {
           if( i == j ) floyd[i][j] = 0;
           else floyd[i][j] = 1000000000;
		// set to size bigger than the biggest cost
       }
   }
   return;
}
