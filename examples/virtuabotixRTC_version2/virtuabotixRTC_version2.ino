//=======================================================================================================//|
//                                                                                                       //|
//                                        Program Description Begin                                      //|
//                                                                                                       //|
//=======================================================================================================//|
//                                                                                                       //|
//  This example executes a print out example that accesses individual data elements.                    //|
//                                                                                                       //|
//=======================================================================================================//|
//                                                                                                       //|
//                                        Program Description End                                        //|
//                                                                                                       //|
//=======================================================================================================//|


//=======================================================================================================//|
//                                                                                                       //|
//                                 This is the Revision Section Begin                                    //|
//                                                                                                       //|
//=======================================================================================================//|
//                                                                                                       //|
//    Date                  Programmer                  Revisions Made                                   //|
//                                                                                                       //|
//    XX June 2012          Krodal                      Original                                         //|
//    XX March 2013         Krodal                      Added bcd2bin, bin2bcd_h, and bin2bcd_l functions//|
//    07 January 2014       Joseph Datillo              Converted file into library format.              //|
//                          T. Daniel Murphy            Added functions to allow for user implentation   //|
//                                                        as a library, vice a stand alone program.      //|
//                                                        This also adds the functions required to access//|
//                                                        individual data elements, and updating time.   //|
//                                                                                                       //|
//=======================================================================================================//|
//                                                                                                       //|
//                                        Revision Section End                                           //|
//                                                                                                       //|
//=======================================================================================================//|


//=======================================================================================================//|
//                                                                                                       //|
//                                        Acknowledgements Begin                                         //|
//                                                                                                       //|
//=======================================================================================================//|
//                                                                                                       //|
//  The original program was provided by Arduino.cc user Kodal on URL:                                   //|
//  http://playground.arduino.cc/Main/DS1302                                                             //|
//                                                                                                       //|
//=======================================================================================================//|
//                                                                                                       //|
//                                          Acknowledgements End                                         //|
//                                                                                                       //|
//=======================================================================================================//|


//=======================================================================================================//|
//                                                                                                       //|
//                                            Reference Links Begin                                      //|
//                                                                                                       //|
//=======================================================================================================//|
                                                                                                         //|
//  Datasheet:  http://www.hobbytronics.co.uk/datasheets/DS1302.pdf                                      //|
//  GET UPDATES: https://www.virtuabotix.com/resources.php?product=versalino                             //|
                                                                                                         //|
//=======================================================================================================//|
//                                                                                                       //|
//                                            Reference Links End                                        //|
//                                                                                                       //|
//=======================================================================================================//|


//=======================================================================================================//|
//                                                                                                       //|
//                          Include files required for Program Function Begin                            //|
//                                                                                                       //|
//=======================================================================================================//|
                                                                                                         //|
#include <virtuabotixRTC.h>                                                                              //|
                                                                                                         //|
//=======================================================================================================//|
//                                                                                                       //|
//                          Include files required for Program Function End                              //|
//                                                                                                       //|
//=======================================================================================================//|


// LED output pin asignments
#define LEDPinGood 2
#define LEDPinBad  3

// Creation of the Real Time Clock Object
virtuabotixRTC myRTC(6, 7, 8);



void setup()  {      
  Serial.begin(9600);
  pinMode(LEDPinGood, OUTPUT);                  // Use LED indicator (if required)
  pinMode(LEDPinBad, OUTPUT);                   // Use LED indicator (if required)
  
// Set the current date, and time in the following format:
// seconds, minutes, hours, day of the week, day of the month, month, year
  myRTC.setDS1302Time(00, 59, 23, 6, 10, 1, 2014);
}

//=======================================================================================================//|    
//                                                                                                       //|   
//                         Printout by accessing Single Element objects BEGIN                            //|   
//                                                                                                       //|   
//=======================================================================================================//|   
//                                                                                                       //|   
//  This example utilizes the Serial.print function to access individual data elements, this allows for  //|
//  user defined output format.                                                                          //|
//                                                                                                       //|   
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//|  
void loop()  {                                                                                           //| 
// This allows for the update of variables for time or accessing the individual elements.                //|
  int timeDiff, lastRead = 0;                                                                            //|
  myRTC.updateTime();                                                                                    //| 
  delay(1500);                                                                                           //|
  timeDiff = myRTC.seconds - lastRead;                                                                   //|
  if ( timeDiff < 2 )   {                                                                                //|
    digitalWrite(LEDPinBad, HIGH);                                                                       //|
    } else  {                                                                                            //|
      digitalWrite(LEDPinGood, HIGH);                                                                    //|
      }                                                                                                  //|
  lastRead = myRTC.seconds;                                                                              //|
                                                                                                         //|
// Delay so the program doesn't print non-stop                                                           //|
  delay( 2000 );                                                                                         //|
                                                                                                         //|
  digitalWrite(LEDPinGood, LOW);                                                                         //|
  digitalWrite(LEDPinBad, LOW);                                                                          //|
}                                                                                                        //| 
                                                                                                         //|    
//=======================================================================================================//|    
//                                                                                                       //|    
//                          Printout by accessing Single Element objects END                             //|   
//                                                                                                       //|    
//=======================================================================================================//|    


  
