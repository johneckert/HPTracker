
#include <Wire.h>
#include <LCD16x2.h>
#include <stdio.h>
#include <stdlib.h>

LCD16x2 lcd;
int buttons;

int currentHP = 33;
int maxHP = 33;
int tempHP = 0;

int currentInsp = 4;
int maxInsp = 4;

int deathSuccess = 0;
int deathFailure = 0;

int currentLvl1= 4;
int maxLvl1= 4;
int currentLvl2 = 3;
int maxLvl2 = 3;
int currentLvl3 = 2;
int maxLvl3 = 2;
int currentLvl4 = 0;
int maxLvl4 = 0;

void setup() {
  Wire.begin();

  lcd.lcdClear();
  
  lcd.lcdGoToXY(1,1);
  lcd.lcdWrite("HP:");

  lcd.lcdGoToXY(7,1);
  lcd.lcdWrite("T:");

  lcd.lcdGoToXY(14,1);
  lcd.lcdWrite("I:");

  lcd.lcdGoToXY(1,2);
  lcd.lcdWrite("1:");

  lcd.lcdGoToXY(5,2);
  lcd.lcdWrite("2:");

  lcd.lcdGoToXY(9,2);
  lcd.lcdWrite("3:");

  lcd.lcdGoToXY(13,2);
  lcd.lcdWrite("4:");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  buttons = lcd.readButtons();
  
  //draw data
  lcd.lcdGoToXY(4,1);
  char hpBuffer[33];
  lcd.lcdWrite(itoa(currentHP, hpBuffer,10));

  lcd.lcdGoToXY(9,1);
  char tHpBuffer[33];
  lcd.lcdWrite(itoa(tempHP, tHpBuffer,10));
  
  lcd.lcdGoToXY(16,1);
  char inspBuffer[33];
  lcd.lcdWrite(itoa(currentInsp, inspBuffer,10));
  
  lcd.lcdGoToXY(3,2);
  char lvl1[33];
  lcd.lcdWrite(itoa(currentLvl1, lvl1, 10));
  
  lcd.lcdGoToXY(7,2);
  char lvl2[33];
  lcd.lcdWrite(itoa(currentLvl2, lvl2, 10));
  
  lcd.lcdGoToXY(11,2);
  char lvl3[33];
  lcd.lcdWrite(itoa(currentLvl3, lvl3, 10));
  
  lcd.lcdGoToXY(15,2);
  char lvl4[33];
  lcd.lcdWrite(itoa(currentLvl4, lvl4, 10));

  // button controls  
  if (buttons & 0x02) { //button 1
    decHP();
  }
  
  if (buttons & 0x01) { //button 2
    incHP();
  }

  if(buttons & 0x08)  { // button 3
    decTempHP();
  }
    
  if(buttons & 0x04) { // button 4
    incTempHP();
  }

    
  delay(100);
}

// HP funcs
void incHP() {
  if (currentHP < maxHP )
    currentHP++;  
}

void decHP() {
  if (currentHP > 0) 
    currentHP--;
}

void incTempHP()
{
  tempHP++;
}

void decTempHP()
{
  if (tempHP >= 0)
  {
    tempHP--;
  }
}
// Inspiration Funcs
void incInsp()
{
  if (currentInsp < maxInsp)
  {
    currentInsp++;
  }
}

void decInsp()
{
  if (currentInsp > 0)
  {
    currentInsp--;
  }
}
// Death Save Funcs
void incDeathSuccess()
{
  if (deathSuccess <= 3) {
    deathSuccess++;
  }
}

void decDeathSuccess()
{
  if (deathSuccess > 0)
  {
    deathSuccess--;
  }
}

void incDeathFailure()
{
  if (deathFailure <= 3)
  {
    deathFailure++;
  }
}

void decDeathFailure()
{
  if (deathFailure > 0)
  {
    deathFailure--;
  }
}

void deathSaves() {}

// Spell Funcs
void incLvl1()
{
  if (currentLvl1 < maxLvl1)
  {
    currentLvl1++;
  }
}

void decLvl1()
{
  if (currentLvl1 > 0)
  {
    currentLvl1--;
  }
  else
  {
    deathSaves();
  }
}

void incLvl2()
{
  if (currentLvl2 < maxLvl2)
  {
    currentLvl2++;
  }
}

void decLvl2()
{
  if (currentLvl2 > 0)
  {
    currentLvl2--;
  }
  else
  {
    deathSaves();
  }
}

void incLvl3()
{
  if (currentLvl3 < maxLvl3)
  {
    currentLvl3++;
  }
}

void decLvl3()
{
  if (currentLvl3 > 0)
  {
    currentLvl3--;
  }
  else
  {
    deathSaves();
  }
}

// Long Rest
void longRest() {
 currentHP = maxHP;
 tempHP = 0;
 currentInsp = maxInsp;

 deathSuccess = 0;
 deathFailure = 0;

 currentLvl1 = maxLvl1;
 currentLvl2 = maxLvl2;
 currentLvl3 = maxLvl3;
}
