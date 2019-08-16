/*
Logging class should eventually be used, but for now (8/10/19) don't use it because there is a lot
Of variability in what needs to be logged and how.
*/
#include "logger_class.h"

LoggeerClass::LoggerClass(string file_name)
{
	file.open("/home/pi/data/" + file_name); //Make it log to a "data" folder. User might not be "pi"	
}

int LoggerClass::writeToFile(data input_data)
{
	if (!file.isopen())
	{
		printf("File not opened yet!\n");
		return errno
	}
	file << input_data << "\n";
}