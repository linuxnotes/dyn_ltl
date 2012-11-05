#include <stdio.h>
#include <stdlib.h>
#include <string>
//#include <string.h>

typedef  int len_type;
typedef  int state_type;
typedef  enum {FALSE ,
			   TRUE  } boolean;

//using namespace std;

class Dnf {
 public: 
  

  Dnf(len_type dnfLength = 0) {
	type_length = sizeof(len_type);
	dnf = NULL;
	setLength(dnfLength);
  }

  void setState(len_type stateNumber) {
    len_type elem_of_array = stateNumber / type_length;
	len_type elem_in_type = stateNumber % type_length;
	len_type elem = 1 << elem_in_type;
	dnf[elem_of_array] |= elem;
  }

  boolean getState(len_type stateNumber) {
	len_type elem_of_array = stateNumber / type_length;
	len_type elem_in_type = stateNumber % type_length;
	len_type elem = 1 << elem_in_type;
	len_type result =  dnf[elem_of_array] | elem;
	return static_cast<boolean>(result);
  }

  void setLength(len_type newLength) {
	length = newLength;
	if (dnf != NULL) delete [] dnf;
	array_length = length/sizeof(state_type) + 1;
	// выделим новую память под dnf, старое значение удаляется
	dnf = new state_type[array_length];  
  }

  len_type getLength() {
	return this->length;
  }
  
  /**
   * преобразование в строку, используется для отладки
   */
  std::string toString() {
	std::string result = "";
	char dnfPart[sizeof(state_type) + 1];
	for (len_type i = 0; i < array_length; i ++ ) {
	  snprintf(dnfPart, sizeof(dnfPart), "%d", dnf[i]);
	  result += dnfPart;
	}
	result += "\n";
	return result;
  } 

  ~Dnf() {
	if (dnf != NULL) delete [] dnf;
	array_length = 0;
	length = 0;
  }
  
 private : 
  len_type length;
  len_type array_length;
  len_type type_length;
  state_type * dnf;

};
