/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

char* morseCode[]={
  ".-", // a
  "-...", // b
  "-.-.", // c
  "-..", // d
  ".", // e
  "..-.", // f
  "--.", // g
  "....", // h
  "..", // i
  ".---", // j
  "-.-", // k
  ".-..", // l
  "--", // m
  "-.", // n
  "---", // o
  ".--.", // p
  "--.-", // q
  ".-.", // r
  "...", // s
  "-", // t
  "..-", // u
  "...-", // v
  ".--", // w
  "-..-", // x
  "-.--", // y
  "--.." // z
  };


 int i;
 int j;

 int dotLength = 200;
 int dashLength = dotLength * 3;
 int dotDashSilenceLength = dotLength;
 int letterSilenceLength = dotLength * 3 - dotLength;
 int wordSilenceLength = dotLength * 7 - dotLength;
 //int letterLength = dotLength;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
}

void dot()
{
  Serial.println("dot");
  flash(dotLength);   
}

void dash()
{
  Serial.println("dash");
  flash(dashLength);
}

void morseCodeLetter(char letter)
{
  int characterIndex = (int)letter - 65;
    
  Serial.print("[");
  Serial.print(letter);
  Serial.print("], (int [");
  Serial.print((int)letter);
  Serial.print("]), index [");
  Serial.print(characterIndex);
  Serial.print("] = [");

  //int morseLettersSize = sizeof(morseCode[characterIndex]);
  //char[morseLettersSize] morseLetters;
  char* morseLetters = morseCode[characterIndex];
  int strlenMorseLetters = strlen(morseLetters);//sizeof(morseLetters);
  Serial.print(morseLetters);
  Serial.print("], strlen [");
  Serial.print(strlenMorseLetters);
  Serial.println("]");
  
  for(j = 0; j < strlenMorseLetters; j++)
  {
    char morseCharacter = morseLetters[j];

    if(morseCharacter == 0)
    {
      Serial.println("NUL");
      break;
    }
    
    if(morseCharacter == '-')
    {
      dash();
    }
    else if(morseCharacter == '.')
    {
      dot();
    }
    else
    {
      Serial.println("oops");
    }
  }
  delay(letterSilenceLength);
  Serial.println("");
}

void morseCodeWord(String wordText)
{
  Serial.println("==========================");
  Serial.println(wordText);
  Serial.println("==========================");
  for(i = 0; i < wordText.length(); i++)//for(i = 0; i < sizeof(wordText) - 1; i++)
  {
    char character = wordText.charAt(i);
    morseCodeLetter(character);
  }
  delay(wordSilenceLength);
}

void morseCodeSentence(String sentenceText)
{
  Serial.println("==========================");
  Serial.println(sentenceText);
  Serial.println("==========================");
  // we need to break up the sentence into words (using " " a space)

  sentenceText.trim();
  String sentenceRemainingText = sentenceText;
  int firstSpace = sentenceRemainingText.indexOf(' ');

  // may not be any spaces
  if(firstSpace == -1)
  {
    morseCodeWord(sentenceRemainingText);
  }
  else
  {
    while(firstSpace != -1)
    {
      sentenceRemainingText.trim();
      String wordText = sentenceRemainingText.substring(0,firstSpace);
      sentenceRemainingText = sentenceRemainingText.substring(firstSpace + 1);

      Serial.print("wordText [");
      Serial.print(wordText);
      Serial.print("], sentenceRemainingText [");
      Serial.print(sentenceRemainingText);
      Serial.println("]");

      morseCodeWord(wordText);

      // see if last bit has any spaces, may be last
      firstSpace = sentenceRemainingText.indexOf(' ');
      if(firstSpace == -1)
      {
        morseCodeWord(sentenceRemainingText);
      }
    }
  }
}

void flash(int timeMilliseconds)
{
  tone(7,441);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(timeMilliseconds);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  noTone(7);
  delay(dotDashSilenceLength);
}

// the loop function runs over and over again forever
void loop() {
  // write "matt" == "-- .- - -"
  morseCodeSentence("MATT IS AWSOME");
  
  delay(10000);
  
}
