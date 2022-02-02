#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
void TempertureDisplay(float celcius);
int TemperatureCheck(float celcius);
int networkAlert(float celcius);
void ClearFailureCnt();

int networkAlertStub(float celcius) {
    TempertureDisplay(celcius);
    int Temperature_Status =TemperatureCheck(celcius);
    return Temperature_Status;
}

int networkAlert(float celcius) {
    TempertureDisplay(celcius);
    /*Considering this as network alert function in production 
    which takes necessary action and clearing the failure count*/
    ClearFailureCnt();
    // Return 200 for ok
    return 200;
}

void ClearFailureCnt()
{
    alertFailureCount=0;
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

void NetworkAlertFailureCheck(int ret_status)
{
     if (ret_status != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        FailureCount();
    }
}
void alertInCelcius(float farenheit,float (*Celsius_calc)(float),int (*networkAlert_call)(float)) {
    int celcius=(*Celsius_calc)(farenheit);
    int returnCode = (*networkAlert_call)(celcius);
    NetworkAlertFailureCheck(returnCode);
}

int main() {
    float (*Celsius_cal)(float)=FarenheitToCelsius;
    int (*networkAlert_call)(float)=networkAlertStub;
    alertInCelcius(400.5,Celsius_cal,networkAlert_call);
    alertInCelcius(303.6,Celsius_cal,networkAlert_call);
    alertInCelcius(572,Celsius_cal,networkAlert_call);
    assert(alertFailureCount==2);
    alertInCelcius(500,Celsius_cal,networkAlert_call);
    alertInCelcius(200,Celsius_cal,networkAlert_call);
    assert(alertFailureCount==3);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("Production code test");
    int (*networkAlert_Prod)(float)=networkAlert;
    alertInCelcius(200,Celsius_cal,networkAlert_Prod);
    assert(alertFailureCount==0);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
