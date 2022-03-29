//Cardiac output is equal to the area between 2 peaks in the second derivative of filtered signal
double data_filtered[] = {0, 0};
double data[] = {0, 0};
double der_signal[]={0,0};
const int n = 1;
const int analog_pin = A1;//output is taken to Analog pin 1
const double fs=100;//sampling frequency
const double fc=25;//cut off frequency

void setup(){
    Serial.begin(9600);
}

void loop(){
  
    // Retrieve Data
    data[0] = analogRead(analog_pin);// read sensor out
    //butterworth filter
  data_filtered[n]= analogRead(analog_pin)*(1/(1+(fs/fc)*(fs/fc)));
    // Store the previous data in correct index
    data[n-1] = data[n];
    data_filtered[n-1] = data_filtered[n];
    //to find the dichrotic notch position and to set the window
    int rawValue, minimum, maximum, peakValue;
    int threshold = 100; // sensitivity

  minimum = 0; // reset
  maximum = 0;
  for (int i = 0; i < 500; i++) { // measure
    rawValue = data_filtered[n];
    if (rawValue < minimum) minimum = rawValue; // store min peak
    if (rawValue > maximum) maximum = rawValue; // store max peak
  }
  peakValue = maximum - minimum; // calc difference
  if (peakValue > threshold) { // action
    // do something
  }
  Serial.print("Peak value: ");
  //Serial.println(peakValue);
  //to find the second derivative of signal out
  der_signal[n]= 2*data_filtered[n-2]-data_filtered[n-1]-2*data_filtered[n]-data_filtered[n+1]+2*(data_filtered[n+2]);
 
  
  delay(250); // remove in final code
}

    // Print Data
//    Serial.println(data_filtered[n]);
 
