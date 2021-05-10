const uint8_t INVALID_PIN = 100;

class Button {
    bool pressed;
    uint8_t pin;

    void updateState() {
        if(pin != INVALID_PIN){
            pressed = (digitalRead(pin) == LOW);
        }
    }

    public:
    Button() : pressed(false), pin(INVALID_PIN) {}
    Button(uint8_t pin) : pressed(false), pin(pin) {
        pinMode(pin,INPUT_PULLUP);
        updateState();
    }

    bool isPressed(){
        updateState();
        return pressed;
    }

    bool wasJustPressed(){
        bool previouslyPressed = pressed;
        updateState();
        return !previouslyPressed && pressed;
    }

};

Button button;

void setup() {
  button = Button(A0);
  Serial.begin(9600);
}

void loop() {
  if (button.wasJustPressed()){
    Serial.println("toto");
  }

}
