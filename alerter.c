#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
void TempertureDisplay(float celcius);
int TemperatureCheck(float celcius);

int networkAlertStub(float celcius) {
    TempertureDisplay(celcius);
    int Temperature_Status =TemperatureCheck(celcius);
    return Temperature_Status;
}
int TemperatureCheck(float celcius)
{
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius<=200)
        return 200;
    else
        return 500;
}
void TempertureDisplay(float celcius)
{
   printf("ALERT: Temperature is %.1f celcius.\n", celcius);
}
    

float FarenheitToCelsius(float farenheit)
{
     float celcius = (farenheit - 32) * 5 / 9;
     return celcius;
}

void FailureCount()
{
    alertFailureCount += 1;
}
void alertInCelcius(float farenheit,float (*Celsius_calc)(float),int (*networkAlert_call)(float)) {
    int celcius=(*Celsius_calc)(farenheit);
    int returnCode = (*networkAlert_call)(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        FailureCount();
    }
}

int main() {
    float (*Celsius_cal)(float)=FarenheitToCelsius;
    int (*networkAlert_call)(float)=networkAlertStub;
    alertInCelcius(400.5,Celsius_cal,networkAlert_call);
    alertInCelcius(303.6,Celsius_cal,networkAlert_call);
    alertInCelcius(572,Celsius_cal,networkAlert_call);
    assert(alertFailureCount==2);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
