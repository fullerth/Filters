#include"RunningStatisticsTests.h"

#ifndef __RFduino__

void testRunningStatistics() {
  // a speed test for running statistics
  
  RunningStatistics myStats;
  
  myStats.setInitialValue( (1.0/1024)*float(analogRead( A0 )) );
  
  float updateInterval = 1.0;
  float nextUpdateTime = 1e-6*float(micros()) + updateInterval;
  
  long nLoops = 0;
  
  while( true ) {
    myStats.input( (1.0/1024)*float(analogRead( A0 )) );
    nLoops++;
    float t = 1e-6*float(micros());
    
    if( t > nextUpdateTime ) {
      nextUpdateTime += updateInterval;
      
      Serial.print( "mean: "); Serial.print( myStats.mean() );
      Serial.print( "\tsigma: " ); Serial.print( myStats.sigma() );
      Serial.print( "\tHz: "); Serial.print( nLoops );
      
      nLoops = 0;
      Serial.print("\n");
    }
  }
}

#endif //__RFduino__
