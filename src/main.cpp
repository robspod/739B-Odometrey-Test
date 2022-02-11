#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "Mitchell you don't impress me..!. ");
	} else {
		pros::lcd::clear_line(2);
	}
}
int a = 1;


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 *//*
 #define IMU_PORT 20
 void initialize() {
 	pros::c::imu_reset(IMU_PORT);
   int time = pros::millis();
   int iter = 0;
   while (pros::c::imu_get_status(IMU_PORT) & pros::c::E_IMU_STATUS_CALIBRATING) {
     printf("IMU calibrating... %d\n", iter);
     iter += 10;
     pros::delay(10);
   }
   // should print about 2000 ms
   printf("IMU is done calibrating (took %d ms)\n", iter - time);
 	pros::lcd::initialize();
 	pros::lcd::set_text(3, "Mitchell you don't impress me..!. ");
 	//pros::lcd::set_text(1, "Hello PROS User!");
 	//pros::lcd::register_btn1_cb(on_center_button);
 }
*/
void disabled() {}
void competition_initialize() {


}
void autonomous() {
	std::shared_ptr<OdomChassisController> chassis =
	//TwoEncoderOdometry(
	ChassisControllerBuilder()
		.withGains(
	 		{0.001*2, 0, 0.0001}, // distance controller gains
	 		{0.001*2, 0, 0.0001}, // turn controller gains
	 		{0.001*2, 0, 0.0001}  // angle controller gains (helps drive straight)
		)
		 .withMotors(
			 {-9,-10},
			 {7,15}
		 ) // left motor is 1, right motor is 2 (reversed)
		 // green gearset, 4 inch wheel diameter, 11.5 inch wheel track
		 .withDimensions(AbstractMotor::gearset::green, {{4.25_in, 14.5_in}, imev5GreenTPR})
		 .withSensors(
				ADIEncoder{'A', 'B'}, // left encoder in ADI ports A & B
				ADIEncoder{'C', 'D',true}  // right encoder in ADI ports C & D (reversed)
		 )
		 .withMaxVelocity(50)
		 // specify the tracking wheels diameter (2.75 in), track (7 in), and TPR (360)
		 // specify the middle encoder distance (1 in) and diameter (2.75 in)
		 .withOdometry({{2.25_in, 3.125_in}, quadEncoderTPR})
		 .buildOdometry();

//	 );

//	pros::lcd::set_text(2, "Mitchell you don't impress me..!. ");
	chassis->setState({0_in, 0_in, 0_deg});
  // turn 45 degrees and drive approximately 1.4 ft
	chassis->driveToPoint({12_in,0_in});
	//chassis->moveDistance(10_in);
	// turn approximately 45 degrees to end up at 90 degrees
//	chassis->turnToAngle(90_deg);
	// turn approximately -90 degrees to face {5_ft, 0_ft} which is to the north of the robot
//	chassis->turnToPoint({5_ft, 0_ft});
}

void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
		pros::Motor frright_mtr(-7);
		pros::Motor bkright_mtr(-15);
		pros::Motor frleft_mtr(-9);
		pros::Motor bkleft_mtr(-10);


	while (true) {
		int fwd = master.get_analog(ANALOG_LEFT_Y);
		int turn = master.get_analog(ANALOG_LEFT_X);
		printf("LeftDrive: %d \n", fwd);
		frleft_mtr = fwd + turn;
		bkleft_mtr = fwd + turn;
		frright_mtr = turn - fwd;
		bkright_mtr = turn - fwd;
		pros::ADIEncoder lefts{'A','B'};
		pros::ADIEncoder rights{'C','D'};
		pros::delay(20);
	}
}
