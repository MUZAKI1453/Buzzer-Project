#define buzzer 8          // Pin untuk buzzer
#define button 3          // Pin untuk push button

bool buzzerState = LOW;   // Status awal buzzer (mati)
bool lastButtonState = HIGH;  // Status awal tombol (tidak ditekan)

void setup() {
  pinMode(buzzer, OUTPUT);     // Set pin buzzer sebagai output
  pinMode(button, INPUT_PULLUP);   // Set push button sebagai input dengan pullup internal

  digitalWrite(buzzer, buzzerState);   // Matikan buzzer pada awalnya
}

void loop() {
  // Baca keadaan tombol
  bool currentButtonState = digitalRead(button);

  // Jika tombol ditekan (LOW karena menggunakan INPUT_PULLUP) dan sebelumnya tidak ditekan
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    buzzerState = !buzzerState;  // Toggle buzzer (nyala/mati)
    digitalWrite(buzzer, buzzerState);  // Ubah status buzzer
    delay(50);  // Debounce sederhana
  }

  // Simpan keadaan tombol saat ini untuk perbandingan pada loop berikutnya
  lastButtonState = currentButtonState;
}
