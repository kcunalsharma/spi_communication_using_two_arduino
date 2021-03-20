
char ReceivedData;
/* ATMEGA328P PINS
 * PB4 IS MISO, D 12 Pin of Arduino board
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
     ReceivedData = (char)SPI_slaveReceive();
     Serial.println(ReceivedData);
}
