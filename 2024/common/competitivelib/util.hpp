#include <string>
#include <vector>
#include <iostream>
/*
This file will only have things related with any kind of manipulation to std::string
*/
namespace sct {
    




	
	/*
		Splits str in a std::string vector, delimiting each str by separator, and at max with maxplit sections.
		Ejemplo: str = "Hola mundo bla bla bla"
		split(str," ") -> {"Hola", "mundo", "bla", "bla", "bla"}
		split(str,"bla") -> {"Hola mundo ", " ", " ", ""}
		split(str," ", 3) -> {"Hola", "mundo", "bla bla bla"}
	*/
	inline std::vector<std::string> split(const std::string& str, const std::string& separator,const size_t& maxplit = std::string::npos){
		std::vector<std::string> ret;
		if(maxplit != std::string::npos) ret.reserve(maxplit);

		size_t curOffset = 0;
		size_t curPos = 0;
		while (ret.size() < maxplit-1 && (curPos=str.find(separator, curOffset)) != std::string::npos) {
			ret.push_back(str.substr(curOffset, curPos - curOffset));
			curOffset = curPos + separator.size();
		}
		ret.push_back(str.substr(curOffset));
		return ret;
	}


	inline std::vector<int> splitToInt(const std::string& str, const std::string& separator, const size_t& maxsplit = std::string::npos) {
		std::vector<int> ret;
		if (maxsplit != std::string::npos) ret.reserve(maxsplit);

		size_t curOffset = 0;
		size_t curPos = 0;
		while (ret.size() < maxsplit - 1 && (curPos = str.find(separator, curOffset)) != std::string::npos) {
			std::string segment = str.substr(curOffset, curPos - curOffset);
			try {
				ret.push_back(std::stoi(segment));
			} catch (const std::invalid_argument&) {
				throw std::runtime_error("Invalid segment for integer conversion: " + segment);
			} catch (const std::out_of_range&) {
				throw std::runtime_error("Segment out of range for integer conversion: " + segment);
			}
			curOffset = curPos + separator.size();
		}
		// Process the final segment
		std::string lastSegment = str.substr(curOffset);
		try {
			ret.push_back(std::stoi(lastSegment));
		} catch (const std::invalid_argument&) {
			throw std::runtime_error("Invalid segment for integer conversion: " + lastSegment);
		} catch (const std::out_of_range&) {
			throw std::runtime_error("Segment out of range for integer conversion: " + lastSegment);
		}

		return ret;
	}

	inline auto transpose(const std::vector<std::string> a ) -> std::vector<std::string>
{
	std::string s(a.size(),'a');
	std::vector<std::string> b(a[0].size(),s);
    int i, j;
	//std::cout << " reservamos" << b.capacity() << std::endl;
    for (i = 0; i < a[0].size(); i++){
        for (j = 0; j < a.size(); j++){
            b[i][j] = a[j][i];
		}

	}
		
	return b;
}



}// END Namespace sct




