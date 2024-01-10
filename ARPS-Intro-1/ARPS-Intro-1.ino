/*
Project:  Intro-1-Input-Output        Activity: mirobo.tech/arps-intro-1
Date:     January 9, 2024
 
This introductory input and output programming activity for the mirobo.tech
ARPS circuit demonstrates pushbutton input, LED outut, the use of time delay
functions, and simple 'if' condition structures.
 
Additional program analysis and programming activities demonstrate logical
AND and OR conditional operators, the tone() function to create sound, and
software-based simulated start-stop button functionality.
*/

// Define I/O pins used for human interface devices
const int SW2 = 0;      // ARPS pushbuttons
const int SW3 = 1;
const int SW4 = 2;
const int SW5 = 3;

const int LED2 = 5;     // ARPS top-side LEDs
const int LED3 = 6;
const int LED4 = 9;
const int LED5 = 10;

const int BEEPER = 11;  // ARPS Piezo beeper LS1

const int onboardLED = 13;  // Arduino on-board LED

// Define variables
int SW2state;
int SW3state;
int SW4state;
int SW5state;

// Setup code runs once to configure I/O pins before running main loop
void setup() {
  pinMode(onboardLED,OUTPUT);
  pinMode(SW2,INPUT_PULLUP);
  pinMode(SW3,INPUT_PULLUP);
  pinMode(SW4,INPUT_PULLUP);
  pinMode(SW5,INPUT_PULLUP);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(BEEPER,OUTPUT);
  tone(BEEPER,4000,100);  // Say hello!
}

// Main loop code repeats forever
void loop() {
  SW2state = digitalRead(SW2);

  if(SW2state == LOW) {
    digitalWrite(LED2,HIGH);
    delay(100);
    digitalWrite(LED3,HIGH);
    delay(100);
    digitalWrite(LED4,HIGH);
    delay(100);
    digitalWrite(LED5,HIGH);
    delay(100);

    digitalWrite(LED2,LOW);
    delay(100);
    digitalWrite(LED3,LOW);
    delay(100);
    digitalWrite(LED4,LOW);
    delay(100);
    digitalWrite(LED5,LOW);
    delay(100);
  }

  // Add your Program Analysis Activities and Programming Activities code here:

  delay(10);  // Added delay helps simulators run this program
}

