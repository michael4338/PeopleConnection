#include <fstream>

using namespace std;

//interface: provide a general function to get a pair of data from any medias
class DataProvider{
public:
	DataProvider(){}
	virtual ~DataProvider(){}
	virtual int getData(unsigned long data[], int size) = 0;
};

//concrete class: get data pair from csv file
class FileDataProvider : public DataProvider{
public:
	FileDataProvider(const char* fileName);
	~FileDataProvider(){}

	/*inline*/ virtual int getData(unsigned long data[], int size);

private:
	const char* m_fileName;
	ifstream m_inFile;
};
