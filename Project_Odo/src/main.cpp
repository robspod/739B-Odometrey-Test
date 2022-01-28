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
//#include "math.h"
using namespace vex;


competition Competition;

//postioning systum 
//Constens

double circum = 3.1415926535 * 2.75;
double Tl = 9.5625;
double Tr = 9.5625;
double Ts = 0.123;

//Formula

double dege = circum / 360;
double leftdis = Encoderleft.position(degrees) * dege;
double rightdis = Encoderright.position(degrees) * dege;
double pheta = (leftdis-rightdis)/(Tl+Tr) ;
//double y = 2 * ((rightdis/pheta)+Tr) * (sin(pheta/2)); 
//double x = 2 * ((Encoderback.position(degrees)/pheta)+Ts) * (sin(pheta/2)); 

//auton
/*
void forwardin(double mats){
 double length = mats * matlength;
 double dege = (length / circum) * 360;
 Left.rotateFor(dege,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct,false);
 Right.rotateFor(dege,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct); 
 Right.stop(vex::brakeType::brake);
 Left.stop(vex::brakeType::brake);
 Controller1.Screen.clearScreen();
 Controller1.rumble("--");
 Controller1.Screen.print("Calculation complete");

}
void backin(double mats){
 double length = mats * matlength;
 double dege = length / circum;
 double deges = dege * -360;
 
 Left.rotateFor(deges,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct,false); 
 Right.rotateFor(deges,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct); 
 Right.stop(vex::brakeType::brake);
 Left.stop(vex::brakeType::brake);
}
void turnright(int degs){
Left.rotateFor(degs,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct,false); 
Right.rotateFor(-degs,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct); 
  
    
}
void turnleft(int degs){
Left.rotateFor(-degs,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct,false); 
Right.rotateFor(degs,vex::rotationUnits::deg,speedfor,vex::velocityUnits::pct); 

*/


//lift controls
void liftdown(){
  lift1.setVelocity(100, percent); 
  lift2.setVelocity(100, percent); 
  lift1.spin(reverse); 
  lift2.spin(reverse); 
}
  void liftup(){
  lift1.setVelocity(100, percent); 
  lift2.setVelocity(100, percent); 
  lift1.spin(forward);
  lift2.spin(forward); 
}
void lifthold(){
  lift1.stop(hold);
  lift2.stop(hold);
}
//claw controls
void clawtoggle(){
  claw.spinFor(forward, 45, degrees); 
}
void clawopen(){
  claw.spinFor(forward, 45, degrees);
  wait(0.6, sec);
  claw.spinFor(forward, 45, degrees);
}
void clawclose(){
  claw.spin(forward);
}
void clawwstop(){
  claw.stop(hold);
}
//tray controls
void trayup(){
  tray2.setVelocity(100, percent);
  tray2.spin(forward);
}
void traydown(){
  tray2.setVelocity(100, percent);
  tray2.spin(reverse);
}
void trayup50(){
  tray2.setVelocity(50, percent);
  tray2.spin(forward);
}
void traydown50(){
  tray2.setVelocity(50, percent); 
  tray2.spin(reverse);
}
void trayhold(){
  tray2.stop(hold);
}
void traystop(){
  tray2.stop(brake);
}



// Atoun drive control
void move(int ins){
Drivetrain.driveFor(forward, ins, inches); 
Controller1.Screen.clearScreen();
Controller1.Screen.print(RangeFinder.distance(inches));
if(RangeFinder.distance(inches) <= 4){
  Drivetrain.stop();
}
}

// atuon turn controls
void rights(int degs){
  Drivetrain.turnFor(right,degs, degrees); 
}
void lefts(int degs){
  Drivetrain.turnFor(left, degs, degrees); 
}



