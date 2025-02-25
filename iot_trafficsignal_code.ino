# define left_ir 13
# define down_ir 12
# define right_ir 11
# define up_ir 10

# define left_red 9 
# define left_yellow 8
# define left_green 7

# define down_red 6
# define down_yellow 5
# define down_green 4

# define right_red 3
# define right_yellow 2
# define right_green 1

# define up_red A1
# define up_yellow A2
# define up_green A3

void setup() {
  pinMode(left_ir, INPUT);
  pinMode(down_ir, INPUT);
  pinMode(right_ir, INPUT);
  pinMode(up_ir, INPUT);

  pinMode(left_red, OUTPUT);
  pinMode(left_yellow, OUTPUT);
  pinMode(left_green, OUTPUT);

  pinMode(down_red, OUTPUT);
  pinMode(down_yellow, OUTPUT);
  pinMode(down_green, OUTPUT);

  pinMode(right_red, OUTPUT);
  pinMode(right_yellow, OUTPUT);
  pinMode(right_green, OUTPUT);

  pinMode(up_red, OUTPUT);
  pinMode(up_yellow, OUTPUT);
  pinMode(up_green, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  all_reds_high();
  default_traffic();
}

void all_reds_high() {
  digitalWrite(left_red, HIGH);
  digitalWrite(right_red, HIGH);
  digitalWrite(up_red, HIGH);
  digitalWrite(down_red, HIGH);
}

void default_traffic() {
  if (digitalRead(left_ir)) { Serial.println("left ir read"); set_lane_lights(left_red, left_yellow, left_green, 3000, 5000); } 
  else { Serial.println("left ir read"); set_lane_lights(left_red, left_yellow, left_green, 2000, 10000); }

  if (digitalRead(down_ir)) { set_lane_lights(down_red, down_yellow, down_green, 3000, 5000); } 
  else { set_lane_lights(down_red, down_yellow, down_green, 2000, 10000); }

  if (digitalRead(right_ir)) { set_lane_lights(right_red, right_yellow, right_green, 3000, 5000); } 
  else { set_lane_lights(right_red, right_yellow, right_green, 2000, 10000); }

  if (digitalRead(up_ir)) { set_lane_lights(up_red, up_yellow, up_green, 3000, 5000); } 
  else { set_lane_lights(up_red, up_yellow, up_green, 2000, 10000); }
}

void set_lane_lights(int red, int yellow, int green, int second_timer, int third_timer) {
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  delay(second_timer);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(third_timer);
  digitalWrite(green, LOW);
  digitalWrite(red,HIGH);
}