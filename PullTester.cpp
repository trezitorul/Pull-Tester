#include <stdio.h>
#include <PropWare/mcp3000.h>
//#include <simple/simpletools.h>
using namespace PropWare;

int main(){
	printf("Hello World-Initializing ADC NOW");
	MCP3000::PartNumber PartNo = MCP3000::MCP320x;
	PropWare::SPI *spi = PropWare::SPI::get_instance();
	MCP3000::Channel chan = MCP3000::CHANNEL_0;
	MCP3000 adc(spi,PartNo);
	
	Port::Mask MOSI = Port::P1;
	Port::Mask MISO = Port::P1;
	Port::Mask SCLK = Port::P0;
	Port::Mask CS = Port::P2;

	adc.start(MOSI, MISO, SCLK, CS);
//	pause(1000);
	printf("ADC STARTED: \n");
	uint16_t data = -1;
	for(int i =0;i<100;i++){
		adc.read(chan, &data);
		printf("The ADC value is %d \n", data); 
//		pause(100);
		waitcnt(CLKFREQ+CNT);
	}
}