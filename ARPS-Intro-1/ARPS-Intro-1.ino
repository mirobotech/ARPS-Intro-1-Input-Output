/*
 Project: Intro-1-Input-Output        Activity: mirobo.tech/arps-intro-1
 Updated: November 6, 2024
 
 This introductory programming activity for the mirobo.tech ARPS circuit
 demonstrates pushbutton input, LED outut, the use of time delay functions,
 and simple 'if ' condition structures.
 
 Additional programming analysis activities explore I/O pin behaviour,
 compare the operation of 'if' and 'while' structures, and demonstrate 
 logical conditional operators. Programming activities introduce the tone()
 function to create sounds, and encourage learners to create software-based
 simulated start-stop buttons and a bicycle turn signal program.
 
 See the https://mirobo.tech/arps website for more programming activities.
*/

// Define I/O pins used by ARPS human interface devices
const int SW2 = 0;      // Pushbuttons SW2 and SW3 are supported only on
const int SW3 = 1;      // Arduino UNO R4 Minima and Arduino UNO R4 WiFi
const int SW4 = 2;      // Pushbuttons SW4 and SW5 work on all Arduino UNO R3
const int SW5 = 3;      // and Arduino UNO R4 circuit boards

const int LED2 = 5;     // ARPS LEDs
const int LED3 = 6;
const int LED4 = 9;
const int LED5 = 10;

const int BEEPER = 11;  // ARPS Piezo beeper LS1

// Define variables
int SW2State;
int SW3State;
int SW4State;
int SW5State;

