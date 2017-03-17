#include <ESP8266WiFi.h>

#define ST_CP 16
#define DS 5
#define SH_CP 4
#define SERVER 13

const char* ssid = "Muhammadreza";
const char* passwd = "Muhammadreza@123456";

int i = 0;

WiFiServer server(80);

byte digits[10] = {
  0x3f,
  0x06,
  0x5b,
  0x4f,
  0x66,
  0x6d,
  0x7d,
  0x07,
  0x7f,
  0x6f
};

char reqs[] = { '/0', '/1', '/2', '/3', '/4', '/5', '/6' , '/7', '/8', '/9'};

void setup() {
  // put your setup code here, to run once:
  pinMode(ST_CP, OUTPUT);
  pinMode(DS, OUTPUT);
  pinMode(SH_CP, OUTPUT);
  pinMode(SERVER, OUTPUT);

  Serial.begin(115200);
  delay(10);
  digitalWrite(SERVER, HIGH);
  WiFi.begin(ssid, passwd); 
  while(WiFi.status() != WL_CONNECTED){
    delay(50);
    Serial.print(".");
  }
  Serial.println(" ");
  Serial.println("Connection Established");

  server.begin();
  Serial.println("Server Started!");
  Serial.println(WiFi.localIP());
  digitalWrite(SERVER, LOW);
  

}

void loop() {
  // put your main code here, to run repeatedly:
 WiFiClient client = server.available();
 if(!client){
  return;
 }

 while(!client.available()){
  delay(1);
 }

 String request = client.readStringUntil('\r');
 Serial.println(request);
 client.flush();

 int value = LOW;

 for(i = 0; i < 10; i++){
  if(request.indexOf(reqs[i]) != -1){
  digitalWrite(ST_CP, LOW);
  shiftOut(DS, SH_CP, MSBFIRST, ~(digits[i]));
  digitalWrite(ST_CP, HIGH);
  value = HIGH;
  } 
 }

 client.println("HTTP/1.1 200 OK");
 client.println("Content-type: text/html");
 client.println("");
 client.println("<!DOCTYPE HTML>");
 client.println("<html>");
 client.println("<head>");
 client.println("<title> Internet Controlled Seven Segment (Shift Register) </title>");
 client.println("</head>");
 client.println("<body>");
 client.println("<h1> IoT Seven Segment </h1>");
 client.println("<p> Just send requests like this :");
 client.println("<br/><pre>/0</pre><br/>");
 client.println("</body>");
 

}
