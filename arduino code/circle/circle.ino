/*
This program controls the motion of the STEWART PLATFORM and contain its inverse kinematics 

*/

 
 
// includes the library that Provides an option to use servo motors
#include <Servo.h>

//ref_servo: defining sero's and the final name we will use to refer to our servos in physical structure
Servo ref_servo[6];

//servo_pin_num: an array storing pin number that we are going to assign to the servo mototrs
const int servo_pin_num[] = {3,5,6,9,10,11};

//servo_zero: not Extended position of each servo
const int servo_zero[6]={1000,1000,1000,1000,1000,1000};

/*
low_mpoints: co-ordinate of lower mounting points of ref_servo [x,y,z][ref_servo]
top_mpoints: co-ordinate of upper mounting points of ref_servo [x,y,z][ref_servo]
diff_low_up: diffrence in the co-ordinates of the lower and upper mounting point of ref_servo [dx,dy,dz][ref_servo]
dist_low_up: distance between upper and lower mounting points of the ref_servo [ref_servo distance]


*/
float low_mpoints[3][6], top_mpoints[3][6], diff_low_up[3][6], dist_low_up[6];

/*
    s_width_top: width of the shorter side on the upper base in meters
    l_width_top: width of the longer side on the upper base in meters
    s_width_bottom: width of the shorter side on the lower base in meters
    l_width_bottom: width of the longer side on the lower base in meters
    i_sep: initial sepration between the centers of the lower base and the upper base
    
*/
float s_width_top=0.020 , l_width_top=0.148 , i_sep=0.020, s_width_bottom=0.020, l_width_bottom=0.154;

//array storing the co-ordinates of the center points of the top base [x,y,z]
float top_center[3]={0.0,0.0,0.13};

// I don't know a shit about what this is :P
float a1[3]={radians(0),radians(0),radians(0)};

// contains the length of the legs returned by in inverseKinematics function
float servo_pos[6];

