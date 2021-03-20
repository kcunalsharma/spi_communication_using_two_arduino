


/* SPI AS A MASTER
PB2 is select slave, D10 - digital Pin of Arduino
PB3 is mosi, D11 - digital Pin of Arduino
PB5 is clock, D13 - digital Pin of Arduino
these all are port B PINS OF ATMEGA328P and D pins refer to digital Pins of arduino board
*/
void SPI_masterInit(void)
{
    DDRB = (1 << PB2) | (1 << PB3) | (1 << PB5);
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void transmit(unsigned char data)
{
    Serial.println("not transmitted");
    SPDR = data;

    while (!(SPSR & (1 << SPIF)))
        ;
    Serial.println("transmitted");
}

void setup()
{
    Serial.begin(9600);
}

void loop()
{
   SPI_masterInit();
   transmit(57);
   delay(3000);
}
