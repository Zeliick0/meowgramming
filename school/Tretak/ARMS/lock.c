/**
  *************************************************************************************************
  * @file       <nazev programu>.c
  * @author     <jmeno autora>
  * @version    <aktualni verze>
  * @date       <datum vytvoreni>
  * @source     <v pripade inspirace jinym zdrojovym kodem uvest jej jako zdroj>
  * @brief      <strucny popis programu>
  *
  *************************************************************************************************
  * @history
  *
  *   v1.0.0  [<aktualni datum>]
  *           - Vytvoreni prvni verze programu.
  *
  *************************************************************************************************
  * @copyright  Copyright <jmeno autora / spolecnosti> (c) <rok> *
  ****************************************************************
*/
#include "stm32f4xx.h"                        // Device header
 
#define STEP        100                      // Krok v ms pro pozdrzeni programu.
#define CLK_DIV     1000                      // Hodnota pro upravu CLK, viz hl. popisek v driveru pro praci s CLK.
 
#define LCD_COLS    16                        // Pocet sloupcu pouziteho displeje.
#define LCD_ROWS    2                         // Pocet radku pouziteho displeje.
 
#define KPAD_COLS   3                         // Pocet sloupcu pouziteho KPAD.
#define KPAD_ROWS   4                         // Pocet radku pouziteho KPAD.
 
static uint8_t
  KPAD_KeyMap[KPAD_ROWS][KPAD_COLS] = {       // Defaultni rozlozeni pro KPAD 4x4.
  '1', '2', '3',
  '4', '5', '6',
  '7', '8', '9',
  '*', '0', '#',
};
void setLED(uint16_t led);
void turnOnLED(uint16_t led);
void turnOffLED(uint16_t led);
uint16_t LEDindex;
 
#include "chrono.h"                           // Pripojeni driveru pro praci s CLK.
#include "LCD.h"                              // Pripojeni driveru pro praci s LCD.
#include "KPAD.h"                             // Pripojeni driveru pro praci s KPAD.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
int main(void) {
  SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000);
 
	RCC->AHB1ENR |= (1 << 0);
	RCC->AHB1ENR |= (1 << 3);
	for(LEDindex = 12; LEDindex < 16; LEDindex++){
			setLED(LEDindex);
	}
	LEDindex = 12;
	LCD_setup();
	KPAD_setup();     
 
	char mark[6];
	char mark2[3];
	char emergency[3] = "222";
	char pass[6] = "123321";
	while(1) {
		uint8_t att = 1;
		while (att > 0) {
		char c = att + '0';
		turnOffLED(13);
		turnOffLED(14);
		turnOffLED(15);
		uint8_t counter = 0;
		uint8_t check = 0;

		LCD_clear();
		LCD_set(LCD_CUR_ON);
		LCD_set(LCD_CUR_BLINK);
		LCD_set(LCD_LINE0);
		LCD_print("Zadej:");
		LCD_put(c);
		LCD_set(LCD_LINE1);

		while(counter < 6) {
		do {
      mark[counter] = KPAD_getKey();
    } while(!mark[counter]);
		if(mark[counter] != pass[counter]) {
			check = 1;
		}
		if(check == 1) {
			LCD_put('E');
		} else {
			LCD_put(mark[counter]);
		}
		delay(10);
		counter++;
		}
		delay(100);
		if(strcmp(mark,pass) == 0){
			LCD_clear();
			LCD_print("OK");
			delay(200);
		} else {
			LCD_clear();
			LCD_print("ERROR");
			att--;
			for(uint8_t i = 0; i < 5; i++) {
			turnOnLED(LEDindex);
			delay(40);
			turnOffLED(LEDindex);
			delay(40);
				}
			}
		}
		uint8_t counter2 = 0;
		LCD_clear();
		LCD_set(LCD_LINE0);
		LCD_print("BLOCKED");
		LCD_set(LCD_LINE1);
		while(counter2 < 3) {
		do {
      mark2[counter2] = KPAD_getKey();
    } while(!mark2[counter2]);
		LCD_put(mark2[counter2]);
		delay(500);
		LCD_setCursor(counter2, 1);
		LCD_put('*');
		counter2++;
		}
		mark2[counter2] = '\0';
		if(strcmp(mark2,emergency) == 0) {
			att = 3;
		} else {
			LCD_clear();
			LCD_set(LCD_LINE0);
			LCD_print("WRONG");
			delay(2000);
		}
    LCD_set(LCD_CUR_OFF);                     
    delay(50);
	}
  return 0;
}
 
void setLED(uint16_t led) {
	GPIOD->MODER &= ~(3UL << led * 2);
	GPIOD->MODER |= (1UL << led * 2);
}
void turnOnLED(uint16_t led) {
	GPIOD->ODR |= (1 << led);
}
void turnOffLED(uint16_t led) {
	GPIOD->ODR &= ~(1 << led);
}
