class QuadRotorModel
{
public:
	QuadRotorModel();
private:

public:

	static QuadRotorModel& get()
	{
		static QuadRotorModel instance;
		return instance;
	}

	//Moments of inertia around the different axis
	//TODO: Change these to the correct values
	//Use the point approx. in the beginning
	const float Ix = 0.1; //Add units
	const float Iy = 0.1; //Add units
	const float Iz = 0.1; //Add units

	const float mass = 10; //kg

	// Should probably move this
	const float g = 9.81; //m/s^2

	const int static num_states = 12;
	const int static num_outputs = 4;
};