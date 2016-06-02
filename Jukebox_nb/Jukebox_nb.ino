#include <Bounce.h>

#include <Adafruit_VS1053.h>
#include <SPI.h>
#include <SD.h>


#define BREAKOUT_RESET 9
#define BREAKOUT_CS 10
#define BREAKOUT_DCS 8

#define CARDCS 4
#define DREQ 3

Adafruit_VS1053_FilePlayer musicPlayer = Adafruit_VS1053_FilePlayer(BREAKOUT_RESET, BREAKOUT_CS, BREAKOUT_DCS, DREQ, CARDCS);

const int A = 22;
const int B = 23;
const int C = 24;
const int D = 25;
const int E = 26;
const int F = 27;
const int G = 28;
const int H = 29;
const int J = 30;
const int K = 31;

const int L = 32;
const int M = 33;
const int N = 34;
const int P = 35;
const int Q = 36;
const int R = 37;
const int S = 38;
const int T = 39;
const int U = 40;
const int V = 41;

const int One = 42;
const int Two = 43;
const int Three = 44;
const int Four = 45;
const int Five = 46;
const int Six = 47;
const int Seven = 48;
const int Eight = 49;

const int Relay = 21;
const int Motor = 20;

const int Reset = 12;

const String MP3 = ".mp3";

Bounce RBbutton = Bounce (Reset, 10);
int counter = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  pinMode(E, INPUT);
  pinMode(F, INPUT);
  pinMode(G, INPUT);
  pinMode(H, INPUT);
  pinMode(J, INPUT);
  pinMode(K, INPUT);

  pinMode(L, INPUT);
  pinMode(M, INPUT);
  pinMode(N, INPUT);
  pinMode(P, INPUT);
  pinMode(Q, INPUT);
  pinMode(R, INPUT);
  pinMode(S, INPUT);
  pinMode(T, INPUT);
  pinMode(U, INPUT);
  pinMode(V, INPUT);

  pinMode(One, INPUT);
  pinMode(Two, INPUT);
  pinMode(Three, INPUT);
  pinMode(Four, INPUT);
  pinMode(Five, INPUT);
  pinMode(Six, INPUT);
  pinMode(Seven, INPUT);
  pinMode(Eight, INPUT);

  pinMode(Reset, INPUT_PULLUP);

  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, LOW);

  pinMode(Motor, OUTPUT);
  digitalWrite(Motor, HIGH);

  if (Serial) {
    Serial.begin(9600);
  }
  Serial.println("Initialize VS1053");
  if (!musicPlayer.begin()) {
    Serial.println("VS1053 NotFound");
    while (1);
  }
  Serial.println("VS1053 Initialized");
  SD.begin(CARDCS);
  Serial.println("SD Card Initialized");
  Serial.println("Jukebox Initialized");

  musicPlayer.setVolume(20, 20);

  musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);

}

void ResetButtons()
{
  delay(500);
  digitalWrite(Relay, HIGH);
  delay(250);
  digitalWrite(Relay, LOW);

}

void ButtonsOn() {
  delay(500);
  digitalWrite(Relay, LOW);
}

void ButtonsOff() {
  delay(500);
  digitalWrite(Relay, HIGH);

}

void PlayTrack (String TrackNumber)
{
  counter = 0;
  delay(500);
  char track2Play[7];
 (TrackNumber + MP3).toCharArray(track2Play, 7);
  Serial.println(track2Play);
  musicPlayer.startPlayingFile(track2Play);
  //Serial.println("Done Playing Track");
  //ButtonsOn();

}

void MotorOn() {
  digitalWrite(Motor, HIGH);
}

