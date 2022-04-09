#include <WiFi.h>

const char* ssid = "nom reseau wifi";
const char* password = "mot de passe ";


//nom du réseau et mot de passe 


IPAddress local_IP(192, 168, 1, 120); // adresse static
IPAddress gateway(192, 168, 1, 1);   // definition de la passerelle
IPAddress subnet(255, 255, 0, 0);  // definition sous masque d'adresse 

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.mode(WIFI_STA);

  if (WiFi.config(local_IP, gateway, subnet) == false) {
    Serial.println("echec de Configuration .");
  }

  WiFi.begin(ssid, password);
  Serial.println("connexion.....");

  while(WiFi.status() != WL_CONNECTED){
    Serial.print("..");
    delay(100);
  }

  Serial.println("\nconnecté à un réseau wifi..");
  Serial.print("adresse IP: ");
  Serial.println(WiFi.localIP());


}

void loop() {
  // put your main code here, to run repeatedly:

}
