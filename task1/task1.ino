#include <WiFi.h>
#include <PubSubClient.h>

// WiFi
const char* ssid = "iPhone";
const char* password = "iroda1119";

// MQTT Broker
const char* mqtt_broker = "mqtt.iotserver.uz";
const char* topic = "ttpu/team1";
const char* mqtt_username = "userTTPU";
const char* mqtt_password = "mqttpass";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

// LED Pins
const int ledRed = 4;
const int ledGreen = 5;
const int ledYellow = 19;
const int ledBlue = 22;

void setup() {
    Serial.begin(115200);
    
    // Set LED pins as output
    pinMode(ledRed, OUTPUT);
    pinMode(ledGreen, OUTPUT);
    pinMode(ledYellow, OUTPUT);
    pinMode(ledBlue, OUTPUT);

    // Connect to WiFi
    connectToWiFi();
    
    // Configure MQTT
    client.setServer(mqtt_broker, mqtt_port);
    client.setCallback(callback);
}

void connectToWiFi() {
    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi!");
}

void reconnectMQTT() {
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        String client_id = "esp32-client-";
        client_id += String(WiFi.macAddress());
        if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
            Serial.println("connected to MQTT broker");
            client.subscribe(topic);
        } else {
            Serial.print("failed with state ");
            Serial.print(client.state());
            Serial.println(" trying again in 2 seconds");
            delay(2000);
        }
    }
}

void callback(char* topic, byte* payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message: ");
    
    String message;
    

    Serial.println();
    Serial.println("-----------------------");

    if (message == "red on") {
        digitalWrite(ledRed, HIGH);
    } else if (message == "red off") {
        digitalWrite(ledRed, LOW);
    } else if (message == "green on") {
        digitalWrite(ledGreen, HIGH);
    } else if (message == "green off") {
        digitalWrite(ledGreen, LOW);
    } else if (message == "yellow on") {
        digitalWrite(ledYellow, HIGH);
    } else if (message == "yellow off") {
        digitalWrite(ledYellow, LOW);
    } else if (message == "blue on") {
        digitalWrite(ledBlue, HIGH);
    } else if (message == "blue off") {
        digitalWrite(ledBlue, LOW);
    }
}

void loop() {
    if (WiFi.status() != WL_CONNECTED) {
        connectToWiFi();
    }
    if (!client.connected()) {
        reconnectMQTT();
    }

    client.loop();
}