void MotorOff() {
  digitalWrite(Motor, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( musicPlayer.playingMusic) {
    MotorOn();
    if (digitalRead(Reset) == LOW) {
      musicPlayer.stopPlaying();
      Serial.println("ResetPressed");
      ButtonsOn();
      MotorOff();
      musicPlayer.softReset();
    }
  }
  else {
    //Serial.println("Track Finished");
    ButtonsOn();
    MotorOff();

    if (RBbutton.update()){
      if(RBbutton.fallingEdge()){
        counter+=1;
        if (counter <= 5){
          counter = 0;
          ButtonsOff();
          PlayTrack("Godzilla");
        }
      }
    }

    if (digitalRead(One) == HIGH)
    {
      Serial.println("Button 1 Pressed");
      if (digitalRead(A) == HIGH) {
        //Play Track 1
        Serial.println("Button A Pressed");
        Serial.println("Play Track A1");
        ButtonsOff();
        PlayTrack("A1");

      }
      if (digitalRead(B) == HIGH) {
        //Play Track 2
        Serial.println("Button B Pressed");
        Serial.println("Play Track B1");
        ButtonsOff();
        PlayTrack("B1");

      }
      if (digitalRead(C) == HIGH) {
        //Play Track 3
        Serial.println("Button C Pressed");
        Serial.println("Play Track C1");
        ButtonsOff();
        PlayTrack("C1");

      }
      if (digitalRead(D) == HIGH) {
        //Play Track 4
        Serial.println("Button D Pressed");
        Serial.println("Play Track D1");
        ButtonsOff();
        PlayTrack("D1");

      }
      if (digitalRead(E) == HIGH) {
        //Play Track 5
        Serial.println("Button E Pressed");
        Serial.println("Play Track E1");
        ButtonsOff();
        PlayTrack("E1");

      }
      if (digitalRead(F) == HIGH) {
        //Play Track 6
        Serial.println("Button F Pressed");
        Serial.println("Play Track F1");
        ButtonsOff();
        PlayTrack("F1");

      }
      if (digitalRead(G) == HIGH) {
        //Play Track 7
        Serial.println("Button G Pressed");
        Serial.println("Play Track G1");
        ButtonsOff();
        PlayTrack("G1");

      }
      if (digitalRead(H) == HIGH) {
        //Play Track 8
        Serial.println("Button H Pressed");
        Serial.println("Play Track H1");
        ButtonsOff();
        PlayTrack("H1");

      }
      if (digitalRead(J) == HIGH) {
        //Play Track 8
        Serial.println("Button J Pressed");
        Serial.println("Play Track J1");
        ButtonsOff();
        PlayTrack("J1");

      }
      if (digitalRead(K) == HIGH) {
        //Play Track 8
        Serial.println("Button K Pressed");
        Serial.println("Play Track K1");
        ButtonsOff();
        PlayTrack("K1");

      }
      if (digitalRead(L) == HIGH) {
        //Play Track 8
        Serial.println("Button L Pressed");
        Serial.println("Play Track L1");
        ButtonsOff();
        PlayTrack("L1");

      }
      if (digitalRead(M) == HIGH) {
        //Play Track 8
        Serial.println("Button M Pressed");
        Serial.println("Play Track M1");
        ButtonsOff();
        PlayTrack("M1");

      }
      if (digitalRead(N) == HIGH) {
        //Play Track 8
        Serial.println("Button N Pressed");
        Serial.println("Play Track N1");
        ButtonsOff();
        PlayTrack("N1");

      }
      if (digitalRead(P) == HIGH) {
        //Play Track 8
        Serial.println("Button P Pressed");
        Serial.println("Play Track P1");
        ButtonsOff();
        PlayTrack("P1");

      }
      if (digitalRead(Q) == HIGH) {
        //Play Track 8
        Serial.println("Button Q Pressed");
        Serial.println("Play Track Q1");
        ButtonsOff();
        PlayTrack("Q1");

      }
      if (digitalRead(R) == HIGH) {
        //Play Track 8
        Serial.println("Button R Pressed");
        Serial.println("Play Track R1");
        ButtonsOff();
        PlayTrack("R1");

      }
      if (digitalRead(S) == HIGH) {
        //Play Track 8
        Serial.println("Button S Pressed");
        Serial.println("Play Track S1");
        ButtonsOff();
        PlayTrack("S1");

      }
      if (digitalRead(T) == HIGH) {
        //Play Track 8
        Serial.println("Button T Pressed");
        Serial.println("Play Track T1");
        ButtonsOff();
        PlayTrack("T1");

      }      if (digitalRead(U) == HIGH) {
        //Play Track 8
        Serial.println("Button U Pressed");
        Serial.println("Play Track U1");
        ButtonsOff();
        PlayTrack("U1");

      }
      if (digitalRead(V) == HIGH) {
        //Play Track 8
        Serial.println("Button V Pressed");
        Serial.println("Play Track V1");
        ButtonsOff();
        PlayTrack("V1");

      }
    }

    if (digitalRead(Two) == HIGH)
    {
      Serial.println("Button B Pressed");
      if (digitalRead(A) == HIGH) {
        //Play Track 1
        Serial.println("Button 1 Pressed");
        Serial.println("Play Track 1");
        ButtonsOff();
        PlayTrack("A2");

      }
      if (digitalRead(B) == HIGH) {
        //Play Track 2
        Serial.println("Button 2 Pressed");
        Serial.println("Play Track 2");
        ButtonsOff();
        PlayTrack("B2");

      }
      if (digitalRead(C) == HIGH) {
        //Play Track 3
        Serial.println("Button 3 Pressed");
        Serial.println("Play Track 3");
        ButtonsOff();
        PlayTrack("C2");

      }
      if (digitalRead(D) == HIGH) {
        //Play Track 4
        Serial.println("Button 4 Pressed");
        Serial.println("Play Track 4");
        ButtonsOff();
        PlayTrack("D2");

      }
      if (digitalRead(E) == HIGH) {
        //Play Track 5
        Serial.println("Button 5 Pressed");
        Serial.println("Play Track 5");
        ButtonsOff();
        PlayTrack("E2");

      }
      if (digitalRead(F) == HIGH) {
        //Play Track 6
        Serial.println("Button 6 Pressed");
        Serial.println("Play Track 6");
        ButtonsOff();
        PlayTrack("F2");

      }
      if (digitalRead(G) == HIGH) {
        //Play Track 7
        Serial.println("Button 7 Pressed");
        Serial.println("Play Track 7");
        ButtonsOff();
        PlayTrack("G2");

      }
      if (digitalRead(H) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("H2");

      }
      if (digitalRead(J) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("J2");

      }
      if (digitalRead(K) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("K2");

      }
      if (digitalRead(L) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("L2");

      }
      if (digitalRead(M) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("M2");

      }
      if (digitalRead(N) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("N2");

      }
      if (digitalRead(P) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("P2");

      }
      if (digitalRead(Q) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("Q2");

      }
      if (digitalRead(R) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("R2");

      }
      if (digitalRead(S) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("S2");

      }
      if (digitalRead(T) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("T2");

      }      if (digitalRead(U) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("U2");

      }
      if (digitalRead(V) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("V2");
      }
    }

    if (digitalRead(Three) == HIGH)
    {
      Serial.println("Button C Pressed");
      if (digitalRead(A) == HIGH) {
        //Play Track 1
        Serial.println("Button 1 Pressed");
        Serial.println("Play Track 1");
        ButtonsOff();
        PlayTrack("A3");

      }
      if (digitalRead(B) == HIGH) {
        //Play Track 2
        Serial.println("Button 2 Pressed");
        Serial.println("Play Track 2");
        ButtonsOff();
        PlayTrack("B3");

      }
      if (digitalRead(C) == HIGH) {
        //Play Track 3
        Serial.println("Button 3 Pressed");
        Serial.println("Play Track 3");
        ButtonsOff();
        PlayTrack("C3");

      }
      if (digitalRead(D) == HIGH) {
        //Play Track 4
        Serial.println("Button 4 Pressed");
        Serial.println("Play Track 4");
        ButtonsOff();
        PlayTrack("D3");

      }
      if (digitalRead(E) == HIGH) {
        //Play Track 5
        Serial.println("Button 5 Pressed");
        Serial.println("Play Track 5");
        ButtonsOff();
        PlayTrack("E3");

      }
      if (digitalRead(F) == HIGH) {
        //Play Track 6
        Serial.println("Button 6 Pressed");
        Serial.println("Play Track 6");
        ButtonsOff();
        PlayTrack("F3");

      }
      if (digitalRead(G) == HIGH) {
        //Play Track 7
        Serial.println("Button 7 Pressed");
        Serial.println("Play Track 7");
        ButtonsOff();
        PlayTrack("G3");

      }
      if (digitalRead(H) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("H3");

      }
      if (digitalRead(J) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("J3");

      }
      if (digitalRead(K) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("K3");

      }
      if (digitalRead(L) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("L3");

      }
      if (digitalRead(M) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("M3");

      }
      if (digitalRead(N) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("N3");

      }
      if (digitalRead(P) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("P3");

      }
      if (digitalRead(Q) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("Q3");

      }
      if (digitalRead(R) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("R3");

      }
      if (digitalRead(S) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("S3");

      }
      if (digitalRead(T) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("T3");

      }      if (digitalRead(U) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("U3");

      }
      if (digitalRead(V) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("V3");
      }
    }

    if (digitalRead(Four) == HIGH)
    {
      Serial.println("Button D Pressed");
            if (digitalRead(A) == HIGH) {
        //Play Track 1
        Serial.println("Button 1 Pressed");
        Serial.println("Play Track 1");
        ButtonsOff();
        PlayTrack("A4");
        
      }
      if (digitalRead(B) == HIGH) {
        //Play Track 2
        Serial.println("Button 2 Pressed");
        Serial.println("Play Track 2");
        ButtonsOff();
        PlayTrack("B4");
        
      }
      if (digitalRead(C) == HIGH) {
        //Play Track 3
        Serial.println("Button 3 Pressed");
        Serial.println("Play Track 3");
        ButtonsOff();
        PlayTrack("C4");
        
      }
      if (digitalRead(D) == HIGH) {
        //Play Track 4
        Serial.println("Button 4 Pressed");
        Serial.println("Play Track 4");
        ButtonsOff();
        PlayTrack("D4");
        
      }
      if (digitalRead(E) == HIGH) {
        //Play Track 5
        Serial.println("Button 5 Pressed");
        Serial.println("Play Track 5");
        ButtonsOff();
        PlayTrack("E4");
        
      }
      if (digitalRead(F) == HIGH) {
        //Play Track 6
        Serial.println("Button 6 Pressed");
        Serial.println("Play Track 6");
        ButtonsOff();
        PlayTrack("F4");
        
      }
      if (digitalRead(G) == HIGH) {
        //Play Track 7
        Serial.println("Button 7 Pressed");
        Serial.println("Play Track 7");
        ButtonsOff();
        PlayTrack("G4");
        
      }
      if (digitalRead(H) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("H4");
        
      }
            if (digitalRead(J) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("J4");
        
      }
            if (digitalRead(K) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("K4");
        
      }
            if (digitalRead(L) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("L4");
        
      }
            if (digitalRead(M) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("M4");
        
      }
            if (digitalRead(N) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("N4");
        
      }
            if (digitalRead(P) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("P4");
        
      }
            if (digitalRead(Q) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("Q4");
        
      }
            if (digitalRead(R) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("R4");
        
      }
            if (digitalRead(S) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("S4");
        
      }
            if (digitalRead(T) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("T4");
        
      }      if (digitalRead(U) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("U4");
        
      }
            if (digitalRead(V) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("V4");
    }
    }
    if (digitalRead(Five) == HIGH)
    {
      Serial.println("Button E Pressed");
            if (digitalRead(A) == HIGH) {
        //Play Track 1
        Serial.println("Button 1 Pressed");
        Serial.println("Play Track 1");
        ButtonsOff();
        PlayTrack("A5");
        
      }
      if (digitalRead(B) == HIGH) {
        //Play Track 2
        Serial.println("Button 2 Pressed");
        Serial.println("Play Track 2");
        ButtonsOff();
        PlayTrack("B5");
        
      }
      if (digitalRead(C) == HIGH) {
        //Play Track 3
        Serial.println("Button 3 Pressed");
        Serial.println("Play Track 3");
        ButtonsOff();
        PlayTrack("C5");
        
      }
      if (digitalRead(D) == HIGH) {
        //Play Track 4
        Serial.println("Button 4 Pressed");
        Serial.println("Play Track 4");
        ButtonsOff();
        PlayTrack("D5");
        
      }
      if (digitalRead(E) == HIGH) {
        //Play Track 5
        Serial.println("Button 5 Pressed");
        Serial.println("Play Track 5");
        ButtonsOff();
        PlayTrack("E5");
        
      }
      if (digitalRead(F) == HIGH) {
        //Play Track 6
        Serial.println("Button 6 Pressed");
        Serial.println("Play Track 6");
        ButtonsOff();
        PlayTrack("F5");
        
      }
      if (digitalRead(G) == HIGH) {
        //Play Track 7
        Serial.println("Button 7 Pressed");
        Serial.println("Play Track 7");
        ButtonsOff();
        PlayTrack("G5");
        
      }
      if (digitalRead(H) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("H5");
        
      }
            if (digitalRead(J) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("J5");
        
      }
            if (digitalRead(K) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("K5");
        
      }
            if (digitalRead(L) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("L5");
        
      }
            if (digitalRead(M) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("M5");
        
      }
            if (digitalRead(N) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("N5");
        
      }
            if (digitalRead(P) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("P5");
        
      }
            if (digitalRead(Q) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("Q5");
        
      }
            if (digitalRead(R) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("R5");
        
      }
            if (digitalRead(S) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("S5");
        
      }
            if (digitalRead(T) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("T5");
        
      }      if (digitalRead(U) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("U5");
        
      }
            if (digitalRead(V) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("V5");
      }
    }

    if (digitalRead(Six) == HIGH)
    {
      Serial.println("Button F Pressed");
            if (digitalRead(A) == HIGH) {
        //Play Track 1
        Serial.println("Button 1 Pressed");
        Serial.println("Play Track 1");
        ButtonsOff();
        PlayTrack("A6");
        
      }
      if (digitalRead(B) == HIGH) {
        //Play Track 2
        Serial.println("Button 2 Pressed");
        Serial.println("Play Track 2");
        ButtonsOff();
        PlayTrack("B6");
        
      }
      if (digitalRead(C) == HIGH) {
        //Play Track 3
        Serial.println("Button 3 Pressed");
        Serial.println("Play Track 3");
        ButtonsOff();
        PlayTrack("C6");
        
      }
      if (digitalRead(D) == HIGH) {
        //Play Track 4
        Serial.println("Button 4 Pressed");
        Serial.println("Play Track 4");
        ButtonsOff();
        PlayTrack("D6");
        
      }
      if (digitalRead(E) == HIGH) {
        //Play Track 5
        Serial.println("Button 5 Pressed");
        Serial.println("Play Track 5");
        ButtonsOff();
        PlayTrack("E6");
        
      }
      if (digitalRead(F) == HIGH) {
        //Play Track 6
        Serial.println("Button 6 Pressed");
        Serial.println("Play Track 6");
        ButtonsOff();
        PlayTrack("F6");
        
      }
      if (digitalRead(G) == HIGH) {
        //Play Track 7
        Serial.println("Button 7 Pressed");
        Serial.println("Play Track 7");
        ButtonsOff();
        PlayTrack("G6");
        
      }
      if (digitalRead(H) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("H6");
        
      }
            if (digitalRead(J) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("J6");
        
      }
            if (digitalRead(K) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("K6");
        
      }
            if (digitalRead(L) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("L6");
        
      }
            if (digitalRead(M) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("M6");
        
      }
            if (digitalRead(N) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("N6");
        
      }
            if (digitalRead(P) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("P6");
        
      }
            if (digitalRead(Q) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("Q6");
        
      }
            if (digitalRead(R) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("R6");
        
      }
            if (digitalRead(S) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("S6");
        
      }
            if (digitalRead(T) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("T6");
        
      }      if (digitalRead(U) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("U6");
        
      }
            if (digitalRead(V) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("V6");
      }
    }

    if (digitalRead(Seven) == HIGH)
    {
      Serial.println("Button G Pressed");
      if (digitalRead(A) == HIGH) {
        //Play Track 1
        Serial.println("Button 1 Pressed");
        Serial.println("Play Track 1");
        ButtonsOff();
        PlayTrack("A7");
        
      }
      if (digitalRead(B) == HIGH) {
        //Play Track 2
        Serial.println("Button 2 Pressed");
        Serial.println("Play Track 2");
        ButtonsOff();
        PlayTrack("B7");
        
      }
      if (digitalRead(C) == HIGH) {
        //Play Track 3
        Serial.println("Button 3 Pressed");
        Serial.println("Play Track 3");
        ButtonsOff();
        PlayTrack("C7");
        
      }
      if (digitalRead(D) == HIGH) {
        //Play Track 4
        Serial.println("Button 4 Pressed");
        Serial.println("Play Track 4");
        ButtonsOff();
        PlayTrack("D7");
        
      }
      if (digitalRead(E) == HIGH) {
        //Play Track 5
        Serial.println("Button 5 Pressed");
        Serial.println("Play Track 5");
        ButtonsOff();
        PlayTrack("E7");
        
      }
      if (digitalRead(F) == HIGH) {
        //Play Track 6
        Serial.println("Button 6 Pressed");
        Serial.println("Play Track 6");
        ButtonsOff();
        PlayTrack("F7");
        
      }
      if (digitalRead(G) == HIGH) {
        //Play Track 7
        Serial.println("Button 7 Pressed");
        Serial.println("Play Track 7");
        ButtonsOff();
        PlayTrack("G7");
        
      }
      if (digitalRead(H) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("H7");
        
      }
            if (digitalRead(J) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("J7");
        
      }
            if (digitalRead(K) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("K7");
        
      }
            if (digitalRead(L) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("L7");
        
      }
            if (digitalRead(M) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("M7");
        
      }
            if (digitalRead(N) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("N7");
        
      }
            if (digitalRead(P) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("P7");
        
      }
            if (digitalRead(Q) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("Q7");
        
      }
            if (digitalRead(R) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("R7");
        
      }
            if (digitalRead(S) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("S7");
        
      }
            if (digitalRead(T) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("T7");
        
      }      if (digitalRead(U) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("U7");
        
      }
            if (digitalRead(V) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("V7");

      }
    }

    if (digitalRead(Eight) == HIGH)
    {
           Serial.println("Button G Pressed");
      if (digitalRead(A) == HIGH) {
        //Play Track 1
        Serial.println("Button 1 Pressed");
        Serial.println("Play Track 1");
        ButtonsOff();
        PlayTrack("A8");
        
      }
      if (digitalRead(B) == HIGH) {
        //Play Track 2
        Serial.println("Button 2 Pressed");
        Serial.println("Play Track 2");
        ButtonsOff();
        PlayTrack("B8");
        
      }
      if (digitalRead(C) == HIGH) {
        //Play Track 3
        Serial.println("Button 3 Pressed");
        Serial.println("Play Track 3");
        ButtonsOff();
        PlayTrack("C8");
        
      }
      if (digitalRead(D) == HIGH) {
        //Play Track 4
        Serial.println("Button 4 Pressed");
        Serial.println("Play Track 4");
        ButtonsOff();
        PlayTrack("D8");
        
      }
      if (digitalRead(E) == HIGH) {
        //Play Track 5
        Serial.println("Button 5 Pressed");
        Serial.println("Play Track 5");
        ButtonsOff();
        PlayTrack("E8");
        
      }
      if (digitalRead(F) == HIGH) {
        //Play Track 6
        Serial.println("Button 6 Pressed");
        Serial.println("Play Track 6");
        ButtonsOff();
        PlayTrack("F8");
        
      }
      if (digitalRead(G) == HIGH) {
        //Play Track 7
        Serial.println("Button 7 Pressed");
        Serial.println("Play Track 7");
        ButtonsOff();
        PlayTrack("G8");
        
      }
      if (digitalRead(H) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("H8");
        
      }
            if (digitalRead(J) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("J8");
        
      }
            if (digitalRead(K) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("K8");
        
      }
            if (digitalRead(L) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("L8");
        
      }
            if (digitalRead(M) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("M8");
        
      }
            if (digitalRead(N) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("N8");
        
      }
            if (digitalRead(P) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("P8");
        
      }
            if (digitalRead(Q) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("Q8");
        
      }
            if (digitalRead(R) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("R8");
        
      }
            if (digitalRead(S) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("S8");
        
      }
            if (digitalRead(T) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("T8");
        
      }      if (digitalRead(U) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("U8");
        
      }
            if (digitalRead(V) == HIGH) {
        //Play Track 8
        Serial.println("Button 8 Pressed");
        Serial.println("Play Track 8");
        ButtonsOff();
        PlayTrack("V8");

      }
    }
    //For Serial Debugging
    //delay(500);
  }
}