void setup(){
 Serial.begin(9600);
 
 /*
     Assigning co-ordinates of the lower/upper mounting points of servos 
     origin at the Geometrical center of the base plate 
 */
 /*
 //lower mounting points co-ordinate
 
 
  low_mpoints[0][0]=-l_width_bottom/2;                                           //ref_servo[1] lower mounting points co-ordinate
  low_mpoints[1][0]=-sqrt(3)*(l_width_bottom + 2*s_width_bottom )/2;
  low_mpoints[2][0]=0;
  
  low_mpoints[0][1]=-(l_width_bottom + s_width_bottom )/2;                       //ref_servo[2] lower mounting points co-ordinate
  low_mpoints[1][1]=-sqrt(3)*(l_width_bottom - s_width_bottom )/6;               //sir hai "-" sign in between them
  low_mpoints[2][1]=0;
  
  low_mpoints[0][2]=-s_width_bottom/2;                                           //ref_servo[3] lower mounting points co-ordinate
  low_mpoints[1][2]=sqrt(3)*(2*l_width_bottom + s_width_bottom)/6;
  low_mpoints[2][2]=0;
  
  low_mpoints[0][3]=s_width_bottom/2;                                            //ref_servo[4] lower mounting points co-ordinate
  low_mpoints[1][3]=sqrt(3)*(2*l_width_bottom + s_width_bottom)/6;
  low_mpoints[2][3]=0;
  
  low_mpoints[0][4]=(l_width_bottom + s_width_bottom )/2;                        //ref_servo[5] lower mounting points co-ordinate
  low_mpoints[1][4]=-sqrt(3)*(l_width_bottom - s_width_bottom )/6;               //sir hai "-" sign in between them
  low_mpoints[2][4]=0;
  
  low_mpoints[0][5]=l_width_bottom/2;                                            //ref_servo[6] lower mounting points co-ordinate
  low_mpoints[1][5]=-sqrt(3)*(l_width_bottom + 2*s_width_bottom )/2;
  low_mpoints[2][5]=0;
  
  
 
 //upper mounting points co-ordinate
 
 
  top_mpoints[0][0]=-s_width_top/2;                                             //ref_servo[1] top mounting points co-ordinate
  top_mpoints[1][0]= -sqrt(3)*(2*l_width_top + s_width_top)/6;
  low_mpoints[2][0]=0;
  
  top_mpoints[0][1]=-(l_width_top + s_width_top )/2;                            //ref_servo[2] top mounting points co-ordinate
  top_mpoints[1][1]=sqrt(3)*(l_width_top - s_width_top )/6;                     //sir hai "-" sign in between them
  low_mpoints[2][1]=0;
  
  top_mpoints[0][2]=-s_width_top/2;                                             //ref_servo[3] top mounting points co-ordinate
  top_mpoints[1][2]=sqrt(3)*(l_width_top + 2*s_width_top )/2;
  low_mpoints[2][2]=0;
  
  top_mpoints[0][3]=s_width_top/2;                                             //ref_servo[4] top mounting points co-ordinate
  top_mpoints[1][3]=sqrt(3)*(l_width_top + 2*s_width_top )/2;
  low_mpoints[2][3]=0;
  
  top_mpoints[0][4]=(l_width_top + s_width_top )/2;                            //ref_servo[5] top mounting points co-ordinate
  top_mpoints[1][4]=sqrt(3)*(l_width_top - s_width_top )/6;                    //sir hai "-" sign in between them
  low_mpoints[2][4]=0;
  
  top_mpoints[0][5]=s_width_top/2;                                            //ref_servo[6] top mounting points co-ordinate
  top_mpoints[1][5]=-sqrt(3)*(2*l_width_top + s_width_top)/6;
  low_mpoints[2][5]=0;
  */
 low_mpoints[0][0] = -l_width_bottom/2;
 low_mpoints[1][0] = -sqrt(3)*(l_width_bottom+2*s_width_bottom)/6;
 low_mpoints[2][0] = 0;
 
 low_mpoints[0][1] = -l_width_bottom/2-s_width_bottom/2;
 low_mpoints[1][1] = -sqrt(3)*(l_width_bottom-s_width_bottom)/6;
 low_mpoints[2][1] = 0;
 
 low_mpoints[0][2] = -s_width_bottom/2;
 low_mpoints[1][2] = sqrt(3)*(2*l_width_bottom+s_width_bottom)/6;
 low_mpoints[2][2] = 0;
 
 low_mpoints[0][3] = s_width_bottom/2;
 low_mpoints[1][3] = sqrt(3)*(2*l_width_bottom+s_width_bottom)/6;
 low_mpoints[2][3] = 0;
 
 low_mpoints[0][4] = l_width_bottom/2+s_width_bottom/2;
 low_mpoints[1][4] = -sqrt(3)*(l_width_bottom-s_width_bottom)/6;
 low_mpoints[2][4] = 0;
 
 low_mpoints[0][5] = l_width_bottom/2;
 low_mpoints[1][5] = -sqrt(3)*(l_width_bottom+2*s_width_bottom)/6;
 low_mpoints[2][5] = 0;
 
 
 
   
  
 top_mpoints[0][0] = -s_width_top/2;
 top_mpoints[1][0] = -sqrt(3)*(2*l_width_top+s_width_top)/6;
 top_mpoints[2][0] = 0;
 
 top_mpoints[0][1] = -l_width_top/2-s_width_top/2;
 top_mpoints[1][1] = sqrt(3)*(l_width_top-s_width_top)/6;
 top_mpoints[2][1] = 0;
 
 top_mpoints[0][2] = -l_width_top/2;
 top_mpoints[1][2] = sqrt(3)*(l_width_top+2*s_width_top)/6;
 top_mpoints[2][2] = 0;
 
 top_mpoints[0][3] = l_width_top/2;
 top_mpoints[1][3] = sqrt(3)*(l_width_top+2*s_width_top)/6;
 top_mpoints[2][3] = 0;
 
 top_mpoints[0][4] = l_width_top/2+s_width_top/2;
 top_mpoints[1][4] = sqrt(3)*(l_width_top-s_width_top)/6;
 top_mpoints[2][4] = 0;
 
 top_mpoints[0][5] = s_width_top/2;
 top_mpoints[1][5] = -sqrt(3)*(2*l_width_top+s_width_top)/6;
 top_mpoints[2][5] = 0;
 
 /* this loop attaches our physical servos with the specific digital pins in arduino uno board
     attach ref_servo[i] to servo_pin_num[i]  servo 1 -> pin 6
     servo 1 -> pin 6
     servo 2 -> pin 7
     servo 3 -> pin 8
     servo 4 -> pin 9
     servo 5 -> pin 10
     servo 6 -> pin 11
 */
   for(int i=0;i<6;i++){
     ref_servo[i].attach(servo_pin_num[i]);
   }
   
   setBack();                                                                   //calling function setBack to get it to the no extended state 
  
}

  
  /*
  
  */

   
    void loop(){
      
      /*
      this code is for circular trajectory of center
      */
      /*
       float r= 0.04  ;                              //radius of the circle
       
      for(int i=0;i<20;i++){                              //takes the center at (r,0,0.12)
        top_center[0]=r*i/20;
        
        inverseKinematics();
          
           for(int i = 0; i < 6; i++){
             ref_servo[i].writeMicroseconds(servo_pos[i]); 
            } 
            delay(200); 
      }
       */ 
        
      for(int i=0;i<360;i+=4){
         
          top_center[0]=0;//r*cos(i*3.14159/180);                 //x-coordinate of the center
          top_center[1]=0;//r*sin(i*3.14159/180);                //y-coordinate of the center
          top_center[2]=0.13;                            //z-coordinate of the center
          a1[0]=0;
          a1[1]=0;
          a1[2]=0;
          
          inverseKinematics();
          
           for(int i = 0; i < 6; i++){
             ref_servo[i].writeMicroseconds(servo_pos[i]); 
            } 
            delay(200); 
    
      } 
          setBack();
    }
   

