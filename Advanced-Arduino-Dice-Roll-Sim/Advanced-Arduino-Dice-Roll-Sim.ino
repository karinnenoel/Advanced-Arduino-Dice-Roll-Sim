int leftTop = 2;
int leftMiddle = 3;
int leftBottom = 4;
int middleMiddle = 5;
int rightTop = 6;
int rightMiddle = 7;
int rightBottom = 8;

int ledPins[] = {
  leftTop,
  leftMiddle,
  leftBottom,
  middleMiddle,
  rightTop,
  rightMiddle,
  rightBottom,
};

int numLedPins = 7;

int one[] = { middleMiddle };
int two[] = { leftTop, rightBottom };
int three[] = { leftTop, middleMiddle, rightBottom };
int four[] = { leftTop, leftBottom, rightTop, rightBottom };
int five[] = { leftTop, leftBottom, middleMiddle, rightTop, rightBottom };
int six[] = { leftTop, leftMiddle, leftBottom, rightTop, rightMiddle, rightBottom };

int* rolls[] = { one, two, three, four, five, six };

int buttonPin = 12;


void setup() {
  pinMode (buttonPin, INPUT);

  for (int i = 0; i < numLedPins; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

int currentButtonState = 0;
int buttonState = 0;
int lastButtonState = 0;
long debounceDelay = 50;
long lastDebounceTime = 0;


void loop() {

  currentButtonState = digitalRead(buttonPin);

  if (currentButtonState != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    buttonState = currentButtonState;

    if (buttonState == HIGH) {
      shuffle(6);
      roll(6);
    }
  }
}

lastButtonState = currentButtonState;

}

void roll() {
  int  number = random(0, 6);

  int* rollPins = rolls[number];

  for (int i = 0; i < numLedPins; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  for (int i = 0; i < number + 1; i++) {
    digitalWrite(rollPins[i], HIGH);
  }
}

void shuffle() {
  for (int i = 0; i < 25; i++) {
    roll(6);
    delay(40);
  }
}    
 
