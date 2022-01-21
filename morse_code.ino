# define ledPin 13 // internal activity led
int timeUnit = 150; // milliseconds
String msgString; // string to contain received message
int msgLength; // number of signs in message

void setup() {
  // setup serial
  Serial.begin(9600);
  // setup communication pin
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // keep waiting for input
  if (Serial.available()) {
    msgString = Serial.readString();
    msgString.toUpperCase();
    //Serial.println(msgString);
    msgLength = msgString.length();
    for (int i=0; i<msgLength; i++) {
      morse(msgString.charAt(i));
    }
  }
}

void morse(char c) {
  Serial.print(c);
  Serial.print('\t');
  switch (c) {
    case ' ':
      delay(4*timeUnit); break; // yields a total of 7 timeUnits
    case 'A':
      dot(); dash(); break;
    case 'B':
      dash(); dot(); dot(); dot(); break;
    case 'C':
      dash(); dot(); dash(); dot(); break;
    case 'D':
      dash(); dot(); dot(); break;
    case 'E':
      dot(); break;
    case 'F':
      dot(); dot(); dash(); dot(); break;
    case 'G':
      dash(); dash(); dot(); break;
    case 'H':
      dot(); dot(); dot(); dot(); break;
    case 'I':
      dot(); dot(); break;
    case 'J':
      dot(); dash(); dash(); dash(); break;
    case 'K':
      dash(); dot(); dash(); break;
    case 'L':
      dot(); dash(); dot(); dot(); break;
    case 'M':
      dash(); dash(); break;
    case 'N':
      dash(); dot(); break;
    case 'O':
      dash(); dash(); dash(); break;
    case 'P':
      dot(); dash(); dash(); dot(); break;
    case 'Q':
      dash(); dash(); dot(); dash(); break;
    case 'R':
      dot(); dash(); dot(); break;
    case 'S':
      dot(); dot(); dot(); break;
    case 'T':
      dash(); break;
    case 'U':
      dot(); dot(); dash(); break;
    case 'V':
      dot(); dot(); dot(); dash(); break;
    case 'W':
      dot(); dash(); dash(); break;
    case 'X':
      dash(); dot(); dot(); dash(); break;
    case 'Y':
      dash(); dot(); dash(); dash(); break;
    case 'Z':
      dash(); dash(); dot(); dot(); break;
    case '1':
      dot(); dash(); dash(); dash(); dash(); break;
    case '2':
      dot(); dot(); dash(); dash(); dash(); break;
    case '3':
      dot(); dot(); dot(); dash(); dash(); break;
    case '4':
      dot(); dot(); dot(); dot(); dash(); break;
    case '5':
      dot(); dot(); dot(); dot(); dot(); break;
    case '6':
      dash(); dot(); dot(); dot(); dot(); break;
    case '7':
      dash(); dash(); dot(); dot(); dot(); break;
    case '8':
      dash(); dash(); dash(); dot(); dot(); break;
    case '9':
      dash(); dash(); dash(); dash(); dot(); break;
    case '0':
      dash(); dash(); dash(); dash(); dash(); break;
  }
  Serial.println(' ');
  delay(3*timeUnit);
}

void dot() {
  Serial.print('.');
  digitalWrite(ledPin, HIGH);
  delay(timeUnit);
  digitalWrite(ledPin, LOW);
  delay(timeUnit);
}

void dash() {
  Serial.print('-');
  digitalWrite(ledPin, HIGH);
  delay(3*timeUnit);
  digitalWrite(ledPin, LOW);
  delay(timeUnit);
}
