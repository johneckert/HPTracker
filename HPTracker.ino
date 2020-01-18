

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

  int currentSpellSlotsOne = 4;
  int maxSpellSlotsOne = 4;
  int currentSpellSlotsTwo = 3;
  int maxSpellSlotsTwo = 3;
  int currentSpellSlitsThree = 2;
  int maxSpellSlitsThree = 2;

  void increaseHP() {
    if (currentHP < maxHP ) {
      currentHP++;  
    }
  }

  void decreaseHP() {
    if (currentHP > 0) {
      currentHP--;
    }
    else {
      deathSaves();
    }
  }

  void deathSaves() {}

  void longRest() {
   currentHP = maxHP;
   tempHP = 0;
   currentInsp = maxInsp;
   deathSuccess = 0;
   deathFailure = 0;
   
  }
  
}
