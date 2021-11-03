#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iomanip>
#include <string.h>
#include <cstring> 


using namespace std;

int percentage;


  void PrintEnvironment (int** arrays, int width, int height){
    int row;
    int col;
    int times;
    int maximum = width * height;

    times = percentage * maximum;
    times = times /100;
    times = ceil(times);
    
    /*

    srand(time(NULL));  //Changed from rand(). srand() seeds rand for you.
    int random_width = rand() % (width-1) + 1;
    int random_height = rand() % (height-1) + 1;
    

    cout << "Times - " << times;
    cout << "random -  " << random_width << " " << random_height ;

    cout << "\n";
    
    */

    int random_width, random_height;
    
    cout << width<<endl;
    cout << height<<endl;
    cout << "maximum" << maximum<< endl;
    cout << "percentage" << percentage << endl;
    cout <<"times = "<< times<<endl;

    srand (time(NULL));

    while(times > 1){
      
      
      //Changed from rand(). srand() seeds rand for you.

      random_width = rand() % (width-1) + 1;
      random_height = rand() % (height-1) + 1;

   
      arrays[random_width][random_height] = -1;
      
      cout << "start"<< endl;

      cout <<"H " <<  random_height << endl;
      cout <<"W " <<  random_width << endl;
      
      cout << times;
      
      times = times -1;
      
    }

    cout << "\n" ;
    cout << "\n";

    for(row=0;row < width; row++){
      for (col = 0; col < height; col++){
	cout << setw(3);
	cout << arrays[row][col] << "   ";
	if(col == height -1 ){
	  
	  cout << "\n";
	}
      }
    }
  



    
  }





