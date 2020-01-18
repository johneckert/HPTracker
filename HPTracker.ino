

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  
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

// HP funcs
  void incHP() {
    if (currentHP < maxHP ) {
      currentHP++;  
    }
  }

  void decHP() {
    if (currentHP > 0) {
      currentHP--;
    }
    else {
      deathSaves();
    }
  }

  void incTempHP()
  {
    tempHP++;
  }

  void decTempHP()
  {
    if (tempHP > 0)
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
  
}