/*
This function takes all the servo's back to the initial stage 
i.e a state in which none of the arms is extended  
*/
  void setBack(){
    for(int i=0;i<6;i++){                                    // This loop set's servo's back to not extended position
      ref_servo[i].writeMicroseconds(servo_zero[i]);
    }
    delay(4000);                                         //Gives servos time to get back to initial stage
  }


   
   
   // Not written by me , Idon't know shit about this, just modified it to work with my code
   
   void inverseKinematics()
{
float rx1[3][3], ry1[3][3],rz1[3][3];
//Rotation Matrices
rx1[0][0]=1;
rx1[0][1]=0;
rx1[0][2]=0;
rx1[1][0]=0;
rx1[1][1]= cos(a1[0]);
rx1[1][2]= -sin(a1[0]);
rx1[2][0]=0;
rx1[2][1]= sin(a1[0]);
rx1[2][2]= cos(a1[0]);



ry1[0][0]=cos(a1[1]);
ry1[0][1]= 0;
ry1[0][2]=sin(a1[1]);
ry1[1][0]=0;
ry1[1][1]=1;
ry1[1][2]=0;
ry1[2][0]= -sin(a1[1]);
ry1[2][1]=0;
ry1[2][2]= cos(a1[1]);



rz1[0][0]=cos(a1[2]);
rz1[0][1]=-sin(a1[2]);
rz1[0][2]=0;
rz1[1][0]=sin(a1[2]);
rz1[1][1]= cos(a1[2]);
rz1[1][2]=0;
rz1[2][0]=0;
rz1[2][1]=0;
rz1[2][2]=1;

float r1[3][3],ri1[3][3];

int i=0;
int j=0;
int k=0;
for(i=0;i<3;i++)
{for (j=0;j<3;j++)
ri1[i][j]=0;
}

for(i=0;i<3;i++)
{for (j=0;j<3;j++)
{for(k=0;k<3;k++)
{ ri1[i][j]+=ry1[i][k]*rx1[k][j];
}}}


i=0;
j=0;
k=0;

for(i=0;i<3;i++)
{for (j=0;j<3;j++)
r1[i][j]=0;
}
for(i=0;i<3;i++)
{for (j=0;j<3;j++)
{for(k=0;k<3;k++)
 {r1[i][j]+=rz1[i][k]*ri1[k][j];
}}}
/*
Serial.print(r1[0][0]);
Serial.print(r1[0][1]);
Serial.print(r1[0][2]);
Serial.print(r1[1][0]);
Serial.print(r1[1][1]);
Serial.print(r1[1][2]);
Serial.print(r1[2][0]);
Serial.print(r1[2][1]);
Serial.print(r1[2][2]);
*/
//reference frame
float ppf[3][6];
i=0;
j=0;
k=0;
for(i=0;i<3;i++)
{for (j=0;j<6;j++)
ppf[i][j]=0;
}

for(i=0;i<3;i++)
{for (j=0;j<6;j++)
{for(k=0;k<3;k++)
{ppf[i][j]+=r1[i][k]*top_mpoints[k][j];
}}
}

for(i=0;i<3;i++)
{for (j=0;j<6;j++)
 ppf[i][j]=ppf[i][j]+top_center[i];
 // Serial.print(top_center[i]);
  // Serial.print("  *  ");
}
 
for(int i = 0; i < 6; i++)
 {
 diff_low_up[0][i] = low_mpoints[0][i] - ppf[0][i];
 diff_low_up[1][i] = low_mpoints[1][i] - ppf[1][i];
 diff_low_up[2][i] = low_mpoints[2][i] - ppf[2][i];
 dist_low_up[i] = sqrt(diff_low_up[0][i]*diff_low_up[0][i] + diff_low_up[1][i]*diff_low_up[1][i] + diff_low_up[2][i]*diff_low_up[2][i]) ;
 servo_pos[i] =  1000 + ((dist_low_up[i]-0.130)/(0.184-0.130)) * ( 2000 - 1000 ) ;
Serial.print(servo_pos[i]);
 Serial.print("  * ");
 }
 Serial.print("\n");
 
}  
  
 
  

