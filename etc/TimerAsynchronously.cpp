#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void print(const boost::system::error_code&)
{
	std::cout << "A Hello World!" << std::endl;
}

int main()
{
	boost::asio::io_service io;
	boost::asio::deadline_timer t(io,boost::posix_time::seconds(5));
	t.async_wait(&print);
	std::cout << "1" << std::endl;
	io.run();
	std::cout << "2" << std::endl;
	return 0;
}
