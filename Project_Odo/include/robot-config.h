using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern smartdrive Drivetrain;
extern motor lift2;
extern motor lift1;
extern motor claw;
extern motor tray2;
extern sonar RangeFinder;
extern encoder Encoderleft;
extern encoder Encoderright;
extern encoder Encoderback;
extern rotation Rotation18;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );