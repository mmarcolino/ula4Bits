int l0 = 10, l1 = 11, l2 = 12, l3 = 13;
int  x, y, w;
int pos, aux;
String process[100];
String mode;

void setup() {
  pinMode(l0, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    mode = Serial.readString();
    
    pos = process[0].toInt();
    if (pos == 0) {
      	process[0] = "4";
      	process[1] = "0";
  	  	process[2] = "0";
  	  	process[3] = "0";
      	pos = 4;
    }
    
    if (mode.length() >= 3 && mode.equals("end") == 0) {
        process[pos] = mode;
      	addprocess();
      	serialPrint(process, pos);
        
    } else {
      aux = process[0].toInt();
      process[0] = 4;
      pos = 4;
      for (int i = 4; i < aux; i++) {
        x = hexToInt(process[i].charAt(0));
        y = hexToInt(process[i].charAt(1));
        w = hexToInt(process[i].charAt(2));
        
		setprocess();
        addprocess();
		serialPrint(process, pos);
        
      	printL(operation(x, y, w));
        delay(2000);
        pos++;
      }
      exit(0);
    }
  }
}

void setprocess(){
    clearArray();

    x = hexToInt(process[pos].charAt(0));
    process[2] += process[pos].charAt(0);

    y = hexToInt(process[pos].charAt(1));
    process[3] += process[pos].charAt(1);
      
    w = hexToInt(process[pos].charAt(2));  
    process[1] += intToHex(operation(x, y, w));
}

void addprocess(){
	process[0] = String(process[0].toInt() + 1);
}

void clearArray(){
    process[1] = "";  
    process[2] = "";
    process[3] = "";
}

int hexToInt(char h) {
  int returner = -1;
  if (h >= 48 && h <= 57) {
    returner = (int)(h - 48);
  } else if (h >= 65 && h <= 70) {
    returner = (int)(h - 55);
  }

  return returner;
}

char intToHex(int i) {
  char returner = '0';
  if (i >= 0 && i <= 9) {
    returner = (char)(i + 48);
  } else if (i >= 10 && i <= 15) {
    returner = (char)(i + 55);
  }

  return returner;
}

int operation(int a, int b, int op) {
  int retorno = 0;
  switch (op) {
  case 0:
    return notNum(a);
    break;
  case 1:
    return notNum(orAB(a, b));
    break;
  case 2:
    return andAB(notNum(a), b);
    break;
  case 3:
    return 0;
    break;
  case 4:
    return notNum(andAB(a, b));
    break;
  case 5:
    return notNum(b);
    break;
  case 6:
    return xorAB(a, b);
    break;
  case 7:
    return andAB(a, notNum(b));
    break;
  case 8:
    return orAB(notNum(a), b);
    break;
  case 9:
    return notNum(xorAB(a, b));
    break;
  case 10:
    return b;
    break;
  case 11:
    return andAB(a, b);
    break;
  case 12:
    return 1;
    break;
  case 13:
    return orAB(a, notNum(b));
    break;
  case 14:
    return orAB(a, b);
    break;
  case 15:
    return a;
    break;
  }

  return retorno;
}


int andAB (int a, int b){
    return a & b;
}

int notNum(int num){
    return 15 - num;
}

int orAB(int a, int b){
    return a | b;
}

int xorAB (int a, int b){
    return a ^ b;
}


void printL(int res) {
  
  if (res >= 8) {
    res -= 8;
    digitalWrite(l3, HIGH);
  } else {
  	digitalWrite(l3, LOW);
  }
  
  if (res >= 4) {
    res -= 4;
    digitalWrite(l2, HIGH);
  } else {
  	digitalWrite(l2, LOW);
  }
  
  if (res >= 2) {
    res -= 2;
    digitalWrite(l1, HIGH);
  } else {
  	digitalWrite(l1, LOW);
  }

  digitalWrite(l0, res == 0 ? LOW : HIGH);
}

void serialPrint(String operations[100], int tam) {
  Serial.print("->|");
  for (int i = 0; i <= tam; i++) {
    Serial.print(operations[i]);
    Serial.print("|");
  }
  Serial.print("\n");
}