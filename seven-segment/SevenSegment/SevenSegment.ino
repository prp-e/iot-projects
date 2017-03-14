//IoT Seven Segment
#include <ESP8266WiFi.h>

const char* ssid = "Muhammadreza";
const char* passwd = "Muhammadreza@123456";

int a = 16;
int b = 5;
int c = 4;
int d = 2;
int e = 0;
int f = 14;
int g = 12;

int led = 13; 

WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  Serial.begin(115200);
  delay(10);
  digitalWrite(led, HIGH);
  WiFi.begin(ssid, passwd);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println(" ");
  Serial.println("WiFi Connected");

  server.begin();
  Serial.println("Server Started!");
  Serial.println(WiFi.localIP());
  digitalWrite(led, LOW);

  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  

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
  
  if(request.indexOf("/1") != -1){
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);

    value = HIGH;
  }

   if(request.indexOf("/2") != -1){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);

    value = HIGH;
  }

   if(request.indexOf("/3") != -1){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);

    value = HIGH;
  }

   if(request.indexOf("/4") != -1){
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

    value = HIGH;
  }

   if(request.indexOf("/5") != -1){
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

    value = HIGH;
  }

  if(request.indexOf("/6") != -1){
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

    value = HIGH;
  }

  if(request.indexOf("/7") != -1){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);

    value = HIGH;
  }

  if(request.indexOf("/8") != -1){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

    value = HIGH;
  }

  if(request.indexOf("/9") != -1){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

    value = HIGH;
  }

  if(request.indexOf("/0") != -1){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);

    value = HIGH;
  }

 if(request.indexOf("/off") != -1){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);

  value = LOW;
 }

 client.println("HTTP/1.1 200 OK");
 client.println("Content-type: text/html");
 client.println("");
 client.println("<!DOCTYPE HTML>");
 client.println("<html>");
 client.println("<head>");
 client.println("<title> IoT Seven Segment </title>");
 client.println("</head>"); 
 client.println("<body>");
 client.println("<h1> IoT Seven Segment </h1>");
 client.println("<p> Just send requests like this :");
 client.println("<br/><pre>/0</pre><br/>");
 client.println("to show the number you want! It works with digits from 0 to 9");
 client.println("if you want to turn it off, just <a href='/off'> click here</a></p>");
 client.println("</body>"); 

}
