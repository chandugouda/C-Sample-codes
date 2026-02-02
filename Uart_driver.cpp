#include <reg51.h>

/* ================= UART DRIVER ================= */

/* UART Initialization */
void UART_Init(void)
{
    TMOD = 0x20;      // Timer1 Mode2 (8-bit auto-reload) Timer1 in auto-reload mode is used for UART baud rate generation.
    TH1  = 0xFD;      // Baud rate 9600 for 11.0592 MHz TH1 determines the UART baud rate.
    SCON = 0x50;      // Mode1 (8-bit UART), REN enabled SCON configures UART mode and enables reception
    TR1  = 1;         // Start Timer1  without this it not generate baud rate
}

/* Transmit one character */
void UART_WriteChar(char data)
{
    SBUF = data;          // Load data to UART buffer
    while (TI == 0);      // Wait for transmission complete ,once transmission complete flag becomes 1
    TI = 0;               // Clear transmit flag
}

/* Transmit string */
void UART_WriteString(char *str)
{
    while (*str)
    {
        UART_WriteChar(*str++);
    }
}

/* Receive one character */
char UART_ReadChar(void)
{
    while (RI == 0);      // Wait for data reception ,once data received flag becomes 1
    RI = 0;               // Clear receive flag
    return SBUF;          // Return received data
}

/* ================= MAIN APPLICATION ================= */

void main(void)
{
    char rx;

    UART_Init();                          // Initialize UART
    UART_WriteString("UART Driver Ready\r\n");

    while (1)
    {
        rx = UART_ReadChar();             // Receive data
        UART_WriteChar(rx);               // Echo back
    }
}
