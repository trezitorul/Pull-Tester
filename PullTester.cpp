#include <PropWare/printer/printer.h>
#include <PropWare/mcp3000.h>

using namespace PropWare;

const Port::Mask SCLK = Port::P29;
const Port::Mask MISO = Port::P28;
const Port::Mask MOSI = Port::P27;
const Port::Mask CS   = Port::P26;

const MCP3000::Channel    CHAN    = MCP3000::CHANNEL_0;
const MCP3000::PartNumber PART_NO = MCP3000::MCP320x;

int main () {
	ErrorCode errorCode;
	uint16_t  data;

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
