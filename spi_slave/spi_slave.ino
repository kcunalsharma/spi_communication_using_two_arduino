
char b;
/* ATMEGA328P PINS
 *  PB4 IS MISO
 */

/*spi slave program*/

void SPI_slaveInit(void)
{
    DDRB = (1 << PB4);
    SPCR = (1 << SPE);
}

unsigned char SPI_slaveReceive(void)
{
    Serial.println("waiting");
    while (!(SPSR & (1 << SPIF)))
        ;
    return SPDR;
}

void setup()
{
    SPI_slaveInit();
    Serial.begin(9600);
}
void loop()
{
    // b = (char)SPI_slaveReceive();
    Serial.println((char)SPI_slaveReceive());
}
