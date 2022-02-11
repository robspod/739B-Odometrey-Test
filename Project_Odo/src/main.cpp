/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    7, 16, 9, 10, 20
// lift2                motor         15              
// lift1                motor         17              
// claw                 motor         18              
// tray2                motor         12              
// RangeFinder          sonar         G, H            
// Encoderleft          encoder       A, B            
// Encoderright         encoder       C, D            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Controls.cpp"
//#include "Odo.cpp"
using namespace vex;


competition Competition;


/*
void task1(void){

  long double pi = 3.14159265358979353;  
  long double circum = pi * 2.75;
  long double Tl = 3.8125;
  long double Tr = -3.8125;
  long double Ts = 0.123;
  long double leftss = Encoderleft.value(); 
  long double rightss = Encoderright.value();
  //Formula
  long double dege = circum / 360 ;
  long double leftdis = leftss * dege;
  long double rightdis = rightss * dege;
  long double pheta = ((leftdis) - (rightdis))/(Tl+Tr)+0.01;
  long double y = 2 * (((rightdis)/pheta)+Tr) * (sin(pheta/2)); 
 // long double x = 2 * (((Encoderback.position(degrees))/pheta)+Ts) * (sin(pheta/2));



};
*/

void pre_auton(void) {
  vexcodeInit();// <-- don't touch
  // put stuff in here is you want it to be run right as soon as the bot is turned on 
  lifthold();
  Rotation18.resetPosition();
  Controller1.Screen.clearScreen();
}



void autonomous(void) {
}





void usercontrol(void) {
  
  


  // drive train speed
  Drivetrain.setDriveVelocity(100, percent); 
  while (1) {
    long double pi = 3.14159265358979353;  
    long double circum = pi * 2.75;
    long double Tl = 3.8125;
    long double Tr = 3.8125;
    long double Ts = 3.75;
    long double leftss = Encoderleft.value()*1.5; 
    long double rightss = Encoderright.value();
  //Formula
    long double dege = circum / 360 ;
    long double leftdis = leftss * dege;
    long double rightdis = rightss * dege;
    long double pheta = ((leftdis +0.00001) - (rightdis))/((Tl+Tr));
    long double y = 2 * (((rightdis)/pheta)+Tr) * (sin(pheta/2)); 
    long double x = 2 * (((Rotation18.position(degrees))/pheta)+Ts) * (sin(pheta/2));
    long double D = sqrt(((y*y)+(x*x)));

    // printing where we are on the field y position 
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print(Encoderleft.value()*2);
    Controller1.Screen.setCursor(1,10);
    Controller1.Screen.print(Encoderright.value());
    Controller1.Screen.setCursor(2,1);
    Controller1.Screen.print(Rotation18.position(degrees) );
    Controller1.Screen.setCursor(3,1);
    Controller1.Screen.print(D);
   
  
    

    //tray button control
    Controller1.ButtonL1.pressed(trayup);
    Controller1.ButtonL2.pressed(traydown);
    Controller1.ButtonL1.released(trayhold);
    Controller1.ButtonL2.released(trayhold);


    //lift button control
    Controller1.ButtonR1.pressed(liftup);
    Controller1.ButtonR2.pressed(liftdown);
    Controller1.ButtonR1.released(lifthold);
    Controller1.ButtonR2.released(lifthold);


    //claw button control
    Controller1.ButtonY.pressed(clawopen);
    Controller1.ButtonA.pressed(clawclose);;
    Controller1.ButtonA.released(clawwstop);




    // some sort of resorse management time thing so leave it alone
    wait(20, msec); // <---  don't touch
    //  ^
    //  |  leave alone
  }
}

// DO NOT TOUCH YOU NEVER NEED TO TOUCH THIS NEVER
int main() {
  //thread_local task(task1);
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  // HANDS OFF DO NOT TOUCH
  
  pre_auton();
  // I SAID HANDS OFF
  
  while (true) {
    wait(100, msec);
  }
}

