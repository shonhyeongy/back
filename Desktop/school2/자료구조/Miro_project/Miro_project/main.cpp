//
//  main.cpp
//  Miro_project
//
//  Created by 손현기 on 2018. 3. 27..
//  Copyright © 2018년 손현기. All rights reserved.
//

#include <iostream>
#define right = 6;

class stack{
  
private:
    int data [255] ;
    int top = 0;
public:
    void push(int mdata){
        data[top++] = mdata ;
    }
    int pop(){
        int a = top-1;
        top--;
        return data[a];
    }
    int top_f(){
        return data[top-1];
    }
    int getter(){
        return top-1;
    }
};

class maze{
private:
    int maze[12][15]= {{0 ,1 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1},
        {1,0,0,0,1,1,0,1,1,1,0,0,1,1,1},
        {0,0,1,0,0,0,0,1,1,1,1,0,0,1,1},
        {1,1,0,1,1,1,1,0,1,1,0,1,1,0,0},
        {1,1,0,1,0,0,1,0,1,1,1,1,1,1,1},
        {0,0,1,1,0,1,1,1,0,1,0,0,1,0,1},
        {0,0,1,1,0,1,1,1,0,1,0,0,1,0,1},
        {0,1,1,1,1,0,0,1,1,1,1,1,1,1,1},
        {0,0,1,1,0,1,1,0,1,1,1,1,1,0,1},
        {1,1,0,0,0,1,1,0,1,1,0,0,0,0,0},
        {0,0,1,1,1,1,1,0,0,0,1,1,1,1,0},
        {0,1,0,0,1,1,1,1,1,0,1,1,1,1,0 }
    };
    int check_point[12][15] ={{0 ,1 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1},
        {1,0,0,0,1,1,0,1,1,1,0,0,1,1,1},
        {0,0,1,0,0,0,0,1,1,1,1,0,0,1,1},
        {1,1,0,1,1,1,1,0,1,1,0,1,1,0,0},
        {1,1,0,1,0,0,1,0,1,1,1,1,1,1,1},
        {0,0,1,1,0,1,1,1,0,1,0,0,1,0,1},
        {0,0,1,1,0,1,1,1,0,1,0,0,1,0,1},
        {0,1,1,1,1,0,0,1,1,1,1,1,1,1,1},
        {0,0,1,1,0,1,1,0,1,1,1,1,1,0,1},
        {1,1,0,0,0,1,1,0,1,1,0,0,0,0,0},
        {0,0,1,1,1,1,1,0,0,0,1,1,1,1,0},
        {0,1,0,0,1,1,1,1,1,0,1,1,1,1,0 }
    };
    
    int finish_v = 11;
    int finish_h = 14;
    int dir [16] = {0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7};
    int move_vert [8] = {0,1,1,1,0,-1,-1,-1};    //left
    int move_horiz [8] = {1,1,0,-1,-1,-1,0,1};    // right
   
public:
    void maze_out();
};

void maze::maze_out(){
    
    stack s;
    int n_l = 0;
    int n_r = 0;
    int direction = 0;
    int check_direction ;
    int back_dir=0;
    
    int n =0;
    int new_nl;
    int new_nr;
    while (1) {
        check_direction =0;
        check_point[n_l][n_r] = 2;
        printf("%d \t %d\n",n_l,n_r);
        if (n_l==finish_v && n_r==finish_h) {
            printf("Finished!!!\n");
            break;
        }
        for (int i = 0 ; i<8; i++) {
            direction = dir[i];
            new_nl = n_l+move_vert[direction];
            new_nr = n_r+move_horiz[direction];
            if (new_nl <0 || new_nl>11 || new_nr <0 || new_nr>14) {
                continue;
            }
            
                if (maze[new_nl][new_nr]==0
                    && check_point[new_nl][new_nr] !=2) {
                    n_l = new_nl;
                    n_r = new_nr;
                    s.push(i);
                    check_direction = 1;
                    break;
                }
        }
        if (check_direction==0) {
            back_dir = s.pop();
            n_l = n_l+move_vert[dir[back_dir+4]];
            n_r = n_r+move_horiz[dir[back_dir+4]];
        }
        n++;
    }
}

int main(int argc, const char * argv[]) {
    
   
    int mark[12][15]={{0 ,1 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1},
        {1,0,0,0,1,1,0,1,1,1,0,0,1,1,1},
        {0,0,1,0,0,0,0,1,1,1,1,0,0,1,1},
        {1,1,0,1,1,1,1,0,1,1,0,1,1,0,0},
        {1,1,0,1,0,0,1,0,1,1,1,1,1,1,1},
        {0,0,1,1,0,1,1,1,0,1,0,0,1,0,1},
        {0,0,1,1,0,1,1,1,0,1,0,0,1,0,1},
        {0,1,1,1,1,0,0,1,1,1,1,1,1,1,1},
        {0,0,1,1,0,1,1,0,1,1,1,1,1,0,1},
        {1,1,0,0,0,1,1,0,1,1,0,0,0,0,0},
        {0,0,1,1,1,1,1,0,0,0,1,1,1,1,0},
        {0,1,0,0,1,1,1,1,1,0,1,1,1,1,0 }
    };
    for (int i=0; i<12; i++) {
        for(int i2=0; i2<15; i2++){
            printf("%d",mark[i][i2]);
        }
        printf("\n");
    }
    
    
    maze m ;
    m.maze_out();
    
    
    
    
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}