int main(int argc, char** argv){
  int x,y;
  

  cout << "Welcome to CSE240 WaveFront Pather" << endl;
  cout << "Please tell me about the grid you want to generate." << endl;
  cout << "Enter the height (at least 10):" << endl;
  cin >> x;
  cout << "Enter the width (at least 10):" << endl;
  cin >> y;
  cout << "" << endl;

  while(x < 10 && y < 10){
    cout<< "-------------------------------" << endl;
    cout << "Enter the width (at least 10):" << endl;
    cin >> x;
    cout << "Enter the height (at least 10):" << endl;
    cin >> y;
    cout << "" << endl;
}
  
  
  int** grid = new int*[x];  
  int i,j;
  
  char percentage_decission = 'n';

  for(i=0;i<x;i++){
    grid[i] = new int[y];
    for(j=0;j<y;j++){
      
      grid[i][j] = 0;
  
}
}


  for(i=0;i<x;i++){
    for(j=0;j<y;j++){
      
      cout << grid[i][j];
      if(j == y-1){
	cout << "\n";
}
    }
  }
  cout << "" << endl;

  while(percentage_decission == 'n'){
  cout << "Enter the percent of impassible terrain (0 – 100):" << endl;
  cin >> percentage;
  if(percentage > 55){
   cout << "Having a value greater than 40% might create poor results, do you with to continue? (y/n):" << endl;
   cin >> percentage_decission ;

  }else{
    percentage_decission = 'y';
  }}

   
  PrintEnvironment (grid,x,y);

  

  int goalX; 
  int goalY;

  cout << "Please enter the Goal Position X:";
  cin >> goalX;
  cout << "Please enter the Goal Position Y:";
  cin >> goalY;
  
  while( (goalX > x || goalY > y) ||  (goalX < 0 ||  goalY < 0) || (grid[goalX][goalY] == -1)  ){
    cout << "Sorry, that position is inside an obstacle" << endl;
    cout << "Please enter the Goal Position X:";
    cin >> goalX;
    cout << "Please enter the Goal Position Y:";
    cin >> goalY;

      }
  
  
  grid[goalX][goalY] = 1;
  
  cout << "New Array" << endl;

  
 
  char** matrix = new char*[x];

  for(i=0;i<x;i++){
    matrix[i] = new char[y];
    for(j=0;j<y;j++){
      matrix[i][j] = grid[i][j] ;
      if( grid[i][j]== -1 ){
	matrix[i][j] = '#' ;
      } 
      cout << setw(3);
      cout << matrix[i][j]<< "  ";
      if(j == y-1){
        cout << "\n";
      }
    }
  }

   matrix[goalX][goalY] = '$';

   int startX; 
   int startY;

   cout << "Please enter the Start Position X:";
   cin >> startX;
   cout << "Please enter the Start Position Y:";
   cin >> startY;
  
   while( (startX > x || startY > y) ||  (startX < 0 ||  startY < 0) || (matrix[startX][startY] == '$')  ){
     cout << "Sorry, that position is inside an obstacle" << endl;
     cout << "Please enter the Start Position X:";
     cin >> startX;
     cout << "Please enter the Start Position Y:";
     cin >> startY;

   }

   matrix[startX][startY] = '@';

   
   for(i=0;i<x;i++){
     for(j=0;j<y;j++){
       cout << setw(3);
       cout << matrix[i][j] << "  ";
  
       if(j == y-1){
	 cout << "\n";
       }
       }
   }

   cout << "Final ***********" << endl;

  
   cout << matrix[goalX][goalY] << endl;
   cout << matrix[startX][startY] << endl;

   cout << "Start " << startX << " " << startY;
   cout << "goal " << goalX << " " << goalY;



   while(startX != goalX || startY != goalY){

     
     if(startX < goalX && startY < goalY)
       {
	 if(matrix[startX+1][startY+1] == '#')
	   {
	     startX = startX + 1;
	      matrix[startX][startY] = '*'; 
	     cout << "Output : " << startX << " - " << startY << endl; 
	   }
	 else
	   {
	     startX = startX + 1;
	     startY = startY + 1;
	     matrix[startX][startY] = '*';
	     cout << "Output : " << startX << " - " << startY << endl; 
	   }
       }


     if(startX > goalX && startY > goalY)
       {
         if(matrix[startX-1][startY-1] == '#')
           {
             startX = startX - 1;
	     matrix[startX][startY] = '*';
             cout << "Output : " << startX << " - " << startY << endl; 
           }
         else
           {
             startX = startX - 1;
             startY = startY - 1;
	     matrix[startX][startY] = '*';
             cout << "Output : " << startX << " - " << startY << endl; 
           }
       }



     if(startX > goalX && startY < goalY)
       {
         if(matrix[startX-1][startY+1] == '#')
           {
             startY = startY + 1;
	     matrix[startX][startY] = '*';
             cout << "Output : " << startX << " - " << startY << endl; 
           }
         else
           {
             startX = startX - 1;
             startY = startY + 1;
	     matrix[startX][startY] = '*';
             cout << "Output : " << startX << " - " << startY << endl; 
           }
       }





     if(startX < goalX && startY > goalY)
       {
         if(matrix[startX+1][startY-1] == '#')
           {
             startX = startX - 1;
	     matrix[startX][startY] = '*';
             cout << "Output : " << startX << " - " << startY << endl; 
           }
         else
           {
             startX = startX + 1;
             startY = startY - 1;
	     matrix[startX][startY] = '*';
             cout << "Output : " << startX << " - " << startY << endl; 
           }
       }







     if(startX == goalX && startY <  goalY)
       {
         if(matrix[startX][startY+1] == '#')
           {
	     if(startX < x && startX > 0)
	       {
		 startX = startX - 1;
		 matrix[startX][startY] = '*';
		 cout << "Output : " << startX << " - " << startY << endl; 
	       }
           }
         else
           {
             startY = startY + 1;
	     matrix[startX][startY] = '*';
             cout << "Output : " << startX << " - " << startY << endl; 
           }
       }     


     if(startY == goalY && startX <  goalX)
       {
         if(matrix[startX][startY+1] == '#')
           {
             if(startY < y && startY > 0)
               {
                 startY = startY - 1;
		 matrix[startX][startY] = '*';
                 cout << "Output : " << startX << " - " << startY << endl; 
               }
           }
         else
           {
             startX = startX + 1;
	     matrix[startX][startY] = '*';
             cout << "Output : " << startX << " - " << startY << endl; 
           }
       }



     if(startY == goalY && startX > goalX)
       {
         if(matrix[startX-1][startY] == '#')
           {
             if(startY < y && startY > 0)
               {
                 startY = startY - 1;
		 matrix[startX][startY] = '*';
                 cout << "Output : " << startX << " - " << startY << endl; 
               }
           }
         else
           {
             startX = startX - 1;
	     matrix[startX][startY] = '*';
             cout << "Output : " << startX << " - " << startY << endl; 
           }
       }









   }


   matrix[goalX][goalY] = '$';


   for(i=0;i<x;i++){
     for(j=0;j<y;j++){
       cout << setw(4);
       cout << matrix[i][j] << "  ";

       if(j == y-1){
         cout << "\n";
       }
     }
   }




 




  return 0;

}
