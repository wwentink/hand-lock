#include <LiquidCrystal.h>

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

// password info
const char correctPassword[5] = "1234";
char enteredPassword[5] = "";
int index = 0;
int attempts = 0;
const int maxAttempts = 3;

// led info
const int failLEDs[3] = {8, 9, 10};
const int successLED = 11;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Enter Password:");

  // success/failure led setup
  for (int i = 0; i < 3; i++) {
    pinMode(failLEDs[i], OUTPUT);
    digitalWrite(failLEDs[i], LOW);
  }
  pinMode(successLED, OUTPUT);
  digitalWrite(successLED, LOW);
}

void loop() {
  // lockout
  if (attempts >= maxAttempts) {
    lcd.clear();
    lcd.print("LOCKED OUT");
    delay(100);
    return;
  }

  // check if serial input is available
  if (Serial.available() > 0) {
    char input = Serial.read();
    Serial.print("Received: ");
    Serial.println(input);
    
    // clear if * is input
    if (input == '*') {
      index = 0;
      memset(enteredPassword, 0, sizeof(enteredPassword));
      lcd.setCursor(0, 1);
      lcd.print("    ");
      lcd.setCursor(0, 1);
    } 

    // enter password if # is input
    else if (input == '#' && index == 4) {
      enteredPassword[4] = '\0';
      Serial.print("Entered Password: ");
      Serial.println(enteredPassword);
      checkPassword();
    } 

    // enter password input
    else if (index < 4 && input != '#') {
      enteredPassword[index] = input;
      index++;
      lcd.setCursor(index - 1, 1);
      lcd.print('*');
    }
  }
}

void checkPassword() {
  Serial.print("Checking Password: ");
  Serial.println(enteredPassword);
  
  // compare character arrays of entered password and correct password
  if (strcmp(enteredPassword, correctPassword) == 0) { // print correct and light correct led if match
    lcd.clear();
    lcd.print("CORRECT");
    digitalWrite(successLED, HIGH);
  } else { // print incorrect and light incorrect led if wrong
    lcd.clear();
    lcd.print("INCORRECT");
    digitalWrite(failLEDs[attempts], HIGH);
    attempts++;
    delay(2000);
    lcd.clear();
    lcd.print("Enter Password:");
  }
  
  index = 0;
  memset(enteredPassword, 0, sizeof(enteredPassword)); // clear password array
}
