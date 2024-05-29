/*
    This sketch demonstrates how to set up a simple HTTP-like server.
    The server will set a GPIO pin depending on the request
      http://server_ip/gpio/0 will set the GPIO2 low,
      http://server_ip/gpio/1 will set the GPIO2 high
    server_ip is the IP address of the ESP8266 module, will be
    printed to Serial when the module is connected.
*/

#include <WiFi.h>

/*
//variáveis
IPAddress ip(192, 168, 1, 121);   //mudar o ultimo digito
IPAddress ip1(192, 168, 1, 10);
IPAddress ip2(255, 255, 255, 0);

#ifndef STASSID
#define STASSID "NTI"
#define STAPSK  "nti41093245"
#endif
*/

const char* ssid = "S10e";
const char* password = "beta01020304";
int LED = 13;

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  // prepare LED
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print(F("Connecting to "));
  Serial.println(ssid);

//  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WiFi connectado:"));
  Serial.println("Endereço IP:");
  // Print the IP address
  Serial.println(WiFi.localIP());

//setup após a conexão
// WiFi.config(ip, ip1, ip2); 

  // Start the server
  server.begin();
  Serial.println(F("Server started"));
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.println(F("new client"));

  client.setTimeout(5000); // default is 1000

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(F("request: "));
  Serial.println(req);

  // Match the request
  int val;
  
  if (req.indexOf("?Desliga=") != -1)      
    val = 0;
  else if (req.indexOf("?Liga=") != -1)    
    val = 1;
  else {
    Serial.println(F("invalid request"));
    val = digitalRead(LED);
  }

  // Set LED according to the request
  digitalWrite(LED, val);

  // read/ignore the rest of the request
  // do not client.flush(): it is for output only, see below
  while (client.available()) {
    // byte by byte is not very efficient
    client.read();
  }

  // Send the response to the client
  // it is OK for multiple small client.print/write,
  // because nagle algorithm will group them into one single packet
  client.print(F("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n "));
//  client.print((val) ? F("high") : F("low"));
//  client.print(F("<br><br>Click <a href='http://"));
 // client.print(WiFi.localIP());
//  client.print(F("/gpio/1'>here</a> to switch LED GPIO on, or <a href='http://"));
///  client.print(WiFi.localIP());
 // client.print(F("/gpio/0'>here</a> to switch LED GPIO off.</html>"));



   client.print(F("<div style=\"text-align: center\">"));
    client.print(F("<h1><html style=\"font-size:14px\"> SECITEC - NTI EDUCATECH\n</h1>"));
    client.print(F("<body>\n"));
   client.print(F("<form action=\"http://"));
  
    client.print(WiFi.localIP());
  
   client.print(F("\" method=\"get\">\n"));
  
   client.print(F("<b><br></br><html style=\"font-size:14px\"> Ligar LED da placa do ESP32_DevKitC\n</b>"));
   client.print(F("<p></p><button input name=\"Desliga\" style=\"height:20px;width:150px;font-size:13px\" >Desligar</button>")); //<br></br>
   client.print(F("<button input name=\"Liga\" style=\"height:20px;width:150px;font-size:13px\" >Ligar</button>"));
   client.print(F("<p></p>"));
   //client.print("F(<img src="\img\SECITEC.jpeg" width="300" height="300" alt="ReUse">)");
   client.print(F("</form>\n"));
   client.print(F("</body>\n"));
   client.print(F("</div>"));

  
   client.print(F("</html>"));




  // The client will actually be *flushed* then disconnected
  // when the function returns and 'client' object is destroyed (out-of-scope)
  // flush = ensure written data are received by the other side
  Serial.println(F("Disconnecting from client"));
}
