#include <iostream>
using namespace std;
class TcpController{
	public: 
		TcpController();
		TcpController(string &);
		void control();
		~TcpController();

	private:
		char *buffer;
		bool send_packet();
		bool receive_packet();



};