void pre_auton(void) {
  vexcodeInit();// <-- don't touch
  // put stuff in here is you want it to be run right as soon as the bot is turned on 
  lifthold();



/*  int choice = 0;
 Brain.Screen.setFont(propXXL); 
 //Brain.Screen.printAt(int32_t x, int32_t y, bool bOpaque, )
 
 
 
  // variables of where on screen stuff is
  int aa = 100;
  int bb = 1;
  int cc = 240;
  int dd = 1;
  int ee = 390;
  int ff = 1;
  // clear and print them
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(black);
  Brain.Screen.setPenColor( red );
  Brain.Screen.setPenWidth(10); 
  Brain.Screen.drawRectangle(5,5,465,220);
  Brain.Screen.setFillColor(yellow);
  Brain.Screen.drawCircle(100, 1, 30); 
  Brain.Screen.drawCircle(240, 1, 30);
  Brain.Screen.drawCircle(390, 1, 30);
 
    // Touch control
  while(choice < 1){
    //circle one
    if (Controller1.ButtonX.pressing()){
     choice += 10; }
    if(Brain.Screen.pressing() and Brain.Screen.xPosition() > aa - 30 and Brain.Screen.yPosition() > bb - 30 and Brain.Screen.xPosition() < aa + 30 and Brain.Screen.yPosition() < bb + 30){
      while(Brain.Screen.pressing()){
      Brain.Screen.clearScreen();
      Brain.Screen.setFillColor(black);
      Brain.Screen.setPenColor( red );
      Brain.Screen.setPenWidth(10); 
      Brain.Screen.drawRectangle(5,5,465,220);
      Brain.Screen.setFillColor(yellow);
      aa = Brain.Screen.xPosition();
      bb = Brain.Screen.yPosition();
      Brain.Screen.drawCircle(cc, dd, 30);
      Brain.Screen.drawCircle(ee, ff, 30);
      Brain.Screen.drawCircle(aa,bb,30);
      wait(50,msec);

      }
    }
    // circle 2
    if(Brain.Screen.pressing() and Brain.Screen.xPosition() > cc - 30 and Brain.Screen.yPosition() > dd - 30 and Brain.Screen.xPosition() < cc + 30 and Brain.Screen.yPosition() < dd + 30){
      while(Brain.Screen.pressing()){
      Brain.Screen.clearScreen();
      Brain.Screen.setFillColor(black);
      Brain.Screen.setPenColor( red );
      Brain.Screen.setPenWidth(10); 
      Brain.Screen.drawRectangle(5,5,465,220);
      Brain.Screen.setFillColor(yellow);
      cc = Brain.Screen.xPosition();
      dd = Brain.Screen.yPosition();
      Brain.Screen.drawCircle(aa, bb, 30); 
      Brain.Screen.drawCircle(ee, ff, 30);
      Brain.Screen.drawCircle(Brain.Screen.xPosition(),Brain.Screen.yPosition(),30);
      wait(50,msec);
      }
    }
    // circle 3
   if(Brain.Screen.pressing() and Brain.Screen.xPosition() > ee - 30 and Brain.Screen.yPosition() > ff - 30 and Brain.Screen.xPosition() < ee + 30 and Brain.Screen.yPosition() < ff + 30){
      while(Brain.Screen.pressing()){
      Brain.Screen.clearScreen();
      Brain.Screen.setFillColor(black);
      Brain.Screen.setPenColor( red );
      Brain.Screen.setPenWidth(10); 
      Brain.Screen.drawRectangle(5,5,465,220);
      Brain.Screen.setFillColor(yellow);
      ee = Brain.Screen.xPosition();
      ff = Brain.Screen.yPosition();
      Brain.Screen.drawCircle(aa, bb, 30); 
      Brain.Screen.drawCircle(cc, dd, 30);
      Brain.Screen.drawCircle(Brain.Screen.xPosition(),Brain.Screen.yPosition(),30);
      wait(50,msec);
      }
    }
  }*/
}



void autonomous(void) {


 //Mitchell Auton 
 Drivetrain.setDriveVelocity(100, percent); 
  traydown();
  wait(0.65,sec);
  trayhold();
  move(-6);
  trayup();
  wait(0.9,sec);
  trayhold();
  clawtoggle();//close
  rights(87);
  Drivetrain.setDriveVelocity(100, percent);
  move(55);

 //Stack Middle Left 
  liftup();
  wait(1.5,sec);
  lifthold();
  rights(140);
  Drivetrain.setDriveVelocity(60, percent);
  move(53);
  clawtoggle();//open

 //Grab Middle Right Goal
  wait(.5,sec);
  move(-19);
  rights(112);
  liftdown();
  clawtoggle();//close
  Drivetrain.setDriveVelocity(100, percent);
  move(-75);
  lifthold();
  move(5);
  rights(35);
  Drivetrain.setDriveVelocity(75, percent);
  move(20);
  wait(600,msec);
  liftup();

 //Stack Middle Right Goal
  lefts(100);
  lifthold();
  move(53);
  clawtoggle();//Open
  move(-10);
  clawtoggle();//close

 //Balance Blue Platform
  move(-10);
  Drivetrain.setDriveVelocity(100, percent);
  liftdown();
  traydown();
  move(-20);
  traystop();
  move(-70);
  rights(43);
  move(15);
  liftup();
  lefts(50);
  move(70);
  clawtoggle();//open
}





void usercontrol(void) {
  // drive train speed
  Drivetrain.setDriveVelocity(100, percent); 
  while (1) {
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("y");
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
  
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  // HANDS OFF DO NOT TOUCH
  
  pre_auton();
  // I SAID HANDS OFF
  
  while (true) {
    wait(100, msec);
  }
}

