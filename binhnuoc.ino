#define SENSOR_PIN 4  // Cảm biến vật cản LM393
#define RELAY_PIN 5   // Relay điều khiển bơm

void setup() {
    pinMode(SENSOR_PIN, INPUT);
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW);  // Tắt bơm ban đầu
    Serial.begin(115200);
    Serial.println("Khoi dong he thong may rot nuoc tu dong...");
}

void loop() {
    int sensorValue = digitalRead(SENSOR_PIN);
    
    Serial.print("Trang thai cam bien: ");
    Serial.println(sensorValue);

    if (sensorValue == LOW) {  // Nếu phát hiện vật cản (ly đặt vào)
        Serial.println("Ly da duoc dat vao - Bat bom...");
        digitalWrite(RELAY_PIN, HIGH);  // Bật bơm
    } else {
        Serial.println("Khong co ly - Tat bom.");
        digitalWrite(RELAY_PIN, LOW);  // Tắt bơm khi không có ly
    }

    delay(500);  // Chờ 0.5 giây để tránh đọc nhiễu liên tục
}
