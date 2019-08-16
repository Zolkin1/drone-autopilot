#include <string>
#include <fstream>
#include <cerrno>
#include <stdint.h> // Might be deprecated, check this

class LoggerClass
{
private:
	ofstream file;
public:
	LoggerClass(string file_name);

	template <typename data>
	int writeToFile(data input_data);
}