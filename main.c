#include <intrinsics.h>
#include <msp430g2253.h>
#define LED_GREEN BIT6
#define LED_RED BIT0
#define BUTTON BIT3

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	//P1OUT = BIT6;   // P1.6 Establese valor de saida a 1
	//P1DIR = BIT6;   // P1.6 configuração de saida digital
	//P1DIR &= ~BIT3; // P1.6 configuração de entrada digital
	//P1REN |= BIT3;  // P1.3- activa resistencia de entrada de P1.3
	//P1OUT |= BIT3;  // resistencia de entrada de P1.3como pullup

		P1OUT = LED_GREEN;   // P1.6 Establese valor de saida a 1
		P1DIR = LED_GREEN;
		P1DIR &= ~BUTTON;
		P1REN |= BUTTON;
		P1OUT |= BUTTON;

		P1IE = BUTTON;  // habilita o interrup do botão
		P1IES |= BUTTON; // interrupção na transição 1-> 10
		P1IFG |= ~BUTTON; // certifica que o indicador de int está limpa

		_enable_interrupts(); //habilita interrutpções não mascaráveis

	while (1) {


	}
}



#pragma vector = PORT1_VECTOR
__interrupt void PORT1_ISR()
{
	P1OUT ^= LED_GREEN; //alternaLED
	P1IFG &= ~BUTTON;  //limpa o indicador de interrupt do botão em P1.3
}
