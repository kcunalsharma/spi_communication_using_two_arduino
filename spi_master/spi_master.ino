


/* SPI AS A MASTER
PB2 is select slave
PB3 is mosi
PB5 is clock
these all are port B PINS OF ATMEGA328P
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
    SPI_masterInit();
    transmit(61);
}

void loop()
{
}
