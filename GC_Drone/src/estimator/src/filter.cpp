#include "filter.h"

//TODO: Can change to a steady state kalman filter, but that is unecessary
Filter::Filter(float dt)
{

	/*
	states_dot:
	phi_dot
	theta_dot
	psi_dot
	p_dot
	q_dot
	r_dot
	u_dot
	v_dot
	w_dot
	x_dot
	y_dot
	z_dot

	[x y z phi theta psi] are the linear then angular postions of the quadrotor in the earth frame
	[u v w p q r] are the linear then angualar positions of the quadrotor in the body frame
	*/
	F << 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, -9.81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 9.81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
		 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0;
 
	B << 0, 0, 0, 0,
		 0, 0, 0, 0,
		 0, 0, 0, 0,
		 0, 1/QuadRotorModel::get().Ix, 0, 0,
		 0, 0, 1/QuadRotorModel::get().Iy, 0,
		 0, 0, 0, 1/QuadRotorModel::get().Iz,
		 0, 0, 0, 0,
		 0, 0, 0, 0,
		 1/QuadRotorModel::get().mass, 0, 0, 0,
		 0, 0, 0, 0,
		 0, 0, 0, 0,
		 0, 0, 0, 0;

	/*
	Sensor inputs:
	IMU:
		Gyro
		Acc
		Mag
	Barometer:
		Height
	GPS:
		Global Pos
	z:
		p //Gyro
		q //Gyrp
		r //Gyro
		x //GPS
		y //GPS
		z //GPS and Barometer
	*/
		 //Seems like this matrix is not taking advantage of the cross coupling of the system
		 //may want to change it to be more accurate
	H <<  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
		  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
		  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1;

	//This will need tuning
	Q.setIdentity();
	Q *= 0.5;

	//Will need to be adjusted
	R.setIdentity();

	//Need to change to a noise from sensor data sheets
	//Should put in variable in class

	//Needs to be adbjusted
	P.setIdentity();
	P *= 0.04;

	I.setIdentity();

	fdt = dt; 
}

void Filter::predict(Eigen::Matrix<double, 4, 1> inputs)
{
	/*
	x_hat = Fx + Bu
	P = FPF' + Q
	*/

	estimated_state = F * estimated_state + B * inputs;
	P = F * P * F.transpose() + Q;
}

Eigen::Matrix<double, QuadRotorModel::num_states, 1> Filter::update(Eigen::Matrix<double, QuadRotorModel::num_outputs, 1> measurements)
{
	/*
	y_hat = z - Hx_hat
	S = HPH'+ R
	K = PH'S^-1
	x_hat += Ky_hat
	P = (I-KH)P
	*/

	Eigen::Matrix<double, QuadRotorModel::num_outputs, 1> y = measurements - H * estimated_state;
    Eigen::Matrix<double, QuadRotorModel::num_outputs, QuadRotorModel::num_outputs> S = H * P * H.transpose() + R;
    Eigen::Matrix<double, QuadRotorModel::num_states,  QuadRotorModel::num_outputs> K = P * H.transpose() * S.inverse();

    estimated_state += K * y;
    P = (I - K * H) * P;
}