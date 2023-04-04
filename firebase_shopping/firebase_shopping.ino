#include<SPI.h>
#include<RFID.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h> 
#include <LiquidCrystal_I2C.h>
#define SS_PIN D4
#define RST_PIN D3
RFID rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27,16,2);
String rfidCard;
// Set these to run example.
#define FIREBASE_HOST "shopping-cart-bd683-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "7CXic2NjZKfCfiOuvXlYjuKEpw2P5lIhc8YdI31d"
#define WIFI_SSID "Galaxy M52 5G37E1."
#define WIFI_PASSWORD "sharan@2000"
int ocount=0;
int hcount=0;
int p2count=0;
int p3count=0;
int p4count=0;
int p5count=0;
int p6count=0;
int p7count=0;
int p8count=0;
int p9count=0;
int p10count=0;
int p11count=0;
int p12count=0;

int total=0;
int price2;
void setup() {
 SPI.begin();
 rfid.init();
 Serial.begin(9600);
 lcd.begin();
 lcd.backlight();
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("connecting");
  lcd.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    lcd.print(".");
    delay(500);
  }
  lcd.clear();
  Serial.println();
  lcd.print("Connected");
  delay(500);
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  lcd.setCursor(0,1);
  lcd.print(WiFi.localIP());
  lcd.setCursor(0,0);
  delay(500);
  lcd.clear();
  int count=0;
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  String path1="id/id0";
  FirebaseObject object=Firebase.get(path1);
  String id2=object.getString("id1");
  if(id2=="0000000000"){
    lcd.print("Please login");
    lcd.setCursor(0,1);
    lcd.print("to app");
    delay(2000);
    lcd.setCursor(0,0);
    lcd.clear();
  }
  else{
    String path2="users/"+id2;
    FirebaseObject object5=Firebase.get(path2);
    String user=object5.getString("name");
    lcd.print("Welcome");
    lcd.setCursor(0,1);
    lcd.print(user);
    Serial.print(user);
    delay(2000);
    lcd.setCursor(0,0);
    lcd.clear();
    delay(500);
  }
}
void loop(){
   String path3="id/id0";
   FirebaseObject object=Firebase.get(path3);
   String id2=object.getString("id1");
   if(id2=="0000000000"){
    lcd.print("You have");
    lcd.setCursor(0,1);
    lcd.print("logged out");
    delay(2000);
    lcd.setCursor(0,0);
    lcd.clear();
    Serial.print(id2);
  }
  else{
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      rfidCard = String(rfid.serNum[0]) + "" + String(rfid.serNum[1]) + "" + String(rfid.serNum[2]) + "" + String(rfid.serNum[3]);
      Serial.println(rfidCard);
      if(rfidCard=="5121119529"){
          String path="Product/5121119529";
          FirebaseObject object=Firebase.get(path);
          String name=object.getString("Name");
          int price=object.getInt("Price");
          int limit=object.getInt("Limit");
          ocount=ocount+1;
          if(ocount>limit){
            lcd.print(name+" limit");
            lcd.setCursor(0,1);
            lcd.print("reached");
            Serial.println(name+" Limit reached");

          }
          else{
               String path="users/"+id2+"/item/product1";
               Firebase.pushString(path+"/name",name);
               Firebase.setInt(path+"/quantity",ocount);
               Firebase.setInt(path+"/price",price*ocount);
            total=total+price;
            Serial.print(name);
            Serial.print(price);
            Serial.println("");
            lcd.print(name+" added");
            lcd.setCursor(0,1);
            lcd.print(price);
          }
      }
      else if(rfidCard=="2272610946"){
        String path="Product/2272610946";
          FirebaseObject object=Firebase.get(path);
          String name=object.getString("Name");
          int price=object.getInt("Price");
          int limit=object.getInt("Limit");
          hcount=hcount+1;
          if(hcount>limit){
            Serial.println(name+" Limit reached");
            lcd.print(name+" limit");
            lcd.setCursor(0,1);
            lcd.print("reached");
          }
          else{
               String path="users/"+id2+"/item/product2";
               Firebase.setString(path+"/name",name);
               Firebase.setInt(path+"/quantity",hcount);
               Firebase.setInt(path+"/price",price*hcount);
            total=total+price;
            Serial.print(name);
            Serial.print(price);
            Serial.println("");
            lcd.print(name+" added");
            lcd.setCursor(0,1);
            lcd.print(price);
          }
      }
      else if(rfidCard=="2265311028"){
        String path="Product/2265311028";
          FirebaseObject object=Firebase.get(path);
          String name=object.getString("Name");
          int price=object.getInt("Price");
          int limit=object.getInt("Limit");
          p2count=p2count+1;
          if(p2count>limit){
            Serial.println(name+" Limit reached");
            lcd.print(name+" limit");
            lcd.setCursor(0,1);
            lcd.print("reached");
            

          }
          else{
               String path="users/"+id2+"/item/product3";
               Firebase.setString(path+"/name",name);
               Firebase.setInt(path+"/quantity",p2count);
               Firebase.setInt(path+"/price",price*p2count);
            total=total+price;
            Serial.print(name);
            Serial.print(price);
            Serial.println("");
            lcd.print(name+" added");
            lcd.setCursor(1,0);
            lcd.print(price);
          }
      }
      else if(rfidCard=="2101783428"){
        String path="Product/2101783428";
          FirebaseObject object=Firebase.get(path);
          String name=object.getString("Name");
          int price=object.getInt("Price");
          int limit=object.getInt("Limit");
          p3count=p3count+1;
          if(p3count>limit){
            Serial.println(name+" Limit reached");
            lcd.print(name+" limit");
            lcd.setCursor(0,1);
            lcd.print("reached");
          }
          else{
               String path="users/"+id2+"/item/product4";
               Firebase.setString(path+"/name",name);
               Firebase.setInt(path+"/quantity",p3count);
               Firebase.setInt(path+"/price",price*p3count);
            total=total+price;
            Serial.print(name);
            Serial.print(price);
            Serial.println("");
            lcd.print(name+" added");
            lcd.setCursor(0,1);
            lcd.print(price);
          }
      }
      else if(rfidCard=="226555128"){
        String path="Product/226555128";
          FirebaseObject object=Firebase.get(path);
          String name=object.getString("Name");
          int price=object.getInt("Price");
          int limit=object.getInt("Limit");
          p4count=p4count+1;
          if(p4count>limit){
            Serial.println(name+" Limit reached");
            lcd.print(name+" limit");
            lcd.setCursor(0,1);
            lcd.print("reached");  
          }
          else{
               String path="users/"+id2+"/item/product5";
               Firebase.setString(path+"/name",name);
               Firebase.setInt(path+"/quantity",p4count);
               Firebase.setInt(path+"/price",price*p4count);
            total=total+price;
            Serial.print(name);
            Serial.print(price);
            Serial.println("");
            lcd.print(name+" added");
            lcd.setCursor(0,1);
            lcd.print(price);
          }
      }
      else if(rfidCard=="1922534526"){
        String path="Product/1922534526";
          FirebaseObject object=Firebase.get(path);
          String name=object.getString("Name");
          int price=object.getInt("Price");
          int limit=object.getInt("Limit");
          p5count=p5count+1;
          if(p5count>limit){
            Serial.println(name+" Limit reached");
            lcd.print(name+" limit");
            lcd.setCursor(0,1);
            lcd.print("reached");
  
          }
          else{
               String path="users/"+id2+"/item/product6";
               Firebase.setString(path+"/name",name);
               Firebase.setInt(path+"/quantity",p5count);
               Firebase.setInt(path+"/price",price*p5count);
            total=total+price;
            Serial.print(name);
            Serial.print(price);
            Serial.println("");
            lcd.print(name+" added");
            lcd.setCursor(0,1);
            lcd.print(price);
          }
      }
      else if(rfidCard=="48292234"){
        String path="Product/48292234";
          FirebaseObject object=Firebase.get(path);
          String name=object.getString("Name");
          int price=object.getInt("Price");
          int limit=object.getInt("Limit");
          p6count=p6count+1;
          if(p6count>limit){
            Serial.println(name+" Limit reached");
            lcd.print(name+" limit");
            lcd.setCursor(0,1);
            lcd.print("reached");
            

          }
          else{
               String path="users/"+id2+"/item/product7";
               Firebase.setString(path+"/name",name);
               Firebase.setInt(path+"/quantity",p6count);
               Firebase.setInt(path+"/price",price*p6count);
            total=total+price;
            Serial.print(name);
            Serial.print(price);
            Serial.println("");
            lcd.print(name+" added");
            lcd.setCursor(0,1);
            lcd.print(price);
          }
      }
      else if(rfidCard=="2102457928"){
        String path="Product/2102457928";
          FirebaseObject object=Firebase.get(path);
          String name=object.getString("Name");
          int price=object.getInt("Price");
          int limit=object.getInt("Limit");
          p7count=p7count+1;
          if(p7count>limit){
            Serial.println(name+" Limit reached");
            lcd.print(name+" limit");
            lcd.setCursor(0,1);
            lcd.print("reached");
            

          }
          else{
               String path="users/"+id2+"/item/product8";
               Firebase.setString(path+"/name",name);
               Firebase.setInt(path+"/quantity",p7count);
               Firebase.setInt(path+"/price",price*p7count);
            total=total+price;
            Serial.print(name);
            Serial.print(price);
            Serial.println("");
            lcd.print(name+" added");
            lcd.setCursor(0,1);
            lcd.print(price);
          }
      }
      else if(rfidCard=="67545947"){
        String path="Product/67545947";
          FirebaseObject object=Firebase.get(path);
          String name=object.getString("Name");
          int price=object.getInt("Price");
          int limit=object.getInt("Limit");
          p8count=p8count+1;
          if(p8count>limit){
            Serial.println(name+" Limit reached");
            lcd.print(name+" limit");
            lcd.setCursor(0,1);
            lcd.print("reached");
            

          }
          else{
               String path="users/"+id2+"/item/product9";
               Firebase.setString(path+"/name",name);
               Firebase.setInt(path+"/quantity",p8count);
               Firebase.setInt(path+"/price",price*p8count);
            total=total+price;
            Serial.print(name);
            Serial.print(price);
            Serial.println("");
            lcd.print(name+" added");
            lcd.setCursor(0,1);
            lcd.print(price);
          }
      }
      else if(rfidCard=="2101217628"){
        String path="Product/2101217628";
          FirebaseObject object=Firebase.get(path);
          String name=object.getString("Name");
          int price=object.getInt("Price");
          int limit=object.getInt("Limit");
          p9count=p9count+1;
          if(p9count>limit){
            Serial.println(name+" Limit reached");
            lcd.print(name+" limit");
            lcd.setCursor(0,1);
            lcd.print("reached");
            

          }
          else{
               String path="users/"+id2+"/item/product10";
               Firebase.setString(path+"/name",name);
               Firebase.setInt(path+"/quantity",p9count);
               Firebase.setInt(path+"/price",price*p9count);
            total=total+price;
            Serial.print(name);
            Serial.print(price);
            Serial.println("");
            lcd.print(name+" added");
            lcd.setCursor(0,1);
            lcd.print(price);
          }
      }
      else if(rfidCard=="2103017828"){
        String path="Product/2103017828";
          FirebaseObject object=Firebase.get(path);
          String name=object.getString("Name");
          int price=object.getInt("Price");
          int limit=object.getInt("Limit");
          p10count=p10count+1;
          if(p10count>limit){
            Serial.println(name+" Limit reached");
            lcd.print(name+" limit");
            lcd.setCursor(0,1);
            lcd.print("Reached");
            

          }
          else{
               String path="users/"+id2+"/item/product11";
               Firebase.setString(path+"/name",name);
               Firebase.setInt(path+"/quantity",p10count);
               Firebase.setInt(path+"/price",price*p10count);
            total=total+price;
            Serial.print(name);
            Serial.print(price);
            Serial.println("");
            lcd.print(name+" added");
            lcd.setCursor(0,1);
            lcd.print(price);
          }
      }
      else if(rfidCard=="2091523828"){
        String path="Product/2091523828";
          FirebaseObject object=Firebase.get(path);
          String name=object.getString("Name");
          int price=object.getInt("Price");
          int limit=object.getInt("Limit");
          p11count=p11count+1;
          if(p11count>limit){
            Serial.println(name+" Limit reached");
            lcd.print(name+" limit");
            lcd.setCursor(0,1);
            lcd.print("reached");
            

          }
          else{
               String path="users/"+id2+"/item/product12";
               Firebase.setString(path+"/name",name);
               Firebase.setInt(path+"/quantity",p11count);
               Firebase.setInt(path+"/price",price*p11count);
            total=total+price;
            Serial.print(name);
            Serial.print(price);
            Serial.println("");
            lcd.print(name+" `added");
            lcd.setCursor(0,1);
            lcd.print(price);
          }
      }
      else if(rfidCard=="25521883"){
        String path="Product/25521883";
          FirebaseObject object=Firebase.get(path);
          String name=object.getString("Name");
          int price=object.getInt("Price");
          int limit=object.getInt("Limit");
          p11count=p11count+1;
          if(p12count>limit){
            Serial.println(name+" Limit reached");
            lcd.print(name+" limit");
            lcd.setCursor(0,1);
            lcd.print("reached");
            

          }
          else{
               String path="users/"+id2+"/item/product13";
               Firebase.setString(path+"/name",name);
               Firebase.setInt(path+"/quantity",p12count);
               Firebase.setInt(path+"/price",price*p12count);
            total=total+price;
            Serial.print(name);
            Serial.print(price);
            Serial.println("");
            lcd.print(name+" `added");
            lcd.setCursor(0,1);
            lcd.print(price);
          }
      }
    }
  }
  delay(500);
  lcd.clear();
  String final="users/"+id2+"";
  Firebase.setInt(final+"/spent",total);
  Firebase.setInt(final+"/balance",5000-total);
  }
}
