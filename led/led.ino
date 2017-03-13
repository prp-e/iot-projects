#include <ESP8266WiFi.h>

const char* ssid=""; //put your SSID here
const char* passwd= ""; //put your password here

WiFiServer server(80); 

int led = 13; 

void setup() {
  // put your setup code here, to run once:
  ; 
  pinMode(led, OUTPUT); 
  
  Serial.begin(115200);
  delay(10);
  digitalWrite(led, HIGH);
  WiFi.begin(ssid, passwd);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("."); 
  }
  Serial.println(" "); 
  Serial.println("WiFi Connected!");

  server.begin();
  Serial.println("Server Started!"); 
  Serial.println(WiFi.localIP());
  digitalWrite(led, LOW);
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

 
 if(request.indexOf("/on") != -1) {
  digitalWrite(led, HIGH);
  value = HIGH;
 }
 if(request.indexOf("/off") != -1){
  digitalWrite(led, LOW);
  value = LOW; 
 }

 if(request.indexOf("/blink") != -1){
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
 }

 if(request.indexOf("/double") != -1){
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW); 
  delay(100); 
  digitalWrite(led, HIGH);
  delay(100); 
  digitalWrite(led, LOW);
  delay(500);
 }

 client.println("HTTP/1.1 200 OK");
 client.println("Content-type: text/html");
 client.println("");
 client.println("<!DOCTYPE HTML>");
 client.println("<html>");
 client.println("<head>");
 client.println("<title> Internet Controlled LED </title>");
 client.println("</head>");
 client.println("<body>");
 client.println("<h1>Internet Controlled LED</h1>");
 client.println("<p> With this program, you can control a stupid LED using internet connection!</p>");
 client.println("<h2> Control Options </h2>");
 client.println("<li/> <a href='/on'> Turn it on! </a>");
 client.println("<li/> <a href='/off'> Turn it off! </a>");
 client.println("<li/> <a href='/blink'> Blink </a>");
 client.println("<li/> <a href='/double'> Double blink </a>");                
 client.println("</body>");
 client.println("</html>");
  
}
