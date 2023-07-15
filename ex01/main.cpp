#include    "Serializer.hpp"

int main()
{
	Data ptr2;
	ptr2.studentName = "othmane1";
	ptr2.number = 42;
	ptr2.next = NULL;

	Data ptr;
	ptr.studentName = "othmane2";
	ptr.number = 42;
	ptr.next = &ptr2;


	std::cout << "original structs:" <<
				"\n\taddress: " << &ptr <<
				"\n\tstudentName: " << ptr.studentName <<
				"\n\tnumber: " << ptr.number <<
				"\n\taddress next: " << ptr.next <<
	std::endl;
	std::cout << "\taddress ptr2: " << &ptr2 <<
				"\n\tstudentName: " << ptr2.studentName <<
				"\n\tnumber: " << ptr2.number <<
				"\n\taddress next: " << ptr2.next <<
	std::endl << std::endl;

	Data *deserialized_struct = Serializer::deserialize(Serializer::serialize(&ptr));

	std::cout << "deserialized structs:" <<
				"\n\taddress: " << deserialized_struct <<
				"\n\tstudentName: " << deserialized_struct->studentName <<
				"\n\tnumber: " << deserialized_struct->number <<
				"\n\taddress next: " << deserialized_struct->next <<
	std::endl;
	std::cout << "\taddress ptr2: " << &ptr2 <<
				"\n\tstudentName: " << ptr2.studentName <<
				"\n\tnumber: " << ptr2.number <<
				"\n\taddress next: " << ptr2.next <<
	std::endl << std::endl;

	return (0);
}