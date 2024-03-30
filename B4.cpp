//Transformations
#include <iostream>
#include <graphics.h>
using namespace std;

class Transformations {
    public:
        float A[3][3], B[3][3], C[3][3];
        int x1, y1, x2, y2;
        float x3, y3, angle;
        
        void triangle() {
            cout << "Enter x and y co-ordinates of two points." << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            
            angle = 60*M_PI/180; //Convert 60 degrees angle into radian
            x3 = x1+(x2-x1)*cos(angle)+(y2-y1)*sin(angle);
            y3 = y1-(x2-x1)*sin(angle)+(y2-y1)*cos(angle);
            
            B[0][0] = x1;
            B[0][1] = x2;
            B[0][2] = x3;
            B[1][0] = y1;
            B[1][1] = y2;
            B[1][2] = y3;
            B[2][0] = B[2][1] = B[2][2] = 1; 
            
            /*cout << "Matrix B : " << endl;
            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    cout << B[i][j] << " ";
                }
                cout << endl;
            }*/
            
            //To display the equilateral triangle
            line(B[0][0], B[1][0], B[0][1], B[1][1]);
            line(B[0][1], B[1][1], B[0][2], B[1][2]);
            line(B[0][2], B[1][2], B[0][0], B[1][0]);
        }
        
        float multiplication(float A[3][3], float B[3][3]){
            //To initialise Matrix C
            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    C[i][j] = 0;
                }
            }
                
            //Multiplication
            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    for(int k=0; k<3; k++) {
                        C[i][j] += A[i][k]*B[k][j];
                    }
                }
            }
            return C[3][3];
       }
       
       void translate() {
            float tx, ty;
            cout << "Enter translation factor x and y." << endl;
            cin >> tx >> ty;
            
            A[0][0] = A[1][1] = A[2][2] = 1;
            A[0][2] = tx;
            A[1][2] = ty;
            A[0][1] = A[1][0] = A[2][0] = A[2][1] = 0;
            
            //To display Matrix A
            /*cout << "Matrix A : " << endl;
            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }*/
            
            multiplication(A, B);
            
            //To display Translated Matrix C
            /*cout << "Matrix C : " << endl;
            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    cout << C[i][j] << " ";
                }
                cout << endl;
            }*/
            
            //To display the translated equilateral triangle
            setcolor(BLUE);
            line(C[0][0], C[1][0], C[0][1], C[1][1]);
            line(C[0][1], C[1][1], C[0][2], C[1][2]);
            line(C[0][2], C[1][2], C[0][0], C[1][0]);
      }     
      
      void scale() {
            float sx, sy;
            cout << "Enter scaling factor x and y." << endl;
            cin >> sx >> sy;
            
            A[0][0] = sx;
            A[1][1] = sy;
            A[2][2] = 1;
            A[0][1] = A[0][2] = A[1][0] = A[1][2] = A[2][0] = A[2][1] = 0;
            
            multiplication(A, B);
            
            setcolor(RED);
            line(C[0][0], C[1][0], C[0][1], C[1][1]);
            line(C[0][1], C[1][1], C[0][2], C[1][2]);
            line(C[0][2], C[1][2], C[0][0], C[1][0]);
      }   
      
      void rotate1() {
            float r_angle, angle1;
            cout << "Enter angle to rotate the figure." << endl;
            cin >> r_angle;
            
            angle1 = r_angle*M_PI/180;
            
            //clockwise rotation matrix : gives anticlockwise rotation on screen
            A[0][0] = cos(angle1);
            A[0][1] = sin(angle1);
            A[1][0] = -sin(angle1);
            A[1][1] = cos(angle1);
            A[2][2] = 1;
            A[0][2] = A[1][2] = A[2][0] = A[2][1] = 0;
            
            /*cout << "Matrix A : " << endl;
            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }*/
            
            multiplication(A, B);
            
            setcolor(GREEN);
            line(C[0][0], C[1][0], C[0][1], C[1][1]);
            line(C[0][1], C[1][1], C[0][2], C[1][2]);
            line(C[0][2], C[1][2], C[0][0], C[1][0]);
     }
     
     void rotate2() {
            float r_angle, angle1;
            cout << "Enter angle to rotate the figure." << endl;
            cin >> r_angle;
            
            angle1 = r_angle*M_PI/180;
            
            //anticlockwise rotation matrix : gives clockwise rotation on screen
            A[0][0] = cos(angle1);
            A[0][1] = -sin(angle1);
            A[1][0] = sin(angle1);
            A[1][1] = cos(angle1);
            A[2][2] = 1;
            A[0][2] = A[1][2] = A[2][0] = A[2][1] = 0;
            
            multiplication(A, B);
            
            setcolor(GREEN);
            line(C[0][0], C[1][0], C[0][1], C[1][1]);
            line(C[0][1], C[1][1], C[0][2], C[1][2]);
            line(C[0][2], C[1][2], C[0][0], C[1][0]);
     }
};
            

int main() {
     int gd = DETECT, gm;
     initgraph(&gd, &gm, NULL);
     
     Transformations ob;
     ob.triangle();
     //ob.translate();
     //ob.scale();
     //ob.rotate();
     
     cout << "\n\nMENU TO PERFORM TRANSFORMATIONS:\n" << endl;
     cout << "1. Translation" << endl;
     cout << "2. Scaling" << endl;
     cout << "3. Rotation" << endl;
     cout << "\nEND\n\n";
     
     int ch, a;
     
     a = 1;
     while(a==1) {
        cout << "Enter your choice." << endl;
        cin >> ch;
        
        switch(ch) {
                case 1:
                    ob.translate();
                    break;
                case 2:
                    ob.scale();
                    break;
                case 3:
                    int n;
                    cout << "Enter 1 for anticlockwise rotation and 2 for clockwise rotation." << endl;
                    cin >> n;
                    
                    if(n==1) {
                        ob.rotate1();
                    }
                    else if(n==2) {
                        ob.rotate2();
                    }
                    else {
                        cout << "Invalid choice." << endl;
                    }
                    break;
                default:
                    cout << "Invalid choice." << endl;   
                    break;
        } 
        
        string ans;
        cout << "Do you want to perform more operations? (enter yes/no)" << endl;
        cin >> ans;   
        
        if(ans=="yes") {
            a = 1;
        }
        else {
            a = 0;
            cout << "Thank you!";    
        }
    }
                          
     delay(15000);
     closegraph();
     return 0;
} 
