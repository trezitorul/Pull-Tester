#include <PropWare/printer/printer.h>
#include <PropWare/mcp3000.h>
#include <simpletools.h>

using namespace PropWare;

const Port::Mask SCLK = Port::P29;
const Port::Mask MISO = Port::P28;
const Port::Mask MOSI = Port::P27;
const Port::Mask CS   = Port::P26;
const Port::Mask MO   = Port::P23;
const Port::Mask M1   = Port::P22;

const MCP3000::Channel    CHAN    = MCP3000::CHANNEL_0;
const MCP3000::PartNumber PART_NO = MCP3000::MCP320x;
int motorControlDemo();
int buttonDemo();
int main () {
	ErrorCode errorCode;
	uint16_t  data;
	buttonDemo();
	motorControlDemo();
	pwOut.printf("Hello World-Initializing ADC NOW" CRLF);
	SPI     *spi = SPI::get_instance();
	MCP3000 adc(spi, PART_NO);

	errorCode = adc.start(MOSI, MISO, SCLK, CS);
	pwOut.printf("ADC STARTED: (code = %d)" CRLF, errorCode);

	for (int i = 0; i < 100000; i++) {
		errorCode = adc.read(CHAN, &data);
		pwOut.printf("The ADC value is %d (code = %d)" CRLF, data, errorCode);
		waitcnt(SECOND + CNT);
	}

	return 0;
}

int motorControlDemo(){
	pwOut.printf("Hello World-Initializing Motor Control Demo Now" CRLF);
	for(int i=1;i<11;i++){
		high(23);
		pwOut.printf("Going up for the # %d time" CRLF, i);
		waitcnt(5*SECOND + CNT);
		low(23);
		high(22);
		pwOut.printf("Goind down for the # %d time" CRLF,i);
		waitcnt(5*SECOND + CNT);
		low(22);
	}
	pwOut.printf("Motor Demo Complete" CRLF);
	return 0;
}

int buttonDemo(){
	pwOut.printf("ButtonDemo");
	int left;
	int right;
	while(1){
		left=input(25);
		right=input(24);
		pwOut.printf("The Left button is %d" CRLF, left);
		pwOut.printf("The Right button is %d" CRLF, right);
		waitcnt(SECOND + CNT);
	}
}