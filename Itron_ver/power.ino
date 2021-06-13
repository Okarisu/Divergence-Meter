/*
           A
        -------
        |     |
      F |     | B
        |  G  |
        -------
        |     |
      E |     | C
        |  D  |   _
        -------  |H|
*/

//segment pinnout
int segmentA = 1;
int segmentB = 2;
int segmentC = 3;
int segmentD = 4;
int segmentE = 5;
int segmentF = 6;
int segmentG = 7;
int segmentH = 8;

//grid pinnout
int grid1 = 9;
int grid2 = 10;
int grid3 = 11;
int grid4 = 12;
int grid5 = 13;
int grid6 = 14;
int grid7 = 15;
int grid8 = 16;

int numberToDisplay;
int gridToPower;

void beginState()
{
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(segmentH, OUTPUT);

  pinMode(grid1, OUTPUT);
  pinMode(grid2, OUTPUT);
  pinMode(grid3, OUTPUT);
  pinMode(grid4, OUTPUT);
  pinMode(grid5, OUTPUT);
  pinMode(grid6, OUTPUT);
  pinMode(grid7, OUTPUT);
  pinMode(grid8, OUTPUT);

  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentD, HIGH);
  digitalWrite(segmentE, HIGH);
  digitalWrite(segmentF, HIGH);
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentH, HIGH);

  digitalWrite(grid1, HIGH);
  digitalWrite(grid2, HIGH);
  digitalWrite(grid3, HIGH);
  digitalWrite(grid4, HIGH);
  digitalWrite(grid5, HIGH);
  digitalWrite(grid6, HIGH);
  digitalWrite(grid7, HIGH);
  digitalWrite(grid8, HIGH);
}

if (display1)
{
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, LOW);
}

if (power1)
{
  digitalWrite(grid1, LOW);
}

void itron1()
{
}

for (int gridToPower = 1; gridToPower <= 8; gridToPower++)
{
  digitalWrite(gridToPower, LOW);
}