// Setup code runs once to configure I/O pins before running the main loop
void setup() {
  pinMode(SW2,INPUT_PULLUP);
  pinMode(SW3,INPUT_PULLUP);
  pinMode(SW4,INPUT_PULLUP);
  pinMode(SW5,INPUT_PULLUP);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(BEEPER,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  tone(BEEPER,4000,100);  // Say hello!
}

// Main loop code repeats forever
void loop() {
  SW2State = digitalRead(SW2);  // Change to SW4 or SW5 for Arduino Uno R3

  if(SW2State == LOW) {
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

/*  Learn More -- Program Analysis Activities

1.  Let's analyze this program! Program analysis is an important skill to
    develop since it helps you to understand a program's operation. Install
    your ARPS circuit on your Arduino, and then connect the Arduino to your
    computer. Press the Upload button at the top of the IDE screen (the large
    right-facing arrow) to start compiling this program sketch and then to
    upload the compiled program to the Arduino. Press and release pushbutton
    SW2 on your ARPS circuit while you observe its LEDs.

    What happens? How many LEDs flash? How many times does each LED flash? Do
    the LEDs flash again if SW2 is pressed and released a second time? What 
    happens if SW2 is held? Does the flashing pattern immediately stop when
    SW2 is released?

    Now, examine the program and try to match your observations with the 
    program's instructions. Explain why all of the LEDs flash on and off and
    why you think flashing pattern continues, instead of immediately turning
    off, when pushbutton SW2 is released.

2.  The first line of code in the program's main 'loop()' function is:

  SW2State = digitalRead(SW2);

    The digitalRead(SW2) function reads the voltage present on the pin
    defined earlier as SW2, and stores the voltage as one of two possible
    states, either HIGH or LOW, in the SW2State variable (also defined
    earlier in the program).

    The next if statement:

  if(SW2State == LOW) {

    compares the value stored in the SW2State variable with the value LOW. In
    C, and many other programming languages, two equal signs '==' are the
    conditional check for equality, while a single equal sign assigns a value.
    If the value stored in SW2State is LOW, all of the program statements
    enclosed within the curly braces '{ ... }' below the if statement will be
    run. If SW2State is high, the program code in the braces will be skipped.

    When the condition is true, the first output statement that runs is:

    digitalWrite(LED2,HIGH);

    This output statement sets the voltage of the pin previously defined as
    LED2 high, enabling current to flow through LED D2 on the circuit board.

    A few lines further down in the program, another LED output statement
    sets the LED2 pin low:

    digitalWrite(LED2,LOW);

    Both the input (digitalRead) and output (digitalWrite) statements use
    the same HIGH and LOW terms to represent input and output voltages.
    What voltages do you think the values HIGH and LOW correspond to?

3.  Each digitalWrite statement is followed by a short delay:

    delay(100);

    The 'delay()' function causes the microcontroller to pause for the amount
    of time specified in milliseconds. Try changing the delay time value to
    1000ms (1s) and re-upload the program again. Press SW2 while observing the
    LEDs. Did you notice the change? Experiment with delay values between 1
    and 10000 and observe the effect it has on your program.

4.  Understanding circuit operation is just as important as understanding
    program operation when analyzing and debugging interface devices (hardware
    components interacting with or controlled by software). If you have access
    to a voltmeter, you can use it to confirm the voltage measurements at
    different points in your circuit and to verify the HIGH and LOW values
    predicted above.
  
    Measure the potential across both leads of one of the pushbuttons while it
    is not being pressed. The microcontroller's pushbutton input pins have been
    configured with internal pull-up resistors enabled, so a voltage should be
    present as soon as the program starts running. Press and hold the pushbutton
    and you should see the voltage across the pushbutton change. Compare the
    measured values with your predicted voltage values from 2, above.

    Next, try measuring the potential across one of the LEDs. Note how the
    voltage changes when a pushbutton is pressed. The voltage will change
    quickly using the program's normal delay values, so you may need to use
    a 'peak hold' or 'max' feature of your multimeter (if it has one), or slow
    down the light pattern by increasing the delay after the the LED output
    instruction for the LED you're measuring.

    What voltage did you measure across the pushbutton? Is it the same as the
    voltage measured across the LED? Did the voltages match your predictions?
    Can you explain why the voltage potentials might be different if they did
    not match your predicted values? (Hint: refer to the ARPS circuit schematic
    to see how the pushbuttons and LEDs are connected.)

5.  Let's compare the operation of 'if' and 'while' structures by making two
    new program blocks that will simulate the operation of real-world momentary
    buttons. Copy and paste the program code, listed below, into your program
    between the existing SW2 'if' block and the 10ms sleep delay, as shown by
    the location of the comment in the program code.

  // Momentary button using an if structure
  SW4State = digitalRead(SW4);
  if(SW4State == LOW) {
      digitalWrite(LED4,HIGH);
  }
  else {
      digitalWrite(LED4,LOW);
  }

  // Momentary button using a while structure
  SW5State = digitalRead(SW5);
  while(SW5State == LOW) {
      digitalWrite(LED5,HIGH);
      SW5State = digitalRead(SW5);
  }
  digitalWrite(LED5,LOW);

    First, press and release pushbutton SW4. LED D4 should light only while
    SW4 is pressed. Next, press and release pushbutton SW5. LED D5 should
    operate exactly the same way as LED D4, staying lit only while SW5 is
    pressed. Both software functions are designed to effectively mimic the
    operation of real-world momentary pushbuttons, but implementing them in
    a series of software steps makes them behave differently than two 
    parallel hardware pushbutton circuits would.
    
    To see the difference, press and hold SW4, and while holding it press
    and release SW5. Do both switches still operate as expected?
    
    Now, press and hold SW5, and then press and release SW4 while holding SW5.
    Do both switches operate still as expected?
    
    Can you explain the differences in the operation of the 'if' and 'while'
    structures used to make the momentary button functions in the program code?
    What happens inside each of the switch structure during the operation of
    the program when each switch is pressed and released? How do both the if
    structure and the while structure alter the program flow through the main
    program loop?

6.  Comment-out the second 'SW5State = digitalRead(SW5);' statement inside 
    the while loop by adding two slashes '//' at the beginning of the line,
    like this: '//SW5State = digitalRead(SW5);'. Re-upload your program and
    test SW5 again. After that, try testing SW4 and SW5. Do they still work?
    If the program seems to be getting stuck, press and release the SW1
    RESET pushbutton on ARSP to re-start it. Explain what you think is
    happening and why the microcontroller might be operating that way.

7.  Next, let's try nesting if conditions to mimic an operator safety circuit
    on an industrial machine. To prevent operator injury, some machines use
    two, widely-spaced start buttons that the machine operator is required to
    press at the same time to activate the machine. The machine will be
    represented by LED D5, and the new program code, below, will replace the
    momentary button code added above to create a logical AND input condition
    that only lights LED D5 when both SW4 and SW5 are pressed. (Make sure you
    remove the SW4 and SW5 code added above because it will prevent this new
    program code from working properly.)

  SW4State = digitalRead(SW4);
  SW5State = digitalRead(SW5);

  if(SW4State == LOW) {
    if(SW5State == LOW) {
      digitalWrite(LED4,HIGH);
    }
    else {
      digitalWrite(LED4,LOW);
    }
  }
  else {
    digitalWrite(LED4,LOW);
  }

    Test the code to ensure it works as expected. Does the order of button
    presses matter? Do you think the order of the conditional checks in the
    program matters? Try swapping the checks for SW4 and SW5 to test it if
    you are unsure.

8.  As seen in the example above, nesting conditions does work, but there is
    an easier and shorter way to accomplish the same task by implementing the
    logical AND conditional operator represented by two ampersands '&&'. This
    is the programming equivalent of an AND gate circuit. Replace the code
    added above with the new code which implements the logical AND operator:

  SW4State = digitalRead(SW4);
  SW5State = digitalRead(SW5);
  
  if(SW4State == LOW && SW5State == LOW) {
    digitalWrite(LED4,HIGH);
  }
  else {
    digitalWrite(LED4,LOW);
  }

    Run the code and test it to ensure it works as expected. Can you think of
    at least two advantages of using a logical conditional operator instead of
    nested if structures as in the previous example?
    
9.  If a logical AND operator can implemented in a progrma condition, it seems
    reasonable to expect that a logical OR operator should also exist. In C
    language programs, the logical OR operator is represented by double
    vertical bars '||'. Replace the double ampersand '&&' with double vertical
    bars '||' to make your program implement a logical OR condition. Your code
    should now look like this:

  SW4State = digitalRead(SW4);
  SW5State = digitalRead(SW5);
  
  if(SW4State == LOW || SW5State == LOW) {
    digitalWrite(LED4,HIGH);
  }
  else {
    digitalWrite(LED4,LOW);
  }

    Run the code and test it. List the conditions under which LED D4 turns on.
    Do these conditions match the truth table of an OR gate circuit?

10. The equivalent of the XOR logical operation is inequality -- the output
    will be true only when one input is different, or not equal, to the other.
    Inequality in a C program is represented by the '!=' (not equal to)
    conditional operator. Try this:

  SW4State = digitalRead(SW4);
  SW5State = digitalRead(SW5);
  
  if(SW4State != SW5State) {
    digitalWrite(LED4,HIGH);
  }
  else {
    digitalWrite(LED4,LOW);
  }

    Does it correctly mimic the output of an XOR gate? Can you re-create the
    XOR operation using the quality '==' operator instead of using the 
    inequality '!=' operator, and still produce the same output? Try it!

Programming Activities

1.  The 'delay(100);' function pauses the microcontroller for 100 milliseconds,
    or 0.1 seconds. Since the delay() function can only support whole numbers,
    a different delay function is provided for making delays shorter than 1ms:

    delayMicroseconds()  - pauses for the specified number of microseconds

    Look up the delay() and delayMicroseconds() functions in the Arduino
    reference documentation. What is one problem you might run into when using
    the delay() function to make long delays in your program? When using the
    delayMicroseconds() function to make delays, what delay length should not
    be exceeded?

2.  Microsecond-length time delays are too short to be seen with our eyes but
    can be measured using an oscilloscope, or heard as an audio tone if they
    are used to turn the piezo speaker on and off.

    Try the following code in your program. The delay between each change in
    the BEEPER pin's output voltage is half of the time period of a wave of
    music note A5, so when SW5 is pressed your circuit should play a tone at a
    frequency of approximately 880 Hz.

  SW5State = digitalRead(SW5);    // Make a tone while SW5 is held
  if(SW5State == LOW) {
    digitalWrite(BEEPER,HIGH);
    delayMicroseconds(568);
    digitalWrite(BEEPER,LOW);
    delayMicroseconds(568);
  }

    If you try to run the program after adding this section, you'll find that
    pressing and holding SW5 will make a buzzing noise, and not a very musical
    sounding tone. Can you figure out why?
    
    Did you figure it out? After the last 568us (microsecond) delay, the
    delay(10); statement adds an extra 10ms of delay before the BEEPER pin
    changes its value again. This creates an extra-long low period of 10568us
    instead of being the same as the 568us high delay the program was trying
    to match! The simplest way to fix the program is by commenting out the
    10ms delay at the end of the program loop with two slashes, as shown:

  // delay(10);

    Run the program and press SW5. Does it sound more like a tone now? Try
    altering both delay values together. Does the pitch of the tone increase
    or decrease when the delay values are made smaller? Does the opposite
    happen if the delay values are made larger?
 
3.  Arduino has a built-in tone() function that can be used to make a specified
    sound frequency without having to calculate a delay time period and create
    a wave in software. Replace the code, added above, with this code:
 
  SW5State = digitalRead(SW5);    // Make a tone when SW5 is pressed
  if(SW5State == LOW) {
    tone(BEEPER,880);
  }

    The tone can be silenced by pressing the RESET (SW1) button on ARPS, or
    in your program by using a 'noTone(BEEPER);' statement. Modify your
    program using either a second 'if' condition or an 'else' condition so
    that it plays a tone while SW5 is held and stops when SW5 is released.

4.  The setup() function includes a tone() function that makes a sound on
    start-up. How is the tone function in the setup function different than
    the one in the example above? What does the third parameter control? (Hint:
    you can find out more about tone in the Arduino reference documents.)
 
5.  Create a program that uses each button to either generate a unique flashing
    pattern on the LEDs, or to play a sequence of tones from the piezo speaker.
    
    Test each of your flashing and sound patterns to verify that they work
    as expected. Describe what happens when multiple buttons are held. Do all
    of the patterns flash the LEDs at the same time, or at the same time as the
    tones play, or do the patterns and tones play in sequence? What sequence do
    they follow? Explain why this is the case.
 
6.  Create a new program that uses individual if structures to simulate the
    operation of 'Start' and 'Stop' buttons for an industrial machine. Use SW4
    as the Start button to turn LED D5 (representing the machine) on when it
    is pressed, and ensure that LED D5 stays on even after SW4 has been
    released. Use SW5 as the Stop button so that it turns LED D5 off when it
    is pressed. Test your program to ensure that your simulated machine turns
    on and off as expected.
    
7.  Run the Start-Stop program created in the previous step again, and describe
    the result when both pushbuttons SW4 and SW5 are held. Does LED D5 turn on?
    Would this be safe behaviour?
    
    Let's do some additional program analysis. If LED D5 turns on, is its
    brightness the same when both SW4 and SW5 are held as when just SW4 has
    been pressed? If the brightness is different, can you explain what part
    of your program might be causing it to change, and why it changes? Hint: 
    pretend to be the computer and simulate each step of the program.

8.  As you might imagine, an industrial machine that is able to turn on even
    while its Stop button is pressed is a significant safety hazard. Use one or
    more of the logical conditional operators introduced in the program analysis
    activities, above, to make your program operate safely. The machine should
    never be able to turn on while the Stop button is being pressed.

9.  With your newly-acquired microcontroller and programming experience you've
    decided to create a turn signal circuit for your bicycle. Assume that up to
    four LEDs can easily be mounted on the bicycle's seat post, and that these
    LEDs will be controlled by at least two momentary pushbuttons mounted on the
    bicycle's handlebars. Plan the best way to implement turn signals, both for
    effective signalling and good visibility, and then write a program that uses
    the LEDs and pushbuttons on ARPS to simulate the operation of the turn
    signals.

10. Modify the bicycle turn signal program, above, to add one or more extra
    features such as a brake signal, a horn or bell function, or a rapidly
    flashing visibility light that can be activated using the unused buttons.
    Test your program to ensure that its functions work as expected under all
    operating conditions (e.g. signalling while braking, or using the bell).

*/