/* Learn More -- Program Analysis Activities
 *
 * 1. Let's analyze this program! Program analysis is an important skill to 
 *    develop to better understand a program's operation. Start by running the
 *    program in your circuit board. Press and immediately release SW2 and watch
 *    what the LEDs do. How many LEDs flash? How many times to they flash? Next,
 *    press and hold SW2 and observe the LEDs and flashing pattern. Does the
 *    pattern stop immediately when you let go of SW2?
 * 
 *    Now, examine the program and try to match your observations of the light
 *    pattern to the program code. How many digitalWrite and delay statements
 *    are grouped together inside the curly braces that follow the SW2state 'if'
 *    statement? Did all of these actions happen when you pressed and let go of
 *    SW2? Can you explain why the microcontroller will always complete all of
 *    the actions inside the braces, and not skip any of the steps each time
 *    pushbutton SW2 is pressed?
 * 
 * 2. Explain the difference between the statements: 'digitalWrite(LED2,HIGH);'
 *    and 'digitalWrite(LED2,LOW);'. How does setting the LED2 pin high or low
 *    actually turn LED2 on or off on the circuit board?
 * 
 * 3. Understanding how a circuit works is another important skill to develop
 *    in interfacing (controlling hardware with software). What voltage do you
 *    expect the microcontroller to output to LED D2 when the statement
 *    'digitalWrite(LED2,LOW);' runs? What voltage do you expect the output to
 *    be when the statement 'digitalWrite(LED2,HIGH);' runs?
 * 
 *    If you have access to a voltmeter, you can use it confirm the output
 *    voltage of the microcontroller in the circuit. Try measuring across one
 *    of the LEDs as the program outputs a LOW, and again when it outputs a 
 *    HIGH. The voltage will change quickly so you may need to use a 'peak hold'
 *    or 'max' feature if your multimeter has one, or slow down the light pattern
 *    in your program by increasing the value of one or more of the time delays.
 * 
 *    Next, carefully measure the voltage between one of the LED header pins and
 *    one of the GND (ground, or common) header pins as you run the program and
 *    press SW2. (Refer to the pin definitions at the top of the program to find
 *    which digital pins connect to the LEDs.) Compare your measurements. Did one
 *    of these voltages match your prediction? Which one? Can you explain why?
 * 
 * 4. The statement 'SW2state = digitalRead(SW2);' contains a single equal sign
 *    while the statement 'if(SW2state == LOW)' contains two equal signs. What
 *    operation is performed by a statement using one equal sign? What operation
 *    is performed by a statement using two equal signs? How are the two
 *    operations different?
 * 
 * 5. Find the switch circuits on the schematic diagram. Why do you think the
 *    program code uses the statement 'if(SW2state == LOW)' to sense if a switch
 *    is pressed? Can you use the schematic and this program's setup() function
 *    code to explain why the input voltage on one of the microcontroller's
 *    switch inputs will be low when the switch is pressed?
 *  
 * 6. Let's compare the operation of 'if' and 'while' structures to simulate the
 *    operation of real-world momentary buttons. Add the following code below
 *    the existing 'if(SW2state == LOW)' block in the program, and then compile
 *    and re-upload your program to your Arduino.

  // Momentary button using an if structure
  SW3state = digitalRead(SW3);
  if(SW3state == LOW) {
      digitalWrite(LED3,HIGH);
  }
  else {
      digitalWrite(LED3,LOW);
  }

  // Momentary button using a while structure
  SW4state = digitalRead(SW4);
  while(SW4state == LOW) {
      digitalWrite(LED4,HIGH);
      SW4state = digitalRead(SW4);
  }
  digitalWrite(LED4,LOW);

 *    First, try pressing and releasing SW3 and SW4 one at a time. They should
 *    act the same way, turning their respective LEDs on as each switch is
 *    pressed, and off as each switch is released.
 * 
 *    Next, press and hold SW3 while pressing and releasing SW4. Does SW4 work
 *    as expected?
 * 
 *    Last, press and hold SW4 while pressing and releasing SW3. Does SW3 work
 *    as expected?
 * 
 *    Can you explain the difference in operation between the 'if' and 'while'
 *    structures in the two different examples of momentary button code?
 *
 * 7. Comment-out the second 'SW4state = digitalRead(SW4);' (the one inside 
 *    the while loop) by adding two slashes '//' at the start of the line,
 *    like this: '//SW4state = digitalRead(SW4);'. Re-upload your program and
 *    test SW4 again. After that, try testing SW2 and SW3. Do they still work?
 *    If the program seems to be getting stuck, press and release the SW1
 *    RESET pushbutton to re-start it. Explain what you think is happening and
 *    why the microcontroller might be doing that. 
 * 
 * 8. Let's explore logical conditions made using 'if' statements. Replace the
 *    program code added in steps 6 and 7, above, with this 'nested if' code
 *    to create a logical AND condition that will light LED D3 only if both
 *    SW3 and SW4 are pressed:

  SW3state = digitalRead(SW3);
  SW4state = digitalRead(SW4);

  if(SW3state == LOW) {
    if(SW4state == LOW) {
      digitalWrite(LED3,HIGH);
    }
    else {
      digitalWrite(LED3,LOW);
    }
  }
  else {
    digitalWrite(LED3,LOW);
  }

 *    Test the code to ensure it works as expected. Does the order of the if
 *    conditions matter? (e.g. swap the conditional checks for SW3 and SW4)
 * 
 * 9. Next, replace the code from activity 8, above, with the following code
 *    which implements the logical AND conditional operator – it's composed of
 *    two ampersands '&&' and becomes part of the 'if' statement:
 
  SW3state = digitalRead(SW3);
  SW4state = digitalRead(SW4);
  
  if(SW3state == LOW && SW4state == LOW) {
    digitalWrite(LED3,HIGH);
  }
  else {
    digitalWrite(LED3,LOW);
  }

 *    Does '&&' work the same way as the nested if structures? Can you think of
 *    at least one advantage of using a logical conditional operator instead of
 *    nested if structures?
 * 
 * 10. Replace the double ampersand '&&' with double vertical bars '||' to make
 *    a logical OR conditional operator. Your code should now look like this:
  
  SW3state = digitalRead(SW3);
  SW4state = digitalRead(SW4);
  
  if(SW3state == LOW || SW4state == LOW) {
    digitalWrite(LED3,HIGH);
  }
  else {
    digitalWrite(LED3,LOW);
  }

 *    Describe the conditions under which LED3 turns on.
 * 
 * Programming Activities
 * 
 * 1. The statement 'delay(100);' creates a 100ms delay. Try changing one or
 *    more of the delay values in the program to 500ms and see what happens.
 * 
 *    Look up the delay() function in the Arduino reference documentation.
 *    What is one problem you might run into when using the delay() function
 *    for long delays in your program?
 * 
 * 2. The 'delay()' function accepts only integers as delay values. To create
 *    delays shorter than 1 ms, a different function must be used instead. Use
 *    the 'delayMicroseconds()' function to specify time delays in
 *    microseconds instead of milliseconds.
 * 
 *    You won't be able to see microsecond length LED flashes with your eyes,
 *    but you can measure them using an oscilloscope or hear them if they are
 *    used to turn the piezo beeper on and off. Try the following code in your
 *    program. The delay was chosen to be the time period of music note A5
 *    which should play a tone at a frequency of 880Hz.
 
  SW5state = digitalRead(SW5);    // Make a tone while SW5 is held
  if(SW5state == LOW) {
    digitalWrite(BEEPER,HIGH);
    delayMicroseconds(567);
    digitalWrite(BEEPER,LOW);
    delayMicroseconds(567);
  }

 *    It definitely makes a sound when SW5 is pressed, but it doesn't sound
 *    like the note that it is supposed to play. Can you guess why?
 * 
 *    The 'delay(10);' statement at the end of the program is the problem – it
 *    makes the delay muuuuuch longer than 567µs. The 10ms delay is not needed
 *    when running the program in an actual Arduino circuit, but it has been
 *    added to this program because it helps some Arduino simulators work better
 *    by limiting the number of times the main loop runs every second. Comment
 *    out the 'delay(10);' statement for the remainder of the programming
 *    activities in this program and try the program in your circuit again.
 *
 *    Did it sound more like a tone now? Next, try changing the delay values.
 *    Does the pitch of the tone increase or decrease if the delay values are
 *    made smaller? Does the opposite happen if the delays are made larger?
 * 
 * 3. Arduino has a built-in tone() function that can be used to make a
 *    specified sound frequency without the programmer needing to calculate a
 *    delay time period. Replace the code, above, with this code:
 
  SW5state = digitalRead(SW5);    // Make a tone when SW5 is pressed
  if(SW5state == LOW) {
    tone(BEEPER,880);
  }

 *    The tone can be silenced by pressing the RESET (SW1) button on ARPS, or
 *    in your program by using a 'noTone(BEEPER);' statement. Modify your
 *    program using either a second 'if' condition or an 'else' condition so
 *    that the it only plays while SW5 is held and stops when SW5 is released.
 *
 * 4. The setup() function includes a tone() function to make a sound on
 *    start-up. How is the tone() function in setup() different than the one
 *    in the example above? What does the third parameter control? (Hint:
 *    you can find out more about tone() in the Adruino reference documents.)
 * 
 * 5. Using modified versions of the original SW2 'if' structure, create a
 *    program that makes a unique LED flashing pattern for each pushbutton.
 * 
 *    Test each of your flashing patterns to verify that they work as expected.
 *    Describe what happens when more than one button is held. Do all of the
 *    patterns flash the LEDs at the same time, or in sequence? What sequence
 *    do they follow? Explain why this happens.
 * 
 * 6. Use individual 'if' structures to simulate 'Start' and 'Stop' buttons for
 *    an industrial machine. Use SW3 as the Start button to turn LED D3 on when
 *    it is pressed, and keep LED D3 on even after SW3 has been released. Use
 *    SW4 as the Stop button to turn LED D3 off when it is pressed. Test your
 *    program to make sure that it works the way you expect it to.
 * 
 * 7. Running your program from step 6, above, describe what happens when both
 *    pushbuttons SW3 and SW4 are held. Does LED D3 turn on? Does LED D3 stay
 *    on? If so, is its brightness the same when both buttons are held as when
 *    just SW3 is pressed? If the brightness is different, can you explain what
 *    part of the code might be causing it to change, and why it changes?
 *    Hint: pretend to be the computer and simulate what the program is doing.
 * 
 * 8. As you might imagine, an industrial machine that is able to turn on an
 *    output even while its 'Stop' button is pressed represents a significant
 *    safety hazard. Using one or more of the logical conditional operators
 *    introduced in the analysis activities, above, modify your start-stop
 *    program to make it safer. SW3 should only be able to turn LED D3 on if
 *    switch SW4 is not being pressed at the same time.
 *
 * 9. Create a program that uses the ARPS pushbuttons and LEDs to make a turn
 *    signal circuit for a bicycle. Use SW2 and SW5 to indicate left or right
 *    turns, and think about the best way to implement turn signals if a pair
 *    of similar momentary pushbuttons were mounted on a bicycle's handlebars.
 *    Would the user have to hold the button to keep the turn signal flashing,
 *    or would pressing the button once start the turn signal and keep it going
 *    until the button was pressed again to cancel it? What will the turn signal
 *    indication look like if the four LEDs were to be mounted horizontally
 *    under the seat of the bicycle? Write a program that implements your best
 *    turn signal solution using the concepts learned in this activity. Test
 *    your solution to ensure it behaves as expected under unusual use cases
 *    such as the user holding both buttons, for example.
 *
 *10. Modify your bike turn signal program, above, to use one or both of the
 *    other buttons to add brake functionality, and/or to implement a rapidly
 *    flashing tail-light for enhanced visibility. Test your program to ensure
 *    that all of its functions work as expected under all conditions.
 */
