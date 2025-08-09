/**
  *************************************************************************************************
  * @file       <nazev programu>.c
  * @author     <jmeno autora>
  * @version    <aktualni verze>
  * @date       <datum vytvoreni>
  * @source     <v pripade inspirace jinym zdrojovym kodem uvest jej jako zdroj>
  * @brief      <strucny popis programu>
  *
  *************************************************************************************************
  * @history
  *
  *   v1.0.0  [<aktualni datum>]
  *           - Vytvoreni prvni verze programu.
  *
  *************************************************************************************************
  * @copyright  Copyright <jmeno autora / spolecnosti> (c) <rok> *
  ****************************************************************
*/
#include "stm32f4xx.h"                        // Device header



#define STEP        100                      // Krok v ms pro pozdrzeni programu.
#define CLK_DIV     1000                      // Hodnota pro upravu CLK, viz hl. popisek v driveru pro praci s CLK.



#define LCD_COLS    16                        // Pocet sloupcu pouziteho displeje.
#define LCD_ROWS    2                         // Pocet radku pouziteho displeje.



#define KPAD_COLS   3                         // Pocet sloupcu pouziteho KPAD.
#define KPAD_ROWS   4                         // Pocet radku pouziteho KPAD.



static uint8_t
  KPAD_KeyMap[KPAD_ROWS][KPAD_COLS] = {       // Defaultni rozlozeni pro KPAD 4x4.
  '1', '2', '3',
  '4', '5', '6',
  '7', '8', '9',
  '*', '0', '#',
};

void LCD_print_float(float value);



#include "chrono.h"                           // Pripojeni driveru pro praci s CLK.
#include "LCD.h"                              // Pripojeni driveru pro praci s LCD.
#include "KPAD.h"                             // Pripojeni driveru pro praci s KPAD.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main(void) {
  SystemCoreClockUpdate();
  SysTick_Config(SystemCoreClock / 1000);



  RCC->AHB1ENR |= (1 << 0);
  RCC->AHB1ENR |= (1 << 3);



  LCD_setup();
  KPAD_setup();     



  char choice;

  char mark;
  char mark2;
  char mark3;

  while(1) {
    float price;
    uint8_t check = 0;
    float fuel = 0.00;
    float finalPrice = 0.00;

    LCD_clear();
    LCD_set(LCD_CUR_ON);
    LCD_set(LCD_CUR_BLINK);

    LCD_set(LCD_LINE0);
    LCD_print("A|Tankovani |");
    LCD_set(LCD_LINE1);
    LCD_print("B|Sprava cen|");

    do {
      mark = KPAD_getKey();
    } while(!mark);

    while (check == 0) {
    LCD_set(LCD_LINE0);
    LCD_print("1|Benzin|32.5Kc/l");
    LCD_set(LCD_LINE1);
    LCD_print("2|Nafta |31.5Kc/l");

    do {
      mark = KPAD_getKey();
    } while(!mark);

    switch(mark){
      case '1': 
        price = 32.5;
        check = 1;
        break;
      case '2': 
        price = 31.5;
        check = 1;
        break;
      case '3':

        break;
    }


    else if(mark == '2') {

    } else {
      LCD_clear();
      LCD_set(LCD_LINE0);
      LCD_print("Spatny input");
      delay(500);
    }
  }

  LCD_clear();
  LCD_set(LCD_LINE0);
  LCD_print("Cena ");
  LCD_print_float(price);
  LCD_print(" Kc/l");
  LCD_set(LCD_LINE1);
  LCD_print("Stiskni 4 pro start");


  do {
      mark2 = KPAD_getKey();
    } while(!mark2);

  if (mark2 == '4') {
    LCD_clear();
    LCD_set(LCD_LINE0);
    LCD_print_float(fuel);
    LCD_print(" l");
    LCD_set(LCD_LINE1);
    LCD_print("Cena: ");
    LCD_print_float(finalPrice);
    LCD_print(" Kc");

    for (fuel = 0.00; fuel < 50.00; fuel += 0.11) {
      LCD_setCursor(0, 0);
      LCD_print("                ");
      LCD_setCursor(0, 0);
      LCD_print_float(fuel);
      LCD_print(" l");

      LCD_setCursor(0, 1);
      LCD_print("                ");
      LCD_setCursor(0,1);
      finalPrice = fuel * price;
      LCD_print_float(finalPrice);
      LCD_print(" Kc");

      do {
      mark3 = KPAD_getKey();
    } while(!mark3);

    if(mark3 == '5') {
      break;
    }
      delay(1000);
    }
  }

}
  return 0;
}





void LCD_print_float(float value) {
    char buffer[16];
    snprintf(buffer, sizeof(buffer), "%.2f", value);
    LCD_print(buffer);
}
