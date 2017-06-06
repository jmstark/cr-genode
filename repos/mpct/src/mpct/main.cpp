#include <base/printf.h>
#include <mosquittopp.h>

#include <cstdio>
#include <cstring>

// lwip includes
extern "C" {
	#include <lwip/sockets.h>
	#include <lwip/api.h>
}
#include <lwip/genode.h>
#include <nic/packet_allocator.h>

class MPCT : public mosqpp::mosquittopp {
public:
	MPCT(const char* id, const char* host, int port) : mosquittopp(id) {
		int keepalive = 60;
		connect(host, port, keepalive);
	}
};

int main(int argc, char* argv[]) {
	lwip_tcpip_init();

	enum { BUF_SIZE = Nic::Packet_allocator::DEFAULT_PACKET_SIZE * 128 };

	if (lwip_nic_init(inet_addr("192.168.100.42"),
										inet_addr("255.255.255.0"),
										inet_addr("192.168.100.254"),
										BUF_SIZE,
										BUF_SIZE)) {
		PERR("lwip init failed!");
		return 1;
	}

	mosqpp::lib_init();
	class MPCT *mpct = new MPCT("mpct", "192.168.100.254", 1883);

	/* endless loop */
	//mpct->loop_start();

	char buffer[1024] = { 0 };
	int i = 0, ret = -1;
	while(1) {
		sprintf(buffer, "Hello World: %d", i);
		ret = mpct->publish(NULL, "mpct", strlen(buffer), buffer);
		PDBG("Publish successful: %d", MOSQ_ERR_SUCCESS == ret);
		i++;
	}

	mosqpp::lib_cleanup();

	return 0;
}
