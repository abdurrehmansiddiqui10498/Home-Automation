//Change these three lines for each blynk project and account.
#define BLYNK_TEMPLATE_ID &quot;TMPL61VVQQZCS&quot;
#define BLYNK_TEMPLATE_NAME &quot;Home&quot;
#define BLYNK_AUTH_TOKEN &quot;hzElgaoRlgVSgZRifM08OIJZCXgsZIIL&quot;

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial
//hardWare Specifics
#include &lt;ESP8266WiFi.h&gt;
#include &lt;BlynkSimpleEsp8266.h&gt;
char auth[] = BLYNK_AUTH_TOKEN;
#define relay1 D1
#define relay2 D2
// Your WiFi credentials.
char ssid[] =  &quot;Home&quot;; //  &quot;WIFI NAME&quot;;
char pass[] =  &quot;12345678&quot;;     //  &quot;WIFI PASSWORD&quot;; // Set password to
&quot;&quot; for open networks.

BLYNK_WRITE(V0) {
  bool value1 = param.asInt();
  // Check these values and turn the relay1 ON and OFF
  if (value1 == 1) {
    digitalWrite(relay1, LOW);
  } else {
    digitalWrite(relay1, HIGH);
  }
}
BLYNK_WRITE(V1) {
  bool value2 = param.asInt();
  // Check these values and turn the relay1 ON and OFF

  if (value2 == 1) {
    digitalWrite(relay2, LOW);
  } else {
    digitalWrite(relay2, HIGH);
  }
}
void setup() {
  //Set the relay pins as output pins
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  // Turn OFF the relay
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, &quot;blynk.cloud&quot;, 80);
}
void loop() {
  //Run the Blynk library
  Blynk.run();
}
