#include "vex.h"
using namespace vex;


//lift controls
extern void liftdown(){
  lift1.setVelocity(100, percent); 
  lift2.setVelocity(100, percent); 
  lift1.spin(reverse); 
  lift2.spin(reverse); 
}
extern void liftup(){
  lift1.setVelocity(100, percent); 
  lift2.setVelocity(100, percent); 
  lift1.spin(forward);
  lift2.spin(forward); 
}
extern void lifthold(){
  lift1.stop(hold);
  lift2.stop(hold);
}
//claw controls
extern void clawtoggle(){
  claw.spinFor(forward, 45, degrees); 
}
void clawopen(){
  claw.spinFor(forward, 45, degrees);
  wait(0.6, sec);
  claw.spinFor(forward, 45, degrees);
}
extern void clawclose(){
  claw.spin(forward);
}
extern void clawwstop(){
  claw.stop(hold);
}
//tray controls
extern void trayup(){
  tray2.setVelocity(100, percent);
  tray2.spin(forward);
}
extern void traydown(){
  tray2.setVelocity(100, percent);
  tray2.spin(reverse);
}
extern void trayup50(){
  tray2.setVelocity(50, percent);
  tray2.spin(forward);
}
extern void traydown50(){
  tray2.setVelocity(50, percent); 
  tray2.spin(reverse);
}
extern void trayhold(){
  tray2.stop(hold);
}
extern void traystop(){
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









