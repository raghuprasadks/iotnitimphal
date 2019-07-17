#include <ESP8266WiFi.h>            
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);    //Webserver Object

const char * htmlMessage = " <!DOCTYPE html> "

"<html> "

"<body> "

"<p>This is a HTML only intro page. Please select a button bellow.</p>"

"<a href=\"/javascript\">Javascript code</a>"

"</br>"

"<a href=\"/cssButton\">CSS code</a>"

"</body> "

"</html> ";

// Java script
const char * javascriptCode = " <!DOCTYPE html> "

"<html> "

"<body> "

"<p>Click the button to get a message from the ESP8266:</p> "

"<button onclick=\"buttonFunction()\">Message</button> "

"<REMOVE THIS script>"

"function buttonFunction() { "

" alert(\"Hello from the ESP8266!\"); "

"} "

"</script>"

"</body> "

"</html> ";


// CSS Code

const char * cssButton ="<!DOCTYPE html>"

"<html>"

"<head>"

"<style>"

".button {"

"background-color: #990033;"
"border: none;"
"color: white;"
"padding: 7px 15px;"
"text-align: center;"
"cursor: pointer;"

"}"

"</style>"

"</head>"

"<body>"

"<input type=\"button\" class=\"button\" value=\"Input Button\">"

"</body>"

"</html>";




void setup() {

Serial.begin(115200);                                             //Open Serial connection

WiFi.begin("vivo 1718", "satusamhu");                          //Connect to the WiFi network

while (WiFi.status() != WL_CONNECTED) {    //Wait for connection

delay(500);
Serial.println("Waiting to connect…");

}

Serial.print("IP address: ");
Serial.println(WiFi.localIP());  //Print the local IP

server.on("/", []() {                     //Define the handling function for root path (HTML message)

server.send(200, "text/html", htmlMessage);

});

server.on("/javascript", []() { //Define the handling function for the javascript path

server.send(200, "text/html", javascriptCode);

});

server.on("/cssButton", []() { //Define the handling function for the CSS path

server.send(200, "text/html", cssButton);

});

server.begin(); //Start the server

Serial.println("Server listening");

}

void loop() {

server.handleClient(); //Handling of incoming requests

}
